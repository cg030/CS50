DROP TABLE meteorites;

CREATE TABLE meteorites (
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

-- DROP columns; no direct way in sqlite3 so you have to create temporary tables
CREATE TEMP TABLE temp_table AS
SELECT id, name, class, mass, discovery, year, lat, long
FROM meteorites;

DROP TABLE meteorites;

ALTER TABLE temp_table RENAME TO meteorites;


-- Any empty values in meteorites.csv are represented by NULL in the meteorites table.
SELECT * FROM meteorites WHERE mass IS NULL;
SELECT * FROM meteorites WHERE lat IS NULL;
SELECT * FROM meteorites WHERE long IS NULL;
-- .import automatically converts empty values to NULL


-- Update decimal values
UPDATE meteorites
SET mass = ROUND(mass, 2),
    lat = ROUND(lat, 2),
    long = ROUND(long, 2);


-- Delete rows
DELETE FROM meteorites
WHERE nametype = 'Relict';


-- sort rows
-- backup the data in a temporary table
CREATE TEMP TABLE temp_table AS
SELECT * FROM meteorites;

-- drop original table
DROP TABLE meteorites;

-- recreat the original table with the sorted temporary table
CREATE TABLE meteorites AS
SELECT
    ROW_NUMBER() OVER(ORDER BY year ASC, name ASC) AS id, *
FROM temp_table;

-- drop temporary table
DROP TABLE temp_table;


