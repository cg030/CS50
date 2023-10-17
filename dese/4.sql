SELECT city , COUNT(city)
FROM districts
WHERE type LIKE '%public%'
GROUP BY city
ORDER BY COUNT(city) DESC , city ASC
LIMIT 10;