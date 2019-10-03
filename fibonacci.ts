const fibonacci = (number: number) => {
    if (number < 3) return 1;
    return fibonacci(number - 1) + fibonacci(number - 2);
}
