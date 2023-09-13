def main():
    # get input from user
    number = input('Number: ')




def luhn(number):
    for i in range(number[len(number - 1)], 0, -2):
        sum_product += i * 2
    for j in range(number[len(number)], 0 , 1):
        sum += j

    if ((sum_product + sum) % 10 == 0):
        return True

def card_type(number):
    if (len(number) == 15 and number[:2] == '34' or number[:2] == '37'):
        return('AMEX')
    elif (len(number) == 13 or len(number) == 16 and number[0] == '4')
    elif (len(number) == 16 and
          number[:2] == '51' or
          number[:2] == '52' or
          number[:2] == '53' or
          number[:2] == '54' or
          number[:2] == '55' or
          ):
        return('MasterCard')
