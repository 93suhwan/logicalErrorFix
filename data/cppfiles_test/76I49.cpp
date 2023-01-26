#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159265358979323846, eps = 1e-9;
const long long M = 1e9 + 7, I = 1e18;
const int mxn = 2e5, mxn1 = 1e6 + 1, lg = 20;
int n, m;
vector<int> arr[mxn];
bool vis[mxn];
void f(vector<int>& v) {
  if (v.size() == 5) {
    int cnt = 0;
    for (int i : v) {
      for (int j : arr[i]) {
        if (vis[j]) cnt++;
      }
    }
    if (cnt == 0 or cnt == 10) {
      for (int i : v) cout << i + 1 << " ";
      exit(0);
    }
    return;
  }
  for (int i = 0; i < n; i++) {
    if (vis[i]) continue;
    vis[i] = 1;
    v.push_back(i);
    f(v);
    v.pop_back();
    vis[i] = 0;
  }
}
int main() {
  cin >> n >> m;
  n = min(n, 48);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (a >= n or b >= n) continue;
    arr[a].push_back(b);
    arr[b].push_back(a);
  }
  vector<int> cur;
  f(cur);
  cout << -1;
}
