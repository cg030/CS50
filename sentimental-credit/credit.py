def main():
    # get input from user
    number = input('Number: ')

    while not number.isnumeric():
        number = input('Number: ')

        type = card_type(number)
        luhn = luhn(number)

    if (luhn == True and type == 'AMEX'):
        print(f'AMEX')
    elif (luhn == True and type == 'MASTERCARD'):
        print(f'MASTERCARD')
    elif (luhn == True and type == 'VISA'):
        print(f'VISA')
    else:
        print(f'INVALID')


def luhn(number):
    for i in range(number[len(number - 1)], 0, -2):
        sum_product += i * 2
    for j in range(number[len(number)], 0 , 1):
        sum += j

    if ((sum_product + sum) % 10 == 0):
        return True
    else:
        return False

def card_type(number):
    if (len(number) == 15 and number[:2] == '34' or number[:2] == '37'):
        return('AMEX')
    elif (len(number) == 13 or len(number) == 16 and number[0] == '4'):
        return('VISA')
    elif (len(number) == 16 and (number[:2] in ('51', '52', '53' , '54' , '55')):
        return('MasterCard')
    else:
        return('InvalidCard')

main()