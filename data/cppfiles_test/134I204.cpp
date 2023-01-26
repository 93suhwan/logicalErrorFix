#include <bits/stdc++.h>
using namespace std;
long long setbit(long long num, long long nth) { return num |= (1LL << nth); }
long long clearbit(long long num, long long nth) {
  return num &= ~(1LL << nth);
}
long long toggle(long long num, long long nth) { return num ^= (1LL << nth); }
long long check(long long num, long long nth) { return (num >> nth) & 1LL; }
long long change(long long num, long long nth, long long val) {
  return num ^= (-val ^ num) & (1LL << nth);
}
int fx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int fy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
long long dx[4] = {+1, -1, +0, -0};
long long dy[4] = {+0, -0, +1, -1};
long long n, k;
string str, s;
long long a[5000003];
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a == b) return a;
  if (a > b) return gcd(a - b, b);
  return gcd(a, b - a);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tt = 1, cas = 0;
  cin >> tt;
  while (tt--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<long long> v;
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (a[i] % 2 == a[j] % 2) {
          v.push_back(gcd(a[i], a[j]));
        }
      }
    }
    if (n == 2) {
      cout << max(a[1], a[2]) << endl;
      continue;
    }
    long long ck = 0;
    for (int i = 0; i < v.size(); i++) {
      string s = "";
      for (int j = 1; j <= n; j++) {
        if (a[j] % v[i] == 0)
          s += "1";
        else
          s += "0";
      }
      long long ok = 0;
      for (int j = 1; j < s.size(); j++) {
        if (s[j - 1] == s[j]) ok = 1;
      }
      if (!ok) {
        cout << v[i] << endl;
        ck = 1;
        break;
      }
    }
    if (!ck) cout << 0 << endl;
  }
  return 0;
}
