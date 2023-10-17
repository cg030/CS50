SELECT p.first_name , p.last_name
FROM players p
JOIN salaries s ON p.id = s.player_id
WHERE s.salary = (SELECT MAX(salary) FROM salaries);