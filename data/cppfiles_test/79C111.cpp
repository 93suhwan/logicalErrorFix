#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
bool st[N];
long long a[N], b[N], d[N], p[N], f[N];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  queue<int> q;
  p[n] = -1;
  q.push(n);
  st[n] = 1;
  int mi = n;
  while (q.size()) {
    int t = q.front();
    q.pop();
    for (int i = t - mi + 1; i <= a[t]; i++) {
      int x = t - i;
      int y = x;
      x += b[x];
      if (!st[x]) {
        p[x] = t;
        f[x] = y;
        d[x] = d[t] + 1;
        st[x] = 1;
        q.push(x);
      }
      mi = min(mi, y);
    }
    if (st[0]) break;
  }
  if (st[0]) {
    stack<int> s;
    int x = 0;
    while (p[x] != -1) {
      s.push(x);
      x = p[x];
    }
    cout << d[0] << endl;
    while (s.size()) {
      int y = s.top();
      cout << f[y] << " ";
      s.pop();
    }
    puts("");
  } else {
    cout << -1 << endl;
  }
}
