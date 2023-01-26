#include <bits/stdc++.h>
using namespace std;
void SolveB();
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  SolveB();
  return 0;
}
void SolveB() {
  int T;
  cin >> T;
  while (T--) {
    int k;
    cin >> k;
    string s;
    cin >> s;
    int num[10] = {0};
    for (int i = 0; i < k; ++i) {
      ++num[s[i] - '0'];
    }
    if (num[1] + num[2] + num[3] + num[5] + num[7] != k) {
      for (int i = 0; i < 10; ++i) {
        if (i == 1 || i == 2 || i == 3 || i == 5 || i == 7) continue;
        if (num[i] != 0) {
          cout << k - 1 << endl << i << endl;
          break;
        }
      }
    } else {
      int cur = k - 1;
      while (1) {
        if (s[cur] == '2' || s[cur] == '5') {
          cout << k - 2 << endl << s[0] << s[cur] << endl;
          break;
        } else if ((s[cur] != '1') && (num[s[cur] - '0'] != 1)) {
          cout << k - 2 << endl << s[cur] << s[cur] << endl;
          break;
        } else if (s[cur] == '1' || s[cur] == '7') {
          if (num[2] != 0) {
            cout << k - 2 << endl << 2 << s[cur] << endl;
            break;
          }
        }
        --cur;
      }
    }
  }
}
