CREATE TABLE houses (
    id INTEGER,
    house TEXT,
    head TEXT,
    PRIMARY KEY(house)
);

CREATE TABLE assignment (
    student_id INTEGER,
    house_id,
    FOREIGN KEY(student_id)
    FOREIGN KEY(house_id)
);

