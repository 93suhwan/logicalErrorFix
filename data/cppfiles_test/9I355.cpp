#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long power(long long x, long long y, long long mod) {
  long long res = 1;
  x = x % mod;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length();
    map<char, long long> mp;
    for (long long i = 0; i < n; i++) mp[s[i]]++;
    if (n == 1) {
      cout << 0 << "\n";
      continue;
    }
    if (mp.size() == 1) {
      cout << 1 << "\n";
      continue;
    }
    long long cnt = 0;
    long long sum = 0;
    for (auto x : mp) {
      if (x.second > 1) {
        cnt += x.second / 2;
      } else if (x.second == 1) {
        sum += x.second;
      }
    }
    cnt = cnt;
    sum = sum / 2;
    long long ans = sum + cnt;
    cout << ans << "\n";
  }
  return 0;
}
