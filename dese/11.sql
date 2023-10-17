SELECT s.name , e.per_pupil_expenditure, g.graduated
FROM schools s
JOIN graduation_rates g ON s.id = g.school_id
JOIN districts d ON s.district_id = d.id
JOIN expenditures e ON d.id = e.district_id
ORDER BY e.per_pupil_expenditure DESC, s.name ASC;