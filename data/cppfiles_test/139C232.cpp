#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s, c;
    cin >> s;
    c = s.substr(0, s.size() / 2);
    cout << (c + c == s ? "yes\n" : "No\n");
  }
}
