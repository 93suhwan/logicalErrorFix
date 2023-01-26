#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> num(n);
    long long max = -1, maxi;
    for (int i = 0; i < n; i++) {
      cin >> num[i];
      if (num[i] > max) {
        max = num[i];
        maxi = i;
      }
    }
    long long ans = 0;
    long long k = n - 1;
    for (int i = n - 1; i >= maxi; i--) {
      if (num[i] > num[k]) {
        ans++;
        k = i;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
