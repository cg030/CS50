SELECT d.name, e.per_pupil_expenditure, se.exemplary
FROM districts d
JOIN expenditures e ON d.id = e.district_id
JOIN staff_evaluations se ON d.id = se.district_id
WHERE e.per_pupil_expenditures >= (SELECT AVG(per_pupil_expenditures) FROM expenditures)
AND se.exemplary >= (SELECT AVG(exemplary) FROM staff_evaluations);