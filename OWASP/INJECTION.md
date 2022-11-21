Here user controlled input is interpreted as actual commands or parameters by the application. 

***There are two types of injection methods:***

1) ***SQL Injection:*** This occurs when user controlled input is passed to SQL queries. An attacker can pass in SQL queries to manipulate the outcome of such queries.
2) ***Command Injection:*** This occurs when user input is passed to system commands. An attacker is able to execute arbitrary system commands on application servers.

***With the help of these injection attacks:***

1) Access, Modify and Delete information in a database when this input is passed into database queries.
2) Execute Arbitrary system commands on a server that would allow an attacker to gain access to users’ systems.

**NOTE:** The main defence for preventing injection attacks is ensuring that user controlled input is not interpreted as queries or commands.

This can be done in multiple ways:

1) ***Using a safe list:*** When input is sent to the server, this input is compared to a list of safe input or characters. If the input is marked as safe, then it is processed. Otherwise, it is rejected and the application throws an error.
2) ***Stripping Input:*** If the input contains dangerous characters, these characters are removed before they are processed.

***
# OS Command Injection:
Command Injection occurs when server-side code (like PHP) in a web application makes a system call on the hosting machine. 
It is a web vulnerability that allows an attacker to take advantage of that made system call to execute operating system commands on the server.

**NOTE:** You can execute a simple NetCat shell command to get a reverse shell using `nc -e /bin/bash`

***
# SQL Injection:

**There are 3 types of SQL Injection:**

1) ***In-Band SQL Injection:*** This type of attack includes discovering an SQL Injection vulnerability on a website page and then being able to extract data from the database to the same page.
2) ***Error-Based SQL Injection:*** This type of SQL Injection is the most useful for easily obtaining information about the database structure as error messages from the database are printed directly to the browser screen.
3) ***Union-Based SQL Injection:*** This type of Injection utilises the SQL UNION operator alongside a SELECT statement to return additional results to the page.

