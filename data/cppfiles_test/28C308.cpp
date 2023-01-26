#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007, N = 500005;
long long a, b, c, d, e, f, g = 1, h[N], arr[N];
string s;
vector<long long> v;
void solve() {
  cin >> a >> b >> c;
  c %= 2;
  if (c and !b) {
    cout << max(3 - a, (a - 3) % 2) << "\n";
  } else {
    cout << (a + 2 * b + 3 * c) % 2 << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> g;
  while (g--) solve();
}
