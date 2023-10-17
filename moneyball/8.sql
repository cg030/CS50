SELECT s.salary, p.first_name , p.last_name
FROM salaries s
JOIN players p ON s.player_id = p.id
JOIN performances per ON p.id = per.player_id
WHERE per.year = 2001
AND per.HR = (SELECT MAX(HR) FROM performances WHERE year = 2001);


