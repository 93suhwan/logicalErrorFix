#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;
int n, q;
vector<vector<long long>> c;
vector<vector<int>> banned;
set<vector<int>> blocked;
long long sum[N];
long long ans = 0;
vector<int> ansv;
string getStr(vector<int>& a) {
  string tmp = "";
  for (int i = 0; i < (int)(n); ++i) {
    tmp = tmp + to_string(a[i]) + "#";
  }
  return tmp;
}
void solve() {
  cin >> n;
  c.resize(n);
  vector<int> mx;
  for (int i = 0; i < (int)(n); ++i) {
    int k;
    cin >> k;
    c[i].resize(k);
    mx.push_back(k - 1);
    for (int j = 0; j < (int)(k); ++j) cin >> c[i][j];
  }
  cin >> q;
  banned.resize(q);
  for (int i = 0; i < (int)(q); ++i) {
    banned[i].resize(n);
    for (int j = 0; j < (int)(n); ++j) {
      cin >> banned[i][j];
      banned[i][j]--;
      sum[i] += c[j][banned[i][j]];
    }
    blocked.insert(banned[i]);
  }
  if (blocked.count(mx) == 0) {
    ansv = mx;
    for (int i = 0; i < (int)(n); ++i) ans += c[i].back();
  }
  for (int i = 0; i < (int)(q); ++i) {
    for (int j = 0; j < (int)(n); ++j) {
      if (banned[i][j] > 0) {
        banned[i][j]--;
        if (blocked.count(banned[i]) == 0 &&
            ans < (sum[i] - c[j][banned[i][j] + 1] + c[j][banned[i][j]])) {
          ans = (sum[i] - c[j][banned[i][j] + 1] + c[j][banned[i][j]]);
          ansv = banned[i];
        }
        banned[i][j]++;
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
