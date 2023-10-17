SELECT p.first_name, p.last_name, s.salary, SUM(per.HR), per.year
FROM players p
JOIN salaries s ON p.id = s.player_id
JOIN performances per ON p.id = per.player_id
GROUP BY p.id
ORDER BY p.id
LIMIT 10;