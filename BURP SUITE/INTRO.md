Burp Suite is a framework written in Java that aims to provide a one-stop-shop for web application penetration testing. 

***Most common tools by Burp:***

1) ***Proxy:*** The Burp Proxy allows us to intercept and modify requests/responses when interacting with web applications.
2) ***Repeater:*** This tool allows us to capture, modify, then resend the same request numerous times. This is helpful during attacks like SQL Injection.
3) ***Intruder:*** This tool allows us to spray an endpoint with requests. This is often used for bruteforce attacks or to fuzz endpoints.
4) ***Decoder:*** This tool is mainly used for decoding captured information, or encoding a payload prior to sending it to the target.
5) ***Comparer:*** This tool allows us to compare two pieces of data at either word or byte level.
6) ***Sequencer:*** This tool is used when assessing the randomness of tokens such as session cookie values or other supposedly random generated data. 