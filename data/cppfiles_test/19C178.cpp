#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
constexpr int INF = 0x3f3f3f3f;
int t[10];
int n, ile, sum;
bool bt(int kt) {
  if (kt == n) {
    if (ile == 0) return false;
    return sum == 0;
  }
  if (bt(kt + 1)) return true;
  ile++;
  sum -= t[kt];
  if (bt(kt + 1)) return true;
  sum += t[kt];
  sum += t[kt];
  if (bt(kt + 1)) return true;
  sum -= t[kt];
  ile--;
  return false;
}
void solve() {
  cin >> n;
  for (int i = (0); i < (n); i++) cin >> t[i];
  ile = sum = 0;
  cout << (bt(0) ? "YES\n" : "NO\n");
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int te = (0); te < (tt); te++) {
    solve();
  }
  return 0;
}
