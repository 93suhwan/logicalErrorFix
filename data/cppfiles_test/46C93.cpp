#include <bits/stdc++.h>
using namespace std;
void fastio() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}
int main() {
  fastio();
  long long int n;
  cin >> n;
  long long int ans = 0;
  long long int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (long long int i = 0; i < n; i += 2) {
    long long int sum = 0;
    for (long long int j = i + 1; j < n; j += 2) {
      long long int x = a[j] - sum;
      if (x < 0) {
      } else {
        ans += min(a[i], x);
        if (sum) ans++;
      }
      sum -= a[j];
      if (sum < 0) {
        if (abs(sum) > a[i])
          break;
        else {
          a[i] += sum;
          sum = 0;
        }
      }
      if (j + 1 < n) sum += a[j + 1];
    }
  }
  cout << ans << "\n";
}
