def TrailingZeros(n):
    count = 0
    i = 5
    while (n / i >= 1):
        count += int(n / i)
        i *= 5
    return int(count)
n = 7
print("Trailing Zeros: ", TrailingZeros(n))
