#include <iostream>
using namespace std;
int main() {
    string s;

    cout << "Enter a word that is a palindrome: ";
    cin >> s;
    string x = s;

    void reverse(string& str) {
        for (int i = 0; i < s.length(); i++) {
            reverse(str[i], str[s.length() - i - 1]);
        }

    }
    bool isPalindrome(string s) {
        if (x == reverse(x)) return true;
        else return false

    }

return 0;
}