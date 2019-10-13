# -*- coding: utf-8 -*-
"""
Created on Oct 8 09:35:32 2019

@author: PRASHANT
"""
l=[]
s=int(input("ENTER NUMBER OF ELEMENTS IN LIST: "))
for i in range(s):
    x=int(input("ENTER AN ELEMENT: "))
    l.append(x)
print(l)
maximum=l[0]
for i in range(s):
    if l[i]>=maximum :
        maximum=l[i]
l.remove(maximum)
max2=l[0]
for i in range(s-1):
    if l[i]>max2:
        max2=l[i]
print("Second greatest element in list: ",max2 )

l.index(max2)
