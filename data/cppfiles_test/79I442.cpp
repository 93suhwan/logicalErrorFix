#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long Mod(long long x);
long long Add(long long a, long long b);
long long Mul(long long a, long long b);
long long FastExp(long long b, long long e);
void init_code() {}
signed main() {
  init_code();
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    set<long long> st = {1, 4, 6, 8, 9};
    bool flag = true;
    for (char c : s) {
      if (st.count(c - '0')) {
        flag = false;
        cout << 1 << '\n' << c << '\n';
        break;
      }
    }
    if (!flag) continue;
    map<char, long long> mp;
    for (char c : s) {
      mp[c]++;
    }
    for (auto p : mp) {
      if (p.second > 1) {
        flag = false;
        string num = "";
        num += p.first;
        num += p.first;
        cout << 2 << '\n' << num << '\n';
      }
    }
    map<char, vector<char>> g;
    g['2'] = {'5', '7'};
    g['3'] = {'2', '5'};
    g['5'] = {'2', '7'};
    g['7'] = {'2', '5'};
    for (long long i = 0; i < n; ++i) {
      for (char num : g[s[i]]) {
        if (s.find(num, i + 1) != string::npos) {
          string ans = "";
          ans += s[i];
          ans += num;
          cout << 2 << '\n' << ans << '\n';
        }
      }
    }
  }
  return 0;
}
long long Mod(long long x) { return (x % MOD + MOD) % MOD; }
long long Add(long long a, long long b) { return Mod(Mod(a) + Mod(b)); }
long long Mul(long long a, long long b) { return Mod(Mod(a) * Mod(b)); }
long long FastExp(long long b, long long e) {
  if (e == 0) return 1;
  if (e == 1) return Mod(b);
  if (e % 2 == 0) {
    long long temp = FastExp(b, e / 2);
    return Mul(temp, temp);
  } else {
    long long temp = FastExp(b, e / 2);
    return Mul(Mul(temp, temp), b);
  }
}
