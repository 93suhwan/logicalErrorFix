#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> p(n);
    for (auto& [a, b, c] : p) {
      cin >> b;
    }
    string mono;
    cin >> mono;
    for (int i = 0; i < n; ++i) {
      auto& [a, b, c] = p[i];
      a = mono[i] - '0';
      c = i;
    }
    sort(p.begin(), p.end());
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
      auto& [a, b, c] = p[i];
      ans[c] = i + 1;
    }
    for (auto& i : ans) {
      cout << i;
      if (&i != &ans.back()) {
        cout << ' ';
      }
    }
    cout << '\n';
  }
}
