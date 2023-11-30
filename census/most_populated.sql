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
ORDER BY population DESC;