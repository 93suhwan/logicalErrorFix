#include <bits/stdc++.h>
using namespace std;
int n, a[10005], b[2];
vector<int> g[2];
int ask(int a, int b, int c) {
  cout << "? " << a << " " << b << " " << c << endl;
  int x;
  cin >> x;
  return x;
}
void get1(int a1, int a2, int a3, int c) {
  int s1 = ask(a1, a2, g[c ^ 1][0]), s2 = ask(a2, a3, g[c ^ 1][0]);
  if (s1 == c && s2 == c)
    g[c].push_back(a1), g[c].push_back(a2), g[c].push_back(a3);
  if (s1 == c && s2 != c)
    g[c].push_back(a1), g[c].push_back(a2), g[c ^ 1].push_back(a3);
  if (s1 != c && s2 == c)
    g[c ^ 1].push_back(a1), g[c].push_back(a2), g[c].push_back(a3);
  if (s1 != c && s2 != c)
    g[c].push_back(a1), g[c ^ 1].push_back(a2), g[c].push_back(a3);
}
void get2(int x) { g[ask(x, g[0][0], g[1][0])].push_back(x); }
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    g[0].clear(), g[1].clear();
    for (int i = 1; i <= n; i += 3) {
      a[i] = ask(i, i + 1, i + 2);
      b[a[i]] = i;
    }
    int a1 = b[0], a2 = b[0] + 1, a3 = b[0] + 2;
    int b1 = b[1], b2 = b[1] + 1, b3 = b[1] + 2;
    int s1 = ask(a1, a2, b1), s2 = ask(a1, a2, b2);
    if (s1 == 0 && s2 == 0) {
      g[0].push_back(a1);
      g[0].push_back(a2);
      get1(b1, b2, b3, 1), get2(a3);
    } else {
      g[0].push_back(a3);
      g[s1].push_back(b1);
      g[s2].push_back(b2);
      get2(a1), get2(a2), get2(b3);
    }
    for (int i = 1; i <= n; i += 3) {
      if (b[0] == i || b[1] == i) continue;
      cout << "hei";
      get1(i, i + 1, i + 2, a[i]);
    }
    cout << "! " << g[0].size() << " ";
    for (int i = 0; i < g[0].size(); i++) {
      cout << g[0][i] << " ";
    }
    cout << endl;
  }
  return 0;
}
