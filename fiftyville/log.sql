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



-- Persons leaving the first flight out of Fiftyville the day after the theft, matched with the people leaving the bakery 10 min after the theft by comparing the license plate number. Also includes the subset of persons making a call on the day of the theft for a duration of less than a minute
SELECT p.name, p.id, p.passport_number, p.phone_number, p.license_plate, f.destination_airport_id
FROM
    people p
JOIN
    passengers pa ON p.passport_number = pa.passport_number
JOIN
    flights f ON pa.flight_id = f.id
JOIN
    airports a ON f.origin_airport_id = a.id
JOIN
    phone_calls pc ON p.phone_number = pc.caller
JOIN
    bakery_security_logs b ON p.license_plate = b.license_plate
JOIN
    bank_accounts ba ON p.id = ba.person_id
JOIN
    atm_transactions atm ON atm.account_number = ba.account_number
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
    AND pc.duration < 60

    -- Checking conditions for atm_withdrawal
    AND  atm.year = 2021 AND atm.month = 7 AND atm.day = 28
    AND atm.atm_location = 'Leggett Street'
    AND atm.transaction_type = 'withdraw';

-- +-------+--------+-----------------+----------------+---------------+
-- | name  |   id   | passport_number |  phone_number  | license_plate |
-- +-------+--------+-----------------+----------------+---------------+
-- | Bruce | 686048 | 5773159633      | (367) 555-5533 | 94KL13X       |
-- +-------+--------+-----------------+----------------+---------------+

-- people who received a call lasting less than a minute

SELECT p.name, p.phone_number
FROM people p
JOIN phone_calls pc ON p.phone_number = pc.receiver
WHERE pc.year = 2021 AND pc.month = 7 AND pc.day = 28
AND pc.duration < 60
AND pc.caller = '(367) 555-5533';

-- +-------+----------------+
-- | name  |  phone_number  |
-- +-------+----------------+
-- | Robin | (375) 555-8161 |
-- +-------+----------------+


SELECT city
FROM airports
WHERE id = 4;