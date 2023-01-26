#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
char grid[100][100];
void solve();
void printGrid(int, int, int);
void createGrid(int, int, int);
int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int max_horizontal, min_horizontal;
  if (m == 1) {
    if (k == 0) {
      printf("YES\n");
    } else
      printf("NO\n");
    return;
  }
  if (n == 1) {
    if (k == m / 2) {
      printf("YES\n");
    } else
      printf("NO\n");
    return;
  }
  if (n % 2 == 0) {
    max_horizontal = (n / 2) * (m / 2) * 2;
    min_horizontal = 0;
  } else {
    max_horizontal = (m * n) / 2;
    min_horizontal = m / 2;
  }
  if (max_horizontal % 2 == k % 2 && k >= min_horizontal &&
      k <= max_horizontal) {
    printf("YES\n");
  } else
    printf("NO\n");
  return;
}
void printGrid(int n, int m, int k) { return; }
void createGrid(int n, int m, int k) {
  char ch = 'a';
  if (n % 2 == 0) {
    for (int i = 0; i < n; i += 2) {
      for (int j = 0; j < n; j += 2) {
        grid[i][j] = ch;
        grid[i + 1][j] = ch;
        grid[i][j + 1] = ch + 1;
        grid[i + 1][j + 1] = ch + 1;
        ch += 2;
      }
      if (ch == 'i') ch = 'a';
    }
  }
  return;
}
