from cs50 import SQL
import csv

db = SQL("sqlite:///roster.db")

with open("students.csv", "r") as file:
    reader = csv.DictReader(file)
    house_dict = dict()

    for row in reader:
        student_id = row["id"]
        student_name = row["student_name"]
        db.execute("INSERT INTO students (id, student_name) VALUES (?, ?)", student_id, student_name)

        house_name = row["house"]
        house_head = row["head"]

        # Check if house is already in the houses table
        house_in_db = db.execute("SELECT * FROM houses WHERE house = ?", house_name)

        if not house_in_db:  # If the house is not in the database, insert it
            house_id = len(house_dict) + 1  # You can also use some other logic to generate house_id
            db.execute("INSERT INTO houses (id, house, head) VALUES (?, ?, ?)", house_id, house_name, house_head)
            house_dict[house_name] = house_id  # Store the house_id in house_dict

        # Get house_id from house_dict and insert into assignment table
        house_id = house_dict[house_name]
        db.execute("INSERT INTO assignment (student_id, house_id) VALUES (?, ?)", student_id, house_id)
