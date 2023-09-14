def main():
    # get size input
    while True:
        height = int(input('Height: '))
        if 1 <= height <= 8:
            break

    # loop to print pyramid
    for i in range(1, height, 1):

        # loop to first print spaces
        for j in range(1, height - i, 1):
            print(' ')

        # loop to print the number of hashes equivalent to the row; +1 row, +1 hash
        for k in range(1, j <=i, 1):
            print('#')

        print(' ')

        # identical for loop as above
        for j in range(1, j<=i, 1):
            print('#')

        print()

main()