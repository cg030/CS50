SELECT DISTINCT t.name
FROM players p
JOIN performances pf ON p.id = pf.player_id
JOIN teams t ON pf.team_id = t.id
WHERE p.first_name = 'Satchel' AND p.last_name = 'Paige';