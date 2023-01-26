#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long INF = 1e18;
const int MAXN = (1e5 + 5);
void setIO(string name = "") {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  if (name.size()) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  } else {
  }
  return;
}
void solve() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  string s;
  cin >> s;
  vector<int> bl, re;
  for (int j = 0; j < n; j++) {
    if (s[j] == 'B')
      bl.push_back(a[j]);
    else
      re.push_back(a[j]);
  }
  if (!bl.empty()) {
    sort(bl.begin(), bl.end());
    int p = bl.size();
    int cur = 1;
    int cnt = 1;
    int val = bl[0];
    for (int i = 1; i < p; i++) {
      if (bl[i] == bl[i - 1]) {
        cnt++;
      } else {
        if (val - cnt + 1 < cur) {
          cout << "NO\n";
          return;
        }
        val = bl[i];
        cur += cnt;
        cnt = 1;
      }
    }
    if (val - cnt + 1 < cur) {
      cout << "NO\n";
      return;
    }
  }
  if (!re.empty()) {
    sort(re.rbegin(), re.rend());
    int p = re.size();
    int cnt = 1;
    int val = re[0];
    int cur = n;
    for (int i = 1; i < p; i++) {
      if (re[i] == re[i - 1]) {
        cnt++;
      } else {
        if (val + cnt - 1 > cur) {
          cout << "NO\n";
          return;
        }
        val = re[i];
        cur -= cnt;
        cnt = 1;
      }
    }
    if (val + cnt - 1 > cur) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}
int main() {
  setIO("");
  int testcases = 1;
  cin >> testcases;
  while (testcases--) {
    solve();
  }
  return 0;
}
