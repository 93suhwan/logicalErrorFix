#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long int n);
long long int pw(long long int x, long long int y);
long long int fact(long long int n);
long long int tc = 0;
void solve() {
  map<long long int, long long int> mp1, mp2;
  string s1, s2, s3, s4, t;
  char ch1, ch2, ch3;
  long long int n{}, m{}, i{}, j{}, f{}, g{}, x{}, y{}, z{}, k{}, u{}, v{}, l{},
      h{}, p{}, q{}, w{}, ans{}, o{}, r{}, s{}, a{}, b{}, c{}, d{}, e{}, sum{},
      ans2{10000000}, ans1{10000000};
  cin >> s1 >> s2;
  n = s1.size();
  m = s2.size();
  for (i = 0; i < n; ++i) {
    if (s1[i] == s2[0]) {
      x = i;
      p = 0;
      y = 1;
      for (k = 1; k + x < n && k < m; k++) {
        if (s2[k] != s1[i + k]) break;
        y++;
      }
      if (y == m) {
        cout << "YES" << ("\n");
        return;
      }
      for (j = 1; j <= y; j++) {
        k = j;
        x = i + j - 2;
        p = 0;
        for (; k < m && x >= 0; k++, x--) {
          if (k == (m - 1)) {
            if (s2[k] == s1[x]) {
              cout << "YES" << ("\n");
              return;
            }
          }
          if (s2[k] != s1[x]) {
            p = 1;
            break;
          }
        }
      }
    }
  }
  cout << "NO" << ("\n");
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
bool isPrime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long int pw(long long int x, long long int y) {
  long long int i = 0;
  long long int ans = 1;
  for (i = 1; i <= y; ++i) ans = (ans * x) % 998244353;
  return ans;
}
long long int fact(long long int n) {
  long long int ans = 1;
  for (long long int i = 1; i <= n; ++i) ans = (ans * i) % 1000000007;
  return ans;
}
long long int nCrModp(long long int n, long long int r, long long int p) {
  if (r > n - r) r = n - r;
  long long int C[r + 1];
  memset(C, 0, sizeof(C));
  C[0] = 1;
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = min(i, r); j > 0; j--) C[j] = (C[j] + C[j - 1]) % p;
  }
  return C[r];
}
