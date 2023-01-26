#include <bits/stdc++.h>
using namespace std;
bool solve(string &b, string &t) {
  if (b.find(t) != string::npos) return true;
  return false;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    bool found = false;
    string s = "", t = "", a = "", b = "";
    cin >> s;
    cin >> t;
    long long l = s.length();
    for (long long i = 0; i < l; i++) {
      a = s.substr(0, i);
      b = s.substr(0, i + 1);
      reverse(a.begin(), a.end());
      b += a;
      if (solve(b, t)) {
        cout << "YES"
             << "\n";
        found = true;
        break;
      }
    }
    if (!found) {
      cout << "NO"
           << "\n";
    }
  }
  return 0;
}
