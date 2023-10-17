SELECT city , COUNT(city)
FROM districts
WHERE type LIKE '%public%'
AND COUNT(city) <= 3
GROUP BY city
ORDER BY COUNT(city) DESC , city ASC;