#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<string, int>> a(n);
  int c = 1;
  for (auto &t : a) {
    cin >> t.first;
    t.second = c++;
  }
  for (auto &t : a) {
    for (int i = 1; i < m; i += 2) {
      t.first[i] = 'z' - t.first[i] + 'a';
    }
  }
  sort(a.begin(), a.end());
  for (auto t : a) {
    cout << t.second << " ";
  }
}
int main() {
  solve();
  return 0;
}
