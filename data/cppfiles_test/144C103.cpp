#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
void solve() {
  priority_queue<pair<int, int>> q;
  int n, m, k;
  cin >> n >> m >> k;
  int x = n % m;
  int y = n / m;
  int u = 0;
  for (int i = 1; i <= x; i++) {
    cout << y + 1 << " ";
    for (int j = 0; j <= y; j++) {
      cout << ++u << " ";
      q.push({1, u});
    }
    cout << '\n';
  }
  for (int i = 1; i <= m - x; i++) {
    cout << y << " ";
    for (int j = 0; j < y; j++) {
      cout << ++u << " ";
      q.push({0, u});
    }
    cout << '\n';
  }
  vector<pair<int, int>> p;
  for (int i = 1; i < k; i++) {
    for (int j = 1; j <= m - x; j++) {
      cout << y << " ";
      for (int v = 0; v < y; v++) {
        cout << q.top().second << " ";
        p.push_back({q.top().first, q.top().second});
        q.pop();
      }
      cout << '\n';
    }
    for (int j = 1; j <= x; j++) {
      cout << y + 1 << " ";
      for (int v = 0; v <= y; v++) {
        cout << q.top().second << " ";
        p.push_back({q.top().first + 1, q.top().second});
        q.pop();
      }
      cout << '\n';
    }
    for (auto x : p) {
      q.push({x.first, x.second});
    }
    p.clear();
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
