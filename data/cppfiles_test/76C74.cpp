#include <bits/stdc++.h>
using namespace std;
int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  int L = min(50, n);
  vector<vector<bool>> g(L, vector<bool>(L, 0));
  for (int i = 0; i < (int)(m); i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    if (a < 50 && b < 50) {
      g[a][b] = g[b][a] = 1;
    }
  }
  bool ok = false, tmpok;
  vector<int> res(5, -1);
  for (int a = 0; a < L; a++) {
    res[0] = a;
    for (int b = a + 1; b < L; b++) {
      tmpok = 1;
      for (int i = 0; tmpok && i < 1; i++) {
        if (!g[b][res[i]]) tmpok = 0;
      }
      if (!tmpok) continue;
      res[1] = b;
      for (int c = b + 1; c < L; c++) {
        tmpok = 1;
        for (int i = 0; tmpok && i < 2; i++) {
          if (!g[c][res[i]]) tmpok = 0;
        }
        if (!tmpok) continue;
        res[2] = c;
        for (int d = c + 1; d < L; d++) {
          tmpok = 1;
          for (int i = 0; tmpok && i < 3; i++) {
            if (!g[d][res[i]]) tmpok = 0;
          }
          if (!tmpok) continue;
          res[3] = d;
          for (int e = d + 1; e < L; e++) {
            tmpok = 1;
            for (int i = 0; tmpok && i < 4; i++) {
              if (!g[e][res[i]]) tmpok = 0;
            }
            if (!tmpok) continue;
            res[4] = e;
            ok = true;
            goto YES;
          }
        }
      }
    }
  }
  for (int a = 0; a < L; a++) {
    res[0] = a;
    for (int b = a + 1; b < L; b++) {
      tmpok = 1;
      for (int i = 0; tmpok && i < 1; i++) {
        if (g[b][res[i]]) tmpok = 0;
      }
      if (!tmpok) continue;
      res[1] = b;
      for (int c = b + 1; c < L; c++) {
        tmpok = 1;
        for (int i = 0; tmpok && i < 2; i++) {
          if (g[c][res[i]]) tmpok = 0;
        }
        if (!tmpok) continue;
        res[2] = c;
        for (int d = c + 1; d < L; d++) {
          tmpok = 1;
          for (int i = 0; tmpok && i < 3; i++) {
            if (g[d][res[i]]) tmpok = 0;
          }
          if (!tmpok) continue;
          res[3] = d;
          for (int e = d + 1; e < L; e++) {
            tmpok = 1;
            for (int i = 0; tmpok && i < 4; i++) {
              if (g[e][res[i]]) tmpok = 0;
            }
            if (!tmpok) continue;
            res[4] = e;
            ok = true;
            goto YES;
          }
        }
      }
    }
  }
  if (!ok) {
    cout << "-1\n";
    return 0;
  }
YES : {
  if (ok) {
    for (auto x : res) {
      cout << x + 1 << ' ';
    }
    cout << "\n";
  }
}
  return 0;
}
