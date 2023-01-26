#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > arr(2);
int solve(int a, int n) {
  int i = 1, ans = 0;
  for (auto x : arr[a]) {
    ans += abs(x - i);
    i += 2;
  }
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, temp, even = 0, odd = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> temp;
      if (temp & 1)
        odd++, arr[0].push_back(i);
      else
        even++, arr[1].push_back(i);
    }
    if (abs(even - odd) > 1)
      cout << "-1\n";
    else {
      int ans;
      if (even > odd)
        ans = solve(1, n);
      else if (odd > even)
        ans = solve(0, n);
      else {
        ans = solve(0, n);
        ans = min(ans, solve(1, n));
      }
      cout << ans << endl;
    }
    arr[0].clear();
    arr[1].clear();
  }
}
