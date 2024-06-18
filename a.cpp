#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

void pushStack(vector<int>& stack);
void popStack(vector<int>& stack);
void displayStack(const vector<int>& stack);
string prefixToInfix(const string& prefix);
string postfixToInfix(const string& postfix);
void saveToFile(const string& filename, const string& content);
void showMenu();

int main() {
    vector<int> stack;
    int choice;
    
    do {
        showMenu();
        cin >> choice;
        cin.ignore(); // Ignore newline character
        
        switch (choice) {
            case 1:
                int subChoice;
                do {
                    cout << "Stack Menu\n";
                    cout << "i. Push\n";
                    cout << "ii. Pop\n";
                    cout << "iii. Display Stack\n";
                    cout << "iv. Back\n";
                    cout << "Enter choice: ";
                    cin >> subChoice;
                    cin.ignore(); // Ignore newline character
                    
                    switch (subChoice) {
                        case 1:
                            pushStack(stack);
                            break;
                        case 2:
                            popStack(stack);
                            break;
                        case 3:
                            displayStack(stack);
                            break;
                        case 4:
                            cout << "Returning to main menu.\n";
                            break;
                        default:
                            cout << "Invalid choice! Please try again.\n";
                    }
                } while (subChoice != 4);
                break;
            case 2:
                {
                    string prefix;
                    cout << "Enter Prefix expression: ";
                    getline(cin, prefix);
                    string infix = prefixToInfix(prefix);
                    cout << "Infix expression: " << infix << endl;
                    saveToFile("prefix_to_infix.txt", infix);
                }
                break;
            case 3:
                {
                    string postfix;
                    cout << "Enter Postfix expression: ";
                    getline(cin, postfix);
                    string infix = postfixToInfix(postfix);
                    cout << "Infix expression: " << infix << endl;
                    saveToFile("postfix_to_infix.txt", infix);
                }
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

void pushStack(vector<int>& stack) {
    int value;
    cout << "Enter value to push: ";
    cin >> value;
    stack.push_back(value);
    cout << "Value pushed to stack.\n";
}

void popStack(vector<int>& stack) {
    if (stack.empty()) {
        cout << "Stack is empty! Cannot pop.\n";
    } else {
        stack.pop_back();
        cout << "Value popped from stack.\n";
    }
}

void displayStack(const vector<int>& stack) {
    if (stack.empty()) {
        cout << "Stack is empty.\n";
    } else {
        cout << "Stack contents: ";
        for (int value : stack) {
            cout << value << " ";
        }
        cout << endl;
    }
}

string prefixToInfix(const string& prefix) {
    // Conversion logic for Prefix to Infix
    stack<string> s;
    for (int i = prefix.length() - 1; i >= 0; i--) {
        if (isalnum(prefix[i])) {
            s.push(string(1, prefix[i]));
        } else {
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            string temp = "(" + op1 + prefix[i] + op2 + ")";
            s.push(temp);
        }
    }
    return s.top();
}

string postfixToInfix(const string& postfix) {
    // Conversion logic for Postfix to Infix
    stack<string> s;
    for (char ch : postfix) {
        if (isalnum(ch)) {
            s.push(string(1, ch));
        } else {
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            string temp = "(" + op2 + ch + op1 + ")";
            s.push(temp);
        }
    }
    return s.top();
}

void saveToFile(const string& filename, const string& content) {
    ofstream file(filename);
    if (file.is_open()) {
        file << content;
        file.close();
        cout << "Result saved to " << filename << endl;
    } else {
        cout << "Unable to open file " << filename << endl;
    }
}

void showMenu() {
    cout << "\nMain Menu\n";
    cout << "1. Stack\n";
    cout << "2. Prefix to Infix\n";
    cout << "3. Postfix to Infix\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}
