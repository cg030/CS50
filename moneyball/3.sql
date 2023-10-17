SELECT per.year, per.HR
FROM performances per
JOIN players p ON per.player_id = p.id
WHERE p.first_name = 'Ken'
AND p.last_name = 'Griffey'
AND p.birth_year = 1969
ORDER BY per.year DESC;