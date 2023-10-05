SELECT english_title, artist
FROM views
WHERE (SELECT MAX(brightness) from views);