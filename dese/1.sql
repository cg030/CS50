SELECT name, city
FROM districts
WHERE state = 'MA'
AND type LIKE '%public%';