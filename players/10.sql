SELECT first_name AS 'First Name', last_name AS 'Last Name'
FROM players
WHERE birth_country = 'Germany'
ORDER BY debut DESC;