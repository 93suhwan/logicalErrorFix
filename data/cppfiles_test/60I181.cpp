#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  int mean = 0;
  for (int i = 0; i < n; i++) {
    int el;
    cin >> el;
    mean += el;
    v.push_back(el);
  }
  mean /= n;
  int ans = 0;
  for (int i = 0; i < v.size() - 1; i++) {
    for (int j = i + 1; j < v.size(); j++) {
      if (v[i] + v[j] == 2 * mean) {
        ans++;
      }
    }
  }
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
