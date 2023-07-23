//Explain what a callback function is and provide a simple example? 
// A callback is a function that is passed into another function as an argument which can be invoked later inside the function.


function print(number, result) {
    console.log(`${number} is ${result}`);
}

function checkEvenOrOdd(number, callback) {
  const result =  (number % 2 === 0) ? 'Even' : 'Odd';
  callback(number, result);
}

checkEvenOrOdd(56, print);