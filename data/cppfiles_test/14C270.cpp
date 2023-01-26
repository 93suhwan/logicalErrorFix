#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n];
    long long int b[n];
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(b, b + n);
    vector<pair<long long int, long long int>> v;
    long long int ans = 0;
    for (long long int i = 0; i < n; i++) {
      long long int r;
      if (a[i] == b[i]) {
        continue;
      }
      for (long long int j = 0; j < n; j++) {
        if (b[i] == a[j]) {
          r = j;
        }
      }
      long long int temp = b[i];
      for (long long int k = r - 1; k >= i; k--) {
        a[k + 1] = a[k];
      }
      a[i] = temp;
      v.push_back({i + 1, r + 1});
      ans++;
    }
    cout << ans << endl;
    for (auto &it : v) {
      cout << it.first << " " << it.second << " " << ((it.second) - (it.first))
           << endl;
    }
  }
  return 0;
}
