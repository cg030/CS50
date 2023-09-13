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
    sum_product = 0
    sum = 0

    for i in range(len(number) -2, -1, -2):
        double_digits += int(number[i]) * 2
        if (double_digits > 9):
            sum_product += (double_digits % 10 + double_digits // 10)
        else:
            sum_product += double_digits

    for j in range(len(number), -1, -2):
        sum += int(number[j])

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