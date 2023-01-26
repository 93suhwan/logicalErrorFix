#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long INF = 0x3f3f3f3f;
void solve() {
  string s;
  cin >> s;
  map<char, long long> m;
  for (long long i = 0; i < s.size(); i++) {
    m[s[i]]++;
  }
  long long red = 0;
  long long green = 0;
  bool flag = true;
  for (auto itr = m.begin(); itr != m.end(); itr++) {
    long long temp = itr->second;
    if (temp >= 2) {
      red++;
      green++;
    } else {
      if (flag) {
        red++;
        flag = false;
      } else {
        green++;
        flag = true;
      }
    }
  }
  cout << min(red, green);
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
