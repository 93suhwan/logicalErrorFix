#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    string str;
    cin >> str;
    int A = 0, B = 0, C = 0;
    for (int j = 0; j < str.size(); j++) {
      if (str[j] == 'A') {
        A++;
      } else if (str[j] == 'B') {
        B++;
      } else
        C++;
    }
    if (A + C == B) {
      cout << "YES\n";
    } else
      cout << "NO\n";
  }
}
