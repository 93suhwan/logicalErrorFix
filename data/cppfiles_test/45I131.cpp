#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 5;
const long long mod = 1e18 + 7;
const long long INF = 0x7f7f7f7f7f7f7f7f;
const int INFi = 0x7f7f7f7;
const long long LEVEL = log2(N) + 1;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  cout << setprecision(15);
  ;
  int t = 1;
  cin >> t;
  while (t--) {
    long long n, ans = 1;
    cin >> n;
    vector<long long> arr(n);
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
    }
    for (long long i = 0; i < n; i++) {
      if (arr[i] == 0) {
        if (i + 1 < n && arr[i + 1] == 0) {
          ans = -1;
          break;
        }
      } else {
        if (i + 1 < n && arr[i + 1] == 1) {
          ans = ans + 6;
          i++;
        } else {
          ans = ans + 1;
        }
      }
    }
    cout << ans << "\n";
    ;
  }
}
