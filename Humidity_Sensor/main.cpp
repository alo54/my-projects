#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "wifi_ssid"; // WiFi SSID
const char* password = "wifi_password"; // WiFi password
String url = "https://"; //webpage url

#define soil_moisture_pin 32
#define led_success_query 26
#define led_failed_query 25
#define led_no_connection 27

int humidity = 54; // Example data

// this function adjusts the sensor value into a percentaje
// the constants min_value and range_scale come from the analysis made on the "Calibration.cpp" file
int dataCompression(int value) 
{

    double min_value = 1119, range_scale = 29.76;

    value = max(value, min_value); // to avoid values out of range

    int percentage = (((double ) value - min_value) / range_scale);

    percentage = 100 - percentage;
    
    return percentage;
}


void connectToWiFi() {
    WiFi.mode(WIFI_STA); // Set mode to Station
    WiFi.begin(ssid, password); // Connect to WiFi
    Serial.println("Connecting to WiFi...");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    digitalWrite(led_no_connection, LOW);
    Serial.println("Connected to WiFi!");
}

void sendPostRequest() {
    if (WiFi.status() == WL_CONNECTED) 
    {
        digitalWrite(led_no_connection, LOW);
        HTTPClient http;
        WiFiClientSecure client; // Use secure connection for HTTPS

        client.setInsecure();
        http.begin(client, url); // Initialize HTTP connection
        http.addHeader("Content-Type", "application/x-www-form-urlencoded"); // Correct Content-Type

        String postData = "humidity=" + String(humidity); // Key-value pair
        Serial.print("Sending POST data: "); 
        Serial.println(postData);


        int httpCode = http.POST(postData); // Send POST request

        if (httpCode == HTTP_CODE_OK) 
        {
            digitalWrite(led_success_query, HIGH);
            delay(1000);
            digitalWrite(led_success_query, LOW);
            String response = http.getString();
            Serial.print("Server Response: "); 
            Serial.println(response);
        } else 
        {
            digitalWrite(led_failed_query, HIGH);
            delay(500);
            digitalWrite(led_failed_query, LOW);
            Serial.printf("[HTTP] POST failed, code: %d\n", httpCode); // HTTP error handling
            Serial.printf("Error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end(); // Always close HTTP connection
    } else 
    {
        digitalWrite(led_no_connection, HIGH);
        Serial.println("WiFi not connected. Reconnecting...");
        connectToWiFi(); // Reconnect if needed
    }
}

void setup() {
    Serial.begin(9600); // Start serial communication
    pinMode(soil_moisture_pin, OUTPUT);
    pinMode(led_success_query, OUTPUT);
    pinMode(led_failed_query, OUTPUT);
    pinMode(led_no_connection, OUTPUT);

    digitalWrite(led_no_connection, HIGH);
    

    connectToWiFi(); // Connect to WiFi
}

void loop() 
{
    humidity = dataCompression(analogRead(soil_moisture_pin));

    sendPostRequest(); // Send POST request with humidity data
    delay(10000); // Delay to avoid excessive requests
}
