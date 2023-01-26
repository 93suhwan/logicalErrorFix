#include <bits/stdc++.h>
using namespace std;
const int N = 100;
char str[N];
char ans[N][N];
void ac() {
  int n;
  cin >> n;
  cin >> str + 1;
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    if (str[i] == '1') {
      for (int j = 1; j <= n; j++) {
        ans[i][j] = '=';
      }
    } else {
      for (int j = 1; j <= n; j++) {
        ans[i][j] = '=';
      }
      v.push_back(i);
    }
  }
  if (v.size() == 1 || v.size() == 2) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  int siz = v.size();
  for (int i = 0; i < siz; i++) {
    if (i == siz - 1) {
      ans[v[i]][v[0]] = '+';
      ans[v[0]][v[i]] = '-';
    } else {
      int ying = v[i];
      int shu = v[i + 1];
      ans[ying][shu] = '+';
      ans[shu][ying] = '-';
    }
  }
  for (int i = 1; i <= n; i++) {
    ans[i][i] = 'X';
  }
  for (int j = 1; j <= n; j++) {
    for (int k = 1; k <= n; k++) {
      cout << ans[j][k];
    }
    cout << endl;
  }
}
signed main() {
  int t;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  for (int i = 1; i <= t; i++) ac();
  return 0;
}
