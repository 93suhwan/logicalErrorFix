#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
const long long mod = 1e18;
long long n, m, k;
int tr[maxn];
void add(int x) {
  for (int i = x; i <= n; i += i & -i) tr[i]++;
}
long long sum(int x) {
  long long s = 0;
  for (int i = x; i > 0; i -= i & -i) s += tr[i];
  return s;
}
void solve() {
  cin >> n;
  long long ans = 0;
  for (int i = 1; i <= n; i++) tr[i] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> m;
    ans += sum(n) - sum(m);
    add(m);
  }
  for (int i = 1; i <= n; i++) {
    if (sum(i) - sum(i - 1) > 1) {
      ans = 0;
      break;
    }
  }
  string s = ans & 1 > 0 ? "NO" : "YES";
  cout << s << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
