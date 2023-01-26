#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
using itn = int;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vpi = vector<pii>;
using i64 = long long;
using vi64 = vector<i64>;
using vvi64 = vector<vi64>;
using pi64 = pair<i64, i64>;
using ld = double;
const int md = 998244353;
const long double pi = 3.14159265358979323846;
const int inf = 100000;
void solve() {
  vi b(7);
  for (int i = 0; i < 7; i++) cin >> b[i];
  cout << b[0] << ' ' << b[1] << ' ' << b[2] << "\n";
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  i64 t = 1;
  cin >> t;
  while (t--) solve();
}
