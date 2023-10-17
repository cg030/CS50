CREATE TABLE passengers (
    id INTEGER,
    first_name TEXT,
    last_name TEXT,
    age INTEGER,
    PRIMARY KEY(id)
);

CREATE TABLE check_ins (
    date_time TEXT,
    FOREIGN KEY(passenger_id) REFERENCES passengers(id),
    FOREIGN KEY(flight_id) REFERENCES flights(id)
);

CREATE TABLE "airlines" (
    id INTEGER,
    name TEXT,
    concourse TEXT CHECK (concourse IN "A","B","C","D","E","F","T")
    PRIMARY KEY(id)
);

CREATE TABLE "flights" (
    id INTEGER,
    flight_number INTEGER,
    airport_dep TEXT,
    airport_arr TEXT,
    dep_date TEXT,
    arr_date TEXT,
    FOREIGN KEY(airline_id) REFERENCES airlines(id)
);
