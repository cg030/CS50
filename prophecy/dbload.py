from cs50 import SQL

import csv

# open database
db = SQL("sqlite:///roster.db")


with open("students.csv", "r") as file:
    reader = csv.DictReader(file)
    # read data from csv file into the students table in the roster.db
    for row in reader:
        student_id = row["id"]
        student_name = row["student_name"]
        db.execute("INSERT INTO students(id,name) VALUES (?,?)", student_id,student_name)

    # read data from the csv file into the houses table in roster.db
    for row in reader:
        # if the house in the csv file already exists in the database skip row otherwise insert house into table
        house_id = 1
        house_name = row["house"]
        house_head = row["head"]
        if row["house"] == db.execute("SELECT house FROM houses"):
            next row
        else:
            db.execute("INSERT INTO houses(id, houses, head) VALUES (?,?,?)", house_id, house_name, house_head)
            house_id += 1

    # populate the assignement table
    for row in reader:
        