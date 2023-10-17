SELECT p.first_name, p.last_name, s.salary, per.HR, per.year
FROM players p
JOIN salaries s ON p.id = s.player_id
JOIN performances per ON p.id = per.player_id
ORDER BY p.id;