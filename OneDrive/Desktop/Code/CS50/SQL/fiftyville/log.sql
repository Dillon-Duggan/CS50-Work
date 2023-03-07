-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Get a description of the crimes that happened on the 28th of July 2021 on Humphrey Street
SELECT description FROM crime_scene_reports WHERE street = 'Humphrey Street' AND day = 28 AND month = 7 AND year = 2021;

-- Check the transcript of the interviews from the theft date that mention the bakery
SELECT transcript FROM interviews WHERE day = "28" AND month = "7" AND year = "2021" AND transcript LIKE "%bakery%";

-- Based on transcript of the first interview: Find the names of the people who left the bakery within 10 minutes of the theft.
SELECT name FROM people JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate WHERE day = "28" AND month = "7" AND year = "2021" AND hour = "10" AND minute >= "15" AND minute <= "25" AND activity = "exit";

-- Based on transcript of the second interview: Find the names of the people who withdrew money from the ATM on Leggett St on the day of the theft.
SELECT DISTINCT name FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number WHERE day = "28" AND month = "7" AND year = "2021" AND transaction_type = "withdraw" AND atm_location = "Leggett Street";

-- Based on the transcript of the third interview: Find the names of the people who bought the first flight ticket for the day after the theft.
SELECT name FROM people JOIN passengers ON people.passport_number = passengers.passport_number WHERE flight_id = (SELECT id FROM flights WHERE day = "29" AND month = "7" AND year = "2021" ORDER BY hour,minute LIMIT 1);

-- Based on the transcript of the third interview: Find the names of the people who had call for less than a minute on the day of the theft.
SELECT name FROM people JOIN phone_calls ON people.phone_number = phone_calls.caller WHERE day = "28" AND month = "7" AND year = "2021" AND duration < "60";

-- Meet all the conditions to find the thief.
SELECT name FROM people JOIN phone_calls ON people.phone_number = phone_calls.caller WHERE day = "28" AND month = "7" AND year = "2021" AND duration < "60" INTERSECT SELECT name FROM people JOIN passengers ON people.passport_number = passengers.passport_number WHERE flight_id = (SELECT id FROM flights WHERE day = "29" AND month = "7" AND year = "2021" ORDER BY hour,minute LIMIT 1) INTERSECT SELECT DISTINCT name FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number WHERE day = "28" AND month = "7" AND year = "2021" AND transaction_type = "withdraw" AND atm_location = "Leggett Street" INTERSECT SELECT name FROM people JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate WHERE day = "28" AND month = "7" AND year = "2021" AND hour = "10" AND minute >= "15" AND minute <= "25" AND activity = "exit";

-- Based on the transcript of the third interview: Finding the destination of the first flight ticket for the day after the theft.
SELECT city FROM airports WHERE id = (SELECT destination_airport_id FROM flights WHERE day = "29" AND month = "7" AND year = "2021" ORDER BY hour,minute LIMIT 1);

-- Based on the transcript of the third interview: Finding the name of the person whom the thief had call for less than a minute on the day of the theft.
SELECT name FROM people JOIN phone_calls ON people.phone_number = phone_calls.receiver WHERE day = "28" AND month = "7" AND year = "2021" AND duration < "60" AND caller = (SELECT phone_number FROM people WHERE name = "Bruce");

-- Bruce is the thief, and Robin helped him escape to New York City.