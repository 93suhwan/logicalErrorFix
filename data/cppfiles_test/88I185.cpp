#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
const double EPS = (1e-7);
const long long mod = (1e9 + 7), OO = 2e18, N = 1e6 + 100;
long long Ceil(long long x, long long y) { return (x + y - 1) / y; }
void run() {}
void fast() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long m = 0, n, k = 0, t = 1, d, test = 1, kk;
vector<long long> in(int n) {
  vector<long long> v(n);
  for (auto &i : v) cin >> i;
  return v;
}
void yes(bool x) { cout << (x ? "YES" : "NO") << '\n'; }
int LIS(vector<long long> &S) {
  vector<long long> L(S.size());
  int lisCount = 0;
  for (int i = 0; i < S.size(); ++i) {
    int pos = lower_bound(L.begin(), L.begin() + lisCount, S[i]) - L.begin();
    L[pos] = S[i];
    if (pos == lisCount) ++lisCount;
  }
  return lisCount;
}
int main() {
  run();
  fast();
  cin >> t;
  while (t--) {
    cin >> n;
    vector<long long> v = in(n);
    long long ans = (LIS(v));
    yes(n % 2 == 0 || ans % 2 == 0 || (ans > 1 && ans < n));
  }
}
