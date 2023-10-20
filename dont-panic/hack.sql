-- First change the password to oops in the users table, which will create a log
UPDATE users
SET password = '982c0381c279d139fd221fce974916e7'
WHERE id = 1;

-- update this log to appear as if the password was change to emily's password
-- set the password of the admin to that of 'emily33' which will trigger the change in the user_log table
UPDATE user_logs
SET password = (SELECT password FROM users WHERE username = 'emily33')
WHERE old_username = admin;

