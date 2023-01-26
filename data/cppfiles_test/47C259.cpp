#include <bits/stdc++.h>
using namespace std;
long long int power(long long int b, long long int e) {
  if (e == 0) return 1;
  if (e % 2)
    return ((b * power((b) * (b), (e - 1) / 2)));
  else
    return power((b) * (b), e / 2);
}
long long int modpower(long long int b, long long int e, long long int q) {
  long long int MOD = q;
  if (e == 0) return 1;
  if (e % 2)
    return ((b % MOD) * modpower((b % MOD) * (b % MOD), (e - 1) / 2, q)) % MOD;
  else
    return modpower((b % MOD) * (b % MOD), e / 2, q) % MOD;
}
void dpv(vector<long long int> v) {
  for (long long int i = 0; i < (v.empty() ? 0 : v.size()); i++) {
    cout << v[i] << " ";
  }
  cout << "\n";
}
long long int ceil1(long long int x, long long int y) {
  long long int r = x / y;
  if (x % y == 0) {
    return r;
  } else {
    return r + 1;
  }
}
long long int solve(vector<long long int> p, long long int k) {
  long long int ans = 0;
  for (long long int i = 0; i < (p.empty() ? 0 : p.size());) {
    long long int k1 = k;
    long long int cur = -1e18;
    while (i < (p.empty() ? 0 : p.size()) and k1) {
      cur = max(cur, abs(p[i]));
      k1--;
      i++;
    }
    ans += 2 * abs(cur);
  }
  return ans;
}
void fuck() {
  long long int n1, k;
  cin >> n1 >> k;
  vector<long long int> p, n;
  for (long long int i = 0; i < n1; i++) {
    long long int x;
    cin >> x;
    if (x > 0) {
      p.push_back(x);
    } else {
      n.push_back(x);
    }
  }
  sort(p.begin(), p.end());
  sort(n.begin(), n.end());
  reverse(p.begin(), p.end());
  long long int ans = solve(p, k);
  ans += solve(n, k);
  if ((p.empty() ? 0 : p.size()) and (n.empty() ? 0 : n.size())) {
    ans -= max(abs(p[0]), abs(n[0]));
  } else if ((p.empty() ? 0 : p.size())) {
    ans -= abs(p[0]);
  } else {
    ans -= abs(n[0]);
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t = 1;
  cin >> t;
  while (t--) {
    fuck();
  }
  return 0;
}
