# Cyber Security

## **References**

- Sites
  - [OWASP](https://www.owasp.org/index.php/Main_Page)
  - [OWASP Cheat Sheet Series](https://cheatsheetseries.owasp.org/)
  - [GDPR.eu](https://gdpr.eu/)
  - [LGPD - Lei Geral de Proteção de Dados Pessoais](http://www.planalto.gov.br/ccivil_03/_Ato2015-2018/2018/Lei/L13709.htm)
  - [https://haveibeenpwned.com/](https://haveibeenpwned.com/)
- Books
  - [The Art of Intrusion: The Real Stories Behind the Exploits of Hackers, Intruders and Deceivers](https://www.amazon.com/Art-Intrusion-Exploits-Intruders-Deceivers-ebook/dp/B000S1M0DG)
  - [The Art of Invisibility: The World's Most Famous Hacker Teaches You How to Be Safe in the Age of Big Brother and Big Data](https://www.amazon.com/The-Art-of-Invisibility-audiobook/dp/B01NC39SM6)
- Cryptography
  - [https://doc.libsodium.org/](https://doc.libsodium.org/)
  - [Practical Cryptography for Developers - Free Book](https://cryptobook.nakov.com/)
- Authentication
  - [Oauth2](https://oauth.net/2/)
  - [JWT.io](https://jwt.io/)
- Network
  - [Man in the Middle](https://owasp.org/www-community/attacks/Manipulator-in-the-middle_attack)
- YouTube
  - [Gabriel Pato](https://www.youtube.com/channel/UC70YG2WHVxlOJRng4v-CIFQ)
- Web
  - [https://content-security-policy.com/](https://content-security-policy.com/)
  - [https://letsencrypt.org/](https://letsencrypt.org/)
  - [Cross-Origin Resource Sharing (CORS)](https://developer.mozilla.org/en-US/docs/Web/HTTP/CORS)
  - [Cross Site Scripting (XSS)](https://owasp.org/www-community/attacks/xss/)
  - [Cross Site Request Forgery (CSRF)](https://owasp.org/www-community/attacks/csrf)
- Softwares
  - [WireShark](https://www.wireshark.org/)
  - [AngryIP Scanner](https://angryip.org/)
  - [metasploit](https://www.metasploit.com/)
- Passwords
  - World's Fastest Password Cracker
    - [HashCat](https://hashcat.net/hashcat/)
    - [HashKiller](https://hashkiller.co.uk/md5-decrypter.aspx)
  - Recommended Encryption
    - [Argon2](https://github.com/P-H-C/phc-winner-argon2)
    - [PBKDF2](https://en.wikipedia.org/wiki/PBKDF2)
    - [Scrypt](https://en.wikipedia.org/wiki/Scrypt)
    - [BCrypt](https://en.wikipedia.org/wiki/Bcrypt)
  - Not Recommended
    - [MD5](https://pt.wikipedia.org/wiki/MD5)
    - [SHA1](https://www.thesslstore.com/blog/difference-sha-1-sha-2-sha-256-hash-algorithms/)
    - [SHA2](https://www.thesslstore.com/blog/difference-sha-1-sha-2-sha-256-hash-algorithms/)
- Operation Systems
  - [Kali Linux](https://www.kali.org/)
  - [Tails Linux](https://tails.boum.org/index.pt.html)
- Virtual Machines for Pentest
  - [PentesterLab](https://www.pentesterlab.com/exercises/)
  - [PentestBox](pentestbox.org)
    - [tools.pentestbox.org](https://tools.pentestbox.org/)
- DataBases
  - [Exploit-DB](https://www.exploit-db.com/)
  - [SQLMap](http://sqlmap.org/)
  - [SQL Injection](https://owasp.org/www-community/attacks/SQL_Injection)
- CLI Commands
  - [NMAP](https://nmap.org/)
  - [Trace Route](https://www.lifewire.com/traceroute-linux-command-4092586)
  - [cURL](https://curl.haxx.se/)
  - [whafw00f](https://github.com/EnableSecurity/wafw00f)
  - [ping](https://www.wikiwand.com/en/Ping)
  - [host](https://www.computerhope.com/unix/host.htm)
  - [whois](https://who.is/)
- Search Engines
  - [DuckDuckGo](https://duckduckgo.com)
- Browsers
  - [Bernes Lee Solid](https://solidproject.org/)
  - [TorProject](https://www.torproject.org/)
- Frameworks Docs
  - [https://docs.nestjs.com/security](https://docs.nestjs.com/security/authentication)
  - <https://docs.adonisjs.com/guides/security>

## **HTTPS**

<img width="100%" alt="img"  src="https://alexgalhardo.vercel.app/images/how-https-works.png">

## **Authentication**

<img width="100%" alt="img"  src="https://alexgalhardo.vercel.app/images/top-4-most-used-auth-mechanisms.png">

## **Hashing vs Encryption**

Hashing and encryption are fundamental techniques in software security, but they have different purposes and characteristics. Here are the main differences between them, along with some use cases:

### Hashing

**Purpose:**

- Hashing is used to ensure data integrity and verify authenticity without having to revert the data to its original state.

**Characteristics:**

1. **Irreversibility:** Hashing is a one-way process; once data is hashed, it cannot be reverted to its original state.
2. **Fixed Length:** Regardless of the size of the input data, the resulting hash value will have a fixed size.
3. **Collisions:** Ideally, hash functions are designed to minimize collisions (when two different sets of data produce the same hash), but they cannot be completely eliminated.

**Use Cases:**

1. **Integrity Verification:** Hashes are used to verify that data has not been altered. For example, when downloading a file, the hash of the downloaded file can be compared with the published hash to ensure that the file has not been corrupted.

2. **Password Storage:** Instead of storing passwords directly, systems store the hash of passwords. When a user attempts to log in, the system compares the hash of the provided password with the stored hash.

3. **Digital Signatures:** Hashes are used in combination with encryption to create digital signatures, ensuring that the content has not been altered and authenticating the source.

### Encryption

**Purpose:** - Encryption is used to protect the confidentiality of data by ensuring that only authorized parties can access the information.

**Features:**

1. **Reversibility:** Encryption is a two-way process; encrypted data can be reverted to its original state through decryption using an appropriate key. 2. **Key:** Cryptographic security relies on a key that must be kept secret. Cryptography can be symmetric (same key for encryption and decryption) or asymmetric (different keys for encryption and decryption).

2. **Complexity:** Cryptography tends to be more computationally complex than hashing, due to the need to encrypt and decrypt data.

**Use Cases:**

1. **Secure Data Transmission:** Encryption is used to protect data transmitted over the internet, such as in HTTPS connections, ensuring that sensitive information (such as banking details) cannot be intercepted and read by unauthorized parties.

2. **Sensitive Data Storage:** Sensitive data, such as medical records or financial information, is encrypted to protect privacy and ensure that only authorized users can access it. 3. **Authentication and Identity:** Authentication systems, such as smart cards or security tokens, use cryptography to securely verify the identity of users.

### Summary of Differences

| Feature                      | Hashing                                                  | Encryption                                          |
| ---------------------------- | -------------------------------------------------------- | --------------------------------------------------- |
| **Purpose**                  | Integrity                                                | Confidentiality                                     |
| **Irreversibility**          | Yes                                                      | No                                                  |
| **Fixed Length**             | Yes                                                      | No                                                  |
| **Use of Keys**              | No                                                       | Yes                                                 |
| **Computational Complexity** | Lower                                                    | Higher                                              |
| **Use Cases**                | Integrity checking, password storage, digital signatures | Secure transmission, secure storage, authentication |

These differences show that hashing and encryption are complementary, each meeting specific security needs within software systems.

## **VPN - Virtual Private Network**

<img width="100%" alt="img"  src="https://alexgalhardo.vercel.app/images/how-vpn-works.png">

## **Tools**

<img width="100%" alt="img"  src="https://alexgalhardo.vercel.app/images/cyber-security-tools.png">

## **Attacks**

<img width="100%" alt="img"  src="https://alexgalhardo.vercel.app/images/top-8-cyber-attack-2024.png">

<br><br>
