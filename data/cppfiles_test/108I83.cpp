#include <bits/stdc++.h>
const int Mod = 1000000007, N = 2e5 + 100;
using namespace std;
using namespace std;
const long long INF = 0x3f3f3f3f;
double pi = 3.1415926;
const long long dx[] = {-1, +1, +0, +0};
const long long dy[] = {+0, +0, -1, +1};
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tc;
  cin >> tc;
  while (tc--) {
    long long n;
    cin >> n;
    long long upp[n], down[n];
    for (long long i = 0; i < n; i++) {
      cin >> upp[i];
    }
    for (long long i = 0; i < n; i++) {
      cin >> down[i];
    }
    map<long long, bool> ans;
    long long max_upp = max_element(upp, upp + n) - upp;
    long long max_down = max_element(down, down + n) - down;
    ans[max_down] = true;
    ans[max_upp] = true;
    for (long long i = 0; i < n; ++i) {
      if (upp[i] > upp[max_down]) {
        ans[i] = true;
      }
    }
    for (long long i = 0; i < n; ++i) {
      if (down[i] > down[max_upp]) {
        ans[i] = true;
      }
    }
    for (long long i = 0; i < n; ++i) {
      cout << ans[i];
    }
    cout << endl;
  }
}
