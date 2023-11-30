CREATE VIEW message AS
SELECT SUBSTR(sentence, 98, 4)
FROM sentences
WHERE id = 14;
