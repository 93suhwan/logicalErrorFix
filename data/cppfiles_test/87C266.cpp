#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v(n + 1, 0);
    for (long long i = 1; i <= n; i++) {
      cin >> v[i];
    }
    long long ans = 0;
    for (long long i = n; i >= 0; i--) {
      long long index = i + ans;
      if (index < v[i]) {
        ans += (v[i] - index);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
