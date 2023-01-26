#include <bits/stdc++.h>
using namespace std;
unsigned long long int fact[100010], fact_inv[100010];
unsigned long long int power(unsigned long long int x, unsigned long long int y,
                             unsigned long long int m) {
  if (y == 0) return 1;
  unsigned long long int a = power(x, y / 2, m);
  if (y % 2) {
    return (a * ((a * x) % m)) % m;
  } else {
    return (a * a) % m;
  }
}
unsigned long long int mod_inverse(unsigned long long int x,
                                   unsigned long long int m) {
  return power(x, m - 2, m);
}
unsigned long long int ncr(unsigned long long int n, unsigned long long int r,
                           unsigned long long int m) {
  if (r > n || r < 0) return 0;
  if (n < 0) return 0;
  unsigned long long int n1 = 1, d1 = 1, d2 = 1;
  n1 = fact[n];
  d1 = fact_inv[r];
  d2 = fact_inv[n - r];
  unsigned long long int ans = (d1 * d2) % m;
  ans = (ans * n1) % m;
  return ans;
}
void pre_compute() {
  int mx = 100001;
  fact[0] = 1ll;
  for (int i = 1; i <= mx; ++i) {
    fact[i] = (fact[i - 1] * ((unsigned long long int)i)) %
              (unsigned long long int)1000000007ll;
  }
  for (int i = 0; i <= mx; ++i) {
    fact_inv[i] = mod_inverse(fact[i], (unsigned long long int)1000000007ll);
  }
}
class solver {
 public:
  void solve() {
    unsigned long long int s, n, k;
    cin >> s >> n >> k;
    n++;
    unsigned long long int tm = s / (2ll * k);
    unsigned long long int tmp = tm * k;
    unsigned long long int lim = min((2 * tm + 1) * k - 1, s);
    tmp += lim - (2 * tm * k) + 1ll;
    if (tmp < n) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test = 1;
  cin >> test;
  while (test--) {
    solver o;
    o.solve();
  }
}
