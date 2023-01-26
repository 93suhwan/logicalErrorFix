#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, i, a, b, c;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> p(n), f(n);
    vector<vector<int>> V(n);
    for (i = 1; i < n; i++) {
      cin >> a >> b;
      a--;
      b--;
      V[a].push_back(b);
      V[b].push_back(a);
    }
    stack<int> s;
    s.push(0);
    p[0] = -1;
    vector<bool> k(n), q(n);
    q[0] = 1;
    while (!s.empty()) {
      a = s.top();
      for (int x : V[a]) {
        if (!q[x]) {
          s.push(x);
          q[x] = 1;
          p[x] = a;
        }
      }
      if (a == s.top()) {
        for (int x : V[a]) {
          if (x != p[a] && !k[x]) {
            k[a] = 1;
            f[a]++;
          }
        }
        s.pop();
      }
    }
    c = 0;
    for (i = 0; i < n; i++)
      if (k[i]) c += f[i] - 1;
    cout << c + 1 << endl;
  }
}
