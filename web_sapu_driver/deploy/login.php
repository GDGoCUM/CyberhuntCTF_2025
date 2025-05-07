<?php
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $username = $_POST['username'];
    $email = $_POST['email'];

    // Create the user data array
    $userData = array(
        "username" => $username,
        "email" => $email,
        "admin" => 0
    );

    // Block some username
    if ($userData["username"] == 'wajiha_hamza') {
        echo "username already exists";
    }
    else {
        // Encode the data to base64
        $cookieValue = base64_encode(json_encode($userData));
        setcookie("biscuit", $cookieValue, time() + (86400 * 30), "/");

        header("Location: index.php");
        exit(); // Make sure to exit after header to stop execution
    }
}
?>
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Umph Coffee - Login</title>
    <link rel="stylesheet" href="login.css">
</head>
<form method="POST">
    <label>Username: <input type="text" name="username"></label><br>
    <label>Password: <input type="text" name="password"></label><br>
    <label>Email: <input type="text" name="email"></label><br>
    <button type="submit">Register</button>
</form>
