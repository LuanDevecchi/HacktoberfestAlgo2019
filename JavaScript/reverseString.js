//           REVERSE STRING ALGORITHM
//
// Create a function that takes in a string (str) as an argument,
// reverses it and returns the reversed string
//
// ----------------------------------------------------------------
//
// Test Cases:
//
// The string 'Hello World' passed as the argument to the function
// returns a string.
//
// The string 'Hello World' passed as the argument to the function
// returns 'dlroW olleH'
//
// ----------------------------------------------------------------

function reverseString(str){
    return str.split('').reverse().join('');
}

reverseString('Hello World')
// returns 'dlroW olleH'