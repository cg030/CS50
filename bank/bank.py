greeting = input('Greeting: ')
greeting = greeting.lower().strip()

words = greeting.split()

if len(words) == 'hello' or len(greeting) == 1:
    print(f'0$')
elif greeting[0] == 'h':
    print(f'20$')
else:
    print(f'100$')