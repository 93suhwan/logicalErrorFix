#include <bits/stdc++.h>
using namespace std;
const long long N = 15;
long long p10[N];
vector<long long> res;
void go(long long n, long long s) {
  if (n == 1)
    res.push_back(s);
  else {
    long long mx = 0;
    for (long long i = 0; i < N; ++i) {
      if (s - p10[i] >= n - 1) mx = i;
    }
    res.push_back(p10[mx]);
    go(n - 1, s - p10[mx]);
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  p10[0] = 1;
  for (long long i = 1; i < N; ++i) p10[i] = p10[i - 1] * 10;
  while (t--) {
    res.clear();
    long long s, n;
    cin >> s >> n;
    go(n, s);
    for (long long x : res) cout << x << " ";
    cout << '\n';
  }
}
