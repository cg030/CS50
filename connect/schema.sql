CREATE TABLE users (
    id INTEGER,
    first_name TEXT,
    last_name TEXT,
    username TEXT,
    password TEXT,
    PRIMARY KEY(id)
);

CREATE TABLE schools (
    id INTEGER,
    name TEXT,
    type TEXT,
    location TEXT,
    founding_year INTEGER,
    PRIMARY KEY(id)
);

CREATE TABLE companies (
    id INTEGER,
    name TEXT,
    industry TEXT,
    location TEXT,
    PRIMARY KEY(id)
);

CREATE TABLE user_connections (
    user_id1 INTEGER,
    user_id2 INTEGER,
    PRIMARY KEY(user_id1, user_id2),
    FOREIGN KEY(user_id1) REFERENCES users(id),
    FOREIGN KEY(user_id2) REFERENCES users(id)
);

CREATE TABLE company_connections (
    user_id INTEGER,
    company_id INTEGER,
    PRIMARY KEY(user_id, company_id),
    FOREIGN KEY(user_id) REFERENCES users(id),
    FOREIGN KEY(company_id) REFERENCES companies(id)
);

CREATE TABLE school_connections (
    user_id INTEGER,
    school_id INTEGER,
    PRIMARY KEY(user_id, school_id),
    FOREIGN KEY(user_id) REFERENCES users(id),
    FOREIGN KEY(school_id) REFERENCES schools(id)
);

