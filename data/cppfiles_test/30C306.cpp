#include <bits/stdc++.h>
using namespace std;
int Min(int a, int b) {
  if (a == -1) return b;
  if (b == -1) return a;
  return min(a, b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    string s;
    cin >> s;
    int ans = -1;
    for (char c = 'a'; c <= 'z'; c++) {
      int L = 0, R = N - 1, ans_local = 0;
      while (L <= R) {
        if (s[L] == s[R])
          L++, R--;
        else {
          if (s[L] == c) {
            while (s[L] != s[R] && s[L] == c) L++, ans_local++;
            if (s[L] != s[R]) {
              ans_local = -1;
              break;
            }
          } else if (s[R] == c) {
            while (s[L] != s[R] && s[R] == c) R--, ans_local++;
            if (s[L] != s[R]) {
              ans_local = -1;
              break;
            }
          } else {
            ans_local = -1;
            break;
          }
        }
      }
      ans = Min(ans, ans_local);
    }
    cout << ans << "\n";
  }
  return 0;
}
