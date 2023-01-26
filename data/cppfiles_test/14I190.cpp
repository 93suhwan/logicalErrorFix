#include <bits/stdc++.h>
using namespace std;
const int Mod = 998244353;
const int Max = 2e5 + 10;
const long long int Inf = 1LL << 62;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t, n, p;
  cin >> t;
  while (t--) {
    cin >> n;
    int ar[n + 1];
    int sorted[n + 1];
    for (int i = 1; i <= n; i++) {
      cin >> ar[i];
      sorted[i] = ar[i];
    }
    sort(sorted + 1, sorted + n + 1);
    cout << n << endl;
    for (int it = 1; it <= n; ++it) {
      int br[n + 1];
      for (int i = 1; i < it; i++) {
        br[i] = ar[i];
      }
      int cnt = it;
      for (int i = it; i <= n; ++i) {
        if (ar[i] == sorted[it]) {
          for (int j = i; j <= n; j++) {
            br[cnt] = ar[j];
            cnt++;
          }
          for (int j = it; j < i; j++) {
            br[cnt] = ar[j];
            cnt++;
          }
          cout << it << " " << n << " " << i - it << endl;
          break;
        }
      }
      for (int i = 1; i <= n; i++) {
        ar[i] = br[i];
      }
    }
    for (int i = 1; i <= n; ++i) {
      assert(sorted[i] == ar[i]);
    }
  }
  return 0;
}
