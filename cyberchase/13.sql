SELECT title, air_date
FROM episodes
WHERE air_date = (SELECT MIN(air_date) FROM episodes)
   OR air_date = (SELECT MAX(air_date) FROM episodes);