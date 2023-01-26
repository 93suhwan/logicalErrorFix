#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long solve(vector<int> vec, bool parity) {
  long long ans = 0;
  vector<int> ptrs(2);
  for (int i = 0; i < vec.size() - 1; ++i)
    if ((parity && (i % 2 != vec[i] % 2)) ||
        (!parity && (i % 2 == vec[i] % 2))) {
      int par = !(vec[i] % 2);
      ptrs[par] = max(ptrs[par], i + 1);
      while (vec[ptrs[par]] % 2 != par) ++ptrs[par];
      ans += (ptrs[par] - i);
      swap(vec[i], vec[ptrs[par]]);
    }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, a, b;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> vec(n), par(2);
    for (int i = 0; i < n; ++i) {
      cin >> vec[i];
      ++par[vec[i] & 1];
    }
    if (abs(par[0] - par[1]) > 1)
      cout << -1;
    else {
      int mx = 0;
      if (par[1] > par[0]) mx = 1;
      long long ans = solve(vec, !mx);
      if (n % 2 == 0) ans = min(ans, solve(vec, mx));
      cout << ans;
    }
    cout << '\n';
  }
}
