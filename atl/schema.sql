CREATE TABLE "passengers" (
    id,
    first_name,
    "last_name",
    "age",
    PRIMARY KEY(id)
)

CREATE TABLE "check_ins" (
    "date_time" DATE,
    FOREIGN KEY("passenger_id") REFERENCES passengers("id")
)

CREATE TABLE "airlines" (

)

CREATE TABLE "flights" (

)

