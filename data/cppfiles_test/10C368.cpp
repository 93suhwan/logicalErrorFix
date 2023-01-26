#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000007;
const long long N = 100005;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  long long q;
  cin >> q;
  while (q--) {
    long long n, k;
    cin >> n >> k;
    long long a[n];
    for (long long i = 0; i < n; i++) cin >> a[i];
    map<long long, vector<long long>> pos;
    for (long long i = 0; i < n; i++) {
      pos[a[i]].push_back(i);
    }
    vector<long long> color(n);
    vector<long long> left;
    for (const auto &val : pos) {
      if (val.second.size() >= k)
        for (long long i = 0; i < k; i++) {
          color[val.second[i]] = i + 1;
        }
      else
        for (long long i = 0; i < val.second.size(); i++)
          left.push_back(val.second[i]);
    }
    long long s = ((left.size()) / k) * k;
    for (long long i = 0; i < s; i++) {
      color[left[i]] = (i) % k + 1;
    }
    for (long long i = 0; i < color.size(); i++) cout << color[i] << " ";
    cout << '\n';
  }
  return 0;
}
