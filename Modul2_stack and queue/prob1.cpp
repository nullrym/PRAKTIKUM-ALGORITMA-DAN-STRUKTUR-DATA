#include <iostream>
#include <string>
#include <cctype>
#include "stack.h"

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    Stack s;
    init(&s);

    for (int i = 0; i < n; i++) {
        string token;
        cin >> token;

        if (isdigit(token[0]) || (token.length() > 1 && token[0] == '-')) {
            push(&s, stoi(token));
        } else {
            int val2 = peek(&s); pop(&s);
            int val1 = peek(&s); pop(&s);
            if (token == "+") push(&s, val1 + val2);
            else if (token == "-") push(&s, val1 - val2);
            else if (token == "*") push(&s, val1 * val2);
            else if (token == "/") push(&s, val1 / val2);
        }
    }

    cout << peek(&s) << endl;
    return 0;
}
