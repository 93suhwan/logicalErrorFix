#include <bits/stdc++.h>
using namespace std;
int codefo;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> codefo;
  while (codefo--) {
    int n;
    cin >> n;
    string S, T;
    cin >> S >> T;
    if (S == T) {
      cout << 0 << endl;
      continue;
    }
    int cnt = 0;
    int cnt2 = 0;
    for (int i = 0; i < n; i++) {
      if (S[i] == '1') cnt++;
      if (T[i] == '1') cnt2++;
    }
    if (cnt != cnt2 && (n - cnt + 1) != cnt2) {
      cout << -1 << endl;
      continue;
    }
    cnt = 0;
    cnt2 = 0;
    int cnt3 = 0;
    for (int i = 0; i < n; i++) {
      if (S[i] != T[i]) {
        cnt++;
        if (S[i] == '1') cnt2++;
      } else {
        if (S[i] == '1') cnt3++;
      }
    }
    if (cnt % 2 == 1) {
      if ((n - cnt) % 2 == 0)
        cout << -1 << endl;
      else
        cout << n - cnt << endl;
    } else {
      if ((n - cnt) % 2 == 0) {
        if (cnt2 == cnt / 2)
          cout << cnt << endl;
        else
          cout << -1 << endl;
      } else {
        if (cnt2 == cnt / 2) {
          if (cnt3 == (n - cnt + 1) / 2)
            cout << min(cnt, n - cnt) << endl;
          else
            cout << cnt << endl;
        } else {
          if (cnt3 == (n - cnt + 1) / 2)
            cout << n - cnt << endl;
          else
            cout << -1 << endl;
        }
      }
    }
  }
}
