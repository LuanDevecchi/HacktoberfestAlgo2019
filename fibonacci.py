def fib(n):	#this function prints fibonacci sequence upto niii
	a ,b = 0, 1
	while a<n:
		print a,
		a, b = b, a+b
    
n = int(input())
print (fib(n))
