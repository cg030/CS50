SELECT city , COUNT(city)
FROM districts
WHERE type LIKE '%public%'
GROUP BY city
HAVING COUNT(city) <= 3
ORDER BY COUNT(city) DESC , city ASC;