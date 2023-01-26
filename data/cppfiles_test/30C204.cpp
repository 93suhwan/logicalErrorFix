#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
const int inf = 0x3f3f3f3f;
const long double PI = acos(-1);
using namespace std;
const int N = 1e5 + 10;
int t, n, ans;
char s[N];
int solve() {
  ans = inf;
  for (char c = 'a'; c <= 'z'; c++) {
    int temp = 0, i = 0, j = n - 1;
    while (i < j) {
      if (s[i] == s[j]) {
        i++, j--;
      } else {
        if (s[i] == c) {
          i++, temp++;
        } else if (s[j] == c) {
          j--, temp++;
        } else {
          temp = n + 1;
          break;
        }
      }
    }
    ans = min(ans, temp);
  }
  if (ans == n + 1) return -1;
  return ans;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    cout << solve() << endl;
  }
}
