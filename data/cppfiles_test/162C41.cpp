#include <bits/stdc++.h>
using namespace std;
bool check(int n, vector<int> h, long long mini) {
  vector<long long> nw(n, 0);
  for (int i = n - 1; i >= 2; i--) {
    if ((long long)h[i] + nw[i] < mini) return false;
    long long x = min((long long)h[i], h[i] + nw[i] - mini);
    long long d = x / 3ll;
    h[i] -= d * 3ll;
    nw[i - 1] += d;
    nw[i - 2] += 2ll * d;
  }
  for (int i = 0; i < n; i++)
    if ((long long)h[i] + nw[i] < mini) return false;
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    int lo = 0, hi = *max_element(h.begin(), h.end());
    while (lo < hi) {
      int mi = (lo + hi + 1) / 2;
      if (check(n, h, mi))
        lo = mi;
      else
        hi = mi - 1;
    }
    cout << lo << "\n";
  }
  return 0;
}
