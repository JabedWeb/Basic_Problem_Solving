// Write a code to calculate if the string is palindrome ? (Use javascript only)


let string = "madam";
let reverseString = "";

for(let i = string.length - 1; i >= 0; i--){
    reverseString += string[i];
}

if(string == reverseString){
    console.log("Palindrome");
}else{
    console.log("Not Palindrome");
}
