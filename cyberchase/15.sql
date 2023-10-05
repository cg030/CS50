SELECT
    strftime('%Y', air_date) AS year,
    MIN(strftime('%m-%d', air_date)) AS first_air_date
FROM episodes
GROUP BY year;