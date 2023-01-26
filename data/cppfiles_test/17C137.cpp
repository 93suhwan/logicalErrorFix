#include <bits/stdc++.h>
using namespace std;
vector<long long> x;
class BIT {
 public:
  vector<long long> bit;
  BIT(long long n) { bit = vector<long long>(n + 1, 0); }
  void update(long long k) {
    while (k < (long long)bit.size()) {
      bit[k]++;
      k += (k & (-k));
    }
  }
  long long query(long long k) {
    long long sum = 0;
    while (k) {
      sum += bit[k];
      k -= (k & (-k));
    }
    return sum;
  }
};
void solve() {
  long long n;
  cin >> n;
  x.clear();
  for (long long i = 0; i < n; i++) {
    long long k;
    cin >> k;
    x.push_back(k);
  };
  vector<long long> y = x;
  sort(y.begin(), y.end());
  y.erase(unique(y.begin(), y.end()), y.end());
  for (auto &i : x) {
    i = lower_bound(y.begin(), y.end(), i) - y.begin() + 1;
  }
  BIT b = BIT(n + 2);
  long long ans = 0;
  for (long long j = 0; j < n; j++) {
    long long p = b.query(x[j] - 1);
    long long s = b.query(x[j]) - p;
    long long l = p, u = j - p - s;
    ans += min(l, u);
    b.update(x[j]);
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
