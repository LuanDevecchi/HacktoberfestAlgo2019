def bubble_sort(myList):
	currentLength = len(myList)
	while currentLength >= 1:
		newCounter = 0
		for i in range(1, currentLength):
			if myList[i-1] > myList[i]:
				temp = myList[i-1]
				myList[i-1] = myList[i]
				myList[i] = temp
				newCounter = i
		currentLength = newCounter
	return myList