# -*- coding: utf-8 -*-
"""
Created on Oct 8 09:14:16 2019

@author: PRASHANT
"""
s=input("enter string :" )
s=s.lower()
ls=set(s)
count=[c for c in ls if ord(c) in range(ord('a'), ord('z')+1)]
if len(count)==26:
    print("It is  pangram")
else:
    print("It is not a pangram")


    
