#include <bits/stdc++.h>
using namespace std;
const long long maxf = 100000000;
void fast() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long n;
void solve() {
  long long a[9] = {};
  for (long long i = (1); i <= (7); i += 1) cin >> a[i];
  sort(a + 1, a + 7 + 1);
  for (long long i = (1); i <= (3); i += 1) cout << a[i] << ' ';
  cout << '\n';
}
void test() {
  int er;
  cin >> er;
  while (er-- > 0) solve();
}
void file() {
  freopen("a.inp", "r", stdin);
  freopen("a.out", "w", stdout);
}
int main() {
  fast();
  test();
}
