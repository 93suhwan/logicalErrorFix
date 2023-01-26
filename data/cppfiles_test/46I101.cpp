#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<long long> v(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  long long soln = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      if (!(i % 2 == 0 && j % 2 == 1)) {
        continue;
      }
      long long run = 0;
      long long minv = 0;
      for (int k = i + 1; k < j; ++k) {
        if (k % 2 == 0) {
          run += v[k];
        } else {
          run -= v[k];
          minv = min(minv, run);
        }
      }
      long long amt = min(v[i] + minv, max(0LL, v[j] - run));
      soln += amt;
    }
  }
  cout << soln << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
