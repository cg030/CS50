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

SELECT p.id, p.passport_number, b.account_number, p.phone_number, p.license_plate
FROM people p
JOIN passengers pa ON p.passport_number = pa.passport_number
JOIN bank_accounts b ON p.id = b.person_id
JOIN flights f ON p.flight_id = f.id
JOIN airports a ON f.origin_airport_id = a.id
WHERE a.city = 'Fiftyville'
AND f.year = 2021
AND f.month = 7
AND f.day = 29
AND f.hour = (SELECT MIN(f2.hour) FROM flights f2 WHERE f2.year = 2021 AND f2.month = 7 AND f2.day = 29);



SELECT *
FROM people p
JOIN bank_accounts b ON p.id = b.person_id
JOIN passengers pa ON p.passport_number = pa.passport_number
WHERE pa.flight_id = 36;

-- Inner join of passengers on the flight (id=36) and people in the people table

-- +--------+--------+----------------+-----------------+---------------+----------------+-----------+---------------+-----------+-----------------+------+
-- |   id   |  name  |  phone_number  | passport_number | license_plate | account_number | person_id | creation_year | flight_id | passport_number | seat |
-- +--------+--------+----------------+-----------------+---------------+----------------+-----------+---------------+-----------+-----------------+------+
-- | 686048 | Bruce  | (367) 555-5533 | 5773159633      | 94KL13X       | 49610011       | 686048    | 2010          | 36        | 5773159633      | 4A   |
-- | 395717 | Kenny  | (826) 555-1652 | 9878712108      | 30G67EN       | 28296815       | 395717    | 2014          | 36        | 9878712108      | 7A   |
-- | 467400 | Luca   | (389) 555-5198 | 8496433585      | 4328GD8       | 28500762       | 467400    | 2014          | 36        | 8496433585      | 7B   |
-- | 449774 | Taylor | (286) 555-6063 | 1988161715      | 1106N58       | 76054385       | 449774    | 2015          | 36        | 1988161715      | 6D   |
-- +--------+--------+----------------+-----------------+---------------+----------------+-----------+---------------+-----------+-----------------+------+

-- Compare the people from this table with the people captured by the security camera by comparing the liscensce plate number
-- These people drove away from the bakery parking lot within 10 minutes of the robbery and were on the first flight the next day

SELECT *
FROM (
    SELECT *
    FROM people p
    JOIN bank_accounts b ON p.id = b.person_id
    JOIN passengers pa ON p.passport_number = pa.passport_number
    WHERE pa.flight_id = 36
) AS flight_passengers

JOIN (
    SELECT *
    FROM bakery_security_logs
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND hour = 10
    AND minute >= 15
) AS security_logs ON flight_passengers.license_plate = security_logs.license_plate

JOIN (
    SELECT *
    FROM atm_transactions
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND atm_location = 'Leggett Street'
    AND transaction_type = 'withdraw'
) AS atm_withdraw ON flight_passengers.account_number = atm_withdraw.account_number

JOIN (
    SELECT *
    FROM phone_calls
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND duration < 60
) AS phone_call ON flight_passengers.phone_number = phone_call.caller

-- The people in the following table are left the bakery after the theft within 10 min, were on the earliest flight the next morning, and withdrew money from the atm before the theft.

-- +--------+--------+----------------+-----------------+---------------+----------------+-----------+---------------+-----------+-------------------+------+-----+------+-------+-----+------+--------+----------+---------------+-----+----------------+------+-------+-----+----------------+------------------+--------+
-- |   id   |  name  |  phone_number  | passport_number | license_plate | account_number | person_id | creation_year | flight_id | passport_number:1 | seat | id  | year | month | day | hour | minute | activity | license_plate | id  | account_number | year | month | day |  atm_location  | transaction_type | amount |
-- +--------+--------+----------------+-----------------+---------------+----------------+-----------+---------------+-----------+-------------------+------+-----+------+-------+-----+------+--------+----------+---------------+-----+----------------+------+-------+-----+----------------+------------------+--------+
-- | 686048 | Bruce  | (367) 555-5533 | 5773159633      | 94KL13X       | 49610011       | 686048    | 2010          | 36        | 5773159633        | 4A   | 261 | 2021 | 7     | 28  | 10   | 18     | exit     | 94KL13X       | 267 | 49610011       | 2021 | 7     | 28  | Leggett Street | withdraw         | 50     |
-- | 467400 | Luca   | (389) 555-5198 | 8496433585      | 4328GD8       | 28500762       | 467400    | 2014          | 36        | 8496433585        | 7B   | 263 | 2021 | 7     | 28  | 10   | 19     | exit     | 4328GD8       | 246 | 28500762       | 2021 | 7     | 28  | Leggett Street | withdraw         | 48     |
-- | 449774 | Taylor | (286) 555-6063 | 1988161715      | 1106N58       | 76054385       | 449774    | 2015          | 36        | 1988161715        | 6D   | 268 | 2021 | 7     | 28  | 10   | 35     | exit     | 1106N58       | 266 | 76054385       | 2021 | 7     | 28  | Leggett Street | withdraw         | 60     |
-- +--------+--------+----------------+-----------------+---------------+----------------+-----------+---------------+-----------+-------------------+------+-----+------+-------+-----+------+--------+----------+---------------+-----+----------------+------+-------+-----+----------------+------------------+--------+


+--------+--------+----------------+-----------------+---------------+----------------+-----------+---------------+-----------+-------------------+------+-----+------+-------+-----+------+--------+----------+---------------+-----+----------------+------+-------+-----+----------------+------------------+--------+-----+----------------+----------------+------+-------+-----+----------+
|   id   |  name  |  phone_number  | passport_number | license_plate | account_number | person_id | creation_year | flight_id | passport_number:1 | seat | id  | year | month | day | hour | minute | activity | license_plate | id  | account_number | year | month | day |  atm_location  | transaction_type | amount | id  |     caller     |    receiver    | year | month | day | duration |
+--------+--------+----------------+-----------------+---------------+----------------+-----------+---------------+-----------+-------------------+------+-----+------+-------+-----+------+--------+----------+---------------+-----+----------------+------+-------+-----+----------------+------------------+--------+-----+----------------+----------------+------+-------+-----+----------+
| 686048 | Bruce  | (367) 555-5533 | 5773159633      | 94KL13X       | 49610011       | 686048    | 2010          | 36        | 5773159633        | 4A   | 261 | 2021 | 7     | 28  | 10   | 18     | exit     | 94KL13X       | 267 | 49610011       | 2021 | 7     | 28  | Leggett Street | withdraw         | 50     | 233 | (367) 555-5533 | (375) 555-8161 | 2021 | 7     | 28  | 45       |
| 449774 | Taylor | (286) 555-6063 | 1988161715      | 1106N58       | 76054385       | 449774    | 2015          | 36        | 1988161715        | 6D   | 268 | 2021 | 7     | 28  | 10   | 35     | exit     | 1106N58       | 266 | 76054385       | 2021 | 7     | 28  | Leggett Street | withdraw         | 60     | 254 | (286) 555-6063 | (676) 555-6554 | 2021 | 7     | 28  | 43       |
+--------+--------+----------------+-----------------+---------------+----------------+-----------+---------------+-----------+-------------------+------+-----+------+-------+-----+------+--------+----------+---------------+-----+----------------+------+-------+-----+----------------+------------------+--------+-----+----------------+----------------+------+-------+-----+----------+