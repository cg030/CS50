SELECT ROUND(AVG(s.salary),2) AS 'average salary', t.name
FROM salaries s
JOIN teams t ON s.team_id = t.id
