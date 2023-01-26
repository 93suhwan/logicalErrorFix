#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    map<char, int> M;
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++) {
      M[s[i]]++;
    }
    int c = 0;
    for (auto i = M.begin(); i != M.end(); i++) {
      if ((i->second) > 2) {
        c += i->second - 2;
      }
    }
    cout << (n - c) / 2 << endl;
  }
  return 0;
}
