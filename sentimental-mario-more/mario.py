def main():
    # get size input
    while True:
        height = int(input('Height: '))
        if height < 1 or height > 8:
            break
