import csv
import sqlite3

# Connect to the SQLite3 database
conn = sqlite3.connect('roster.db')
cursor = conn.cursor()

# Open the students.csv file
with open('students.csv', 'r') as file:
    reader = csv.reader(file)
    for row in reader:
        # Extract student_name, house, and head from each row in the CSV
        student_name, house, head = row

        # Insert the student_name into the students table
        cursor.execute('INSERT INTO students (student_name) VALUES (?)', (student_name,))
        student_id = cursor.lastrowid  # Get the id of the last inserted row

        # Check if the house already exists in the houses table, if not, insert it
        cursor.execute('SELECT id FROM houses WHERE house_name = ?', (house,))
        house_id = cursor.fetchone()
        if not house_id:
            cursor.execute('INSERT INTO houses (house_name, head) VALUES (?, ?)', (house, head))
            house_id = cursor.lastrowid  # Get the id of the last inserted row
        else:
            house_id = house_id[0]

        # Insert the student_id and house_id into the house_assignments table
        cursor.execute('INSERT INTO house_assignments (student_id, house_id) VALUES (?, ?)', (student_id, house_id))

# Commit the transactions and close the connection
conn.commit()
conn.close()
