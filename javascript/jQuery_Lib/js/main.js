


//============Fractal Tree 1================
var s = function (sketch){
	let angle = 0

	sketch.setup = function(){
		angle = sketch.PI/5;

		sketch.createCanvas(500,500)
		sketch.stroke("#f9a11b");
	}

	sketch.draw = function() {
	    sketch.background("#f2e9e1")
		sketch.translate(250, sketch.height)
		branch(120);

  	}

  	function branch(len){
  		sketch.line(0,0,0, -len)
		sketch.translate(0, -len)

		if (len >1){
			sketch.push()
            sketch.stroke("#ff7761")
			sketch.rotate(angle)
			branch(len*0.7)
			sketch.pop()
            
			sketch.push()
            sketch.stroke("#008c9e")
			sketch.rotate(-angle)
			branch(len*0.7)
			sketch.pop()
		}
  	}

}
var myp5 = new p5(s, 'fractal-tree-1');

//============Fractal Tree 2============

var s = function (sketch){
    let angle = 0
//    let value = 5

	sketch.setup = function(){
		angle = sketch.PI/8;

		sketch.createCanvas(500,500)
		sketch.stroke("#f9a11b");
        sketch.strokeWeight(5)
	}

	sketch.draw = function() {
	    sketch.background("#f2e9e1")
		sketch.translate(250, sketch.height)
		branch(120, 5);
        
  	}

  	function branch(len, weight){
  		sketch.line(0,0,0, -len)
		sketch.translate(0, -len)
        console.log(len)
        console.log(weight)
		if (len >2 & weight>0){
			sketch.push()
            sketch.stroke("#ff7761")
			sketch.rotate(angle)  
            sketch.strokeWeight(weight)
			branch(len*0.7, weight*0.7)
			sketch.pop()
            
			sketch.push()
            sketch.stroke("#008c9e")
			sketch.rotate(-angle)
            sketch.strokeWeight(weight)
			branch(len*0.7, weight*0.7)
			sketch.pop()
		}
  	}
}

var myp5 = new p5(s, 'fractal-tree-2');



//============Fractal Tree 3============

//==================JQuery==================
function init(){
//    console.log("111111")
    $('#click-1').click(function(){
        $('.contents-1').toggle("slow")
    })
}

$(document).ready(function () {
	init();
    
});






