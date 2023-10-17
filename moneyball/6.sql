SELECT t.name , SUM(per.H) AS 'total hits'
FROM teams t
JOIN performances per ON t.id = per.team_id
WHERE per.year = 2001
GROUP BY per.team_id
ORDER BY SUM(per.H) DESC
LIMIT 5;