Broken Access Control is basically a vulnerability which allows unauthorized users to access information which is owned and accessed by root. 

This vulernability allows the attacker to:
- View sensitive information
- Access unauthorized functionality
***
# Insecure Direct Object Reference (IDOR):

It is the act of exploiting a misconfiguration in the way user input is handled, to access resources you wouldn't ordinarily be able to access. 

Here you can login to a website which and then change the URL parameters that specify a particular account such as `id=1` to `id=0`, `id=2`, etc. and check whether you can access other user's account. 
If this is possible then the web application is vulnerable to **IDOR**, which is indirectly vulnerable to **Broken Access Control**.
