SELECT d.name
FROM districts d
JOIN expenditures e ON d.id = e.district_id
GROUP BY d.name
HAVING e.pupils = (SELECT MIN(pupils) FROM expenditures);