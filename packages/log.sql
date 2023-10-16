
-- *** The Lost Letter ***

-- two joins : packages on from_address_id and packages on to_address_id
SELECT a2.address, a2.type
FROM packages p
JOIN addresses a ON p.from_address_id = a.id
JOIN addresses a2 ON p.to_address_id = a2.id
WHERE a.address = "900 Somerville Avenue"
AND a2.address LIKE "2%Finn%gan% Street";

-- *** The Devious Delivery ***
SELECT a_to.type, p.contents
FROM packages p
JOIN addresses a_to ON p.to_address_id = a_to.id
LEFT JOIN addresses a_from ON p.from_address_id = a_from.id
WHERE p.contents LIKE '%duck%'
AND (p.from_address_id IS NULL OR a_from.address IS NULL);



SELECT id, contents
FROM packages
WHERE from_address_id = (
    SELECT id
    FROM addresses
    WHERE address IS NULL
);

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