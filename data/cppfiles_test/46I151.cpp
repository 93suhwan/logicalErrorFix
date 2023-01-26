#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int q = 0; q < t; q++) {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> xs(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      xs[i] = v[i];
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    map<int, int> c;
    for (int i = 0; i < xs.size(); i++) {
      c[xs[i]] = i;
    }
    int maxx = xs.size() - 1;
    int ans = (int)1e9;
    for (int i = 0; i < n; i++) {
      v[i] = c[v[i]];
      ans = min(ans, n - i - 1 + maxx - v[i]);
    }
    cout << ans << endl;
  }
}
