/* Create a "psychic duck" that gives out a random reply from a list of 
preset replies in an array, while changing expressions. Steps are numbered. 
*/

// -- 1
// Create variables. 
const replies = ["Yes", "No", "How should I know?", "Feed me and then I'll tell you.", "Maaaaybe."]; // list of replies, order must correspond with the right sound file
const sounds = ["yes", "no", "how", "feedme", "maybe"]; // name of sound files
const eyes = ["eyes", "eyes2", "eyes3", "eyes4", "eyes5", "eyes", "eyes7"]; // name of image files for eyes
let randomNum = 0; // this variable will hold the current randomized number to pull from the replies array
let randomEyes = 0; // variable that holds random number to pull a new eye expression, separate variable because the amount of eyes exceed the amount of replies
let audioElement;

// create function to play sound based off of random variable being passed
const playSounds = r => {    
    audioElement.setAttribute("src", "assets/sound/"+sounds[r]+".mp3")
    audioElement.play()
}

// create a function that returns a random number within the limits of the array length. 
// function passes name of the array, so we can use one function for different arrays with different lengths
const randomNumGenerator = arrayName => { // create random number for random reply
	
    return Math.floor(Math.random()*arrayName.length)
    

}

// -- Create a function to bring the duck to life.
const answerQuestion = () => {
    randomNum = randomNumGenerator(replies)
    randomEyes = randomNumGenerator(eyes)
    //return answers =  replies[randomNum]
    console.log("the randomNum is "+randomNum)
    console.log("the randomEyes is "+randomEyes)
    console.log(eyes[randomEyes]+'.png')
    console.log(sounds[randomNum]+'.mp3')
    
    $('#speech').text(replies[randomNum])
    $('#eyes').css("background", 'url(assets/img/' + eyes[randomEyes] + '.png) no-repeat')
    $('#eyes').css("background-size", "100% auto")
    playSounds(randomNum)
    
//    
}

// -- step 3
// init function will initialize the rest of the functions
const init = () => {
	console.log('Hello World') // check to see if script is linked properly and running
    
    audioElement = document.createElement("audio")
    audioElement.setAttribute("autoplay","autoplay")
    
    
    $("#submit").click(function(){
        answerQuestion()
    })

}

// -- step 2
// wait until dom is loaded then run init function
$(document).ready(function () {
	init();
    
});