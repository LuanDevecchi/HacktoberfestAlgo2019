//recursively multiplying two big positive numbers
//using karatsuba's algorithm

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//numbers 'll be stored in array of integers in reverse order
//i.e. array[1] is 10's digit and array[0] is 1's digit
#define MAX_DIGIT 1024
#define CUTOFF 4

void input(int aa[], int *x);
int find1(int a, int b);
void initialize(int xx[], int yy[], int xLen, int yLen, int tLEn);
void karatsuba(int xx[], int yy[], int rr[], int tLen);
void print(int aa[], int x);
void normalMultiplication(int *xx, int *yy, int *rr, int tLen);
void fixCarry(int rr[], int tLen);

int main(int agrc, char *argv[]) {

    int xx[MAX_DIGIT]; //first multiplicand
    int xLen = 0;
    int yy[MAX_DIGIT]; //second multiplicand
    int yLen = 0;
//result 'll be in first 2d digits...
//remaining space will be used for various purposes
    int zz[6*MAX_DIGIT];

    printf("digite o primeiro numero:");
    input(xx, &xLen);
    assert(xLen >= 0);
    printf("\ndigite o segundo numero:");
    input(yy, &yLen);
    assert(yLen >= 0);
//smallest power of 2 greater than both xLen && yLen
    int tLen = find1(xLen, yLen);

    initialize(xx, yy, xLen, yLen, tLen);

    karatsuba(xx, yy, zz, tLen);

//since we didn't checked in karatsuba that digits are b/w 0-9
    fixCarry(zz, 2 * tLen);

    printf("\n\nresultado:\n");

    print(zz, tLen);
    
    
    system("pause");

    return EXIT_SUCCESS;
}

//take input and store it in reverse order in array of integers
void input(int aa[], int *x) {

    char c;
    if((c=getchar()) != '\n' && *x <= MAX_DIGIT) {
        input(aa, x);
        aa[*x] = c - '0';
        (*x)++;
    } else return;
}

//finds smallest power of 2 greater than both a and b
int find1(int a, int b) {
    int tLen = 1;
    while(tLen <= a || tLen <=b) {
        tLen *=2;
    }
    return tLen;
}

//initialize xx and yy to 0 uptil tLen
void initialize(int xx[], int yy[], int xLen, int yLen, int tLen) {
    int i;
    for(i=xLen; i<tLen; i++) xx[i] = 0;
    for(i=yLen; i<tLen; i++) yy[i] = 0;
}

void karatsuba(int xx[], int yy[], int rr[], int tLen) {
    int *a = &xx[tLen/2];
    int *b = &xx[0];
    int *c = &yy[tLen/2];
    int *d = &yy[0];

//since only 2d space is required for result
//hence we 'll use remaining space
    int *wx = &rr[tLen*5]; //sum of xx's halves
    int *wy = &rr[tLen*5 + tLen/2]; //sum of yy's halves

    int *V = &rr[tLen*0]; //location of b*d
    int *U = &rr[tLen*1]; //location of a*c
    int *W = &rr[tLen*2]; //location of (a+b)*(c+d)

//for small value of tLen ormal multiplication is faster
    if(tLen <= CUTOFF) {
        normalMultiplication(xx, yy, rr, tLen);
        return;
    }
    int i;
//compute wx and wy
    for(i=0; i<tLen/2; i++) {
        wx[i] = a[i] + b[i];
        wy[i] = c[i] + d[i];
    }

//divide
    karatsuba(b, d, V, tLen/2);
    karatsuba(a, c, U, tLen/2);
    karatsuba(wx, wy, W, tLen/2);

//conquer and combine
    for(i=0; i<tLen; i++)  W[i]=W[i]-U[i]-V[i];
    for(i=0; i<tLen; i++)  rr[i+tLen/2] += W[i];

}

//print the result
void print(int aa[], int x) {
    int i;
    for( i = x-1; i>0; i--) if(aa[i] != 0) break;
    for( ; i>=0; i--) printf("%d", aa[i]);
    printf("\n");
}

//standard multiplication
void normalMultiplication(int *xx, int *yy, int *rr, int tLen) {

    int i, j;
    for(i=0; i<2*tLen; i++)  rr[i] = 0;
    for(i=0; i<tLen; i++) {
        for(j=0; j<tLen; j++) {
            rr[i+j] += xx[i]*yy[j];
        }
    }
}

//to make sure that all numbers are b/w 0-9
void fixCarry(int rr[], int tLen) {

    int i;
    int carry = 0;
    for(i=0; i<tLen; i++) {
        rr[i]+=carry;
        if(rr[i] < 0) {
            carry = ( -(rr[i]+1)/10 +1 );
        } else {
            carry = rr[i]/10;
        }
        rr[i] = rr[i]- carry*10;
    }
    assert(carry == 0); //check overflow

}
