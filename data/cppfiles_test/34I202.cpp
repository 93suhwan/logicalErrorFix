#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
const int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long arr[n + 1];
    arr[0] = 0;
    for (int i = 1; i <= n; i++) {
      cin >> arr[i];
    }
    long long ans = -1e12;
    for (int i = n; i > 0; i--) {
      for (int j = i - 1; (i - j) <= 100 && j > 0; j--) {
        ans = max(ans, (i * j) - (k * (arr[i] | arr[j])));
      }
    }
    cout << ans << endl;
  }
}
