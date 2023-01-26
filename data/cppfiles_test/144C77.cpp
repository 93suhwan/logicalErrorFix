#include <bits/stdc++.h>
using namespace std;
vector<long long> prime;
vector<bool> mark(1e6 + 6, true);
vector<long long> fact(1e6 + 1, 1);
vector<long long> inv(1e6 + 1, 1);
vector<long long> invf(1e6 + 1, 1);
long long Mod = 1e9 + 7;
void seive(long long n) {
  long long i, j;
  mark[1] = false;
  prime.push_back(2);
  for (i = 4; i <= n; i += 2) mark[i] = false;
  for (i = 3; i * i <= n; i++) {
    if (mark[i]) {
      for (j = i * i; j <= n; j += 2 * i) {
        mark[j] = false;
      }
    }
  }
  for (i = 3; i <= n; i += 2)
    if (mark[i]) prime.push_back(i);
}
long long ck(long long n) {
  long long l = 1, r = n, mid;
  while (l <= r) {
    mid = (l + r) / 2;
    if ((mid * (mid + 1)) / 2 < n)
      l = mid + 1;
    else
      r = mid - 1;
  }
  return l;
}
void ft() {
  for (long long i = 2; i <= 1e6; i++) {
    fact[i] = (i * fact[i - 1]) % Mod;
  }
}
void modinv() {
  inv[0] = inv[1] = 1;
  for (long long i = 2; i <= 1e6; i++) {
    inv[i] = inv[Mod % i] * (Mod - Mod / i) % Mod;
  }
}
void modfactinv() {
  invf[0] = invf[1] = 1;
  for (long long i = 2; i <= 1e6; i++) {
    invf[i] = (invf[i - 1] * inv[i]) % Mod;
  }
}
void solve(long long cs) {
  long long n, m, i, z, h, w, e, k = 0, j, a, x, y, b, ans = 1;
  string s;
  cin >> n >> m >> k;
  x = n / m;
  y = x;
  if (n % m) x++;
  w = n % m;
  z = 0;
  while (k--) {
    for (i = 0; i < m; i++) {
      if (i < w) {
        cout << x << " ";
        for (j = 0; j < x; j++) cout << (z++) % n + 1 << " ";
        cout << '\n';
        a = z;
      } else {
        cout << y << " ";
        for (j = 0; j < y; j++) cout << (a++) % n + 1 << " ";
        cout << '\n';
      }
    }
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1, cs = 1;
  cin >> t;
  while (t--) {
    solve(cs++);
  }
}
