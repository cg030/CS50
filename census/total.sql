CREATE VIEW total AS
SELECT
    locality,
    SUM(families) AS families,
    SUM(households) AS households,
    SUM(population) AS population,
    SUM(male),
    SUM(female)
FROM census
GROUP BY locality;

SELECT SUM(households) FROM total;
