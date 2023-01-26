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
      if (now.second - 1 > 0 && win[now.second - 1] == 0) {
        if (a[now.second - 1] < a[now.second])
          win[now.second - 1] = -1;
        else if (a[now.second - 1] == a[now.second])
          win[now.second - 1] = 1;
      }
      if (now.second + 1 <= n && win[now.second + 1] == 0) {
        if (a[now.second + 1] < a[now.second])
          win[now.second + 1] = -1;
        else if (a[now.second + 1] == a[now.second])
          win[now.second + 1] = 1;
      }
    }
  }
  if (win[1] == -1 && win[n] == -1)
    cout << "Bob\n";
  else
    cout << "Alice\n";
  return 0;
}
