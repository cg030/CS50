greeting = input('Greeting: ')
greeting = greeting.lower().strip()
if greeting == 'hello':
    print(f'0$')
elif greeting[0] == 'h':
    print(f'20$')
else:
    print(f'100$')