#include <bits/stdc++.h>
using namespace std;
const int INF = 1000 * 1000 * 1000;
const long long LINF = 1LL * INF * INF;
const int MAX = 100010;
const long double PI = acos(-1.);
const double EPS = 1e-6;
const long long MOD = INF + 7;
void solve() {
  long long n, k;
  cin >> n >> k;
  long long cnt = 1;
  long long step = 0;
  while (cnt <= k) {
    cnt *= 2;
    step++;
  }
  cout << step + (n - cnt + k - 1) / k << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
