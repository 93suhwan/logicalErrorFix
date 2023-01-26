#include <bits/stdc++.h>
using namespace std;
bool can1(int r, int c, int k) {
  if (k & 1)
    return false;
  else
    return true;
}
bool can2(int r, int c, int k) {
  k -= c / 2;
  if (k < 0) return false;
  return can1(r - 1, c, k);
}
bool can3(int r, int c, int k) {
  if ((r * (c - 1)) / 2 >= k)
    return can1(r, c - 1, k);
  else
    return false;
}
bool isPossible(int x, int y, vector<vector<int>>& v) {
  if (x < 0 || y < 0) return false;
  if (x >= v.size() || y >= v[0].size()) return false;
  return true;
}
char get_h(int x, int y, vector<vector<int>>& v) {
  long long state = 0;
  {
    int a = x;
    int b = y - 1;
    if (isPossible(a, b, v) && v[a][b] != '$')
      state = state | (1 << (v[a][b] - 'a'));
  }
  {
    int a = x;
    int b = y + 2;
    if (isPossible(a, b, v) && v[a][b] != '$')
      state = state | (1 << (v[a][b] - 'a'));
  }
  {
    int a = x - 1;
    int b = y;
    if (isPossible(a, b, v) && v[a][b] != '$')
      state = state | (1 << (v[a][b] - 'a'));
  }
  {
    int a = x - 1;
    int b = y + 1;
    if (isPossible(a, b, v) && v[a][b] != '$')
      state = state | (1 << (v[a][b] - 'a'));
  }
  {
    int a = x + 1;
    int b = y;
    if (isPossible(a, b, v) && v[a][b] != '$')
      state = state | (1 << (v[a][b] - 'a'));
  }
  {
    int a = x + 1;
    int b = y + 1;
    if (isPossible(a, b, v) && v[a][b] != '$')
      state = state | (1 << (v[a][b] - 'a'));
  }
  for (int i = 0; i < 26; i++) {
    if ((state & (1 << i)) == 0) return 'a' + i;
  }
}
char get_v(int x, int y, vector<vector<int>>& v) {
  long long state = 0;
  {
    int a = x;
    int b = y - 1;
    if (isPossible(a, b, v) && v[a][b] != '$')
      state = state | (1 << (v[a][b] - 'a'));
  }
  {
    int a = x;
    int b = y + 1;
    if (isPossible(a, b, v) && v[a][b] != '$')
      state = state | (1 << (v[a][b] - 'a'));
  }
  {
    int a = x - 1;
    int b = y;
    if (isPossible(a, b, v) && v[a][b] != '$')
      state = state | (1 << (v[a][b] - 'a'));
  }
  {
    int a = x + 1;
    int b = y - 1;
    if (isPossible(a, b, v) && v[a][b] != '$')
      state = state | (1 << (v[a][b] - 'a'));
  }
  {
    int a = x + 1;
    int b = y + 1;
    if (isPossible(a, b, v) && v[a][b] != '$')
      state = state | (1 << (v[a][b] - 'a'));
  }
  {
    int a = x + 2;
    int b = y;
    if (isPossible(a, b, v) && v[a][b] != '$')
      state = state | (1 << (v[a][b] - 'a'));
  }
  for (int i = 0; i < 26; i++) {
    if ((state & (1 << i)) == 0) return 'a' + i;
  }
}
void print_1(int k, vector<vector<int>>& v, int x1, int y1, int x2, int y2) {
  int i = x1;
  int j = y1;
  while (k > 0) {
    char c = get_h(i, j, v);
    v[i][j] = c;
    v[i][j + 1] = c;
    i++;
    if (i > x2) {
      i = x1;
      j += 2;
    }
    k--;
  }
  while (i <= x2 && j <= y2) {
    char c = get_v(i, j, v);
    v[i][j] = c;
    v[i + 1][j] = c;
    c = get_v(i, j + 1, v);
    v[i][j + 1] = c;
    v[i + 1][j + 1] = c;
    i += 2;
    if (i > x2) {
      i = x1;
      j += 2;
    }
  }
}
void print_2(int k, vector<vector<int>>& v, int x1, int y1, int x2, int y2) {
  int i = x1;
  int j = y1;
  while (j <= y2) {
    char c = get_h(i, j, v);
    v[i][j] = c;
    v[i][j + 1] = c;
    j += 2;
    k--;
  }
  print_1(k, v, x1 + 1, y1, x2, y2);
}
void print_3(int k, vector<vector<int>>& v, int x1, int y1, int x2, int y2) {
  int i = x1;
  int j = y1;
  while (i <= x2) {
    char c = get_v(i, j, v);
    v[i][j] = c;
    v[i + 1][j] = c;
    i += 2;
  }
  print_1(k, v, x1, y1 + 1, x2, y2);
}
void print(int r, int c, int k) {
  vector<vector<int>> v(r, vector<int>(c, '$'));
  if (r & 1)
    print_2(k, v, 0, 0, r - 1, c - 1);
  else if (c & 1)
    print_3(k, v, 0, 0, r - 1, c - 1);
  else
    print_1(k, v, 0, 0, r - 1, c - 1);
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) cout << (char)v[i][j];
    cout << "\n";
  }
}
void solve() {
  int r, c, k;
  cin >> r >> c >> k;
  bool isPossibles = false;
  if (r & 1)
    isPossibles = can2(r, c, k);
  else if (c & 1)
    isPossibles = can3(r, c, k);
  else
    isPossibles = can1(r, c, k);
  if (isPossibles) {
    cout << "YES"
         << "\n";
    print(r, c, k);
  } else
    cout << "NO"
         << "\n";
}
int main() {
  int t = 1;
  cin >> t;
  for (int tt = 0; tt < t; tt++) {
    solve();
  }
  return 0;
}
