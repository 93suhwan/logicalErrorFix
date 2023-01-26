#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int a = 0, b = 0, c = 0;
    for (char x : s) {
      if (x == 'A') a++;
      if (x == 'B') b++;
      if (x == 'C') c++;
    }
    if (s.length() % 2 == 1 || s.length() < 4) {
      cout << "no";
    } else if (s.length() == 4) {
      if (s == "ABBA" || s == "BAAB" || s == "BCCB" || s == "CBBC") {
        cout << "yes";
      } else {
        cout << "no";
      }
    } else {
      if (b == a + c) {
        cout << "yes";
      } else {
        cout << "no";
      }
    }
    cout << endl;
  }
}
