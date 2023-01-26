#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
const int INF = 1e9 + 7;
const int MAXN = 2e6 + 7;
int A[N], B[N];
vector<pair<int, int> > pp[MAXN];
void solve() {
  int n;
  cin >> n;
  vector<int> V[2];
  for (int i = 1; i <= n; ++i) {
    int val;
    cin >> val;
    V[val & 1].push_back(val);
  }
  if (n == 2) {
    int flag = -INF;
    for (int c = 0; c < 2; ++c)
      for (int to : V[c]) {
        if (flag == -INF) flag = to;
        if (flag != to) {
          cout << "NO\n";
          return;
        }
      }
    cout << "YES\n";
    cout << 0 << ' ' << flag << '\n';
    return;
  }
  if (V[0].empty()) {
    for (int i = 0; i < n; ++i) {
      B[i + 1] = V[1][i];
    }
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j) {
        if (B[i] < B[j] || (B[i] == B[j] && i < j))
          pp[abs(B[i] - B[j])].push_back({i, j});
      }
    pair<pair<int, int>, pair<int, int> > need = {{-1, -1}, {-1, -1}};
    for (int s = 0; s < MAXN; ++s) {
      int sz = pp[s].size();
      for (int i = 0; i < sz; ++i) {
        for (int j = i + 1; j < sz; ++j) {
          pair<int, int> p1 = pp[s][i], p2 = pp[s][j];
          if (p1.first != p2.first && p1.first != p2.second &&
              p1.second != p2.first && p1.second != p2.second) {
            need = {p1, p2};
            break;
          }
        }
        if (need.first.first != -1) break;
      }
      if (need.first.first != -1) break;
    }
    if (need.first.first == -1) {
      cout << "NO\n";
      return;
    }
    A[1] = 0;
    A[2] = B[need.second.first] - B[need.first.first];
    int ptr = 1;
    for (int i = 3; i <= n; ++i) {
      while (ptr == need.second.first || ptr == need.second.second) ++ptr;
      A[i] = B[ptr++];
    }
    cout << "YES\n";
    for (int i = 1; i <= n; ++i) cout << A[i] << ' ';
    cout << '\n';
    return;
  }
  int ptr = 1;
  for (int to : V[1]) {
    A[++ptr] = to;
  }
  for (int to : V[0]) {
    A[++ptr] = to;
  }
  int val = A[n + 1] - A[2] - A[3];
  if (val & 1) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  val = val >> 1;
  A[1] = -(val << 1);
  for (int i = 1; i <= n; ++i) cout << A[i] + val << ' ';
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) solve();
}
