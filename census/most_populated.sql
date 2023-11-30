DROP VIEW most_populated;

CREATE VIEW most_populated AS
SELECT
    district,
    SUM(families) AS families,
    SUM(households) AS households,
    SUM(population) AS population,
    SUM(male),
    SUM(female)
FROM census
GROUP BY district
ORDER BY SUM(population) DESC;

SELECT * FROM by_district;
