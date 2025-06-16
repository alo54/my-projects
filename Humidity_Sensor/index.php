<?php
echo "<button onclick=\"window.location.href='humidity_submission.php'\">Go to Humidity Submission</button>";
echo "<button onclick=\"window.location.href='newestValue.php'\">Go to Newest Value</button>";

$servername = "localhost"; // Database server address
$username = "id22040496_greencare"; // Database username
$password = "aguapurificadac13L#"; // Database password
$dbname = "id22040496_sensor_db"; // Database name

$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Ensure correct Content-Type
$expectedContentType = "application/x-www-form-urlencoded"; // Expected Content-Type
$currentContentType = $_SERVER['CONTENT_TYPE'] ?? null;

if ($currentContentType != $expectedContentType) {
    http_response_code(400); // Bad request
    die("Incorrect Content-Type. Expected: " . $expectedContentType); // Correct concatenation
}

// Retrieve humidity from POST data
$humidity = $_POST['humidity'] ?? null;

if ($humidity !== null) {
    // Insert into the `esp1` table with the current timestamp
    $sql = "INSERT INTO esp1 (humidity, datetime) VALUES ('$humidity', NOW())"; 
    
    if ($conn->query($sql) === TRUE) {
        echo "Data stored successfully";
    } else {
        echo "Error inserting data: " . $conn->error;
    }
} else {
    http_response_code(400); // Bad request
    echo "Missing 'humidity' parameter";
}

$conn->close(); // Correct way to close the MySQL connection

// Add a button to link to 'humidity_submission.php'

?>