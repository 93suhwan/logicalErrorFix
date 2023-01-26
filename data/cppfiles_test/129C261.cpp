#include <bits/stdc++.h>
using namespace std;
int mod = pow(10, 9) + 7;
void solve() {
  int n;
  cin >> n;
  vector<int> rem;
  set<int> us;
  for (int i = 1; i <= n; i++) us.insert(i);
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    if (us.find(t) == us.end()) {
      rem.push_back(t);
    } else
      us.erase(t);
  }
  sort(rem.begin(), rem.end());
  reverse(rem.begin(), rem.end());
  for (auto item : rem) {
    auto iter = us.end();
    iter--;
    int m = *iter;
    if (m > (item - 1) / 2) {
      cout << "-1\n";
      return;
    }
    us.erase(iter);
  }
  cout << rem.size() << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tests;
  cin >> tests;
  for (int test = 0; test < tests; test++) {
    solve();
  }
}
