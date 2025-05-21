- **_Assetfinder_** is a tool used to perform subdomain enumeration.

**SYNTAX:** **_`assetfinder --subs-only <target domain>`_**

- **_Amass_** is another tool used to perform subdomain enumeration.

**SYNTAX:** **_`amass enum -d <domain name>`_**

### Finding Alive Domains using `httprobe`:

To check if a list of domains are alive and running, run:

**_`cat <file containing a list of domains>.txt | httprobe`_**

![[Pasted image 20250211234951.png]]

This will send out an **HTTP** and **HTTPS** request to all the domains within the file to check if any of them respond back to the request. 

**NOTE:** To extract the list of domains that are alive and running based on the output given by **_`httprobe`_**, run

**_`cat domains.txt | httprobe | sed 's/http\?:\/\///' | sed 's/https\?:\/\///'`_**

***
