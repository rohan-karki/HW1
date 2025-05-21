Active Directory is composed of both physical and logical components.

### PHYSICAL COMPONENTS:

- **Domain Controller:** This is a server with the AD DS (Active Directory Domain Services) server role installed that has specifically been promoted to a domain controller. 

	Domain Controllers:
	- Host a copy of the AD DS directory store
	- Provide authentication and authorization services
	- Replicate updates to other domain controllers in the domain and forest
	- Allow administrative access to manage user accounts and network resources

- **AD DS Data Store:** This store contains the database files and processes that store and manage directory information for users, services, and applications.

	AD DS data store:
	- Consists of the **_Ntds.dit_** file
	- Is stored by default in the **_%SystemRoot%\NTDS_** folder on all domain controllers
	- Is accessible only through the domain controller processes and protocols
***
### LOGICAL COMPONENTS:

- **AD DA Schema:** This defines every type of object that can be stored in the directory. It also enforces rules regarding object creation and configuration. 
![[Pasted image 20250117022754.png]]

- **Domain:** Domains are used to group and manage objects in an organization.

	- A domain is an administrative boundary for applying policies to groups of objects
	- A domain is also a replication boundary for replicating data between domain controllers
	- It is also an authentication & authorization boundary that provides a way to limit the scope of access to resources

- **Tree:** A domain tree is a hierarchy of domains in AD DS.

	All domains in the tree:
	- Share a contiguous namespace with the parent domain
	- Can have additional child domains
	- By default create a two-way transitive trust with other domains

- **Forest:** A forest is a collection of one or more domain trees.

	Forests:
	- Share a common schema
	- Share a common configuration partition
	- Share a common global catalog to enable searching
	- Enable trusts between all domains in the forest
	- Share the Enterprise Admins & Schema Admins groups

- **Organizational Units (OUs):** OUs are Active Directory containers that can contain users, groups, computers, and other OUs.

	OUs are used to:
	- Represent organization hierarchically and logically
	- Manage a collection of objects in a consistent way
	- Delegate permissions to administer groups of objects
	- Apply policies

- **Trusts:** Trusts provide a mechanism for users to gain access to resources in another domain.
![[Pasted image 20250119204516.png]]

All domains in a forest trust all other domains in the same forest. Also, Trusts can extend outside the forest.

- **Objects:** Objects live within an Organizational Unit (OU).
![[Pasted image 20250119205002.png]]

