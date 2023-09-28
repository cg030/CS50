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