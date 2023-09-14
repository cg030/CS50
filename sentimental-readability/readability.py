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
    word_count = len(user_input.split())
    return word_count

def count_sentences(user_input):
    sentence_count = sum(1 for punc in user_input if )