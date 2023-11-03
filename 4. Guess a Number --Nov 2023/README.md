# Guess the number

This mini project built upon 
- JavaScript 
- Html & Css

### Working:
1. User gets 10 chance to predict number from 1 -> 100<br>
2. After 10 chance user can not type any number unless pressing <b>Reset </b> Button <br>
3. Complete Logic of this game is (javaScript) :



<br>

```JavaScript
let random=parseInt( Math.random()*100 + 1 );
console.log(random);
const input= document.querySelector('#guessField');
const submit = document.querySelector('#subt');
const preGuess= document.querySelector('.guesses');
const remGuess=document.querySelector('.lastResult');
const lowOrhi=document.querySelector('.lowOrHi');
const p = document.createElement('p');
const startOver=document.querySelector('.resultParas')
let preGuessArray=[];
const corWro = document.querySelector('#correctWrong')
let rem =0;
let playGame= true;

if(playGame){
    submit.addEventListener('click',function(e){
        e.preventDefault();
        let userInput= parseInt(input.value);
        validateInput(userInput);
    })
} else {
    endGame();
}

function validateInput(guess){
    
    if(rem<10){
    if(guess>0 && guess<=100){
        
        checkInput(guess);
        displayGuess(guess);
        
        
    } else {
        alert('Enter Valid number from 1 to 100')
    }
    } else {
        
        endGame();
    }
    
}

function checkInput(guess){
    
    if(guess===random){
       
        guessChange(`Correct guess!, ${guess} `,'lawngreen');
        endGame();
    } else if(guess>random){
        const msg= `0------(Number)----(<b style = "color:#33a036">${guess}</b>)-----100`;
        displayMessage(msg);
        guessChange('Wrong!','#d33333');
    } else{
        const msg= `0-----(<b style = "color:#33a036">${guess}</b>)-----(Number)-----100`;
        displayMessage(msg);
        guessChange('Wrong!','#d33333');
    }
    
}
function guessChange(msg,colorr){
    
    corWro.innerHTML=`<b style="color:${colorr}"><u>${msg}</u></b>`
}
function displayGuess(guess) {
    input.value = '';
    preGuess.innerHTML += `${guess} | `;
    rem++;
    remGuess.innerHTML = `${10 - rem} `;
  }

function displayMessage(msg){
    console.log(msg)
    lowOrhi.innerHTML=`${msg}`
}

function endGame(){
    input.setAttribute('disabled','')
    input.value=''
    playGame=false;
    lowOrhi.innerHTML=`Correct number: ${random}`
    const P = document.querySelector('#newGame')
    P.innerHTML=`<h2 style="background-color:black ; cursor:pointer">Reset</h1>`
    reset(P);
}

function reset(P){
   
    P.addEventListener('click',function(e){
        
        rem=0;
       
        random = parseInt(Math.random() * 100 + 1);
        input.removeAttribute('disabled');
        lowOrhi.innerHTML ='';
        preGuess.innerHTML = '';
        remGuess.innerHTML = 10;
        P.innerHTML='';
        corWro.innerHTML='<span style="visibility: hidden;">Hidden</span>'
        playGame=true;
    })
}


```
