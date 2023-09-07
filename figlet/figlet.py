from pyfiglet import Figlet, figlet_format
import random
import sys

user_input = input('Input:')

available_fonts = Figlet().getFonts()

random_font = random.choice(available_fonts)

if len(sys.argv) == 1:
    x = figlet_format(user_input, font=random_font)
    print(f'Output: {x}')
elif len(sys.argv) == 3 and (sys.argv[1] == '-f' or sys.argv[1] == '--font') and sys.argv[2] in available_fonts:
    y = figlet_format(user_input, font=sys.argv[2])
    print(f'Output: {y}')
else:
    print('Invalid command-line argument')
    sys.exit(1)

