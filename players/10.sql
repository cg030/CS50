SELECT first_name AS 'First Name', last_name AS 'Last Name', debut
FROM players
WHERE birth_country = 'Germany'
ORDER BY debut DESC;