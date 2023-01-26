#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 5;
bool ok(long long k, long long h, vector<long long> &pos) {
  long long sum = 0;
  for (int i = 1; i < pos.size(); i++) {
    sum += min(pos[i] - pos[i - 1], k);
    if (sum >= h) return true;
  }
  sum += k;
  if (sum >= h) return true;
  return false;
}
void solu() {
  int n;
  long long h;
  cin >> n >> h;
  vector<long long> a(n);
  for (auto &x : a) cin >> x;
  long long lo = 1, hi = h;
  while (lo < hi) {
    long long mid = (lo + hi) / 2;
    if (ok(mid, h, a))
      hi = mid;
    else
      lo = mid + 1;
  }
  cout << hi << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int cas = 1;
  cin >> cas;
  while (cas--) {
    solu();
  }
}
