#include <bits/stdc++.h>
using namespace std;
int n;
int cnt = 0;
void rec(vector<bool> mask, int i, int ops) {
  if (cnt == n) return;
  if (i == n) {
    for (int j = 0; j < n; j++) cout << char('(' + mask[j]);
    for (int j = 0; j < n; j++) {
      if (ops > 0) {
        cout << ')';
        ops--;
      } else {
        cout << '(';
        ops++;
      }
    }
    cout << endl;
    cnt++;
  } else {
    mask[i] = 0;
    rec(mask, i + 1, ops + 1);
    if (ops > 0) {
      mask[i] = 1;
      rec(mask, i + 1, ops - 1);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    cnt = 0;
    vector<bool> t(n, 0);
    rec(t, 0, 0);
  }
  return 0;
}
