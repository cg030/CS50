SELECT first_name, last_name
FROM players
WHERE birth_country IS NOT 'United States'
ORDER BY first_name ASC, last_name ASC;