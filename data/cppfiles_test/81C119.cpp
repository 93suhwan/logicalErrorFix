#include <bits/stdc++.h>
using namespace std;
int long long inline powerM(int long long a, int long long b, int long long p) {
  a %= p;
  int long long ans = 1;
  while (b > 0) {
    if (b & 1) ans = (ans * a) % p;
    a = (a * a) % p;
    b >>= 1;
  }
  return ans;
}
int long long inv(int long long n, int long long p) {
  return powerM(n, p - 2, p);
}
int long long inline power(int long long a, int long long b) {
  int long long ans = 1;
  while (b > 0) {
    if (b & 1) ans = (ans * a);
    a = (a * a);
    b >>= 1;
  }
  return ans;
}
void solve() {
  int long long n, q;
  cin >> n >> q;
  int long long a[n + 1], b[n + 1];
  string s;
  cin >> s;
  a[0] = 0;
  for (int long long i = 0; i < n; i++) {
    a[i + 1] = a[i];
    if (s[i] == '+') {
      if (i % 2 == 0)
        a[i + 1]--;
      else
        a[i + 1]++;
    } else {
      if (i % 2 == 0)
        a[i + 1]++;
      else
        a[i + 1]--;
    }
  }
  while (q--) {
    int long long l, r;
    cin >> l >> r;
    if ((l - r + 1) % 2 != 0) {
      cout << "1\n";
      continue;
    }
    int long long v = abs(a[r] - a[l - 1]);
    cout << min((int long long)2, v) << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int long long t;
  cin >> t;
  for (int long long i = 1; i <= t; i++) {
    solve();
  }
}
