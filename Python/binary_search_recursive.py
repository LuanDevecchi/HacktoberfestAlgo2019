'''
This is a recursive implementation of binary search
Time Complexity: O(logn)
Space Complexity: O(logn)

The iterative implementation is better as it has constant space complexity O(1)
'''


def binary_search(arr, s, e, x):
    '''
    #arr: the array in which we need to find an element (sorted, increasing order)
    #s: start index
    #e: end index
    #x: element we are looking for
    '''
    #if the search space is non empty
    if e >= s:
        m = s + int((e-s)/2) #middle index
        if x==arr[m]:
            return m
        elif x>arr[m]:
            return binary_search(arr, m+1, e, x)
        elif x<arr[m]:
            return binary_search(arr, s, m-1, x)
    #if search space is empty
    else:
        return -1

arr = [2,3,4,10,40]
x = 10

index = binary_search(arr, 0, len(arr)-1, x)
if index==-1:
    print("Element not present in list")
else:
    print("Element",x,"is present at",index)
