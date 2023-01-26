#include <bits/stdc++.h>
using namespace std;
const long long M = 210000;
long long arr[M], brr[M];
long long ltt[M], rtt[M];
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
    long long cur_lt = act;
    for (long long i = n - 1; i > 0; i--) {
      long long v = max(cur_lt - arr[i], ltt[i - 1]);
      ltt[i] = arr[i] - (cur_lt - v);
      rtt[i] = m - (arr[i] - (cur_lt - v));
      cur_lt = v;
    }
    cout << arr[0] - cur_lt << ' ' << m - (arr[0] - cur_lt) << endl;
    for (long long i = 1; i < n; i++) cout << ltt[i] << ' ' << rtt[i] << endl;
  }
  return 0;
}
