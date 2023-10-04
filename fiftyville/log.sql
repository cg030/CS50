-- Keep a log of any SQL queries you execute as you solve the mystery.
-- July 28, 2021
-- 'Humphrey Street'

SELECT *
FROM crime_scene_reports
WHERE street = 'Humphrey Street'
AND year = 2021
AND month = 7
and day = 28;

-- | id  | year | month | day |     street      |                                                                                                       description                                                                                                        |
-----+------+-------+-----+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
-- | 295 | 2021 | 7     | 28  | Humphrey Street | Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.


SELECT *
FROM interviews
WHERE transcript LIKE '%bakery%';

-- | 161 | Ruth    | 2021 | 7     | 28  | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          |
-- | 162 | Eugene  | 2021 | 7     | 28  | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.                                                                                                 |
-- | 163 | Raymond | 2021 | 7     | 28  | As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket. |



-- Persons leaving the parking lot of the nearby bakery with a car within 10 minutes of the theft
SELECT id, license_plate
FROM bakery_security_logs
WHERE year = 2021
AND month = 7
AND day = 28
AND hour = 10
AND minute >= 15
AND minute <=25;

-- +-----+---------------+
-- | id  | license_plate |
-- +-----+---------------+
-- | 260 | 5P2BI95       |
-- | 261 | 94KL13X       |
-- | 262 | 6P58WS2       |
-- | 263 | 4328GD8       |
-- | 264 | G412CB7       |
-- | 265 | L93JTIZ       |
-- | 266 | 322W7JE       |
-- | 267 | 0NTHK55       |
-- +-----+---------------+


-- Persons withdrawing money the morning of the theft
SELECT id, account_number
FROM atm_transactions
WHERE year = 2021
AND month = 7
AND day = 28
AND atm_location = 'Leggett Street'
AND transaction_type = 'withdraw';

-- +-----+----------------+
-- | id  | account_number |
-- +-----+----------------+
-- | 246 | 28500762       |
-- | 264 | 28296815       |
-- | 266 | 76054385       |
-- | 267 | 49610011       |
-- | 269 | 16153065       |
-- | 288 | 25506511       |
-- | 313 | 81061156       |
-- | 336 | 26013199       |
-- +-----+----------------+


-- Persons making a call on the day of the theft for a duration of less than a minute
SELECT id, caller, receiver
FROM phone_calls
WHERE year = 2021
AND month = 7
AND day = 28
AND duration < 60;

-- +-----+----------------+----------------+
-- | id  |     caller     |    receiver    |
-- +-----+----------------+----------------+
-- | 221 | (130) 555-0289 | (996) 555-8899 |
-- | 224 | (499) 555-9472 | (892) 555-8872 |
-- | 233 | (367) 555-5533 | (375) 555-8161 |
-- | 251 | (499) 555-9472 | (717) 555-1342 |
-- | 254 | (286) 555-6063 | (676) 555-6554 |
-- | 255 | (770) 555-1861 | (725) 555-3243 |
-- | 261 | (031) 555-6622 | (910) 555-3251 |
-- | 279 | (826) 555-1652 | (066) 555-9701 |
-- | 281 | (338) 555-6650 | (704) 555-2131 |
-- +-----+----------------+----------------+


-- passport numbers of passengers on the earliest flight out of Fiftyville the day after the theft
SELECT p.passport_number
FROM passengers p
JOIN flights f ON p.flight_id = f.id
JOIN airports a ON f.origin_airport_id = a.id
WHERE a.city = 'Fiftyville'
AND f.year = 2021
AND f.month = 7
AND f.day = 29
AND f.hour = (SELECT MIN(f2.hour) FROM flights f2 WHERE f2.year = 2021 AND f2.month = 7 AND f2.day = 29);

-- +-----------------+
-- | passport_number |
-- +-----------------+
-- | 7214083635      |
-- | 1695452385      |
-- | 5773159633      |
-- | 1540955065      |
-- | 8294398571      |
-- | 1988161715      |
-- | 9878712108      |
-- | 8496433585      |
-- +-----------------+

-- name, people_id number, passport number, license plate number, phone number bank account number of passengers on the earliest flight out of Fiftyville the day after the theft

-- Is this correct to join the list of passengers on the earliest flight with the bank_account table since the person making the purchase isn't on the flight, thus the name we receive from the query is the bank account number of the person who made the purchase not the thief
-- break down into two different queries
-- SELECT p.name, p.id, p.passport_number, b.account_number, p.phone_number, p.license_plate
-- FROM people p
-- JOIN passengers pa ON p.passport_number = pa.passport_number
-- JOIN bank_accounts b ON p.id = b.person_id
-- JOIN flights f ON pa.flight_id = f.id
-- JOIN airports a ON f.origin_airport_id = a.id
-- WHERE a.city = 'Fiftyville'
-- AND f.year = 2021
-- AND f.month = 7
-- AND f.day = 29
-- AND f.hour = (SELECT MIN(f2.hour) FROM flights f2 WHERE f2.year = 2021 AND f2.month = 7 AND f2.day = 29);

