#include <bits/stdc++.h>
using namespace std;
const long long M = 1000000007;
const double eps = 1e-9;
const double pie = acos(-1);
void solve();
bool cmp(long long n1, long long n2);
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int kase = 1;
  cin >> kase;
  while (kase--) solve();
  return 0;
}
bool cmp(long long n1, long long n2) { return n1 > n2; }
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> pos{0};
  vector<long long> neg{0};
  long long posCnt = 0, negCnt = 0;
  for (long long i = 0; i < n; ++i) {
    long long input;
    cin >> input;
    if (input > 0) {
      pos.push_back(input);
      posCnt += 1;
    } else if (input < 0) {
      neg.push_back(-input);
      negCnt += 1;
    }
  }
  sort(pos.begin(), pos.end(), cmp);
  sort(neg.begin(), neg.end(), cmp);
  long long ans = 0;
  for (long long i = 0; i < pos.size(); i += k) {
    ans += pos[i];
  }
  for (long long i = 0; i < neg.size(); i += k) {
    ans += neg[i];
  }
  ans = ans * 2;
  long long maxOf2 = max(pos[0], neg[0]);
  ans = ans - maxOf2;
  cout << ans << "\n";
}
