#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
const long long M = 1e6 + 7;
int n, m;
bool cmp(pair<int, int>& left, pair<int, int>& right) {
  return ((left.second * right.second) - m * left.first) >
         ((left.second * right.second) - m * right.first);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int me[N], him[N], vis[N] = {}, arr[N] = {};
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      char c;
      cin >> c;
      him[i] = c - '0';
    }
    for (int i = 0; i < n; i++) {
      char c;
      cin >> c;
      me[i] = c - '0';
      if (me[i]) {
        if (!him[i])
          ans++;
        else {
          if (i - 1 >= 0 && him[i - 1]) {
            if (!vis[i - 1]) {
              vis[i - 1] = 1;
              arr[i]++;
            } else {
              if (arr[i - 2] > 1) arr[i]++;
            }
          }
          if (i + 1 < n && him[i + 1]) {
            if (!vis[i + 1]) {
              vis[i + 1] = 1;
              arr[i]++;
            }
          }
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (him[i] && arr[i] > 0) ans++;
    }
    cout << ans << endl;
  }
}
