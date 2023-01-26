#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long power(long long a, long long n) {
  long long p = n;
  long long b = a;
  long long ans = 1;
  while (p) {
    if (p % 2) ans = (ans * b) % mod;
    b = (b * b) % mod;
    p /= 2;
  }
  return ans;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void solve() {
  long long w, h;
  cin >> w >> h;
  vector<long long> l1, l2, l3, l4;
  long long a;
  cin >> a;
  for (int i = (1); i <= (a); i++) {
    long long x;
    cin >> x;
    l1.push_back(x);
  }
  long long b;
  cin >> b;
  for (int i = (1); i <= (b); i++) {
    long long x;
    cin >> x;
    l2.push_back(x);
  }
  long long c;
  cin >> c;
  for (int i = (1); i <= (c); i++) {
    long long x;
    cin >> x;
    l3.push_back(x);
  }
  long long d;
  cin >> d;
  for (int i = (1); i <= (d); i++) {
    long long x;
    cin >> x;
    l4.push_back(x);
  }
  long long area1 = h * (max((l1[a - 1] - l1[0]), (l2[b - 1] - l2[0]))),
            area2 = w * (max((l3[c - 1] - l3[0]), (l4[d - 1] - l4[0])));
  cout << max(area1, area2) << "\n";
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
