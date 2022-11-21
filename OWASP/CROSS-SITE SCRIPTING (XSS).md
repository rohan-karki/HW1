It’s a type of injection which can allow an attacker to execute malicious scripts and have it execute on a victim’s machine. 

**A web application is vulnerable to XSS if it uses unsanitized user input**. 
***XSS is possible in Javascript, VBScript, Flash and CSS***.

There are 3 types of XSS:

1) ***Stored XSS:*** This often happens when a website allows user input that is not sanitised (remove the "bad parts" of a users input) when inserted into the database.
2) ***Reflected XSS:*** In this the malicious payload is part of the victims request to the website. The website includes this payload in response back to the user.
3) ***DOM-Based XSS:*** DOM stands for ***Document Object Model***. It represents the page so that programs can change the document structure, style and content. 

***
# XSS Payloads:

These are some common payloads which can be used to exploit XSS:

1) ***Pop-ups:*** `<script>alert(“Hello World”)</script>` -- Creates a **Hello World message popup** on a users browser.
2) ***Writing HTML:*** `document.write` -- Override the website's HTML to add your own
3) ***XSS Keylogger:*** 
`http://www.xss-payloads.com/payloads/scripts/simplekeylogger.js.html` -- You can log all keystrokes of a user, capturing their password and other sensitive information they type into the webpage
4) ***Port Scanning:*** 
`http://www.xss-payloads.com/payloads/scripts/portscanapi.js.html` -- A mini local port scanner

**NOTE:**  **XSS-Payloads.com** http://www.xss-payloads.com/ is a website that has XSS related Payloads, Tools, Documentation and more.

