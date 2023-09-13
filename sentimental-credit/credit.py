def main():
    # get input from user
    number = input('Number: ')

    while not number.isnumeric():
        number = input('Number: ')

    if luhn(number):
        card = card_type(number)
        if card:
            print(f'{card}')
        else:
            print(f'INVALID')
    else:
        print(f'INVALID')


def luhn(number):
    sum = 0
    count = 0
    digit = int(number)

    while digit > 0:
        cur_digit = digit % 10

        if count % 2 != 0:  # conditional for calculation according to digit order
            product = cur_digit * 2
            sum += (
                product // 10 + product % 10
            )  # if the product is a two-digit number this splits it into two digits; integer division on product by 10. Integer division in C rounds towards zero.

        else:
            sum += cur_digit

        count += 1
        digit = digit // 10 # remove last digit

    return sum % 10 == 0


def card_type(number):
    if len(number) == 15 and (number[:2] == '34' or number[:2] == '37'):
        return 'AMEX'
    elif (len(number) == 13 or len(number) == 16) and number[0] == '4':
        return 'VISA'
    elif len(number) == 16 and (number[:2] in ('51', '52', '53', '54', '55')):
        return 'MASTERCARD'
    else:
        return False
main()