from cs50 import SQL
import csv

# Connect to the SQLite3 database
db = SQL('sqlite:///roster.db')

# Open the students.csv file
with open('students.csv', 'r') as file:
    reader = csv.reader(file)
    next(reader)  # Skip the header row.
    for row in reader:
        # Adjust the number of variables to match the columns in the CSV.
        id, student_name, house, head = row

        # Insert the student_name into the students table
        student_id = db.execute('INSERT INTO students (student_name) VALUES (?)', student_name)

        # Check if the house already exists in the houses table, if not, insert it
        house_id = db.execute('SELECT id FROM houses WHERE house_name = ?', house)
        if not house_id:
            house_id = db.execute('INSERT INTO houses (house_name, head) VALUES (?, ?)', house, head)
        else:
            house_id = house_id[0]['id']

        # Insert the student_id and house_id into the house_assignments table
        db.execute('INSERT INTO house_assignments (student_id, house_id) VALUES (?, ?)', student_id, house_id)
