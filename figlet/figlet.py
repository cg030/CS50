import pyfiglet as fi
import random
import sys


input = input('Input:')

available_fonts = fi.Figlet().getFonts()

random_font = random.choice(available_fonts)

if len(argv) == 0:
    x = fi.figlet_format(input, font = random_font)
    print(f'Output: {x}')
elif len(argv) == 2 and argv[0] == '-f' or argv[0] == '--font' and argv[1] in available_fonts:
    y = fi.figlet_format(input, font = argv[1])
    print(f'Output: {y}')
else:
    print(f'Invalid command-line argumment')
    sys.exit(1)