#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long comb(long long n, long long r) {
  long long ans = 1;
  for (long long i = n; i > (n - r); i--) {
    ans = (ans * i) / (n + 1 - i);
  }
  return ans;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> lev(n, 0);
  vector<long long> dif(n, 0);
  vector<long long> v1(n + 1, 0);
  vector<long long> v2(n + 1, 0);
  for (long long i = 0; i < n; i++) {
    cin >> lev[i] >> dif[i];
    v1[lev[i]]++;
    v2[dif[i]]++;
  }
  long long tmi = 0;
  for (long long i = 0; i < n; i++) {
    if (v1[lev[i]] > 1 && v2[dif[i]] > 1) {
      tmi += (v1[lev[i]] - 1) * (v2[dif[i]] - 1);
    }
  }
  long long ans = 0;
  ans = n * (n - 1) * (n - 2) / 6;
  ans -= tmi;
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  for (long long i = 0; i < t; i++) solve();
  return 0;
}
