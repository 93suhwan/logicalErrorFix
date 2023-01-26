#include <bits/stdc++.h>
using namespace std;
const long long M = 1e5 + 10, OO = 2e9 + 10;
vector<char> v, vv;
long long n, m, k;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    v.clear();
    vv.clear();
    string s;
    cin >> s;
    bool f = 0;
    long long n = s.length();
    if (n & 1) {
      cout << "NO" << '\n';
      continue;
    }
    for (long long i = 0; i < n / 2; i++) v.push_back(s[i]);
    for (long long i = n / 2; i < n; i++) vv.push_back(s[i]);
    for (long long i = 0; i < v.size(); i++)
      if (v[i] != vv[i]) {
        f = 1;
        break;
      }
    if (f)
      cout << "NO" << '\n';
    else
      cout << "YES" << '\n';
  }
}
