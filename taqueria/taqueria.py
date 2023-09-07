menu = {
    "Baja Taco": 4.00,
    "Burrito": 7.50,
    "Bowl": 8.50,
    "Nachos": 11.00,
    "Quesadilla": 8.50,
    "Super Burrito": 8.50,
    "Super Quesadilla": 9.50,
    "Taco": 3.00,
    "Tortilla Salad": 8.00
}


def main():
    total = 0
    while True:
        try:
            user_input = input('Item: ').title()
            if user_input in menu:
                total += menu[user_input]
                print(f'Total: {total:.2f}')
            else:
                print(f'Item not found')


main()