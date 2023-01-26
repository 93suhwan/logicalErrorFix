#include <bits/stdc++.h>
using namespace std;
const long long INFLL = LLONG_MAX;
const int INF = INT_MAX;
const long long MAXLL = 0x3f3f3f3f3f3f3f3f;
const int MAX = 0x3f3f3f3f;
const long long MOD = 1000000007;
const long long mod = 998244353;
template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T> >;
template <class T>
void sort(vector<T>& v) {
  sort(v.begin(), v.end());
}
template <class T, class U>
void sort(vector<T>& v, U func) {
  sort(v.begin(), v.end(), func);
}
template <class T>
void rsort(vector<T>& v) {
  sort(v.rbegin(), v.rend());
}
template <class T>
int lb_index(vector<T>& v, T k) {
  return lower_bound(v.begin(), v.end(), k) - v.begin();
}
template <class T>
int ub_index(vector<T>& v, T k) {
  return upper_bound(v.begin(), v.end(), k) - v.begin();
}
template <class T>
bool is_sorted(vector<T>& v) {
  return is_sorted(v.begin(), v.end());
}
template <class T>
bool sorted(vector<T>& v) {
  return is_sorted(v);
}
void precompute() { return; }
void solve() {
  long long n, d;
  cin >> n >> d;
  vector<long long> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  long long ans = 0;
  if (n % d == 0) {
    for (int i = 0; i < d; i++) {
      long long dlo = INF, dhi = -10, lo = INF, hi = -10;
      long long sum = 0;
      for (int j = i; j < n; j += d) {
        if (v[j]) {
          sum++;
          dhi = max(dhi + 1, 1ll);
          dlo = min(dlo + 1, 1ll);
        } else {
          sum -= INF;
          dhi = max(dhi - INF, (long long)(-INF));
          dlo = min(dlo - INF, (long long)(-INF));
        }
        hi = max(dhi, hi);
        lo = min(dlo, lo);
      }
      long long mx = max(hi, sum - lo);
      mx = max(0ll, mx);
      if (mx == n / d) {
        cout << "-1\n";
        return;
      }
      ans = max(ans, mx);
    }
  } else {
    int i = 0;
    long long dlo = INF, dhi = -10, lo = INF, hi = -10;
    long long sum = 0;
    for (int j = 0; j < n; j++) {
      if (v[i]) {
        sum++;
        dhi = max(dhi + 1, 1ll);
        dlo = min(dlo + 1, 1ll);
      } else {
        sum -= INF;
        dhi = max(dhi - INF, (long long)(-INF));
        dlo = min(dlo - INF, (long long)(-INF));
      }
      hi = max(dhi, hi);
      lo = min(dlo, lo);
      i += d;
      i %= n;
    }
    long long mx = max(hi, sum - lo);
    mx = max(0ll, mx);
    if (mx == n) {
      cout << "-1\n";
      return;
    }
    ans = max(ans, mx);
  }
  cout << ans << "\n";
  return;
}
int main() {
  ios::sync_with_stdio(0);
  int numberofsubtestcases = 1;
  cin >> numberofsubtestcases;
  precompute();
  for (int looping = 1; looping <= numberofsubtestcases; looping++) {
    solve();
  }
  return 0;
}
