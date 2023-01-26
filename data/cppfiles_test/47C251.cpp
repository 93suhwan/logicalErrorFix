#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int t, n, k;
long long solve(vector<int> &v) {
  sort(begin(v), end(v));
  int n = (int)v.size();
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += long long(v[i] - (i ? v[i - 1] : 0)) *
           ((n - i - 1) / k + 1 + max(0, (n - i - 1) / k));
  }
  return ans;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    vector<int> a, b;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      if (x < 0)
        a.push_back(-x);
      else
        b.push_back(x);
    }
    long long ans = solve(a) + solve(b);
    if (!a.size() || !(int)b.size()) {
      cout << ans << "\n";
      continue;
    }
    ans += min(a[(int)a.size() - 1], b[(int)b.size() - 1]);
    cout << ans << "\n";
  }
}
