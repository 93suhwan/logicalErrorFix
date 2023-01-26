#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e6 + 15, inf = 2e9, lg = 26, M = 1e9 + 7;
int main() {
  int n, ans = 0, l = 1, r, lindex, rindex, cnt = 0;
  string s[2] = {"Alice", "Bob"};
  cin >> n;
  r = n;
  int a[n + 2];
  for (int i = 1; i < n + 1; i++) cin >> a[i];
  a[0] = a[n + 1] = -1;
  for (int i = 1; i < n + 1; i++) {
    if (a[i] <= a[i - 1]) {
      lindex = i - 1;
      break;
    }
  }
  for (int i = n; i > 0; i--) {
    if (a[i] >= a[i - 1]) {
      rindex = i;
      break;
    }
  }
  if (n == 1) {
    cout << "Alice";
    return 0;
  }
  while (true) {
    if ((a[l] >= a[r] && (lindex - l + 1) % 2) ||
        (a[r] >= a[l] && (r - rindex + 1) % 2)) {
      cout << s[ans];
      break;
    }
    if (a[l] == a[r]) {
      ans = 1 - ans;
      cout << s[ans];
      break;
    }
    if (a[l] < a[r]) {
      while (a[l] < a[r] && l < lindex) l++;
    } else {
      while (a[r] < a[l] && r > rindex) r--;
    }
    ans = 1 - ans;
    if (l == lindex && r == rindex) {
      cout << s[ans];
      break;
    }
    if (l == lindex) {
      ans = ((r - rindex + 1) % 2) - ans;
      cout << s[abs(ans)];
      break;
    }
    if (r == rindex) {
      ans = ((lindex - l + 1) % 2) - ans;
      cout << s[abs(ans)];
      break;
    }
  }
  return 0;
}
