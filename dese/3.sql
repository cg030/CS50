SELECT AVG(per_pupil_expenditure) AS 'Average District Per-Pupil Expenditure'
FROM expenditures e
JOIN districts d ON e.district_id = d.id
GROUP BY d.id;