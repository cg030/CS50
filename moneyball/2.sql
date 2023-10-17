SELECT s.year, s.salary, p.first_name, p.last_name
FROM salaries s
JOIN players p ON s.player_id = p.id
WHERE p.first_name LIKE '%Calvin%';
-- AND p.last_name LIKE '%Ripken Jr.%'