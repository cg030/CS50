def main():
    # get size input
    while True:
        height = int(input('Height: '))
        if 1 <= height <= 8:
            break

    for i in range(height):
        print(' ' * (height - i) + '#' * i + ' ' + '#' * i +  ' ' * (height - i))

main()