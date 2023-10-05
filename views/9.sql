SELECT english_title, artist, brightness
FROM views
WHERE brightness = (SELECT MAX(brightness) from views);