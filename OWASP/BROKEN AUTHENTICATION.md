The most common form of authentication is using a username and password mechanism. 

If they are correct, the server would then provide the users’ browser with a session cookie. A session cookie is needed because web servers use HTTP(S) to communicate which is stateless.

***The most common authentication attacks are:***

1) Brute Force attacks
2) Common password guessing
3) Stealing session cookies to access user accounts
4) SQL Injection: Enter SQL querries in the username and password input section to login onto a user's account

***Steps to mitigate authentication attacks:***

1) Usage of a strong password policy
2) To avoid brute force attacks, ensure the application enforces an automatic lockout after a certain number of attempts
3) Implement Multi-Factor authentication

***
# SQL Injection for authentication:

You can use `' or 1=1 --` to bypass login authentication. Enter the SQL string in the username and password section to bypass authentication.

