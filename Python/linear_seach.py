'''
Implementation of linear search
Time Complexity: O(n)
Space Complexity: O(1)
'''

def linear_search(arr, x):
    for index, element in enumerate(arr):
        if x==element:
            return index
    return -1


arr = [2, 3, 4, 10, 40] #the array need not be sorted for linear search
x = 10 #the element to find in the above array

index = linear_search(arr, x)
if index==-1:
    print("Element not present in list")
else:
    print("Element",x,"is present at",index)
