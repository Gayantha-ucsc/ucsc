<?php
// Database connection
$conn = new mysqli("localhost", "root", "<PASSWORD>", "student_db");

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Insert student data into database
if (isset($_POST['register'])) {
    $email = $_POST['email'];
    $username = $_POST['username'];
    $password = password_hash($_POST['password'], PASSWORD_BCRYPT); // Encrypt password

    $sql = "INSERT INTO students (email, username, password) VALUES ('$email', '$username', '$password')";

    if ($conn->query($sql) === TRUE) {
        echo "Student registered successfully!";
    } else {
        echo "Error: " . $conn->error;
    }
}


if(isset($_POST['delete'])){
    $search = $_POST['search'];
    $sql = "DELETE FROM students WHERE username='$search'";
    $result = $conn->query($sql);
}


// Show all students
if (isset($_POST['show'])) {
    $sql = "SELECT email, username FROM students";
    $result = $conn->query($sql);

    echo "<table border='1'>
    <tr>
        <th>Email</th>
        <th>Username</th>
    </tr>";

    if ($result->num_rows > 0) {
        while ($row = $result->fetch_assoc()) {
            echo "<tr>
                <td>" . htmlspecialchars($row["email"]) . "</td>
                <td>" . htmlspecialchars($row["username"]) . "</td>
            </tr>";
        }
    } else {
        echo "<tr><td colspan='2'>No students found.</td></tr>";
    }
    echo "</table>";
}
// Search for a student in the database
if (isset($_POST['find'])) {
    $search = $_POST['search'];

    $sql = "SELECT * FROM students WHERE username='$search'";
    $result = $conn->query($sql);

    if ($result->num_rows > 0) {
        while ($row = $result->fetch_assoc()) {
            echo "Email: " . $row["email"] . "<br>";
            echo "Username: " . $row["username"] . "<br>";
        }
    } else {
        echo "No student found!";
    }
    
}

$conn->close();
?>
