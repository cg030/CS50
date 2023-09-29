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


SELECT *
FROM bakery_security_logs
WHERE year = 2021
AND month = 7
AND day = 28
AND hour = 10
AND minute >= 15;

-- | id  | year | month | day | hour | minute | activity | license_plate |
-- +-----+------+-------+-----+------+--------+----------+---------------+
-- | 260 | 2021 | 7     | 28  | 10   | 16     | exit     | 5P2BI95       |
-- | 261 | 2021 | 7     | 28  | 10   | 18     | exit     | 94KL13X       |
-- | 262 | 2021 | 7     | 28  | 10   | 18     | exit     | 6P58WS2       |
-- | 263 | 2021 | 7     | 28  | 10   | 19     | exit     | 4328GD8       |
-- | 264 | 2021 | 7     | 28  | 10   | 20     | exit     | G412CB7       |
-- | 265 | 2021 | 7     | 28  | 10   | 21     | exit     | L93JTIZ       |
-- | 266 | 2021 | 7     | 28  | 10   | 23     | exit     | 322W7JE       |
-- | 267 | 2021 | 7     | 28  | 10   | 23     | exit     | 0NTHK55

SELECT *
FROM atm_transactions
WHERE year = 2021
AND month = 7
AND day = 28
AND atm_location = 'Leggett Street'
AND transaction_type = 'withdraw';

-- | id  | account_number | year | month | day |  atm_location  | transaction_type | amount |
-- +-----+----------------+------+-------+-----+----------------+------------------+--------+
-- | 246 | 28500762       | 2021 | 7     | 28  | Leggett Street | withdraw         | 48     |
-- | 264 | 28296815       | 2021 | 7     | 28  | Leggett Street | withdraw         | 20     |
-- | 266 | 76054385       | 2021 | 7     | 28  | Leggett Street | withdraw         | 60     |
-- | 267 | 49610011       | 2021 | 7     | 28  | Leggett Street | withdraw         | 50     |
-- | 269 | 16153065       | 2021 | 7     | 28  | Leggett Street | withdraw         | 80     |
-- | 288 | 25506511       | 2021 | 7     | 28  | Leggett Street | withdraw         | 20     |
-- | 313 | 81061156       | 2021 | 7     | 28  | Leggett Street | withdraw         | 30     |
-- | 336 | 26013199       | 2021 | 7     | 28  | Leggett Street | withdraw         | 35


SELECT *
FROM phone_calls
WHERE year = 2021
AND month = 7
AND day = 28
AND duration < 60;

-- | id  |     caller     |    receiver    | year | month | day | duration |
-- +-----+----------------+----------------+------+-------+-----+----------+
-- | 221 | (130) 555-0289 | (996) 555-8899 | 2021 | 7     | 28  | 51       |
-- | 224 | (499) 555-9472 | (892) 555-8872 | 2021 | 7     | 28  | 36       |
-- | 233 | (367) 555-5533 | (375) 555-8161 | 2021 | 7     | 28  | 45       |
-- | 251 | (499) 555-9472 | (717) 555-1342 | 2021 | 7     | 28  | 50       |
-- | 254 | (286) 555-6063 | (676) 555-6554 | 2021 | 7     | 28  | 43       |
-- | 255 | (770) 555-1861 | (725) 555-3243 | 2021 | 7     | 28  | 49       |
-- | 261 | (031) 555-6622 | (910) 555-3251 | 2021 | 7     | 28  | 38       |
-- | 279 | (826) 555-1652 | (066) 555-9701 | 2021 | 7     | 28  | 55       |
-- | 281 | (338) 555-6650 | (704) 555-2131 | 2021 | 7     | 28  | 54


SELECT *
FROM flights f
JOIN airports a ON f.origin_airport_id = a.id
WHERE a.city = 'Fiftyville'
AND year = 2021
AND month = 7
AND day = 29
ORDER BY f.hour ASC
LIMIT 1;

-- +----+-------------------+------------------------+------+-------+-----+------+--------+----+--------------+-----------------------------+------------+
-- | id | origin_airport_id | destination_airport_id | year | month | day | hour | minute | id | abbreviation |          full_name          |    city    |
-- +----+-------------------+------------------------+------+-------+-----+------+--------+----+--------------+-----------------------------+------------+
-- | 36 | 8                 | 4                      | 2021 | 7     | 29  | 8    | 20     | 8  | CSF          | Fiftyville Regional Airport | Fiftyville |
-- +----+-------------------+------------------------+------+-------+-----+------+--------+----+--------------+-----------------------------+------------+

SELECT *
FROM passengers
WHERE flight_id = 36;

-- Table of all the passengers on flight 36, the earliest flight on the 29.07.

-- +-----------+-----------------+------+
-- | flight_id | passport_number | seat |
-- +-----------+-----------------+------+
-- | 36        | 7214083635      | 2A   |
-- | 36        | 1695452385      | 3B   |
-- | 36        | 5773159633      | 4A   |
-- | 36        | 1540955065      | 5C   |
-- | 36        | 8294398571      | 6C   |
-- | 36        | 1988161715      | 6D   |
-- | 36        | 9878712108      | 7A   |
-- | 36        | 8496433585      | 7B   |
-- +-----------+-----------------+------+

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
FROM
(
    SELECT *
    FROM people p
    JOIN bank_accounts b ON p.id = b.person_id
    JOIN passengers pa ON p.passport_number = pa.passport_number
    WHERE pa.flight_id = 36
) as flight_passengers
JOIN
(
    SELECT *
    FROM bakery_security_logs
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND hour = 10
    AND minute >= 15
) as security_logs
ON flight_passengers.license_plate = security_logs.license_plate
JOIN
(
    SELECT *
FROM atm_transactions
WHERE year = 2021
AND month = 7
AND day = 28
AND atm_location = 'Leggett Street'
AND transaction_type = 'withdraw'
) as atm_withdraw
ON flight_passengers.account_number = atm_withdraw.account_number

+--------+--------+----------------+-----------------+---------------+----------------+-----------+---------------+-----------+-------------------+------+-----+------+-------+-----+------+--------+----------+---------------+
|   id   |  name  |  phone_number  | passport_number | license_plate | account_number | person_id | creation_year | flight_id | passport_number:1 | seat | id  | year | month | day | hour | minute | activity | license_plate |
+--------+--------+----------------+-----------------+---------------+----------------+-----------+---------------+-----------+-------------------+------+-----+------+-------+-----+------+--------+----------+---------------+
| 686048 | Bruce  | (367) 555-5533 | 5773159633      | 94KL13X       | 49610011       | 686048    | 2010          | 36        | 5773159633        | 4A   | 261 | 2021 | 7     | 28  | 10   | 18     | exit     | 94KL13X       |
| 467400 | Luca   | (389) 555-5198 | 8496433585      | 4328GD8       | 28500762       | 467400    | 2014          | 36        | 8496433585        | 7B   | 263 | 2021 | 7     | 28  | 10   | 19     | exit     | 4328GD8       |
| 449774 | Taylor | (286) 555-6063 | 1988161715      | 1106N58       | 76054385       | 449774    | 2015          | 36        | 1988161715        | 6D   | 268 | 2021 | 7     | 28  | 10   | 35     | exit     | 1106N58       |
+--------+--------+----------------+-----------------+---------------+----------------+-----------+---------------+-----------+-------------------+------+-----+------+-------+-----+------+--------+----------+---------------+


