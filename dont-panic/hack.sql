SELECT * FROM users WHERE username = 'admin';

UPDATE users
SET password = 'oops!'
WHERE id = 1;

-- If I execute this the Trigger will be executed.
-- remove the trigger
-- 