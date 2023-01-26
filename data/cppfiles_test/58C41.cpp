#include <bits/stdc++.h>
using namespace std;
template <typename T>
using vv = vector<vector<T>>;
void scar(long long *arr, long long n) {
  for (long long i = 0; i < n; i++) cin >> arr[i];
}
vector<pair<long long, long long>> px({{-1, 1}, {0, 1}, {1, 1}});
void q1() {
  long long n;
  string str[2];
  cin >> n;
  cin >> str[0] >> str[1];
  long long x = 0, y = 0;
  if (str[0][0] == '1') {
    cout << "NO"
         << "\n";
    return;
  }
  vector<vector<bool>> vis(2, vector<bool>(n, false));
  vis[0][0] = true;
  queue<pair<long long, long long>> q;
  q.push({x, y});
  while (!q.empty()) {
    pair<long long, long long> top = q.front();
    q.pop();
    if (top.first == 1 && top.second == (n - 1)) {
      cout << "YES"
           << "\n";
      return;
    }
    for (auto p : px) {
      if (p.first + top.first >= 0 && p.first + top.first < 2 &&
          p.second + top.second < n &&
          vis[p.first + top.first][p.second + top.second] == false &&
          str[p.first + top.first][p.second + top.second] == '0') {
        vis[p.first + top.first][p.second + top.second] = true;
        q.push({p.first + top.first, p.second + top.second});
      }
    }
  }
  cout << "NO"
       << "\n";
}
void q2() {}
void q3() {}
void q4() {}
void q5() {}
void solve() { q1(); }
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
