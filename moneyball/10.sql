SELECT p.first_name, p.last_name, s.salary, per.HR, per.year
FROM players p
JOIN salaries s ON p.id = s.player_id
JOIN performances per ON p.id = per.player_id AND s.year = per.year
ORDER BY p.id ASC, per.year DESC, 
LIMIT 10;