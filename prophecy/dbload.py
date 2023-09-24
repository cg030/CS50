from cs50 import SQL

import csv

# open database
db = SQL("sqlite:///roster.db")


with open("students.csv", "r") as file:
    reader = csv.DictReader(file)
    # read data from csv file into the students table in the roster.db
    for row in reader:
        id = row["id"]
        name = row["student_name"]
        db.execute("INSERT INTO students(id,name) VALUES (?,?)", id,name)

    # read data from the csv file into the houses table in roster.db
    for row in reader:
        # if the house in the csv file already exists in the database skip row
        if row["house"] == db.execute("SELECT house FROM houses"):
            next row
        else:
            


