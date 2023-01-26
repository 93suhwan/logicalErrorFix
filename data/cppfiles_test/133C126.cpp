#include <bits/stdc++.h>
using namespace std;
string solve(int n, string arr[]) {
  string ans;
  int vis = 0;
  if (n == 3) {
    ans += arr[0];
    ans += "a";
    return ans;
  }
  for (int i = 0; i < n - 2; i++) {
    if (i == 0) {
      ans += arr[i][0];
    } else if (i == n - 3) {
      ans += arr[i][1];
      continue;
    }
    if (arr[i][1] == arr[i + 1][0]) {
      ans += arr[i][1];
    } else {
      vis = 1;
      ans += arr[i][1];
      ans += arr[i + 1][0];
    }
  }
  if (vis == 0) ans += "a";
  return ans;
}
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string arr[n - 2];
    for (int i = 0; i < n - 2; i++) cin >> arr[i];
    cout << solve(n, arr) << "\n";
  }
  return 0;
}
