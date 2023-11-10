import re
from email.header import decode_header

def parse_email_header(header_text):
    email_header = {}
    
    # Split the header into lines
    header_lines = header_text.split('\n')
    
    for line in header_lines:
        if ':' in line:
            key, value = line.split(':', 1)
            key = key.strip()
            value = value.strip()
            
            # Decode email header values
            value, encoding = decode_header(value)[0]
            if encoding:
                value = value.decode(encoding)
            
            email_header[key] = value
    
    return email_header

def extract_ip_addresses(header_text):
    # Use regular expressions to find IP addresses in the header
    ip_pattern = r'\b\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}\b'
    ip_addresses = re.findall(ip_pattern, header_text)
    
    return ip_addresses

if __name__ == "__main__":
    # Example email header text
    email_header_text = """
From: Sender <sender@example.com>
To: Recipient <recipient@example.com>
Subject: Important Information
Date: Thu, 26 Oct 2023 09:15:20 +0000
Received: from mail.example.net (mail.example.net [203.0.113.55])
    by smtp.example.net with SMTP
Received: from [198.51.100.1] by mail.example.net
"""

    
    # Parse the email header
    email_header = parse_email_header(email_header_text)
    
    # Extract IP addresses from the header
    ip_addresses = extract_ip_addresses(email_header_text)
    
    # Display the parsed header and extracted IP addresses
    print("Parsed Email Header:")
    for key, value in email_header.items():
        print(f"{key}: {value}")
    
    print("\nExtracted IP Addresses:")
    for ip in ip_addresses:
        print(ip)
