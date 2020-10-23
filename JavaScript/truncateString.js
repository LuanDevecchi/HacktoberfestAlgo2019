//           TRUNCATE STRING ALGORITHM
//
// Create a function that takes in a string (str) and a number (num)
// as arguments, truncates the string (str) after (num) no. of characters,
// adds an ellipsis(...) at the end and returns the truncated string.
//
// -------------------------------------------------------------------------
//
// Test Cases:
//
// The string 'Floccinaucinihilipilification' and the number 13 passed as
// arguments to the function returns a string.
//
// The string 'Floccinaucinihilipilification' and the number 13 passed as
// arguments to the function returns 'Floccinaucini...'
//
// The string 'Hello World' and the number 13 passed as
// arguments to the function returns 'Hello World'
//
// -------------------------------------------------------------------------

function truncateString(str, num){
    console.log(str.length > num ? str.slice(0,num) + '...' : str)
}

truncateString('Floccinaucinihilipilification', 13)
// returns 'Floccinaucini...'

truncateString('Hello World', 13)
// returns 'Hello World'