from cs50 import SQL

import csv

with open("students.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        row["id"]

# open database
db = SQL("sqlite:///roster.db")

