def main():
    # get input from user
    number = input('Number: ')

    while not number.isnumeric():
        number = input('Number: ')

    type = card_type(number)
    luhn_valid = luhn(number)

    if (luhn_valid == True and type == 'AMEX'):
        print(f'AMEX')
    elif (luhn_valid == True and type == 'MASTERCARD'):
        print(f'MASTERCARD')
    elif (luhn_valid == True and type == 'VISA'):
        print(f'VISA')
    else:
        print(f'INVALID')


def luhn(number):
    sum = 0
    count = 0

    digit = int(number) % 10

    if (count % 2 != 0): # conditional for calculation according to digit order
        product = digit * 2
        sum = sum + product / 10 + product % 10 # if the product is a two-digit number this splits it into two digits; integer division on product by 10. Integer division in C rounds towards zero.

    else:
        sum = sum + digit;

    count += 1
    return (sum % 10 == 0)


def card_type(number):
    if (len(number) == 15 and (number[:2] == '34' or number[:2] == '37')):
        return('AMEX')
    elif ((len(number) == 13 or len(number) == 16) and number[0] == '4'):
        return('VISA')
    elif (len(number) == 16 and (number[:2] in ('51', '52', '53', '54', '55'))):
        return('MasterCard')
    else:
        return('InvalidCard')

main()