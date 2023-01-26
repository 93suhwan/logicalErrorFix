#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
long long a[N], b[N];
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    vector<pair<long long, long long> > one, zero;
    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++) cin >> a[i];
    string s;
    cin >> s;
    for (long long i = 0; i < n; i++) {
      if (s[i] == '1')
        one.push_back({a[i], i});
      else
        zero.push_back({a[i], i});
    }
    sort(one.begin(), one.end());
    sort(zero.begin(), zero.end());
    for (long long i = 0; i < zero.size(); i++) a[zero[i].second] = i + 1;
    for (long long i = 0; i < one.size(); i++)
      a[one[i].second] = zero.size() + i + 1;
    for (long long i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";
  }
}
