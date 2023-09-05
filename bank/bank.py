greeting = input('Greeting: ')
words = greeting.lower().strip().split()

if words[0] == 'hello':
    print(f'0$')
elif words[0][0] == 'h':
    print(f'20$')
else:
    print(f'100$')