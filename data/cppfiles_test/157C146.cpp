#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e4;
long long F[maxN + 1];
void fact() {
  F[0] = F[1] = 1;
  for (int i = 2; i <= maxN; i++) F[i] = (1LL * F[i - 1] * i) % 998244353;
}
long long power(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res = (1LL * res * a) % 998244353, b--;
    } else {
      a = (1LL * a * a) % 998244353, b >>= 1;
    }
  }
  return res;
}
long long C(long long n, long long r) {
  if (r > n) return 0;
  long long res = F[n];
  res = (1LL * res * power(F[r], 998244353 - 2)) % 998244353;
  res = (1LL * res * power(F[n - r], 998244353 - 2)) % 998244353;
  return res;
}
void solve() {
  long long n, k;
  cin >> n >> k;
  string second;
  cin >> second;
  if (!k) {
    cout << "1\n";
    return;
  }
  long long ans = 1, l = 0, r = 0, cnt = 0;
  while (r < n) {
    if (second[r] == '1') {
      if (cnt == k) {
        (ans += (C(r - l, k) - 1 + 998244353) % 998244353) %= 998244353;
        while (l < n && second[l] != '1') l++;
        l++, cnt--;
        ans = (ans - C(r - l, k - 1) + 1 + 998244353) % 998244353;
      }
      cnt++;
    }
    r++;
  }
  if (cnt == k) (ans += (C(r - l, k) - 1 + 998244353) % 998244353) %= 998244353;
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0), fact();
  solve();
  return 0;
}
