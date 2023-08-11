# Help desk management system
import re

responses = {
    "greeting": "Hello! Welcome to our mobile repairing shop. How can I assist you today?",
    "farewell": "Thank you for choosing our mobile repairing services. Have a great day!",
    "help": "Sure, I'm here to help. What issues are you facing with your mobile?",
    "screen_cracked": "A cracked screen is a common issue. We can replace the screen for you. Please bring your mobile to our shop, and our technicians will take care of it.",
    "battery_problem": "If you're experiencing battery issues, we can replace your mobile's battery. Bring it to our shop, and we'll ensure it gets fixed.",
    "software_issue": "Software issues can often be resolved by resetting your mobile or updating its software. We can assist you with that. Please bring your phone to our shop, and our technicians will help you out.",
    "water_damage": "Water damage can be critical for mobiles. We suggest immediately turning off your device and bringing it to our shop for professional repair. Do not attempt to power it on.",
    "default": "I apologize, but I couldn't understand your request."
}
class Rule:
    def __init__(self, pattern, response_key):
        self.pattern = pattern
        self.response_key = response_key


class ExpertSystem:
    def __init__(self, rules):
        self.rules = rules

    def respond_to_inquiry(self, inquiry):
        for rule in self.rules:
            if re.search(rule.pattern, inquiry):
                return responses[rule.response_key]
        return responses["default"]


# Define the rules
rules = [
    Rule(r"\b(?:hello|hi)\b", "greeting"),
    Rule(r"\b(?:goodbye|bye)\b", "farewell"),
    Rule(r"\b(?:help|support)\b", "help"),
    Rule(r"\b(?:screen|cracked)\b", "screen_cracked"),
    Rule(r"\b(?:battery|charge)\b", "battery_problem"),
    Rule(r"\b(?:software|update|reset)\b", "software_issue"),
    Rule(r"\b(?:water|damage)\b", "water_damage")
]

# Create an instance of ExpertSystem
chatbot = ExpertSystem(rules)

# Main loop to simulate customer interaction
print("Welcome to the Customer Interaction Chatbot!")
print("Type 'exit' to end the conversation.")

while True:
    user_input = input("Customer: ")

    if user_input.lower() == "exit":
        break

    bot_response = chatbot.respond_to_inquiry(user_input)
    print("Chatbot: " + bot_response)

print("Thank you for using the Customer Interaction Chatbot. Goodbye!")