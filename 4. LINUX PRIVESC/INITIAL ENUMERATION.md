**Best online resources for Linux Privilege Escalation:**

- https://swisskyrepo.github.io/InternalAllTheThings/redteam/escalation/linux-privilege-escalation/

- https://viperone.gitbook.io/pentest-everything/everything/everything-linux/privilege-escalation-checklist

- https://book.hacktricks.xyz/linux-hardening/linux-privilege-escalation-checklist

- https://github.com/TCM-Course-Resources/Linux-Privilege-Escalation-Resources

## System Enumeration:

- ==_**`uname -a`**_== : This command is used to display the Kernel information.

- ==_**`lscpu`**_== : This command will display the architecture information.

- ==_**`ps aux`**_== : This command lists all the services that are running

***
## User Enumeration:

- ==_**`id`**_== : This command shows the group information for the current running user.

- ==_**`sudo -l`**_== : This command displays information about what the user can run as sudoer/root.

- ==_**`/etc/passwd`**_== : This file contains the list of users and their shell type within the system.

***
## Network Enumeration:

- ==_**`ip a`**_== : This command displays the network details for different network adapters within a system.

- ==_**`ip route`**_== : This command displays any type of network route that the current machine has to any other network.

- ==_**`ip neigh`**_== : This command lists the devices within the network along with their IP address and current state, either reachable or stale.

- ==_**`netstat -ano`**_== : This command lists active connections for the machine along with detailed overview of services and connections to other devices.
***
## Password Hunting:

- ==_**`grep --color=auto -rnw '/' -ie "PASSWORD" --color=always 2>/dev/null`**_== : This command will perform a search within the entire system for the word "PASSWORD" and will display the output with PASSWORD highlighted in color Red.

- ==_**`find / -name id_rsa 2>/dev/null`**_== : This command searches for a file named **_id_rsa_**.

***
