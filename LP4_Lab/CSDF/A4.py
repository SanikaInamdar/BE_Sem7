# # Sample log entries (replace with real log data)
# log_entries = [
#     {"timestamp": "2023-10-25 08:00:00", "source": "Server", "event": "Login Attempt", "user": "user1", "status": "Failed"},
#     {"timestamp": "2023-10-25 08:15:00", "source": "Firewall", "event": "Blocked Access", "user": "user2", "status": "Blocked"},
#     {"timestamp": "2023-10-25 08:30:00", "source": "Server", "event": "Login Attempt", "user": "user3", "status": "Failed"},
#     {"timestamp": "2023-10-25 08:45:00", "source": "Firewall", "event": "Blocked Access", "user": "user4", "status": "Blocked"},
#     {"timestamp": "2023-10-25 09:00:00", "source": "Server", "event": "Login Attempt", "user": "user5", "status": "Failed"},
# ]

log_entries = [
    {"timestamp": "2023-10-25 08:00:00", "source": "Server", "event": "Login Attempt", "user": "user1", "status": "Failed"},
    {"timestamp": "2023-10-25 08:15:00", "source": "Server", "event": "Login Attempt", "user": "user1", "status": "Failed"},
    {"timestamp": "2023-10-25 08:30:00", "source": "Server", "event": "Login Attempt", "user": "user1", "status": "Failed"},
    {"timestamp": "2023-10-25 08:45:00", "source": "Server", "event": "Login Attempt", "user": "user1", "status": "Failed"},
]

# Event correlation rules (example: detecting multiple failed login attempts)
def correlate_events(log_entries):
    correlated_events = []
    login_attempts = {}
    
    for entry in log_entries:
        if entry["event"] == "Login Attempt" and entry["status"] == "Failed":
            user = entry["user"]
            if user in login_attempts:
                login_attempts[user] += 1
                if login_attempts[user] >= 3:
                    correlated_events.append(f"Multiple failed login attempts for user {user}")
            else:
                login_attempts[user] = 1
    
    return correlated_events

if __name__ == "__main__":
    correlated_events = correlate_events(log_entries)
    
    if correlated_events:
        print("Correlated Events:")
        for event in correlated_events:
            print(event)
    else:
        print("No correlated events found.")
    
    # Additional sample log entries for testing
    additional_log_entries = [
        {"timestamp": "2023-10-25 10:00:00", "source": "Server", "event": "Login Attempt", "user": "user1", "status": "Failed"},
        {"timestamp": "2023-10-25 10:15:00", "source": "Server", "event": "Login Attempt", "user": "user2", "status": "Failed"},
        {"timestamp": "2023-10-25 10:30:00", "source": "Server", "event": "Login Attempt", "user": "user2", "status": "Failed"},
        {"timestamp": "2023-10-25 10:45:00", "source": "Firewall", "event": "Blocked Access", "user": "user4", "status": "Blocked"},
        {"timestamp": "2023-10-25 11:00:00", "source": "Server", "event": "Login Attempt", "user": "user3", "status": "Failed"},
    ]

    correlated_events = correlate_events(additional_log_entries)
    
    if correlated_events:
        print("\nAdditional Test Case - Correlated Events:")
        for event in correlated_events:
            print(event)
    else:
        print("\nAdditional Test Case - No correlated events found.")
