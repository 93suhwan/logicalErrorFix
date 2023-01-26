#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;
int n, q;
vector<vector<long long>> c;
vector<vector<int>> banned;
set<string> blocked;
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
    for (int j = 0; j < (int)(n); ++j) {
      cin >> banned[i][j];
      banned[i][j]--;
      sum[i] += c[j][banned[i][j]];
    }
    blocked.insert(getStr(banned[i]));
  }
  for (int i = 0; i < (int)(q); ++i) {
    for (int j = 0; j < (int)(n); ++j) {
      if (banned[i][j] > 0) {
        banned[i][j]--;
        if (blocked.count(getStr(banned[i])) == 0 &&
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
