import figlet as fi
import random
from sys import argv

input = input('Input:')

available_fonts = fi.Figlet().getFonts()

random_font = random.choice(available fonts)

if len(argv) == 0:
    x = fi.figlet_format(input, font = random_font)
    print(f'Output: {x}')
elif len(argv) == 2 and argv[0] == '-f' or argv[0] == '--font' and argv[1] == # valid font from available_fonts
    y = fi.figlet_format(input, font = argv[1])
    print(f'Output: {y}')
else
    print(f'Invalid command-line argumment')
    return(1)