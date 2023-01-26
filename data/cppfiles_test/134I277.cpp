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
    long long g = a[1];
    for (int i = 1; i <= n; i += 2) {
      g = gcd(a[i], g);
    }
    long long ok = 0;
    for (int i = 1; i <= n; i += 2) {
      if (i + 1 <= n && a[i + 1] % g == 0) ok = 1;
    }
    if (ok == 0) {
      cout << g << endl;
      continue;
    }
    g = a[2];
    for (int i = 2; i <= n; i += 2) {
      g = gcd(a[i], g);
    }
    ok = 0;
    for (int i = 2; i <= n; i += 2) {
      if (a[i - 1] % g == 0) ok = 1;
    }
    if (ok == 0) {
      cout << g << endl;
      continue;
    }
    cout << 0 << endl;
  }
  return 0;
}
