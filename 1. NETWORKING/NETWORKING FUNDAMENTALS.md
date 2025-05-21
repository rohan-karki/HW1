_**IPv4 addresses**_ are 32-bit numerical addresses represented in a dotted-decimal format, such as "192.168.0.1"

_**IPv6 addresses**_ are 128-bit addresses represented in a hexadecimal format, such as "2001:0db8:85a3:0000:0000:8a2e:0370:7334".

**NOTE:** IP address falls under layer 3 of networking, whereas MAC address falls under layer 2 of networking since they use switching or switches to communicate.

![[Pasted image 20241017211830.png]]

***
## OSI MODEL:

The OSI (Open Systems Interconnection) model is a conceptual framework that standardizes the functions of a communication system into seven distinct layers. 

1) **PHYSICAL LAYER:** The physical layer is responsible for the transmission and reception of raw unstructured data bits over a physical medium. It defines the electrical, mechanical, and functional characteristics of the physical interface between devices.

2) **DATA LINK LAYER:** The data link layer handles the reliable transmission of data frames between directly connected nodes over a physical link. It provides error detection and correction, flow control, and handles access to the physical medium. 

Ethernet, Wi-Fi, and PPP (Point-to-Point Protocol) are examples of data link layer protocols.

3) **NETWORK LAYER:** The network layer enables the routing of data packets across different networks. It deals with logical addressing and determines the best path for data delivery based on network conditions and routing protocols.

4) **TRANSPORT LAYER:** The transport layer ensures the reliable and orderly delivery of data between end systems. It breaks data into smaller segments, manages end-to-end communication, and provides error recovery, flow control, and congestion control. TCP (Transmission Control Protocol) and UDP (User Datagram Protocol) operate at this layer.

5) **SESSION LAYER:** The session layer establishes, manages, and terminates communication sessions between applications. It provides synchronization and dialog control mechanisms to enable seamless communication between devices.

6) **PRESENTATION LAYER:** The presentation layer is responsible for data representation, encryption, compression, and formatting. It ensures that data sent by the application layer of one system is understandable by the application layer of another system.

7) **APPLICATION LAYER:** The application layer is the closest layer to the end-user and provides services directly to user applications. It includes protocols for various application-level services such as file transfer, email, web browsing, and remote access.

***
## SUBNETTING:

**_Subnetting_** is the process of dividing a network into smaller subnetworks called subnets. 

It allows for more efficient use of IP addresses and facilitates network management and routing.

_**CIDR**_ (**Classless Inter-Domain Routing**) notation is a method used to represent IP addresses and their corresponding subnet masks. 

**NOTE:** The **_/24_** notation is used to represent _**255.255.255.0**_ subnet mask.

**Example:** **192.168.0.0/24** which has a subnet mask of **255.255.255.0** indicates that the first 3 octets are reserved for the network, and the last octet can be used for addressing hosts within the subnet. 

![[Pasted image 20241023094543.png]]

![[Pasted image 20241023095324.png]]

***
