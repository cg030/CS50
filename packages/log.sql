
-- *** The Lost Letter ***

-- two joins : packages on from_address_id and packages on to_address_id
SELECT a2.address, a2.type
FROM packages p
JOIN addresses a ON p.from_address_id = a.id
JOIN addresses a2 ON p.to_address_id = a2.id
WHERE a.address = "900 Somerville Avenue"
AND a2.address LIKE "2%Finn%gan% Street";

-- *** The Devious Delivery ***
-- text
SELECT a.type, p.contents
FROM packages p
JOIN addresses a ON p.to_address_id = a.id
WHERE p.contents LIKE '%duck%'
AND p.from_address_id IS NULL;

-- *** The Forgotten Gift ***
-- text

SELECT p.contents , d.name
FROM packages p
JOIN addresses a ON p.from_address_id = a.id
JOIN addresses a2 ON p.to_address_id = a2.id
JOIN scans s ON p.id = s.package_id
JOIN drivers d ON s.driver_id = d.id
WHERE a.address = "109 Tileston Street"
AND a2.address = "728 Maple Place"
ORDER BY s.timestamp DESC;

SELECT
    p.contents AS package_contents,
    d.name AS driver_name
FROM
    packages p
    LEFT JOIN scans s ON p.id = s.package_id
    LEFT JOIN drivers d ON s.driver_id = d.id
    INNER JOIN addresses a_from ON p.from_address_id = a_from.id
    INNER JOIN addresses a_to ON p.to_address_id = a_to.id
WHERE
    a_from.address = '109 Tileston Street'
    AND a_to.address = '728 Maple Place'
ORDER BY
    s.timestamp DESC
LIMIT 1;
