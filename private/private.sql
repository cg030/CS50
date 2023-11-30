DROP TABLE substrings;

CREATE VIEW message AS
SELECT SUBSTR(sentence, 98, 4) AS phrase
FROM sentences
WHERE id = 14

UNION

SELECT SUBSTR(sentence, 3, 5)
FROM sentences
WHERE id = 114

UNION

SELECT SUBSTR(sentence, 72, 9)
FROM sentences
WHERE id = 618

UNION

SELECT SUBSTR(sentence, 7, 3)
FROM sentences
WHERE id = 630

UNION

SELECT SUBSTR(sentence, 12, 5)
FROM sentences
WHERE id = 932

UNION

SELECT SUBSTR(sentence, 50, 7)
FROM sentences
WHERE id = 2230

UNION

SELECT SUBSTR(sentence, 44, 10)
FROM sentences
WHERE id = 2346

UNION

SELECT SUBSTR(sentence, 14, 10)
FROM sentences
WHERE id = 3041;
