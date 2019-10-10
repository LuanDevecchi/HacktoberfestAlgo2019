from collections import Counter

'''def check(inp,dict1):
for i in range(len(inp)-1):
    if dict1[inp[i]]==dict1[inp[i+1]]:
        return "Yes"'''
inp = input()
dict1 = dict(Counter(inp))
ls1= list(dict1.values())
max_ = max(ls1)
min_  = min(ls1)
if max_==min_:
    print("YES")
else:
    c = 0
    if ls1.count(min_)==1:
        ls1.remove(min_)
        min_ = min(ls1)
        if max_==min_:
            print("YES")
        else:
            print("NO")
    else:
        for i in range(len(ls1)):
            if max_!=min_:
                ls1[ls1.index(max_)]-=1
                max_ = max(ls1)
                c+=1

        if c<2:
            print("YES")
        else:
            print("NO")
