#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using VI = vector<int>;
using VL = vector<LL>;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
void dout() { cerr << endl; }
template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
  cerr << H << ' ';
  dout(T...);
}
const int INF = 1e9 + 47;
struct BIT {
  BIT(int n) : bit(n + 1, -INF) {}
  void setmax(int pos, int val) {
    for (int i = pos + 1; i < (int)bit.size(); i += i & -i)
      bit[i] = max(bit[i], val);
  }
  int getmax(int pos) {
    int res = -INF;
    for (int i = pos + 1; i > 0; i -= i & -i) res = max(res, bit[i]);
    return res;
  }
  vector<int> bit;
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  VI a(n);
  vector<PII> b;
  for (int i = (0); i < (n); ++i) {
    cin >> a[i];
    b.emplace_back(i + 1 - a[i], a[i]);
  }
  sort(b.begin(), b.end());
  BIT bit(n + 1);
  bit.setmax(0, 0);
  int ans = 0;
  for (auto [dif, x] : b) {
    if (dif < 0) continue;
    int dp = bit.getmax(x - 1) + 1;
    bit.setmax(x, dp);
    ans = max(ans, dp);
  }
  cout << ans << "\n";
  return 0;
}
