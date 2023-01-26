#include <bits/stdc++.h>
using namespace std;
clock_t time_p = clock();
void timer() {
  time_p = clock() - time_p;
  cerr << "Time Taken : " << (float)(time_p) / CLOCKS_PER_SEC << "sec\n";
}
template <class T>
using prq = priority_queue<T>;
template <class T>
using prqg = priority_queue<T, vector<T>, greater<T>>;
const long long INF = 1e18 + 1;
long long expo(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = res * x;
    res %= 1000000007;
    y = y >> 1;
    x = x * x;
    x %= 1000000007;
  }
  return res;
}
long long smod(long long a, long long md = 1000000007) {
  a = a % md;
  if (a < 0) a += md;
  return a;
}
void zoldyck() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  long long a0 = a[0], sum = 0, m;
  long long mn = max(0ll, accumulate(a.begin(), a.end(), 0) - k);
  for (int i = 1; i < n; i++) {
    sum += a[i];
    m = n - 1 - i;
    mn = min(mn, m + max(0ll, (a0 * (m + 1) + (sum - k) + m) / (m + 1)));
  }
  cout << max(0ll, mn) << '\n';
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    zoldyck();
  }
  timer();
  return 0;
}
