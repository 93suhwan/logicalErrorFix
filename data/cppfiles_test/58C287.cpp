#include <bits/stdc++.h>
using namespace std;
bool solve(string s1, string s2) {
  for (long long i = 1; i < (long long)s1.size(); i++) {
    if (s1[i] == '1' and s2[i] == '1') return false;
  }
  return true;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n = 0;
    cin >> n;
    string s1 = "", s2 = "";
    cin >> s1;
    cin >> s2;
    if (solve(s1, s2))
      cout << "YES";
    else
      cout << "NO";
    cout << "\n";
  }
  return 0;
}
