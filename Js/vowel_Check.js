// Write a code on how to calculate the number of vowels and consonants in a string?(Use Javascript only)

let string = "abul";

let vowel = 0;
let consonant = 0;

for(let i = 0; i < string.length; i++){
    if(string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u'){
        vowel++;
    }else{
        consonant++;
    }
}

console.log("Vowel: " + vowel);
console.log("Consonant: " + consonant);


