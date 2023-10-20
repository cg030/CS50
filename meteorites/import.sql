-- DROP TABLE meteorites;

-- CREATE TABLE meteorites (
--     name TEXT,
--     id INTEGER,
--     nametype TEXT,
--     class TEXT,
--     mass REAL,
--     discovery TEXT,
--     year INTEGER,
--     lat REAL,
--     long REAL
-- );

-- Any empty values in meteorites.csv are represented by NULL in the meteorites table.

SELECT * FROM meteorites WHERE mass IS NULL;
SELECT * FROM meteorites WHERE lat IS NULL;
SELECT * FROM meteorites WHERE long IS NULL;

-- .import automatically converts empty values to NULL

UPDATE meteorites
SET mass = ROUND(mass, 2),
    lat = ROUND(lat, 2),
    long = ROUND(long, 2)