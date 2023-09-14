def main():

    while True:
        try:
            user_input = input('Text: ')
            if user_input = isalpha:
                break
            else:
                print(f'Enter text')
        except ValueError:
            print(f'Invalid Input')

def count_letters(user_input):
    letter_count = sum(1 for char in user_input if char.isalpha())
    return letter_count

def count_words(user_input):
    