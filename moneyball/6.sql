SELECT t.name , per.H AS 'total hits'
FROM teams t
JOIN performances per ON t.id = per.team_id
WHERE t.year = 2001
ORDER BY per.H DESC;