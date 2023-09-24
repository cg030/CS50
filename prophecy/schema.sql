-- DROP TABLE students;
-- DROP TABLE houses;
-- DROP TABLE house_assignments;

CREATE TABLE students (
    id INTEGER PRIMARY KEY,
    student_name TEXT NOT NULL
);


CREATE TABLE houses (
    id INTEGER PRIMARY KEY,
    house_name TEXT NOT NULL,
    head TEXT NOT NULL
);


CREATE TABLE house_assignments (
    student_id INTEGER,
    house_id INTEGER,
    FOREIGN KEY (student_id) REFERENCES students (id),
    FOREIGN KEY (house_id) REFERENCES houses (id)
);
