<?php
// Database connection details
$servername = "localhost"; // Database server address
$username = "id22040496_greencare"; // Database username
$password = "aguapurificadac13L#"; // Database password
$dbname = "id22040496_sensor_db"; // Database name

// Create a database connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// SQL query to fetch data from the `esp1` table
$sql = "SELECT humidity, datetime FROM esp1 ORDER BY datetime DESC"; // Fetch all records, sorted by datetime
$result = $conn->query($sql);

// HTML structure to display data
echo "<!DOCTYPE html>";
echo "<html lang='en'>";
echo "<head>";
echo "<title>Humidity Data</title>";
echo "</head>";
echo "<body>";
echo "<h2>Humidity Data from Database</h2>";

// Check if the query returned any rows
if ($result->num_rows > 0) {
    echo "<table border='1'>"; // Start of the table
    echo "<tr><th>Humidity</th><th>Date and Time</th></tr>"; // Table headers

    // Loop through the results and create table rows
    while ($row = $result->fetch_assoc()) {
        echo "<tr><td>" . $row["humidity"] . "</td><td>" . $row["datetime"] . "</td></tr>"; // Data rows
    }

    echo "</table>"; // End of the table
} else {
    echo "No data found."; // If no records are returned
}

// Correct way to close MySQL connection
$conn->close();

echo "</body>";
echo "</html>";
?>
