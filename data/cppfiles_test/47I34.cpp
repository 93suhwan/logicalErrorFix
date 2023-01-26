#include <bits/stdc++.h>
using namespace std;
inline void smax(int& a, int b) {
  if (b > a) a = b;
}
inline void smin(int& a, int b) {
  if (b < a) a = b;
}
inline void smax(long long& a, long long b) {
  if (b > a) a = b;
}
inline void smin(long long& a, long long b) {
  if (b < a) a = b;
}
const long long LLINF = 2e18 + 13;
const int INF = 1e9 + 7;
mt19937 rng(time(nullptr) + 'm' + 'a' + 'n' + 'u' + 'l');
uniform_int_distribution<int> uid(0, INF);
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> pos, neg;
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    if (t > 0)
      pos.push_back(t);
    else if (t < 0)
      neg.push_back(-t);
  }
  sort(pos.begin(), pos.end());
  sort(neg.begin(), neg.end());
  int leftover = k;
  long long cnt = 0;
  for (int i = 0; i < pos.size(); ++i) {
    assert(leftover > 0);
    cnt += pos[i] - (i ? pos[i - 1] : 0);
    --leftover;
    if (leftover == 0 && i + 1 != pos.size()) {
      cnt += 2ll * pos[i];
      leftover = k;
    }
  }
  leftover = k;
  for (int i = 0; i < neg.size(); ++i) {
    assert(leftover > 0);
    cnt += neg[i] - (i ? neg[i - 1] : 0);
    --leftover;
    if (leftover == 0 && i + 1 != neg.size()) {
      cnt += 2ll * neg[i];
    }
  }
  cout << cnt + min(neg.size() ? neg.back() : 0, pos.size() ? pos.back() : 0)
       << endl;
}
int32_t main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
