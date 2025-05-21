**XSS** is a vulnerability that allows an attacker to compromise the interactions that users have with a vulnerable application. 

It allows the attacker to circumvent the same origin policy, which is designed to segregate different websites from each other. 

XXS vulnerability can be confirmed by injecting a payload that causes the browser to execute some arbitrary JS. The most common payload that can be used is:

**_`alert(1)`_** -- This can be executed in the browser's console located within the developer tools.
Some modern browsers may block the **_`alert()`_** JS function in specific locations, which is why an alternative like **_`print()`_** is used which will pop up the browser print dialog.

**NOTE**: XSS vulnerabilities are solely executed on the client-side. Thus, only the user executing the vulnerability is affected.
***
## Stored XSS:

This type occurs when user input is stored on the back-end database and then displayed upon retrieval. This type of XSS is persistent and may affect any user that visits the page.

- To test the presence of stored XSS, enter the below mentioned payload within any customer input field and then refresh the page:
**_`<script>print(window.origin)</script>`_**

- Upon refreshing the page, the alert should pop up with the URL of the page it is being executed on. Further, view the page source and if you see your payload in the page's source code, then this determines the XSS type as **stored**.

- Another way to check if the XSS present is of stored type is to refresh the page and if you see the pop up again then this proves that the XSS present is of Stored type.

![[Pasted image 20250415150820.png]]
***
## Reflected XSS:

In a Reflected XSS vulnerability, our input reaches the back-end server and gets returned to us without being filtered or sanitized. 

The user input is usually returned through error messages and confirmation messages. 

- Initially, enter a test string within the user input field and look for any error or confirmation messages in the response.

- Once you confirm an error or confirmation message within the response, replace the test string with **_`<script>alert(window.origin)</script>`_** and then submit/send the input to the server. You should see a pop-up displaying the URL of the web page.

**NOTE:** If the **_`alert()`_** parameter gets blocked, then try with **_`print()`_**. 

You can confirm whether the error message includes the XSS payload by viewing the page source.

**NOTE:** If you visit the page again, the error message no longer appears and the XSS payload is not executed. This confirms the XSS vulnerability to be **Non-Persistent**.

- To use this vulnerability to target victims is to inspect the type of HTTP request used to send the input to the server. This can be done by accessing the **Developer Tools** of the browser and navigating to the **_Network_** tab. Then, enter the test input within the input section of the application and send it to the server. 
![[Pasted image 20250418013116.png]]


- The **_Network_** section shows the request used to send the test input to the server is a **_GET_** request. 

**_GET_** request sends their parameters and data as part of the URL. So, to target a user, send them a URL containing the XSS payload. The URL of the **_GET_** request can be extracted from the **_Network_** tab of the developer tools, by right clicking on the **_GET_** request.

![[Pasted image 20250418014512.png]]
***
## DOM XSS:

**DOM XSS** is completely processed on the client-side through JavaScript. DOM XSS occurs when JavaScript is used to change the page source through the **Document Object Model**.

In a DOM-based XSS:
- No HTTP requests are being made to send the user input to the backend server.
- The input parameter in the URL is using a **`#`** for the user input. This means it is a client-side parameter that is completely processed on the browser.
- The user input is processed at the client-side through JavaScript and never reaches the back-end.
- The user input cannot be found in the page source once the input has been submitted as the JavaScript code updates the page source back to default.

**NOTE:** To view the rendered page source after submitting the user input, open Web Developer tools and navigate to **_Inspecter_** tool.
![[Pasted image 20250429203913.png]]

#### **Source** & **Sink**:

**_Source_** is the JavaScript object that takes the user input. The input can be any parameter, either a URL parameter or an input field.

**_Sink_** is the function that writes the user input to a DOM Object on the page. If the **_Sink_** function does not properly sanitize the user input, it would be vulnerable to an XSS attack. 

Some of the commonly used JavaScript functions to write to DOM objects are:

-  **_`document.write()`_**
- **_`DOM.innerHTMl`_**
- **_`DOM.outerHTML`_**

Some of the **_jQuery_** library functions that write to DOM objects are:

- **_`add()`_**
- **_`after()`_**
- **_`append()`_**

