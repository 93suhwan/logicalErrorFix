#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 100, M = 1e6 + 100;
int a[M];
vector<int> num[N];
int r[N * 2];
bool ans[N * 2];
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i < N * 2; i++) r[i] = N - 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    num[a[i]].push_back(0);
  }
  ans[0] = 1;
  int cnt = 1;
  for (int i = 1; i <= n; i++) {
    for (int v : num[a[i]]) {
      int h = a[i] ^ v;
      if (!ans[h]) {
        ans[h] = 1;
        cnt++;
      }
      while (r[h] > a[i]) num[r[h]--].push_back(h);
    }
    num[a[i]].clear();
  }
  cout << cnt << endl;
  for (int i = 0; i < N * 2; i++) {
    if (ans[i]) cout << i << " ";
  }
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  t = 1;
  while (t--) {
    solve();
  }
}
