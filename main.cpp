#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    // Given a string containing just the characters 
    // '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
    bool isValid(string s) {
        stack<char> opened;
        for (int i = 0; i < s.length(); ++i) {
          char look = s[i];
          // cout << "Looking at " << look << endl;
          if (look == '(' || look == '{' || look == '[') {
            opened.push(look);
          } else {
            if (opened.empty())
              return false;
            char lastOpen = opened.top();
            opened.pop();
            if (look == ')') {
              if (lastOpen != '(')
                return false;
            } else if (look == '}') {
              if (lastOpen != '{')
                return false;
            } else if (look == ']') {
              if (lastOpen != '[')
                return false;
            } else {
              cout << "Unexpected character: " << look << endl;
              return false;
            }
          }
        }
        return opened.empty();
    }
};

int main() {
  Solution S;
  cout << boolalpha;
  cout << "1 true: " << S.isValid("()") << endl;
  cout << "2 true: " << S.isValid("()[]{}") << endl;
  cout << "3 false: " << S.isValid("(]") << endl;
  cout << "4 false: " << S.isValid("([)]") << endl;
  cout << "5 false: " << S.isValid("((()))]") << endl;
  return 0;
}