from cs50 import SQL

import csv

# open database
db = SQL("sqlite:///roster.db")


with open("students.csv", "r") as file:
    reader = csv.DictReader(file)
    house_dict = dict()

    for row in reader:
        # read data from csv file into the students table in roster.db
        student_id = row["id"]
        student_name = row["student_name"]
        db.execute("INSERT INTO students(id,student_name) VALUES (?,?)", student_id,student_name)

        # read data from csv file into the houses and assignments table in roster.db
        house_name = row["house"]
        house_head = row["head"]

        # check if the house is already in the houses table
        house_in_db = db.execute("SELECT * FROM houses WHERE house = ?", house_name)

        # if the house is not in the database, insert it
        if not house_in_db:
            house_id = len(house_dict) + 1
            db.execute("INSERT INTO houses(id, house, head) VALUES (?,?,?)", house_id, house_name, house_head)
            house_dict[house_name] = house_id # store the house_id in house_dict

        # get house_id from house_dict and insert into assignment table
        house_id = house_dict[house_name]
        db.execute("INSERT INTO assignment (student_id, house_id) VALUES (?,?)", student_id, house_id)

