#include <bits/stdc++.h>
using namespace std;
int arr[100001], ori[100001];
int* sz[100001];
bool vis[100001];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n, q, cnt = 0;
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) cin >> arr[i];
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      int x = i;
      for (; !vis[x];) {
        ++ori[cnt];
        sz[x] = &ori[cnt];
        vis[x] = 1;
        x = arr[x];
      }
    }
  }
  for (; q--;) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      if (sz[x] != sz[y]) {
        int sum = *sz[x] + *sz[y];
        *sz[x] = *sz[y] = sum;
      }
      swap(arr[x], arr[y]);
    } else {
      int need = y % *sz[x];
      int ans = x;
      for (; need--; ans = arr[ans])
        ;
      cout << ans << '\n';
    }
  }
}
