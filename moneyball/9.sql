SELECT ROUND(AVG(s.salary),2) AS 'average salary', t.name
FROM salaries s
JOIN teams t ON s.team_id = t.id
GROUP BY s.team_id
HAVING s.year = 2001
ORDER BY ROUND(AVG(s.salary),2) ASC
LIMIT 5;