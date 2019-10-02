//Fibonacci definition: the first two numbers in the Fibonacci sequence are either 1 and 1, or 0 and 1, depending on the chosen starting point of the sequence, and each subsequent number is the sum of the previous two.


//O(N) solution

function fibonacci(number) {
    let a = 1
    let b = 0, temporaryVariable;

    while (number >= 0) {
        temporaryVariable = a;
        a = a + b;
        b = temporaryVariable;
        num--;
    }
    return b;
}


