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
    if (len(number) == 15):
        return('AMEX')
    elif
    elif (len(number) == 16):
        return('MasterCard')
