from cs50 import SQL

import csv

# open database
db = SQL("sqlite:///roster.db")

house_dict = dict()

with open("students.csv", "r") as file:
    reader = csv.DictReader(file)

    for row in reader:
        # read data from csv file into the students table in roster.db
        student_id = row["id"]
        student_name = row["student_name"]
        db.execute("INSERT INTO students(id,name) VALUES (?,?)", student_id,student_name)

        # read data from csv file into the houses and assignments table in roster.db
        house_name = row["house"]
        house_head = row["head"]
        n = 1
        house_dict[row["house"]] = n

        if row["house"] == db.execute("SELECT house FROM houses"):
            # if the house alread exists in the houses table then you don't have to update the houses table
            # however you still have to update the assignments table connecting the student id with the house id
            db.execute("INSERT INTO assignment(student_id, house_id) VALUES (?,?)", student_id, house_dict[row["house"]])
        else:
            db.execute("INSERT INTO houses(id, house, head) VALUES (?,?,?)", house_dict[row["house"]], house_name, house_head)
            db.execute("INSERT INTO assignment(student_id, house_id) VALUES (?,?)", student_id, house_dict[row["house"]])
            n += 1

            