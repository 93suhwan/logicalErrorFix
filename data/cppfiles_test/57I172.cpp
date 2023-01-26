#include <bits/stdc++.h>
using namespace std;
long long int fact[100010], fact_inv[100010];
long long int power(long long int x, long long int y, long long int m) {
  if (y == 0) return 1;
  long long int a = power(x, y / 2, m);
  if (y % 2) {
    return (a * ((a * x) % m)) % m;
  } else {
    return (a * a) % m;
  }
}
long long int mod_inverse(long long int x, long long int m) {
  return power(x, m - 2, m);
}
long long int ncr(long long int n, long long int r, long long int m) {
  if (r > n || r < 0) return 0;
  if (n < 0) return 0;
  long long int n1 = 1, d1 = 1, d2 = 1;
  n1 = fact[n];
  d1 = fact_inv[r];
  d2 = fact_inv[n - r];
  long long int ans = (d1 * d2) % m;
  ans = (ans * n1) % m;
  return ans;
}
void pre_compute() {
  int mx = 100001;
  fact[0] = 1ll;
  for (int i = 1; i <= mx; ++i) {
    fact[i] = (fact[i - 1] * ((long long int)i)) % (long long int)1000000007ll;
  }
  for (int i = 0; i <= mx; ++i) {
    fact_inv[i] = mod_inverse(fact[i], (long long int)1000000007ll);
  }
}
class solver {
 public:
  void solve() {
    long long int s, n, k;
    cin >> s >> n >> k;
    if (k > s) {
      cout << "NO\n";
      return;
    }
    n++;
    long long int tm = s / (2ll * k);
    long long int tmp = tm * k;
    tmp += min(k, (s % (2ll * k)) + 1ll);
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
