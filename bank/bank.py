import cs50 as cs


greeting = input('Greeting: ')
if greeting == 'hello':
    print(f'100$')
elif greeting[0] == 'h':
    print(f'20$')
else:
    print(f'0$')