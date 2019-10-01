let factorial = number => {
	return number < 2 ? 1 : number * factorial(number - 1)
}