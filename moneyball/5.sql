SELECT t.name
FROM teams t
JOIN salaries s ON t.id = s.team_id
JOIN players p ON s.player_id = p.id
WHERE p.first_name = 'Satchel'
AND p.last_name = 'Paige';

SELECT * FROM pl