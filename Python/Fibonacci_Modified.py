n1,n2,k = map(int,input().split())
fib = [n1,n2]
for i in range(2,k):
    x = fib[i-2]+fib[i-1]**2
    fib.append(x)
print(fib[-1])
