CREATE TABLE passengers (
    id,
    first_name,
    last_name,
    age,
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
    
    FOREIGN KEY(airline_id) REFERENCES airlines(id)
)

