from pyfiglet import Figlet, figlet_format
import random
import sys

available_fonts = Figlet().getFonts()

random_font = random.choice(available_fonts)

if len(sys.argv) == 1:
    user_input = input('Input:')
    x = figlet_format(user_input, font=random_font)
    print(f'Output:\n{x}')
elif len(sys.argv) == 3 and (sys.argv[1] == '-f' or sys.argv[1] == '--font') and sys.argv[2] in available_fonts:
    user_input = input('Input:')
    y = figlet_format(user_input, font=sys.argv[2])
    print(f'Output:\n{y}')
else:
    print('Invalid usage')
    sys.exit(1)

