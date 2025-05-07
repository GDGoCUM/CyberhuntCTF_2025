<!DOCTYPE html>
<?php
$username = "";  

if (isset($_COOKIE['biscuit'])) {
    $decodedData = base64_decode($_COOKIE['biscuit']);
    if ($decodedData !== false) {  
        $userData = json_decode($decodedData, true);
        if (isset($userData['username'])) {
            $username = $userData['username'];
        }
    }
}
?>

<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Umph Coffee - Welcome</title>
    <link rel="stylesheet" href="styles.css">
</head>
<body>
    <header>
        <div class="logo">Umph Coffee</div>
        <nav>
            <ul>
                <li><a href="#about">About Us</a></li>
                <li><a href="#menu">Menu</a></li>
                <li><a href="#specials">Specials</a></li>
                <li><a href="login.php">Login</a></li>
            </ul>
        </nav>
    </header>
    <section class="hero">
        <h1>Welcome to Umph Coffee<?php if($username){echo htmlspecialchars(", ".$username);} ?>!</h1>
        <p>Your daily dose of perfectly brewed happiness.</p>
        <button>Order Now</button>
    </section>
    <section id="about">
        <h2>About Us</h2>
        <p>Umph Coffee is your go-to spot for handcrafted beverages and delicious pastries. Our passion for quality and flavor is evident in every cup we serve. Whether you’re here for a quick pick-me-up or a relaxing break, we’ve got you covered.</p>
    </section>
    <section id="menu">
        <h2>Our Menu</h2>
        <ul>
            <li>Espresso</li>
            <li>Latte</li>
            <li>Cappuccino</li>
            <li>Cold Brew</li>
            <li>Pastries & Snacks</li>
        </ul>
    </section>
    <section id="specials">
        <h2>Specials of the Week</h2>
        <p>Try our new Caramel Macchiato and Chocolate Croissant Combo at a special price!</p>
    </section>
    <footer>
        <p>Send any feedback to <a href="mailto:feedback@umphcofee.yum">feedback@umphcofee.yum</a></p>
        <p>Need help? Contact <a href="mailto:wajiha_hamza@umphcofee.yum">wajiha_hamza@umphcofee.yum</a></p>
    </footer>
</body>
</html>

