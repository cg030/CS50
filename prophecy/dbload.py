from cs50 import SQL

import csv

# open database
db = SQL("sqlite:///roster.db")

house_dict = dict()

with open("students.csv", "r") as file:
    reader = csv.DictReader(file)
    # read data from csv file into the students table in the roster.db
    for row in reader:
        student_id = row["id"]
        student_name = row["student_name"]
        db.execute("INSERT INTO students(id,name) VALUES (?,?)", student_id,student_name)

        # if the house in the csv file already exists in the database skip row otherwise insert house into table
        n = 1
        house_dict["id"] = 1
        house_dict["house_name"] = row["house"]

        house_name = row["house"]
        house_head = row["head"]

        # if the value in house column in the csv file is equal to a house name in the house_dict, insert the corresponding id of the house in the dictionary into the assignments table
        if row["house"] == house_dict("house_name"):
            temp_house_id = row["house_name"]
            db.execute("INSERT INTO assignment (student_id, house_id) VALUES (?,?)", student_id, temp_house_id)
        # if the name doesn't yet exist in the dictionary add the house and id to the dictionary and then insert the id into the assignment table
        else:
            house_dict[row["house"]] = n
            n += 1


        if row["house"] == db.execute("SELECT house FROM houses"):

            db.execute("INSERT INTO assignment(student_id, house_id) VALUES (?,?)", student_id, )
            next row
        else:
            db.execute("INSERT INTO houses(id, houses, head) VALUES (?,?,?)", house_id, house_name, house_head)
            house_id += 1

    # populate the assignement table
    for row in reader:
        db.execute("INSERT INTO assignment (student_id, house_id) VALUES (?,?)", student_id, )