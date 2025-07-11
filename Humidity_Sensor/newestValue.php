<?php
$servername = "localhost";
$username = "db_username";
$password = "db_password";
$dbname = "db_name";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$sql = "SELECT humidity FROM esp1 ORDER BY datetime DESC LIMIT 1"; // Fetch the most recent record
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    $row = $result->fetch_assoc();
    echo json_encode(["humidity" => $row["humidity"]]); // Return as JSON
} else {
    echo json_encode(["humidity" => "No data"]); // Return default response
}

$conn->close();
?>
