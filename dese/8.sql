SELECT d.name, e.pupils
FROM districts d
JOIN expenditures e ON d.id = e.district_id
GROUP BY d.name
ORDER BY pupils DESC;