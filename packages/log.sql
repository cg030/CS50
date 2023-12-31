
-- *** The Lost Letter ***
SELECT a2.address, a2.type
FROM packages p
JOIN addresses a ON p.from_address_id = a.id
JOIN addresses a2 ON p.to_address_id = a2.id
WHERE a.address = "900 Somerville Avenue"
AND a2.address LIKE "2%Finn%gan% Street";

-- *** The Devious Delivery ***
SELECT a.type, p.contents
FROM packages p
JOIN addresses a ON p.to_address_id = a.id
WHERE p.contents LIKE '%duck%'
AND p.from_address_id IS NULL;


-- *** The Forgotten Gift ***
SELECT p.contents , d.name
FROM packages p
JOIN addresses a ON p.from_address_id = a.id
JOIN addresses a2 ON p.to_address_id = a2.id
JOIN scans s ON p.id = s.package_id
JOIN drivers d ON s.driver_id = d.id
WHERE a.address = "109 Tileston Street"
AND a2.address = "728 Maple Place"
ORDER BY s.timestamp DESC;