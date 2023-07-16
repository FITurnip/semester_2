<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Pimp My Host</title>
    <style>
        ul {
            list-style-type: none;
            line-height: 2;
        }
    </style>
</head>
<body>
    <?php
    
    ?>
    <form action="/shoes.php" method="post">
        <h1>"Pimp My Shoes" Contest Entry Form</h1>
        <p>Want to trade in your old sneakers for a custom pair of Forcefields? Make a case for why your shoes have <i>got</i> to go and you may be one of ten lucky winners.</p>
        <p>Contest Entry Information</p>
        <ul>
            <li><label for="name">Name: </label><input type="text" name="name" id="name"/></li>
            <li><label for="email">Email Adress: </label><input type="email" name="email" id="email"/></li>
            <li><label for="tel">Telephone Number: </label><input type="tel" name="tel" id="tel"/></li>
            <li><label for="comment">My shoes are so old...<br/></label><textarea name="comment" id="comment" placeholder="No more than 300 characters long" cols="50" rows="5"></textarea></li>
        </ul>

        <h2>Design your custom Forcefields:</h2>
        <fieldset>
            <legend>Custom Shoe Design</legend>
            <fieldset>
                <legend>Color(<i>choose one</i>):</legend>
                <ul>
                    <?php
                    //
                    ?>
                    <li><input type="radio" name="color" value="red" />Red</li>
                    <li><input type="radio" name="color" value="blue" />Blue</li>
                    <li><input type="radio" name="color" value="black" />Black</li>
                    <li><input type="radio" name="color" value="silver" />Silver</li>
                </ul>
            </fieldset>
            <fieldset>
                <legend>Features(<i>Choose as many as you want</i>)</legend>
                <ul>
                    <li><input type="checkbox" name="features" value="sparkley laces"/>Sparkley laces</li>
                    <li><input type="checkbox" name="features" value="metallic logo" checked/>Metallic logo</li>
                    <li><input type="checkbox" name="features" value="lightup heels"/>Light-up heels</li>
                    <li><input type="checkbox" name="features" value="mp3enabled"/>MP3-Enables</li>
                </ul>
            </fieldset>
            <fieldset>
                <legend>Size</legend>
                <label for="size">Sizes reflect standard men's sizes: </label>
                <select name="size" id="size">
                    <option value="5">5</option>
                    <option value="4">4</option>
                    <option value="3">3</option>
                    <option value="2">2</option>
                    <option value="1">1</option>
                </select>
            </fieldset>
        </fieldset>
        <br/>
        <input type="submit" name="submit" id="submit" value="Pimp My Shoes"/>
        <input type="reset" name="reset" id="reset"/>
    </form>
</body>
</html>