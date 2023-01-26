#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
int n, m, k, vis[12][22];
char ar[12][22];
int isValid(int r, int c) {
  int ret = 0;
  for (int i = 1;; i++) {
    int currR = r - i;
    int currC1 = c - i, currC2 = c + i;
    if (currR >= 0 && currR < n && currC1 >= 0 && currC1 < m && currC2 >= 0 &&
        currC2 < m && ar[currR][currC1] == '*' && ar[currR][currC2] == '*') {
      ret++;
    } else {
      break;
    }
  }
  return ret;
}
void taken(int r, int c) {
  vis[r][c] = 1;
  for (int i = 1;; i++) {
    int currR = r - i;
    int currC1 = c - i, currC2 = c + i;
    if (currR >= 0 && currR < n && currC1 >= 0 && currC1 < m && currC2 >= 0 &&
        currC2 < m && ar[currR][currC1] == '*' && ar[currR][currC2] == '*') {
      vis[currR][currC1] = 1;
      vis[currR][currC2] = 1;
    } else {
      break;
    }
  }
}
void solve() {
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      ar[i][j] = s[j];
    }
  }
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (ar[i][j] == '*') {
        int sizeOfTick = isValid(i, j);
        if (sizeOfTick >= k) {
          taken(i, j);
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (ar[i][j] == '*' && !vis[i][j]) {
        cout << "NO" << endl;
        ;
        return;
      }
    }
  }
  cout << "YES" << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int ts = 1, cs = 1;
  cin >> ts;
  while (ts--) {
    solve();
  }
}
