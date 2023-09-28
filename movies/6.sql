SELECT AVG(rating) AS AverageRatingOfMoviesReleasedIn2012
FROM ratings r
JOIN movies m ON r.movie_id = m.id
WHERE m.year = 2012;