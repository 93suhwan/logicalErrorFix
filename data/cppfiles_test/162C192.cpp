#include <bits/stdc++.h>
using namespace std;
constexpr long long SZ = 2e5 + 7;
int tc_cnt = 1;
int modpow(int a, int b, int m = (long long)1000000007) {
  a = a & m;
  int ans = 1;
  while (b) {
    if (b & 1) {
      ans = (ans * a) % m;
    }
    b = b >> 1;
    a = (a * a) % m;
  }
  return ans;
}
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
void maxi() {
  int n, i;
  cin >> n;
  vector<int> a(n);
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0, lo = 0, hi = INT_MAX;
  while (lo <= hi) {
    auto v = a;
    int mid = (lo + hi) / 2;
    bool can = true;
    for (int i = n - 1; i > 1; i--) {
      if (v[i] < mid) break;
      int extra = v[i] - mid;
      extra = min(extra, a[i]);
      extra /= 3;
      v[i - 1] += extra;
      v[i - 2] += 2 * extra;
    }
    for (auto x : v) {
      if (x < mid) {
        can = false;
        break;
      }
    }
    if (can) {
      ans = mid;
      lo = mid + 1;
    } else
      hi = mid - 1;
  }
  cout << (ans) << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    maxi();
  }
  return 0;
}
