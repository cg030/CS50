SELECT DISTINCT p.name
FROM people p
JOIN stars s1 ON p.id = s1.person_id
JOIN (
    SELECT s.movie_id
    FROM stars s
    JOIN people p ON p.id = s.person_id
    WHERE p.name = 'Kevin Bacon' AND p.birth = 1958
) kb_movies ON s1.movie_id = kb_movies.movie_id
WHERE p.id != (SELECT id FROM people WHERE name = 'Kevin Bacon' AND birth = 1958);
