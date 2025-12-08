# DevOps

<img width="100%" alt="img"  src="https://alexgalhardo.vercel.app/images/dev-ops.png">

## References

- [TechWorld with Nana](https://www.youtube.com/@TechWorldwithNana)
- [Redes de Computadores - 2ª Edição, de Gabriel Torres](https://hotmart.com/pt-br/marketplace/produtos/redes-de-computadores-gabriel-torres/P7275275J)

## Tools

- [LocalStack](https://www.localstack.cloud/)
- [Kafka](https://kafka.apache.org/)
- [RabbitMQ](https://www.rabbitmq.com/)
- [Kubernetes](https://kubernetes.io/)

## SRE - Site Reliability Engineering

It is a discipline that combines principles and practices from software engineering and operations to create highly scalable and reliable software systems. Here is a simplified explanation:

- Primary Goal:
  - Ensure that software systems operate consistently and reliably.
- How It Works:

  - Automation: Automating repetitive tasks, such as deployments and monitoring, to reduce human error.
  - Monitoring: Continuously monitoring systems to detect and correct problems before they affect users.
  - Troubleshooting: Rapidly identifying and correcting faults and incidents to minimize downtime.
  - Continuous Improvement: Analyzing past incidents to learn from mistakes and improve systems.

- Tools and Practices:
  - Alerts: Alert systems to notify staff of problems.
  - Dashboards: Control panels that show the current state of the system.
  - Scripts: Scripts and tools to automate tasks.
  - Backup Policies: Procedures for backing up and recovering data.
- Collaboration with Developers:
  - Works closely with developers to ensure that software is designed to be reliable and maintainable.
  - Implements DevOps practices, which bring together development (Dev) and operations (Ops) to accelerate and improve software development.
- Benefits:
  - Less Downtime: Fewer failures and outages.
  - Better Performance: Faster, more efficient systems.
  - Scalability: Ability to grow without compromising quality.
  - Focus on Innovation: More time to develop new features instead of fixing problems.

In short, SRE is about applying software engineering principles to solve operational problems, making systems more reliable and efficient, and allowing teams to focus more on innovation than fixing problems.

<img width="100%" alt="img"  src="https://alexgalhardo.vercel.app/images/sre-vs-devops.png">

## Network

- **IPv4 == Internet Protocol Version 4**

  - Format by 4 bytes (10111011.01101011.11111011.01011011) = 2^32 = 4,294,967,296
  - Example: 192.168.0.1
  - <img width="100%" alt="img"  src="https://user-images.githubusercontent.com/19540357/81460486-2d09e800-9195-11ea-998d-3a49cd03a6f1.png">"

- **IPv6 == Internet Protocol Version 6**

  - Version 6, due to lack of sufficient addresses currently
  - 3.4x10^38 addresses
  - <img width="100%" alt="img"  src="https://user-images.githubusercontent.com/19540357/81460485-2b402480-9195-11ea-9b34-7a652e058b98.jpg">

- **MacAddress**

  - Media Access Control
  - "Unique" physical address associated with the communication interface, which connects a device to the network.
  - Your identification is recorded in hardware, that is, in ROM (Read-Only-Memory).
  - The first three bytes are used to identify the manufacturer - they are provided by IEEE itself
  - The last three bytes are defined by the manufacturer, who is responsible for controlling the numbering of each board it produces. Despite being unique and recorded in hardware, the MAC address can be changed using specific techniques.

- **HTTP**

  - HyperText Transfer Protocol
  - Used for hypermedia and hypertext information systems
  - HTTP: Port 80
  - HTTPS: Port 443

- **TCP = Transmission Control Protocol**

  - Is a set of communication protocols between computers on a network. The protocol suite can be seen as a layered model (OSI Model), where each layer is responsible for a group of tasks, providing a set of well-defined services to the upper layer protocol.
  - The higher layers are logically closer to the user (called application layer) and deal with more abstract data, relying on lower layer protocols for tasks with a lower level of abstraction.
  - It is connection oriented, that is, before sending the data, communication is carried out between the sender and the recipient and a communication channel is created, then the data is transmitted. Example of use: FTP (File Transfer Protocol) managers, such as FileZilla, as they need to guarantee the integrity of receiving/sending the file.
  - **Benefits**
    - Standardization: a standard, a routable protocol that is the most complete and accepted protocol currently available. All modern operating systems support TCP/IP, and most large networks rely on TCP/IP for most of their traffic.
    - Interconnectivity: a technology for connecting dissimilar systems. Many standard connectivity utilities are available to access and transfer data between these dissimilar systems, including FTP (File Transfer Protocol) and Telnet (Terminal Emulation Protocol).
    - Routing: allows and enables older and newer technologies to connect to the Internet. It works with line protocols such as P2P (Point to Point Protocol) allowing remote connection from a dial-up or dedicated line.
    - It works with the IPCs and interfaces mechanisms most used by operating systems, such as Windows sockets and NetBIOS.
    - Robust Protocol: scalable, multiplatform, with a structure to be used in client/server operating systems, allowing the use of applications of this size between two distant points.
    - Internet: it is through the TCP/IP suite of protocols that we obtain access to the Internet.
    - Local networks distribute Internet access servers (proxy servers) and local hosts connect to these servers to obtain Internet access. This access can only be achieved if computers are configured to use TCP/IP.
    - Total TCP Ports: 2^16 = 65,536

- **UDP = User Datagram Protocol**
  - Is a simple transport layer protocol. It is described in RFC 768 and allows the application to send a datagram encapsulated in an IPv4 or IPv6 packet to a destination, but without any guarantee that the packet will arrive correctly (or at all).
  - It is not connection oriented, so data is sent without being sure that the receiver has received the data.
  - Example of use: are those that do not need to guarantee the arrival of data.
  - All video and voice programs are of the UDP type (Skype, all "Voice over IP" type programs and streaming videos).

<img width="100%" alt="img"  src="https://alexgalhardo.vercel.app/images/tcp-ip-model.png">

- **ICMP = Internet Control Message Protocol**

  - Is a protocol that is part of the IP Protocol, defined by RFC 792, and is used to provide error reports to the original source.
  - Any computer that uses IP must accept ICMP messages and change its behavior according to the reported error.
  - TYPE (8 bits): identifies the type of message, for example, if the value is 8 it is a request (echo request). If the content is 0, it is an echo reply.
  - CODE (8 bits): used in conjunction with the TYPE field to identify the type of ICMP message being sent.
  - CHECKSUM (16 bits): checks the integrity of the ICMP packet.
  - MESSAGE CONTENTS (Variable Size): contains the content of the ICMP message.

- **Open System Interconnection**

  - Is a computer network model with the aim of being a standard for communication protocols between the most diverse systems on a local network (Ethernet), ensuring communication between two computer systems ( end-to-end) divided into 7 layers.

- **PING or Latency**

  - Is a utility that uses the ICMP protocol to test connectivity between equipment. It is a command available on practically all operating systems.
  - Its operation consists of sending packets to the destination equipment and "listening" for responses.
  - If the target equipment is active, a "response" (the "pong", an analogy to the famous game of ping-pong) is returned to the requesting computer.
  - $ ping -c 5 google.com

- **Firewal or Wall of Fire**

  - Is a device on a computer network that aims to apply a security policy to a certain point on the network. The firewall can be of the packet filter type, application proxy, etc.
  - Firewalls are generally associated with TCP/IP networks[1]. This security device exists in the form of software and hardware, the combination of both is technically called an "appliance".

- **Gateway**

  - In a communications network, a network node equipped to interface with another network that uses different protocols.
  - A computer or computer program configured to perform the tasks of a gateway.
  - What it is for: Organizing information traffic between an end device (computer, notebook, smartphone, tablet, etc.) and the internet in addition to “translating” information between heterogeneous networks. That is, allowing communication between different environments and architectures. Thus, the tool is capable of converting data between different systems, so that each side is able to “understand” the other.
  - Examples of use: router and firewall.

- **Proxy**

  - Is a server (a computer system or an application) that acts as an intermediary for client requests requesting resources from other servers.
  - A client connects to the proxy server, requesting some service, such as a file, connection, web page, or other resources available from a different server, and the proxy evaluates the request as a means of simplifying and controlling its complexity.
  - An HTTP cache proxy or, in English, caching proxy, allows, for example, the client to request a document on the World Wide Web and the proxy searches for the document in its box (cache). If found, the request is fulfilled and the document is returned immediately.
  - Otherwise, the proxy fetches the document from the remote server, delivers it to the client, and saves a copy in its cache. This allows for a reduction in latency, as the proxy server, and not the original server, is requested, also providing a reduction in bandwidth usage.

- **Traceroute**

  - Is a diagnostic tool that traces the route of a packet through a computer network that uses IP and ICMP protocols. Its operation is based on the use of the Time to Live (TTL) field of the IPv4[8] packet to limit its lifetime. This value is decremented each time the packet is forwarded by a router. When reaching the zero value, the packet is discarded and the originator is alerted by an ICMP TIME_EXCEEDED message. $ traceroute google.com

- **PAN = Personal Area Network**

  - Is a home network that connects various resources throughout a residence. A PAN network is obtained through Bluetooth technology and/or a USB cable.

- **LAN = Local Area Network**

  - Is a set of hardware and software that allows individual computers to establish communication with each other, exchanging and sharing information and resources.
  - These networks are called local because they cover a very limited area, but with technological advances, LAN has surpassed 100 m of coverage to extend to a larger area.

- **MAN = Metropolitan Area Network** are networks larger than LANs.

  - This type of network is characterized by having a greater range than LANs, covering nearby cities or metropolitan regions, for example.
  - In a more practical definition, let's imagine, for example, that a company has two offices in the same city and wants the computers to remain interconnected.
  - For this, there is the metropolitan area network, which connects several local networks within a few dozen kilometers.

- **WAN = Wide Area Network**

  - Is a computer network that covers a large geographic area, often a country or continent.
  - A classic example of a typical WAN network is the Internet itself, as it covers a global geographic area, interconnecting countries and continents.

- **OSI model**

<img width="100%" alt="img"  src="https://user-images.githubusercontent.com/19540357/81460482-29766100-9195-11ea-8219-d1138b16d965.jpg">

- **Three Way Handshake**

<img width="100%" alt="img"  src="https://user-images.githubusercontent.com/19540357/81460481-28ddca80-9195-11ea-883a-d2b94b63cfa2.jpg">

## **Linux**

<img width="100%" alt="img"  src="https://alexgalhardo.vercel.app/images/linux-file-systems.png">

<img width="100%" alt="img"  src="https://alexgalhardo.vercel.app/images/linux-boot-process-explained.png">

## **Domain Name System - DNS**

<img width="100%" alt="img"  src="https://user-images.githubusercontent.com/19540357/126329587-680de6c9-c47a-4142-b1f4-e3a95cc05707.png">
<img width="100%" alt="img"  src="https://github.com/AlexGalhardo/Software-Engineering/assets/19540357/c03be150-1458-4427-8c99-80b53364c898">

## **Web Domain**

- <img width="100%" alt="img"  src="https://user-images.githubusercontent.com/19540357/81460480-28453400-9195-11ea-92b5-ac79f2370427.jpg">
- URL = Uniform Resource Locator (Domain Name)
  - https://google.com
- Subdomain
  - https://play.google.com
- URN == Uniform Resource Name
  - /maps (resource that will be used in the URL)
- URI == Uniform Resource Identifier
  - https://google.com/maps (URL + URN)
- TDL == Top Level Domain or Top Level Domain
  - The IANA (Internet Assigned Numbers Authority) currently distinguishes the following groups of top-level domains
    - country-code top-level domains or ccTLD: always have two letters and derive from the ISO 3166-1 alpha-2 code
    - generic top-level domains (generic top-level domains or gTLD): always have more than two letters
    - sponsored top-level domains (sponsored top-level domains or sTLD)
    - unsponsored top-level domains
    - infrastructure top-level domains
    - internationalized top-level domains (IDN)
    - internationalized country code top-level domains or IDN ccTLD
    - testing top-level domains
- DNS == Domain Name System
  - It is a hierarchical and distributed name management system for computers, services or any machine connected to the Internet or a private network.
  - By default, DNS uses the User Datagram Protocol (UDP) on port 53 to serve requests and requests.
  - BIND == Berkeley Internet Name Domain is the server for the most used DNS protocol on the Internet, especially on Unix-type systems.
  - 13 Root Servers
    - https://www.iana.org/domains/root/servers
    - The authoritative name servers that serve the DNS root zone, commonly known as the “root servers”, are a network of hundreds of servers in many countries around the world. They are configured in the DNS root zone as 13 named authorities, as follows.
    ```
    List of Root Servers
    HOSTNAME IP ADDRESSES MANAGER
    a.root-servers.net 198.41.0.4, 2001:503:ba3e::2:30 VeriSign, Inc.
    b.root-servers.net 199.9.14.201, 2001:500:200::b University of Southern California (ISI)
    c.root-servers.net 192.33.4.12, 2001:500:2::c Cogent Communications
    d.root-servers.net 199.7.91.13, 2001:500:2d::d University of Maryland
    e.root-servers.net 192.203.230.10, 2001:500:a8::e NASA (Ames Research Center)
    f.root-servers.net 192.5.5.241, 2001:500:2f::f Internet Systems Consortium, Inc.
    g.root-servers.net 192.112.36.4, 2001:500:12::d0d US Department of Defense (NIC)
    h.root-servers.net 198.97.190.53, 2001:500:1::53 US Army (Research Lab)
    i.root-servers.net 192.36.148.17, 2001:7fe::53 Netnod
    j.root-servers.net 192.58.128.30, 2001:503:c27::2:30 VeriSign, Inc.
    k.root-servers.net 193.0.14.129, 2001:7fd::1 RIPE NCC
    l.root-servers.net 199.7.83.42, 2001:500:9f::42 ICANN
    m.root-servers.net 202.12.27.33, 2001:dc3::35 WIDE Project
    ```

## <b>Cloud</b>

- <img width="100%" alt="img"  src="https://user-images.githubusercontent.com/19540357/81460484-2b402480-9195-11ea-98d4-138ff2e19e5f.png">
- SaaS
  - SaaS (Software as a Service) allows users to connect and use cloud-based applications over the Internet. Common examples are email, calendar, and Office tools (such as Microsoft Office 365).
  - SaaS provides a complete software solution that you can purchase on a pay-as-you-go basis from a cloud service provider. You can rent application usage to your organization and have your users connect to it over the Internet, typically through a web browser. All underlying infrastructure, middleware, application software, and application data reside in the service provider's data center. The service provider manages hardware and software and, with the appropriate service contract, ensures the availability and security of the application and its data.
  - <em>Example: Apps/hosted applications (Office 365, Google Docs)</em>
  - PaaS
    - PaaS (Platform as a Service) is a complete development and deployment environment in the cloud, with features that enable you to deliver everything from simple cloud-based applications to sophisticated cloud-enabled enterprise applications. You purchase the resources you need through a cloud service provider on a pay-as-you-go basis and access them over a secure Internet connection.
    - Just like IaaS, PaaS includes infrastructure – servers, storage and networking – as well as middleware, development tools, BI (business intelligence) services, database management systems and much more. PaaS is built to support the complete web application lifecycle: build, test, deploy, manage, and update.
    - <em>Example: Development tools, database management, business analysis, Operating systems.</em>
    - IaaS
      - IaaS (Infrastructure as a Service) is an instant computing infrastructure, provisioned and managed over the Internet. Scale up or down with demand and only pay for what you use.
      - IaaS helps you avoid the expense and complexity of purchasing and managing your own physical servers and other data center infrastructure. Each feature is offered as a separate service component, and you can only rent a specific one for as long as you need it. The cloud computing service provider manages the infrastructure, while you purchase, install, configure and manage your own software – operating systems, middleware and applications.
      - <em>Example: Servers and storage Network security/firewalls Datacenter construction/physical plant</em>

<img width="100%" alt="img"  src="https://alexgalhardo.vercel.app/images/does-the-cloud-save-costs.png">

## **AWS**

<img width="100%" alt="img"  src="https://alexgalhardo.vercel.app/images/typical-aws-network-architecture.png">

## **CI/CD**

<img width="100%" alt="img"  src="https://alexgalhardo.vercel.app/images/ci-cd-workflow.png">

## **Docker**

- [docker.com](https://www.docker.com/)
- [DockerHub](https://www.docker.com/products/docker-hub/)
- [YouTube - Docker Tutorial for Beginners [FULL COURSE in 3 Hours]](https://www.youtube.com/watch?v=3c-iBn73dDE)
- [YouTube PlayList - What is Docker? from TechWorld with Nana](https://www.youtube.com/watch?v=jPdIRX6q4jA&list=PLy7NrYWoggjzfAHlUusx2wuDwfCrmJYcs)
- <https://livro.descomplicandodocker.com.br/>
- [Docker CheatSheet PDF](https://alexgalhardo.vercel.app/images/docker.pdf)

## **Virtual Machines (VMs) vs Containers**

<img width="100%" alt="img"  alt="vm_x_container" src="https://github.com/AlexGalhardo/Software-Engineering/assets/19540357/8922a07a-245d-4015-9396-753daa441cbf">
<img width="100%" alt="img"  alt="virtual_vs_container_benefits" src="https://github.com/AlexGalhardo/Software-Engineering/assets/19540357/a4bc69ec-96c3-4243-86ae-cb5a92f5ecd4">

<img width="100%" alt="img"  src="https://user-images.githubusercontent.com/19540357/165997551-bb8923f1-4bec-409b-b604-b73ddd1049f7.svg">

## <b>Kubernetes</b>

- [Documentation](https://kubernetes.io/pt-br/docs/_print/)
- [YouTube Video - Kubernetes Tutorial for Beginners [FULL COURSE in 4 Hours]](https://www.youtube.com/watch?v=X48VuDVv0do)

<img width="100%" alt="img"  src="https://user-images.githubusercontent.com/19540357/165997536-0fc77950-4b57-4dd7-9960-1341e6983ca6.png">
<img width="100%" alt="img"  src="https://user-images.githubusercontent.com/19540357/165997544-f2b90436-5d0a-4852-b9be-cea8d1ed6af7.png">
<img width="100%" alt="img"  src="https://user-images.githubusercontent.com/19540357/165997547-17182379-efbc-414e-8253-d0c593b42f77.png">
<img width="100%" alt="img"  src="https://user-images.githubusercontent.com/19540357/165997549-f5b6d977-1e0c-4352-b652-e25e0939a757.png">
<img width="100%" alt="img"  src="https://user-images.githubusercontent.com/19540357/165997557-f677bf5a-d7d6-4011-a260-fbeeee2e03c0.png">

<br><br>
