SELECT * FROM users WHERE username = 'admin';

UPDATE users
SET password = 'oops!'
WHERE id = 1;

-- If I execute this the Trigger will be executed.
-- remove the trigger
-- in user log table change the password of admin to that of emily33's. Do this by changing it in the users table, which will activate the trigger and log 