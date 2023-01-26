#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
const int maxn = 1e5 + 5;
void solve() {
  double n;
  cin >> n;
  vector<long long> v(n);
  double ans_m = 0;
  unordered_map<long long, long long> amp;
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    ans_m += v[i];
    amp[v[i]]++;
  }
  ans_m = (2 * ans_m) / n;
  long long res = 0;
  for (long long i = 0; i < n; i++) {
    long long ans = ans_m - v[i];
    if (amp[ans] > 0) {
      res += amp[ans];
    }
    if (ans == v[i]) {
      res--;
    }
  }
  cout << res / 2 << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long l = 1;
  cin >> l;
  while (l--) {
    solve();
  }
  return 0;
}
