import figlet as fi
import random
from sys import argv

input = input(print(f'Input:'))

available_fonts = fi.Figlet().getFonts()

random_font = random.choice(available fonts)

if len(argv) == 0:
    x = fi.figlet_format(input, font = random_font)
    print(f'{x}')
elif len(argv) == 2 and argv[0] == '-f' or argv[0] == '--f' and argv[1] == font_name


