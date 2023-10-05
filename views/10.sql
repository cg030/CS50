SELECT artist, ROUND(AVG(contrast),2) AS 'Average Contrast'
FROM views
WHERE english_title LIKE '%Fuji%'
GROUP BY artist
ORDER BY contrast;