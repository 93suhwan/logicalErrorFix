#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
bool st[N];
long long a[N], b[N], d[N], p[N];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  queue<int> q;
  p[n] = -1;
  q.push(n);
  st[n] = 1;
  while (q.size()) {
    int t = q.front();
    q.pop();
    for (int i = 0; i <= a[t]; i++) {
      int x = t - i;
      x += b[x];
      if (!st[x]) {
        p[x] = t;
        d[x] = d[t] + 1;
        st[x] = 1;
        q.push(x);
      }
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
    while (s.size()) {
      int y = s.top();
      cout << y - b[y] << " ";
      s.pop();
    }
    puts("");
    cout << d[0] << endl;
  } else {
    cout << -1 << endl;
  }
}
