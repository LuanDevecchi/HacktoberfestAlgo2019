// prime number upto n using sieve algorithm
//  prime no. using  Sieve of Eratosthenes
let primeSieveMethod = n => {
    let numArray=[];
    let result=[];
    for(let i=0;i<=n;i++){
        numArray.push(i)
    }
    for(let j=2;j<=Math.sqrt(n);j++){
        if(numArray[j]){
            for (let k = j * j; k < n; k += j) {
                numArray[k] = false;
            }
        }
    }
    for (let i = 2; i < n; i++) {
        if(numArray[i]) {
            result.push(i);
        }
    }

    return result;
}
console.log(`\n Prime using Sieve method \n`,primeSieveMethod(100))