-- +--------+--------+-----------------+----------------+----------------+---------------+
-- |  name  |   id   | passport_number | account_number |  phone_number  | license_plate |
-- +--------+--------+-----------------+----------------+----------------+---------------+
-- | Bruce  | 686048 | 5773159633      | 49610011       | (367) 555-5533 | 94KL13X       |
-- | Taylor | 449774 | 1988161715      | 76054385       | (286) 555-6063 | 1106N58       |
-- | Kenny  | 395717 | 9878712108      | 28296815       | (826) 555-1652 | 30G67EN       |
-- | Luca   | 467400 | 8496433585      | 28500762       | (389) 555-5198 | 4328GD8       |
-- +--------+--------+-----------------+----------------+----------------+---------------+


-- SELECT p.name, p.id, p.passport_number, p.phone_number, p.license_plate
-- FROM people p
-- JOIN passengers pa ON p.passport_number = pa.passport_number
-- JOIN flights f ON pa.flight_id = f.id
-- JOIN airports a ON f.origin_airport_id = a.id
-- WHERE a.city = 'Fiftyville'
-- AND f.year = 2021
-- AND f.month = 7
-- AND f.day = 29
-- AND f.hour = (SELECT MIN(f2.hour) FROM flights f2 WHERE f2.year = 2021 AND f2.month = 7 AND f2.day = 29);

-- +--------+--------+-----------------+----------------+---------------+
-- |  name  |   id   | passport_number |  phone_number  | license_plate |
-- +--------+--------+-----------------+----------------+---------------+
-- | Doris  | 953679 | 7214083635      | (066) 555-9701 | M51FA04       |
-- | Sofia  | 398010 | 1695452385      | (130) 555-0289 | G412CB7       |
-- | Bruce  | 686048 | 5773159633      | (367) 555-5533 | 94KL13X       |
-- | Edward | 651714 | 1540955065      | (328) 555-1152 | 130LD9Z       |
-- | Kelsey | 560886 | 8294398571      | (499) 555-9472 | 0NTHK55       |
-- | Taylor | 449774 | 1988161715      | (286) 555-6063 | 1106N58       |
-- | Kenny  | 395717 | 9878712108      | (826) 555-1652 | 30G67EN       |
-- | Luca   | 467400 | 8496433585      | (389) 555-5198 | 4328GD8       |
-- +--------+--------+-----------------+----------------+---------------+

-- Persons leaving the first flight out of Fiftyville the day after the theft, matched with the people leaving the bakery 10 min after the theft by comparing the license plate number
SELECT p.name, p.id, p.passport_number, p.phone_number, p.license_plate
FROM people p
JOIN passengers pa ON p.passport_number = pa.passport_number
JOIN flights f ON pa.flight_id = f.id
JOIN airports a ON f.origin_airport_id = a.id
JOIN bakery_security_logs b ON p.license_plate = b.license_plate
WHERE a.city = 'Fiftyville'
AND f.year = 2021
AND f.month = 7
AND f.day = 29
AND f.hour = (SELECT MIN(f2.hour) FROM flights f2 WHERE f2.year = 2021 AND f2.month = 7 AND f2.day = 29)
AND b.year = 2021
AND b.month = 7
AND b.day = 28
AND b.hour = 10
AND b.minute >= 15
AND b.minute <=25;

-- +--------+--------+-----------------+----------------+---------------+
-- |  name  |   id   | passport_number |  phone_number  | license_plate |
-- +--------+--------+-----------------+----------------+---------------+
-- | Sofia  | 398010 | 1695452385      | (130) 555-0289 | G412CB7       |
-- | Bruce  | 686048 | 5773159633      | (367) 555-5533 | 94KL13X       |
-- | Kelsey | 560886 | 8294398571      | (499) 555-9472 | 0NTHK55       |
-- | Luca   | 467400 | 8496433585      | (389) 555-5198 | 4328GD8       |
-- +--------+--------+-----------------+----------------+---------------+


-- Persons leaving the first flight out of Fiftyville the day after the theft, matched with the people leaving the bakery 10 min after the theft by comparing the license plate number. Also includes the subset of persons making a call on the day of the theft for a duration of less than a minute
SELECT p.name, p.id, p.passport_number, p.phone_number, p.license_plate
FROM
    people p
JOIN
    passengers pa ON p.passport_number = pa.passport_number
JOIN
    flights f ON pa.flight_id = f.id
JOIN
    airports a ON f.origin_airport_id = a.id
JOIN
    bakery_security_logs b ON p.license_plate = b.license_plate
JOIN
    phone_calls pc ON p.phone_number = pc.caller
WHERE
    a.city = 'Fiftyville'
    AND f.year = 2021 AND f.month = 7 AND f.day = 29
    AND f.hour = (SELECT MIN(f2.hour) FROM flights f2 WHERE f2.year = 2021 AND f2.month = 7 AND f2.day = 29)

    -- Checking conditions for bakery logs
    AND b.year = 2021 AND b.month = 7 AND b.day = 28
    AND b.hour = 10
    AND b.minute BETWEEN 15 AND 25

    -- Checking conditions for phone calls
    AND pc.year = 2021 AND pc.month = 7 AND pc.day = 28
    AND pc.duration < 60;

