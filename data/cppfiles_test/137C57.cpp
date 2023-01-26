#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
const long long infll = (long long)1e18 + 228;
const int inf = 1e9 + 228;
const int mod = 998244353;
const int MOD = 1e9 + 7;
map<string, int> used;
void rec(string s) {
  if (used[s] || s.size() > 100) {
    return;
  }
  used[s] = 1;
  string t = s;
  t += "0";
  while (t.size() > 1 && t.back() == '0') {
    t.pop_back();
  }
  reverse((t).begin(), (t).end());
  rec(t);
  t = s;
  t += "1";
  rec(t);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long a, b;
  cin >> a >> b;
  string s = "", t = "";
  while (a) {
    s += char('0' + a % 2);
    a /= 2;
  }
  while (b) {
    t += char('0' + b % 2);
    b /= 2;
  }
  reverse((s).begin(), (s).end());
  reverse((t).begin(), (t).end());
  rec(s);
  if (used[t]) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
