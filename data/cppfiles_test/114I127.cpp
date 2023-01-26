#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;
int n, q;
vector<vector<long long>> c;
vector<vector<int>> banned;
long long ans = 0;
vector<int> ansv;
void solve() {
  cin >> n;
  c.resize(n);
  for (int i = 0; i < (int)(n); ++i) {
    int k;
    cin >> k;
    c[i].resize(k);
    for (int j = 0; j < (int)(k); ++j) cin >> c[i][j];
  }
  cin >> q;
  banned.resize(q);
  for (int i = 0; i < (int)(q); ++i) {
    banned[i].resize(n);
    long long sum = 0;
    for (int j = 0; j < (int)(n); ++j) {
      cin >> banned[i][j];
      banned[i][j]--;
      sum += c[j][banned[i][j]];
    }
    for (int j = 0; j < (int)(n); ++j) {
      if (banned[i][j] > 0) {
        if (ans < (sum - c[j][banned[i][j]] + c[j][banned[i][j] - 1])) {
          ans = (sum - c[j][banned[i][j]] + c[j][banned[i][j] - 1]);
          ansv = banned[i];
          ansv[j]--;
        }
      }
    }
  }
  for (int x : ansv) cout << x + 1 << " ";
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(9);
  solve();
  return 0;
}
