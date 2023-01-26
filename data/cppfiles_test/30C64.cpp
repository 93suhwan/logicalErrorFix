#include <bits/stdc++.h>
using namespace std;
string s;
int n;
const int INF = 0x3f3f3f3f;
int work() {
  int left = 0, right = n - 1;
  char erased = '#';
  int cnt = 0;
  while (left < right) {
    if (s[left] != s[right]) {
      if (erased == '#') {
        erased = s[left];
        left++;
        cnt++;
      } else if (s[left] == erased) {
        left++;
        cnt++;
      } else if (s[right] == erased) {
        right--;
        cnt++;
      } else {
        break;
      }
    } else {
      left++, right--;
    }
  }
  if (left < right) {
    return INF;
  } else {
    return cnt;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> s;
    int res = work();
    reverse(s.begin(), s.end());
    res = min(res, work());
    if (res == INF) {
      cout << -1 << endl;
    } else {
      cout << res << endl;
    }
  }
  return 0;
}
