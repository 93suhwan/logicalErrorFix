#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    string s;
    cin >> s;
    if (s[0] == s[s.size() - 1])
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
