This is when a web application divulges sensitive data such as customer information, usernames and passwords. 
This mainly happens in databases which store information, such as MySQL or MariaDB. 

These databases are known as ***flat-file*** databases as they are stored as a single of on a system. **This would be a problem if the database file is stored under the root directory of a web application.** If so, we can download this file by compromising the web application, and then query this database on our own system to extract the information within the database.

We can use `sqlite3` and `mysql` to query with ***sqlite*** and ***MySQL*** databases.
***
# Interacting with SQLite database:

Once we download an SQLite database file, we can run `sqlite3 <database_name>` to access it. 
Once we start interacting with the database, to view the ***tables*** within a database, we can run `.tables` 

Now to view what information is stored within the table, we can run `PRAGMA table_info(<table_name>);`
And to dump all the information present within this table, we run `SELECT * FROM <table_name>;`

**NOTE:** This database may contain usernames, password hashes, credit card details, etc. which can be used to login to the target system.

