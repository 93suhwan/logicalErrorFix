#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
long long dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
long long dy[] = {0, 1, 0, -1, -1, 1, 1, -1};
char dir[] = {'U', 'R', 'D', 'L'};
void solve() {
  long long n, sum = 0;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    sum += v[i];
  }
  if (sum % n)
    cout << 1;
  else
    cout << 0;
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long q = 1;
  cin >> q;
  for (long long i = 0; i < q; i++) {
    solve();
    cout << "\n";
  }
  return 0;
}
