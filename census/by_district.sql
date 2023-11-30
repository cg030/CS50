CREATE VIEW by_district AS
SELECT
    district,
    SUM(families) AS families,
    SUM(households) AS households,
    SUM(population) AS population,
    SUM(male),
    SUM(female)
FROM census
GROUP BY district;
