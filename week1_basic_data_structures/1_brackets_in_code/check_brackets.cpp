#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Bracket {
    public:
        char type;
        int position;

    Bracket(char type, int position){
        this->type = type;
        this->position = position;
    }

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

};

int main() {
    std::string text;
    getline(std::cin, text);

    stack <char> opening_brackets_stack;
    stack <int> po;
    int position;
    for (position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            opening_brackets_stack.push(next);
            po.push(position+1);
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            char b;
            int t;
            if(opening_brackets_stack.empty())
            {
                cout<<position+1<<endl;
                exit(0);
            }
            else
            {
                b = opening_brackets_stack.top();
                opening_brackets_stack.pop();
                t = po.top();
                po.pop();
            }   
            if(next == ']' && b != '[' || next == ')' && b != '(' || next == '}' && b != '{')
            {
                cout<<position+1<<endl;
                exit(0);
            }
        }
    }

    // Printing answer, write your code here
    if(!opening_brackets_stack.empty())
    {
        int t = po.top();
        cout<<t<<endl;
        exit(0);
    }

    cout<<"Success"<<endl;

    return 0;
}
