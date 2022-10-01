
/*
    Question:

        Given an array nums of length n. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

        Return the running sum of nums.

        Input Format
        First line contains an integer n representing number of elements. Next line contains n integers denoting array elements.

        Constraints
        1 <= nums.length <= 1000
        -10^6 <= nums[i] <= 10^6

        Output Format
        An integer representing running sum array of the given array

        Sample Input
        4
        1 2 3 4
        Sample Output
        1 3 6 10
        Explanation
        Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].


*/

#include <iostream>
using namespace std;
int main() {
    int size,arr[1000],sum,ans[1000];
    cin>>size;

    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }

    for(int i=0;i<size;i++)
    {
        sum=0;
        for(int j=0;j<=i;j++)
        {
            sum=sum+arr[j];
        }
        ans[i]=sum;
        cout<<ans[i]<<" ";
    }    
}
