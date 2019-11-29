<html>
    <head>
    <meta charset="UTF-8" />
    <title>Score</title>
    <style>
        #score {
            text-align: center;
            padding: 200px;
            font-size: 50px;
            font-weight: bold;
        }
    </style>
    </head>
    <body>
        <div id="score">
            <?php
            $conn = mysqli_connect('localhost','사용자이름','비밀번호','DB이름');
            $sql = "SELECT * FROM score order by id desc limit 1";
            $result = mysqli_query($conn, $sql);
            $row = mysqli_fetch_array($result);
            echo $row['score1']+$row['score2']+$row['score3']+$row['score4'];
            ?>
            점
    </div>
    </body>
</html>