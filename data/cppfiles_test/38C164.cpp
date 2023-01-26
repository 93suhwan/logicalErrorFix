#include <bits/stdc++.h>
using namespace std;
void inppp() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
}
const int MAXN = 1e5 * 5 + 5;
void solve() {
  long long n;
  cin >> n;
  n = max(1ll * 6, n);
  if (n % 2 == 1) n++;
  cout << n / 2 * 5 << endl;
}
int main() {
  int t;
  cin >> t;
  while (t) {
    solve();
    t--;
  }
  return 0;
}
