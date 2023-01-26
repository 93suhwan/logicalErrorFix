#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7, INF = 2e9 + 5, NN = 100000;
void solve() {
  int n;
  cin >> n;
  set<int> S;
  for (int x = 1; x * x <= n; x++) {
    S.insert(x * x);
  }
  for (int x = 1; x * x * x <= n; x++) {
    S.insert(x * x * x);
  }
  cout << S.size();
}
int main() {
  int t = 1;
  cin >> t;
  for (int tt = 0; tt < t; tt++) {
    solve();
    cout << endl;
  }
}
