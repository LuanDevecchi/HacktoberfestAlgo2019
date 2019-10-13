# Function to get number of set bits in binary representation of a number.

x = int(input("enter a number"))
count = 0
while (x): 
	x &= (x-1)  
        count+=1
print(count)
