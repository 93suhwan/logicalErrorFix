#include <bits/stdc++.h>
using namespace std;
bool ispow10(long long int n) {
  long long int temp = 1;
  while (temp <= n) {
    if (temp == n) return true;
    temp *= 10;
  }
  return false;
}
long long int calc(long long int n) {
  long long int exchange = 1, temp = n;
  while (n > 0) {
    n /= 10;
    exchange *= 10;
  }
  exchange /= 10;
  if (temp == exchange) exchange /= 10;
  return exchange;
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int s, n, i, j;
    cin >> s >> n;
    vector<long long int> ans;
    ans.push_back(s);
    for (i = 0; i < n - 1; i++) {
      long long int num = 0;
      for (j = 0; j < i + 1; j++) {
        if (!ispow10(ans[j])) {
          num = ans[j];
          ans.erase(ans.begin() + j);
          break;
        }
      }
      if (num == 0) {
        long long int mi = 1e18;
        for (j = 0; j < i + 1; j++)
          if (ans[j] != 1) mi = min(mi, ans[j]);
        for (j = 0; j < i + 1; j++)
          if (ans[j] == mi) break;
        num = mi;
        ans.erase(ans.begin() + j);
      }
      ans.push_back(calc(num));
      ans.push_back(num - calc(num));
    }
    for (i = 0; i < n; i++) cout << ans[i] << " ";
    cout << "\n";
  }
}
