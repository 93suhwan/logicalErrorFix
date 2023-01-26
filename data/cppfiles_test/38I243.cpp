#include <bits/stdc++.h>
using namespace std;
int n, m;
string s[1000005];
vector<int> del;
vector<int> del2;
void sol(int L, int R) {
  int pos = lower_bound(del.begin(), del.end(), L + 1) - del.begin();
  if (pos != del.size()) {
    int val = del[pos];
    if (val <= R) {
      cout << "NO" << endl;
      return;
    }
  }
  if (L + 1 < R) {
    int pos2 = lower_bound(del2.begin(), del2.end(), L + 2) - del2.begin();
    if (pos != del2.size()) {
      int val = del2[pos];
      if (val <= R) {
        cout << "NO" << endl;
        return;
      }
    }
  }
  cout << "YES" << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 1; i < m; i++) {
    int ok = 0;
    for (int j = 1; j < n; j++) {
      int row = j;
      int col = i;
      if (s[row][col - 1] == s[row - 1][col] && s[row - 1][col] == 'X') {
        if (s[row][col] == '.') {
          ok = 1;
        }
      }
    }
    if (ok) del.push_back(i);
  }
  for (int i = 2; i < m; i++) {
    int ok = 0;
    for (int j = 2; j < n; j++) {
      int row = j;
      int col = i;
      int sum = 0;
      sum += s[row - 2][col - 2] == 'X';
      sum += s[row - 2][col - 2] == 'X';
      sum += s[row - 2][col] == 'X';
      sum += s[row - 1][col - 2] == 'X';
      sum += s[row - 1][col - 1] == 'X';
      sum += s[row - 1][col] == 'X';
      sum += s[row][col - 2] == 'X';
      sum += s[row][col - 1] == 'X';
      sum += s[row][col] == 'X';
      if (sum == 9) {
        ok = 1;
      }
    }
    if (ok) del2.push_back(i);
  }
  int q;
  cin >> q;
  while (q--) {
    int L, R;
    cin >> L >> R;
    L--;
    R--;
    if (L == R || n == 1 || m == 1) {
      cout << "YES" << endl;
    } else
      sol(L, R);
  }
  return 0;
}
