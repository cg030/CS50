SELECT * FROM users WHERE username = 'admin';

UPDATE users
SET password = 'oops!'
WHERE id = 1;

-- If I execute this the Trigger will be executed.
-- remove the trigger
-- in user log table change the password of admin to that of emily33's. Do this by changing it in the users table, which will activate the trigger and log.
-- do this in reverse order

-- set the password of the admin to that of 'emily33' which will trigger the change in the user_log table
UPDATE users
SET password = (SELECT password FROM users WHERE username = 'emily33')
WHERE id = 1;

-- if I now try to upate the password of the admin to oops this will execute the trigger again
-- I want a new row to appear in the user_logs table where it looks like the password was changed to emily's
-- this will happen if I update the users table
UPDATE user_logs
SET

