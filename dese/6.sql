SELECT s.name
FROM schools s
JOIN graduation_rates gr ON s.id = gr.school_id
WHERE graduated = 100;