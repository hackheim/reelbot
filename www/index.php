<!doctype html>
<html lang="en">
<head>
  <meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1, user-scalable=0"/>
  <title>click demo</title>
<script type="text/javascript" src="/jquery.min.js"></script>
  <style>
  html, body {
-webkit-touch-callout: none;
-webkit-user-select: none;
-khtml-user-select: none;
-moz-user-select: none;
-ms-user-select: none;
user-select: none;
margin: 0;
padding: 0;
}
  .button {
    color: red;
    background-color: #333; 
    cursor: pointer;
    text-align: center;
    font-size: 3em;
    margin-bottom: 10px;
    display: block;
  }
#buttons {
 position: relative;
 z-index: 2;
}
#video {
  position: fixed;
  z-index: 1;
  width: 100%;
  left: 0;
}
  </style>
</head>
<body>
<div id="buttons">
<div style="float:left;width:10%"> 
<a class="button" id="LF">&uarr;</a><br>
<a class="button" id="LB">&darr;</a>
</div>
<div style="float:right;width:10%">
<a class="button" id="RF">&uarr;</a><br>
<a class="button" id="RB">&darr;</a>
</div>
</div>
<script>

//touchstart, mousedown
$( ".button" ).on('touchstart', function(event) {
  //e.stopPropagation();
  //  e.preventDefault();
  $.get( "/api.php?cmd="+event.target.id, function( data ) {
    //$( ".result" ).html( data );
  });
});
//touchend, mouseup
$( ".button" ).on('touchend', function(event) {
  $.get( "/api.php?cmd="+event.target.id.charAt(0)+"S", function( data ) {
    //$( ".result" ).html( data );
  });
});
</script>
<img id="video" src="http://<?php echo $_SERVER['SERVER_NAME'] ?>:8080/stream/video.mjpeg" alt="image"> 
</body>
</html>
