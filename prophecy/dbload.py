from cs50 import SQL

import csv

with open("students.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        id = row["id"]
        name = row["student_name"]
        db.execute("INSERT INTO students(id,name) VALUES (?,?)", id,name)

    

# open database
db = SQL("sqlite:///roster.db")

