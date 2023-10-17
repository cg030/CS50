SELECT t.name
FROM teams t
JOIN salaries s ON t.id = s.team_id
JOIN players p ON s.player_id = p.id
WHERE p.first_name = 'Satchel'
AND p.last_name = 'Paige';


SELECT DISTINCT t.name
FROM players p
JOIN performances pf ON p.id = pf.player_id
JOIN teams t ON pf.team_id = t.id
WHERE p.first_name = 'Satchel' AND p.last_name = 'Paige';
