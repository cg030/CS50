def main():

    # Get user input
    while True:
        try:
            user_input = input('Text: ')
            if user_input.isalpha():
                break
            else:
                print(f'Enter text')
        except ValueError:
            print(f'Invalid Input')

    # calculate Index

    L = count_letters(user_input) / count_words(user_input) * 100 # L is the average number of letters per 100 words in the text
    S = count_sentences(user_input) / count_words(user_input) * 100 # S is the average number of sentences per 100 words in the text
    score = 0.0588 * L - 0.296 * S - 15.8
    grade = round(score)

    # print score
    if grade < 1:
        print(f'Before Grade 1')
    elif grade < 16:
        print(f'Grade {grade}')
    else:
        print(f'Grade 16+')


def count_letters(user_input):
    letters = sum(1 for char in user_input if char.isalpha())
    return letters


def count_words(user_input):
    words = len(user_input.split())
    return words

def count_sentences(user_input):
    sentences = sum(1 for punc in user_input if char in '.?!')
    return sentences

main()