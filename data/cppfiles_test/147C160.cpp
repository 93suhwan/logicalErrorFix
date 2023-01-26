#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  string s;
  cin >> t;
  getline(cin, s);
  while (t--) {
    getline(cin, s);
    int cnt = 0;
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == 'N') {
        ++cnt;
      }
    }
    if (cnt == 1) {
      cout << "NO";
    } else {
      cout << "YES";
    }
    cout << '\n';
  }
  return 0;
}
