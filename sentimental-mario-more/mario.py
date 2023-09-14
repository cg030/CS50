def main():
    # get size input
    while True:
        height = int(input('Height: '))
        if 1 <= height <= 8:
            break
        elif 

    for i in range(1, height + 1 , 1):
        print(' ' * (height - i) + '#' * i + '  ' + '#' * i)

main()