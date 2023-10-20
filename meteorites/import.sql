DROP TABLE meteorites;


CREATE TABLE meteorites_import (
    name TEXT,
    id INTEGER,
    nametype TEXT,
    class TEXT,
    mass REAL,
    discovery TEXT,
    year INTEGER,
    lat REAL,
    long REAL
);

CREATE TABLE meteorites (
    id INTEGER,
    name TEXT,
    class TEXT,
    mass REAL,
    discovery TEXT,
    year INTEGER,
    lat REAL,
    long REAL
);

-- Any empty values in meteorites.csv are represented by NULL in the meteorites table.
SELECT * FROM meteorites_import WHERE mass IS NULL;
SELECT * FROM meteorites_import WHERE lat IS NULL;
SELECT * FROM meteorites_import WHERE long IS NULL;
-- .import automatically converts empty values to NULL


-- Update decimal values
UPDATE meteorites_import
SET mass = ROUND(mass, 2),
    lat = ROUND(lat, 2),
    long = ROUND(long, 2);


-- Delete rows
DELETE FROM meteorites_import
WHERE nametype = 'Relict';

-- DROP columns; no direct way in sqlite3 so you have to create temporary tables
INSERT INTO meteorites (id, name, class, mass, discovery, year, lat, long)
SELECT id, name, class, mass, discovery, year, lat, long
FROM meteorites_import;

DROP TABLE meteorites_import;


-- sort rows
-- backup the data in a temporary table
CREATE TEMP TABLE temp_table AS
SELECT * FROM meteorites;

-- drop original table
DROP TABLE meteorites;

-- recreat the original table with the sorted temporary table
CREATE TABLE meteorites AS
SELECT
    ROW_NUMBER() OVER(ORDER BY year ASC, name ASC) AS id,
    name,
    class,
    mass,
    discovery,
    year,
    lat,
    long
FROM temp_table;

-- drop temporary table
DROP TABLE temp_table;


