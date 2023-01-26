#include <bits/stdc++.h>
using namespace std;
const long long M = 210000;
long long arr[M], brr[M];
long long ltt[M], rtt[M];
struct node {
  long long inx;
  long long lt, rt;
};
int main() {
  ios::sync_with_stdio(false);
  long long tt;
  cin >> tt;
  while (tt--) {
    long long m, n;
    cin >> n >> m;
    long long sum = 0;
    long long lt = 0, rt = 0;
    for (long long i = 0; i < n; i++) {
      cin >> arr[i] >> brr[i];
      sum += arr[i] + brr[i];
      long long min_lt = max(0ll, arr[i] - m);
      long long max_rt = min(arr[i], arr[i] - (m - min(m, brr[i])));
      lt += min_lt, rt += max_rt;
      ltt[i] = lt;
      rtt[i] = rt;
      cout << i << '=' << lt << ':' << rt << endl;
    }
    sum -= m * n;
    long long tot = (sum + 1) / 2;
    long long act = 0;
    if (tot >= lt && tot <= rt)
      act = tot;
    else if (tot > rt)
      act = rt;
    else
      act = lt;
    cout << long long(abs(act * 2 - sum)) << endl;
    vector<node> p;
    for (long long i = 0; i < n; i++) {
      p.push_back({i, arr[i], brr[i]});
    }
    sort(p.begin(), p.end(), [&](node a, node b) { return b.rt > a.rt; });
    for (auto u : p) {
      if (act) {
        long long mn = min(brr[u.inx], m);
        long long pl = m - mn;
        long long sur = min(act, arr[u.inx] - pl);
        ltt[u.inx] = arr[u.inx] - sur, rtt[u.inx] = m - (ltt[u.inx]);
        act -= sur;
      } else {
        if (u.lt < m) {
          ltt[u.inx] = u.lt, rtt[u.inx] = m - u.lt;
        } else {
          ltt[u.inx] = m, rtt[u.inx] = 0;
        }
      }
    }
    for (long long i = 0; i < n; i++) cout << ltt[i] << ' ' << rtt[i] << endl;
  }
  return 0;
}
