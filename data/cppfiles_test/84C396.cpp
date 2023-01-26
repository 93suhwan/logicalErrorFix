#include <bits/stdc++.h>
using namespace std;
const long long INF_LL = 1e18;
const int INF = 1e9 + 100;
const long double EPS = 1e-10;
const int BLOCK = 550;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
void open_file() {}
const int maxN = 2e5 + 100;
const int MOD = 1e9 + 7;
void sol() {
  int n, s;
  cin >> n >> s;
  int L = 1, R = s;
  int med = (n + 1) / 2;
  int ans = 0;
  while (L <= R) {
    int mid = (L + R) >> 1;
    long long sum = 1LL * (n - med + 1) * mid;
    if (sum <= s) {
      ans = mid;
      L = mid + 1;
    } else
      R = mid - 1;
  }
  cout << ans << '\n';
}
void solve() {
  int T = 1;
  cin >> T;
  int TestCase = 0;
  while (T--) {
    TestCase += 1;
    sol();
  }
}
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  open_file();
  solve();
  return 0;
}
