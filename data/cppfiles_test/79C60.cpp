#include <bits/stdc++.h>
using namespace std;
const bool read_file = false;
const char fi[] = "XX.inp";
const char fo[] = "XX.out";
void set_up() {
  if (read_file) {
    freopen(fi, "r", stdin);
    freopen(fo, "w", stdout);
  }
  cin.clear();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void just_do_it();
int main() {
  set_up();
  just_do_it();
}
const int ms = 3e5 + 20;
vector<int> adj[ms];
int dp[ms];
int a[ms];
int b[ms];
int f[ms];
set<pair<int, int>> s;
queue<int> q;
int n, cc;
vector<int> res;
void just_do_it() {
  fill_n(dp, ms, -1);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (i - a[i] == 0) {
      q.push(i);
      dp[i] = 1;
      f[i] = 0;
    } else {
      s.insert({i - a[i], i});
    }
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    adj[i + b[i]].push_back(i);
  }
  while (!q.empty()) {
    cc = q.front();
    for (auto x : adj[cc]) {
      set<pair<int, int>> t;
      for (auto p : s) {
        if (p.first > x) {
          break;
        }
        dp[p.second] = dp[cc] + 1;
        f[p.second] = x;
        t.insert(p);
        q.push(p.second);
      }
      for (auto p : t) {
        s.erase(p);
      }
    }
    q.pop();
  }
  if (dp[n] == -1) {
    cout << -1 << endl;
    return;
  }
  cc = n;
  while (true) {
    cc = f[cc];
    res.push_back(cc);
    if (cc == 0) {
      break;
    }
    cc += b[cc];
  }
  cout << res.size() << endl;
  for (auto x : res) {
    cout << x << " ";
  }
  return;
}
