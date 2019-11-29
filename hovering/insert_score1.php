<?php
$conn = mysqli_connect(
  'localhost',
  '사용자이름',
  '비밀번호',
  'DB이름');
 
if (mysqli_connect_errno()){
    
    echo "MySQL 연결 오류: " . mysqli_connect_error();
    
    exit;
    
} else {
    
    echo "DB 접속 성공";
    
    $num=$_GET["num"];
    $sql = "Update score set score1=$num where id=1";
    $result = mysqli_query($conn, $sql);
    
    mysqli_close($conn);
    
}

?>