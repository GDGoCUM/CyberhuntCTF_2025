<?php
if (!isset($_COOKIE['biscuit'])) {
    die("Access Denied :3");
}

$userData = json_decode(base64_decode($_COOKIE['biscuit']), true);

if ($userData && $userData['username'] === "wajiha_hamza" && $userData['admin'] == 1) {
    echo "Welcome, Admin! Here is your flag: Hunt{yep_thats_the_sus_biscuit}";
} else {
    echo "Access denied!";
}
?>

