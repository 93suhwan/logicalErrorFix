#include <bits/stdc++.h>
using namespace std;
mt19937 rng((int)chrono::steady_clock::now().time_since_epoch().count());
int vx[] = {-1, 0, 1, -1, 1, 0};
int vy[] = {0, -1, 0, 1, 1, 2};
int vvx[] = {-1, 0, 1, 1, -1, 0, 1, 1};
int vvy[] = {0, -1, -1, 0, 1, 2, 2, 1};
char mat[105][105];
void solve() {
  int n, m, horizontal;
  cin >> n >> m >> horizontal;
  int vertical = n * m / 2 - horizontal;
  int oxe = 0, nte = 0;
  if (n % 2 != m % 2) {
    if (n % 2 == 0) {
      char cur = 'a';
      for (int i = 0; i < n; i += 2) {
        mat[i][m - 1] = mat[i + 1][m - 1] = cur++;
        if (cur > 'z') cur = 'a';
      }
      vertical -= n / 2;
      m--;
      nte = 1;
    } else {
      char cur = 'a';
      for (int j = 0; j < m; j += 2) {
        mat[n - 1][j] = mat[n - 1][j + 1] = cur++;
        if (cur > 'z') cur = 'a';
      }
      horizontal -= m / 2;
      n--;
      oxe = 1;
    }
  }
  assert(n % 2 == 0 && m % 2 == 0);
  int puth = n * m / 2;
  int putv = 0;
  auto valid = [&](int i, int j) {
    if (i >= 0 && i < n && j >= 0 && j < m) return mat[i][j];
    return '?';
  };
  char cur = 'a';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j += 2) {
      vector<char> caras;
      bool flag = false;
      for (int k = 0; k < 6; k++) {
        caras.push_back(valid(i + vx[k], j + vy[k]));
        if (caras.back() == cur) flag = true;
      }
      while (flag) {
        cur++;
        if (cur > 'z') cur = 'a';
        flag = false;
        for (auto x : caras) {
          if (x == cur) flag = true;
        }
      }
      mat[i][j] = mat[i][j + 1] = cur;
    }
  }
  char other = 'a';
  for (int i = 0; i < n; i += 2) {
    for (int j = 0; j < m; j += 2) {
      if (puth == horizontal && putv == vertical) {
        cout << "YES\n";
        for (int ii = 0; ii < n + oxe; ii++) {
          for (int jj = 0; jj < m + nte; jj++) {
            cout << mat[ii][jj];
          }
          cout << '\n';
        }
        return;
      }
      vector<char> aa, bb;
      for (int k = 0; k < 8; k++) {
        if (k < 4)
          aa.push_back(valid(i + vvx[k], j + vvy[k]));
        else
          bb.push_back(valid(i + vvx[k], j + vvy[k]));
      }
      bool flag = false;
      for (auto x : aa) {
        if (x == cur) flag = true;
      }
      for (auto x : bb) {
        if (x == other) flag = true;
      }
      while (flag) {
        cur++;
        if (cur > 'z') cur = 'a';
        flag = false;
        for (auto x : aa) {
          if (x == cur) flag = true;
        }
      }
      while (flag) {
        other++;
        if (other > 'z') other = 'a';
        flag = false;
        for (auto x : bb) {
          if (x == other) flag = true;
        }
        if (other == cur) flag = true;
      }
      mat[i][j] = mat[i + 1][j] = cur;
      mat[i][j + 1] = mat[i + 1][j + 1] = other;
      puth -= 2;
      putv += 2;
    }
  }
  cout << "NO\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
