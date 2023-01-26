#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 1;
priority_queue<pair<int, int> > q;
int n, a[maxn], win[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    q.push(pair<int, int>(a[i], i));
  }
  while (!q.empty()) {
    pair<int, int> now = q.top();
    q.pop();
    if (win[now.second] == 0) {
      win[now.second] = 1;
      int j = now.second - 1;
      while (j > 0 && a[now.second] == a[j] && win[j] == 0) {
        win[j] = 1;
        j--;
      }
      if (j > 0 && win[j] == 0) win[j] = -1;
      j = now.second + 1;
      while (j <= n && a[now.second] == a[j] && win[j] == 0) {
        win[j] = 1;
        j++;
      }
      if (j <= n && win[j] == 0) win[j] = -1;
    }
  }
  if (win[1] == -1 && win[n] == -1)
    cout << "Bob\n";
  else
    cout << "Alice\n";
  return 0;
}
