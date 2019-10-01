//Paulo Henrique SN
//github/paulohenriquesn


var mov=0;
var time=20;
var timeez=0;
var tempao = true;
var textotempo = document.getElementById("time")
var canvas = document.getElementById('game');
var context = canvas.getContext('2d');
var scorex = document.getElementById('score')
var dif = document.getElementById('dificuldade')
var grid = 16;
var score=0;
var count = 0;
var record=0;
var fps = 4; 
var fpsz=0;
var snake = {
  x: 160,
  y: 160,
  
  
  dx: grid,
  dy: 0,
  
 
  cells: [],
  
 
  maxCells: 4
};
var apple = {
  x: 320,
  y: 320
  };
function getRandomInt(min, max) {
  return Math.floor(Math.random() * (max - min)) + min;
}

function loop() {

  requestAnimationFrame(loop);
  if (++count < fps) {
    return;
  }
 
  		
  timeez++;	
if(timeez>10){
	

time--
  textotempo.innerHTML = `Tempo ${time}`
  timeez=0
  }

  
  if(time<=0){
  	
  	 snake.x = 160;
        snake.y = 160;
        snake.cells = [];
        snake.maxCells = 4;
        snake.dx = grid;
        snake.dy = 0;
        apple.x = getRandomInt(0, 25) * grid;
        apple.y = getRandomInt(0, 25) * grid;
        if(score>record){
        	record=score;
        }
        score=0
        fps=4
        fpsz=0
        scorex.innerHTML = "Score "+ score + " Recorde. " + record
      dif.innerHTML="Dificuldade Facil"
      time=20
  }
  
  
  count = 0;
  context.clearRect(0,0,canvas.width,canvas.height);
 
  snake.x += snake.dx;
  snake.y += snake.dy;
  
  if (snake.x < 0) {
    snake.x = canvas.width - grid;
  }
  else if (snake.x >= canvas.width) {
    snake.x = 0;
  }
  
  if (snake.y < 0) {
    snake.y = canvas.height - grid;
  }
  else if (snake.y >= canvas.height) {
    snake.y = 0;
  }
  
  snake.cells.unshift({x: snake.x, y: snake.y});
 
  if (snake.cells.length > snake.maxCells) {
    snake.cells.pop();
  }
  
  context.fillStyle = 'red';
  //context.fillRect(apple.x, apple.y, grid-1, grid-1);
  
  context.fillStyle = 'white';
  context.shadowColor='black'
  context.shadowBlur=6;
  context.shadowOffsetX=6
  context.shadowOffsetY=6
  context.beginPath()
  context.fillStyle='purple'
  
 context.arc(apple.x, apple.y, grid-1, 0, 2 * Math.PI);
  context.stroke()
  context.fill(
  	)
  
  snake.cells.forEach(function(cell, index) {
    
 //  context.fillRect(cell.x, cell.y, grid-1, grid-1);  
    
      context.beginPath()
      context.fillStyle='cyan'
  context.arc(cell.x, cell.y, grid-1, 0, 2* Math.PI);
  context.stroke()
  context.fill()

    
    if (cell.x === apple.x && cell.y === apple.y) {
      snake.maxCells++;
    
      if(fpsz<5){
      	fpsz++
      }else{
      	fps--
      		if(fps== 3){
      			dif.innerHTML = "Dificuldade Medio"
      		}
      		if(fps<3){
      			dif.innerHTML = "Dificuldade Difícil"
      		}
      	fpsz=0
      }
      time=20
      
      score++
      	scorex.innerHTML = "Score "+ score + " Recorde. " + record
     
    
      apple.x = getRandomInt(0, 25) * grid;
      apple.y = getRandomInt(0, 25) * grid;
    }
    
    for (var i = index + 1; i < snake.cells.length; i++) {
      if (cell.x === snake.cells[i].x && cell.y === snake.cells[i].y) {
       snake.x = 160;
        snake.y = 160;
        snake.cells = [];
        snake.maxCells = 4;
        snake.dx = grid;
        snake.dy = 0;
        apple.x = getRandomInt(0, 25) * grid;
        apple.y = getRandomInt(0, 25) * grid;
        if(score>record){
        	record=score;
        }
        score=0
        fps=4
        fpsz=0
        scorex.innerHTML = "Score "+ score + " Recorde. " + record
      dif.innerHTML="Dificuldade Facil"
      }
    }
  })
  
}
document.addEventListener('keydown', function(e) {
  
  // left arrow key
  if (e.which === 37 && snake.dx === 0) {
    snake.dx = -grid;
    snake.dy = 0;
  }
  // up arrow key
  else if (e.which === 38 && snake.dy === 0) {
    snake.dy = -grid;
    snake.dx = 0;
  }
  // right arrow key
  else if (e.which === 39 && snake.dx === 0) {
    snake.dx = grid;
    snake.dy = 0;
  }
  // down arrow key
  else if (e.which === 40 && snake.dy === 0) {
    snake.dy = grid;
    snake.dx = 0;
  }
});

//android and ios
function Anda(){
	  if(mov == 2){
  	  snake.dx = -grid;
    snake.dy = 0;
  }
  if (mov == 0){
  	  snake.dx = grid;
    snake.dy = 0;  }
    
    if(mov == 3){
    	    snake.dy = -grid;
    snake.dx = 0;    }
    if(mov == 1){
    	    snake.dy = grid;
    snake.dx = 0;
    }
   
	if(mov<3){
		mov++
	}else{
		mov = 0;
	}
}
requestAnimationFrame(loop);
