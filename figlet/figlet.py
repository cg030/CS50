import figlet as fi
import random
from sys import argv

input = input(print(f'Input:'))

available_fonts = fi.Figlet().getFonts()

random_font = random.choice(available fonts)

if len(argv) == 0:
    x = fi.figlet_format(input, font = random_font)
elif len(argv) == 2 and argv == '-f' or argv == '--f'

