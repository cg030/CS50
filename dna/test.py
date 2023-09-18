import csv

with open('databases/small.csv') as file:
    dict_reader = csv.DictReader(file)
    for person in dict_reader:
        print(person['AGATC'])