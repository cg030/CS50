CREATE TABLE passengers (
    id,
    first_name TEXT,
    last_name TEXT,
    age INTEGER,
    PRIMARY KEY(id)
)

CREATE TABLE check_ins (
    date_time DATE,
    FOREIGN KEY(passenger_id) REFERENCES passengers(id),
    FOREIGN KEY(flight_id) REFERENCES flights(id)
)

CREATE TABLE "airlines" (
    id,
    name,
    concourse CHECK(A,B,C,D,E,F,T)
    PRIMARY KEY(id)
)

CREATE TABLE "flights" (
    id,
    flight_number,
    airport_dep,
    airport_arr,
    dep_date DATE,
    arr_date DATE,
    FOREIGN KEY(airline_id) REFERENCES airlines(id)
)

