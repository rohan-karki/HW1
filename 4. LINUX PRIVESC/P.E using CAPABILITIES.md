Linux Capabilities allow users and processes to be granted specific access to resources without providing full root access.

Linux Capabilities are used to allow a process or a program to be run as root, while not providing full root access.

**NOTE:** Run **_`getcap -r / 2>/dev/null`_** to list all the Capabilities within a Linux system.

**Example:** Consider an example where you run **_`getcap -r / 2>/dev/null`_** and find that **_/usr/bin/python2.6 = cap_setuid+ep_** is a capability.

- This means that **_python2.6_** can run any program as root since it has a **setuid** bit with **_ep_** as permit everything.

- To escalate current shell into a root shell, run 
**_`/usr/bin/python2.6 -c 'import os; os.setuid(0); os.system("/bin/bash")'`_**

Here, _**`python2.6`**_ will import the **_`os`_** function and set privileges to root using the **_`os.setuid(0)`_** part and then run **_`/bin/bash`_** to spawn a bash root shell. 
***
