#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

// Function to convert string to lowercase
string toLower(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

// Function to get a response based on user input
string getResponse(const string& input) {
    map<string, string> responses = {
        {"hello", "Hi there! How can I help you?"},
        {"hi", "Hello! What can I do for you today?"},
        {"how are you", "I'm just a computer program, but thanks for asking! How about you?"},
        {"what is your name", "I'm a simple chatbot created in C++. You can call me Chatbot."},
        {"bye", "Goodbye! Have a great day!"},
        {"what can you do", "I can chat with you and answer simple questions!"}
    };

    string lowerInput = toLower(input);

    // Search for a response
    if (responses.find(lowerInput) != responses.end()) {
        return responses[lowerInput];
    } else {
        return "I'm sorry, I don't understand that.";
    }
}

int main() {
    string userInput;

    cout << "Welcome to the Chatbot! Type 'bye' to exit." << endl;

    while (true) {
        cout << "You: ";
        getline(cin, userInput);

        if (toLower(userInput) == "bye") {
            cout << "Chatbot: Goodbye! Have a great day!" << endl;
             break;
        }

        string response = getResponse(userInput);
        cout << "Chatbot: " << response << endl;
    }

    return 0;
}