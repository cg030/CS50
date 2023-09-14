def main():
    # get size input
    while True:
        try:
            height = int(input('Height: '))
            if 1 <= height <= 8:
                break
            else:
                print(f'Enter a value between 1 and 8')
        except ValueError:
            print(f'Invalid Input')
    for i in range(1, height + 1 , 1):
        print(' ' * (height - i) + '#' * i + '  ' + '#' * i)

main()