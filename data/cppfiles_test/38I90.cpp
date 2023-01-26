#include <bits/stdc++.h>
using namespace std;
int n, m;
string s[1000005];
vector<int> del;
void sol(int L, int R) {
  int pos = lower_bound(del.begin(), del.end(), L + 1) - del.begin();
  if (pos != del.size()) {
    int val = del[pos];
    if (val <= R) {
      cout << "NO" << endl;
      return;
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
  int q;
  cin >> q;
  while (q--) {
    int L, R;
    cin >> L >> R;
    L--;
    R--;
    sol(L, R);
  }
  return 0;
}
