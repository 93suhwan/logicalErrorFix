#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5;
long long int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<long long int> c(n);
  for (int i = 0; i < n; i++) cin >> c[i];
  long long int ans = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2) continue;
    long long int mi = 0;
    long long int sum = 0;
    for (int j = i + 1; j < n; j++) {
      if (j % 2 == 0) {
        sum += c[j];
        continue;
      }
      long long int temp = sum - mi;
      long long int bl = c[i] + mi;
      if (c[j] - temp >= 0) {
        ans += min(bl, c[j] - temp);
        if (mi && temp) ++ans;
      }
      sum -= c[j];
      mi = min(mi, sum);
      if (-mi > c[i]) break;
    }
  }
  cout << ans << "\n";
  return 0;
}
