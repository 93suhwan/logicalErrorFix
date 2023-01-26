#include <bits/stdc++.h>
using namespace std;
char read() {
  char ch = getchar();
  while (ch != '.' && ch != 'X') ch = getchar();
  return ch;
}
int n, m;
vector<vector<char> > s;
bool cant[1000005];
int seq[1000005], total;
bool check(int l, int r) {
  if (total == 0) return true;
  int nl = 1, nr = total;
  while (nl <= nr) {
    int mid = nl + nr >> 1;
    if (seq[mid] >= l)
      nr = mid - 1;
    else
      nl = mid + 1;
  }
  int tp = nr + 1;
  nl = 1, nr = total;
  while (nl <= nr) {
    int mid = nl + nr >> 1;
    if (seq[mid] <= r)
      nl = mid + 1;
    else
      nr = mid - 1;
  }
  int tp2 = nl - 1;
  if (tp > tp2) return true;
  return false;
}
int main() {
  cin >> n >> m;
  vector<char> tp;
  for (int i = 0; i <= m; ++i) tp.push_back(0);
  for (int i = 0; i <= n; ++i) {
    s.push_back(tp);
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      s[i][j] = read();
    }
  for (int i = 2; i <= n; ++i) {
    for (int j = 2; j <= m; ++j) {
      if (s[i][j] == 'X') {
        if (s[i - 1][j] == 'X' && s[i][j - 1] == 'X')
          ;
        else if (s[i - 1][j] == '.' && s[i][j - 1] == '.')
          ;
        else
          cant[j] = true;
      }
    }
  }
  for (int i = 1; i <= m; ++i)
    if (cant[i]) {
      seq[++total] = i;
    }
  int T;
  cin >> T;
  while (T--) {
    int l, r;
    cin >> l >> r;
    if (check(l, r))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
