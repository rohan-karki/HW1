In Linux, Scheduled Tasks are known as **_cron jobs_**. The scheduled tasks can be viewed at **_`/etc/crontab`_**.

**NOTE:** Within the **_`/etc/crontab`_** file, both **_SHELL_** and **_PATH_** variables are mentioned. 

***
## Escalation via Cron Paths:

- Within the **_`/etc/crontab`_** file, sometimes certain binaries or shell scripts are set to run every minute as root. These files are searched by the **_`/etc/crontab`_** within the PATH mentioned in the crontab file. 

- If an executable is set to be executed as root every minute and there is a folder which is writable by the current user within the **_$PATH_**, then a file with the specified filename can be created with a malicious code as its contents. 

- The following code can be entered as contents for the malicious file: **_`echo 'cp /bin/bash /tmp/bash; chmod +s /tmp/bash' > maliciousfile.sh`_**

- Once the malicious file has been executed by root as per the **_crontab_**, when the **_`/tmp/bash`_** is run a root shell is spawned.

***
