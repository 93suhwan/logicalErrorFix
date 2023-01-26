#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(123);
const int N = 2005;
struct line {
  int a, b;
  int y(int x) { return a * x + b; }
};
double inter(line l1, line l2) { return (double)(l1.b - l2.b) / (l2.a - l1.a); }
vector<line> st;
bool bad(line l) {
  return ((int)(st).size()) >= 2 &&
         inter(l, st.back()) < inter(st.back(), st[((int)(st).size()) - 2]);
}
void add(line l) {
  while (bad(l)) {
    st.pop_back();
  }
  st.push_back(l);
}
int query(int x) {
  int l = 0, r = ((int)(st).size());
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (inter(st[m], st[m - 1]) <= x) {
      l = m;
    } else {
      r = m;
    }
  }
  return st[l].y(x);
}
int n, m;
int a[N][N];
int best[N][N];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  ++n, ++m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char aa;
      cin >> aa;
      a[i][j] = aa - '0';
    }
  }
  for (int j = 0; j < m; ++j) {
    vector<int> prv(n, -1);
    for (int i = 0; i < n; ++i) {
      if (i != 0) prv[i] = prv[i - 1];
      if (a[i][j] == 1) prv[i] = i;
    }
    vector<int> nxt(n, -1);
    for (int i = n - 1; i >= 0; --i) {
      if (i != n - 1) nxt[i] = nxt[i + 1];
      if (a[i][j] == 1) nxt[i] = i;
    }
    for (int i = 0; i < n; ++i) {
      if (prv[i] == -1 && nxt[i] == -1) {
        best[i][j] = -1;
      } else {
        if (prv[i] == -1 || (nxt[i] != -1 && nxt[i] - i < i - prv[i])) {
          best[i][j] = nxt[i];
        } else {
          best[i][j] = prv[i];
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    st.clear();
    for (int j = 0; j < m; ++j) {
      if (best[i][j] != -1) {
        int x = best[i][j];
        add(line{-2 * j, x * x - 2 * x * i + i * i + j * j});
      }
    }
    for (int j = 0; j < m; ++j) {
      ans += query(j) + j * j;
    }
  }
  cout << ans << endl;
  return 0;
}
