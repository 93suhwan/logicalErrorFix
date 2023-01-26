#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v1(n);
    for (int i = 0; i < n; i++) {
      cin >> v1[i];
    }
    long long ans = 1;
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        if (v1[i] == 1) ans++;
      } else {
        if (v1[i] == 1) {
          if (v1[i - 1] == 1) {
            ans += 5;
          } else {
            ans++;
          }
        } else if (v1[i] == 0) {
          if (v1[i - 1] == 0) {
            ans = -1;
            break;
          }
        }
      }
    }
    cout << ans << endl;
  }
}
