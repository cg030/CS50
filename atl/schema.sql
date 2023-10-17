-- DROP TABLE passengers;
-- DROP TABLE check_ins;
-- DROP TABLE airlines;
-- DROP TABLE flights;

CREATE TABLE passengers (
    id INTEGER,
    first_name TEXT,
    last_name TEXT,
    age INTEGER,
    PRIMARY KEY(id)
);

CREATE TABLE check_ins (
    date_time TEXT,
    passenger_id INTEGER,
    flight_id INTEGER,
    FOREIGN KEY(passenger_id) REFERENCES passengers(id),
    FOREIGN KEY(flight_id) REFERENCES flights(id)
);

CREATE TABLE airlines (
    id INTEGER,
    name TEXT,
    concourse TEXT CHECK (concourse IN ("A","B","C","D","E","F","T")),
    PRIMARY KEY(id)
);

CREATE TABLE flights (
    id INTEGER,
    flight_number INTEGER,
    airline_id INTEGER,
    airport_dep TEXT,
    airport_arr TEXT,
    dep_date TEXT,
    arr_date TEXT,
    PRIMARY KEY(id)
    FOREIGN KEY(airline_id) REFERENCES airlines(id)
);

-- INSERT INTO passengers (first_name, last_name, age)
-- VALUES ('Amelia', 'Earhart', 39);

-- INSERT INTO airlines (name,concourse)
-- VALUES ('Delta','A');

-- INSERT INTO flights (flight_number, airport_dep, airport_arr, dep_date, arr_date)
-- VALUES (300, "ATL", "BOS", "2023-08-03 18:46:00", "2023-08-03 19:09:00");

-- INSERT INTO check_ins (passenger_id, flight_id, date_time)
-- VALUES (1, 1, "2023-08-03 15:03:00");