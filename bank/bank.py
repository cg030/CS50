greeting = input('Greeting: ')
greeting = greeting.lower().strip()
if greeting == 'hello':
    print(f'100$')
elif greeting[0] == 'h' and greeting:
    print(f'20$')
else:
    print(f'0$')