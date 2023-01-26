#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
const int maxn = 1e5 + 5;
void solve() {
  double n;
  cin >> n;
  vector<double> v(n);
  double ans_m = 0;
  unordered_map<double, long long> amp;
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    ans_m += v[i];
    amp[v[i]]++;
  }
  ans_m /= n;
  long long res = 0;
  for (long long i = 0; i < n; i++) {
    double r = v[i];
    amp[v[i]]--;
    double ans = ans_m;
    ans = ans * 2;
    ans -= v[i];
    if (amp[ans] > 0) {
      if (amp[ans] > 1) {
        res += (amp[ans] * 2);
      } else {
        res++;
      }
      amp[ans] = 0;
    }
  }
  cout << res << '\n';
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
