SELECT s.salary
FROM salaries s
JOIN players p ON s.player_id = p.id
JOIN performance per ON p.id = per.player_id
WHERE per.year = 2001