let random=parseInt( Math.random()*100 + 1 );

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
        guessChange('Wrong! git Try again','#d33333');
    } else{
        const msg= `0-----(<b style = "color:#33a036">${guess}</b>)-----(Number)-----100`;
        displayMessage(msg);
        guessChange('Wrong! Try again','#d33333');
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