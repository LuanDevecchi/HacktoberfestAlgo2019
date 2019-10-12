//Program to find Median of two sorted arrays of same size
//Ahmad Javed

#include<bits/stdc++.h>

using namespace std;

int findMedianSortedArray(int a[], int b[], int start_a, int end_a, int start_b, int end_b)
{
    if((end_a - start_a == 1) && (end_b - start_b == 1))
        return (max(a[start_a], b[start_b]) + min(a[end_a], b[end_b]))/2;

    int m1_index = (start_a + end_a)/2;
    int m2_index = (start_b + end_b)/2;

    int m1 = a[m1_index];
    int m2 = b[m2_index];

    if(m1 == m2)
        return m2;

    if(m1 < m2)
    {
        start_a = m1_index;
        end_b = m2_index;
    }

    else
    {
        end_a = m1_index;
        start_b = m2_index;
    }

    return findMedianSortedArray(a, b, start_a, end_a, start_b, end_b);
}

int main()
{
    int len;
    cout<<"Enter size of arrays: ";
    cin>>len;

    int arr1[len], arr2[len];
    cout<<"Enter elements of first array: ";
    for(int i = 0;i < len; i++)
    {
        cin>>arr1[i];
    }

    cout<<"Enter elements of second array: ";
    for(int i = 0;i < len; i++)
    {
        cin>>arr2[i];
    }

    int median = findMedianSortedArray(arr1, arr2, 0, len -1, 0, len -1);
    cout<<"Median of the two sorted arrays is: "<<median;

    return 0;
}
