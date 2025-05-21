- **_`arp-scan -l`_:** This command is used to list all the devices on the network, along with their IP addresses and MAC addresses.

![[Pasted image 20241122160051.png]]

**NOTE:** **NetDiscover** can also be used to list all the machines on the specified network. 

**SYNTAX**: **_`netdiscover -r <IP range>`_**
***
## Types of Nmap Scans:

1) **_Stealth Scan_:** **_`-sS`_** flag is used to run a stealth scan which does not complete the 3-way handshake.

2) **_Full Scan_:** **_`-A`_** flag is used to perform a complete scan including version detection, OS detection, and banner grabbing. 

3) **_Ping Scan_:** **_`-sn`_** flag is used to perform a ping scan or a network sweep to detect active targets within the network.

4) **_TCP Connect Scan_:** **_`-sT`_** flag is used to perform a TCP connect scan which performs a full 3-way handshake before scanning.

5) **_UDP Scan_:** **_`-sU`_** flag is used to perform a UDP scan, which is a connection-less scan or does not perform a 3-way handshake. 

**NOTE:** The **_`-A`_** switch is used for an **ALL SCAN**, which runs version detection, OS detection, script scan, etc. ALL SCAN is generally considered very slow compared to manually mentioning various scan switches.
***
## Web Application Vulnerability Scanning using Nikto:

**SYNTAX**: **_`nikto -h <target URL>`_**

**NOTE:** If a web application firewall is used for the target web application, then a Nikto scan can be easily detected since it is very noisy.
***
## Web Directory Brute Forcing:

- **_DirBuster_:** This is a directory brute forcing tool, with a GUI.

**SYNTAX** -- **_`dirbuster`_** 
***
## Enumerating SMB Service:

==_**``smbclient -L \\\\<target ip>\\``**_== -- **This command is used to list shares within an SMB fileshare**

==**_`smbclient \\\\<target ip>\\<share name>`_**== -- **This command is used to connect to an SMB share**.
***
## Vulnerability Scanning with Nessus:

Initially, run ==**_`/bin/systemctl start nessusd.service`_**== to start the Nessus service and then navigate to ==**_`https://localhost:8834`_**== to access the scanner web interface.

===**NESSUS ACTIVATION CODE:** _Activation Code: UJ7D-8WXW-S46G-URA3-G7GT_===

### Basic Network Scan using Nessus:

- Click on **_New Scan_** and then select **_Basic  Network Scan_**. Then enter the **_Name_**, **_Description_**, and **_Target IP address_**.

- Next, under the **_Discovery_** section, select the type of scan to be performed. Further, under **_Assessment_** section, select the type of vulnerability scan to be carried out. 

- Next, under the **_Advanced_** section, select **_Performance Options_** and then save the scan setup. Finally, launch the scan.


### Understanding Nessus Scan Results:

- To view the scan results, click on the created scan. The results are segregated findings based on the severity of the vulnerability. 

- The scan results give you the plugin used to check this vulnerability, along with the CVE, if the discovered vulnerability has one.
***
