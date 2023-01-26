#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e16;
const int mod = 1e9 + 7;
void solve() {
  int n, m, h;
  cin >> n >> m >> h;
  int v = n * m / 2 - h;
  if (n % 2) {
    h -= m / 2;
    n--;
  }
  if (m % 2) {
    v -= n / 2;
    m--;
  }
  if (h < 0 || v < 0 || h % 2 || v % 2) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  return;
}
int main(int argc, const char* argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int test_cnt = 1;
  cin >> test_cnt;
  for (int test = 1; test <= test_cnt; test++) {
    solve();
  }
  return 0;
}
