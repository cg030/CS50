greeting = input('Greeting: ')
greeting = greeting.lower().strip()
if greeting == 'hello':
    print(f'100$')
elif greeting[0] == 'h' and len(greeting) == 1:
    print(f'20$')
else:
    print(f'0$')