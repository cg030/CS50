SELECT t.name
FROM teams t
JOIN players p ON t.player_id = p.id
WHERE p.first_name = 'Satchel'
AND p.last_name = 'Paige';