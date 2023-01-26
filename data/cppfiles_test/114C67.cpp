#include <bits/stdc++.h>
using namespace std;
void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (fopen("1574"
            ".inp",
            "r")) {
    freopen(
        "1574"
        ".inp",
        "r", stdin);
    freopen(
        "1574"
        ".out",
        "w", stdout);
  }
}
const bool love = true;
const int N = 10;
int n, m;
int c[N];
vector<int> a[N];
map<vector<int>, bool> vis, D;
void readinp() {
  cin >> n;
  for (int i = int(0); i <= int(n - 1); i++) {
    cin >> c[i];
    for (int j = int(1); j <= int(c[i]); j++) {
      int x;
      cin >> x;
      a[i].push_back(x);
    }
  }
  cin >> m;
  for (int i = int(1); i <= int(m); i++) {
    vector<int> b;
    for (int j = int(1); j <= int(n); j++) {
      int x;
      cin >> x;
      x--;
      b.push_back(x);
    }
    D[b] = true;
  }
}
void solve() {
  vector<int> arr, ans;
  int sum = 0, res = 0;
  for (int i = int(0); i <= int(n - 1); i++)
    arr.push_back(c[i] - 1), sum += a[i][c[i] - 1];
  vis[arr] = true;
  priority_queue<pair<int, vector<int>>> Q;
  Q.push({sum, arr});
  int cnt = 0;
  while (!Q.empty() && cnt <= m * 2) {
    cnt++;
    sum = Q.top().first;
    arr = Q.top().second;
    Q.pop();
    if (D.find(arr) == D.end()) {
      for (auto i : arr) cout << i + 1 << ' ';
      return;
    }
    for (int j = int(0); j <= int(n - 1); j++) {
      if (arr[j] - 1 >= 0) {
        vector<int> tmp(arr.begin(), arr.end());
        int stmp = sum;
        tmp[j]--;
        stmp = stmp - a[j][arr[j]] + a[j][tmp[j]];
        if (vis.find(tmp) == vis.end()) {
          vis[tmp] = true;
          Q.push({stmp, tmp});
        }
      }
    }
  }
}
int main() {
  setIO();
  int t = 1;
  while (t--) {
    readinp();
    solve();
  }
  return 0;
}
