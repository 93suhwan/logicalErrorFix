#include <bits/stdc++.h>
using namespace std;
long long const N = 1e6 + 5;
long long a[N];
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    vector<long long> v0, v1;
    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++) cin >> a[i];
    string s;
    cin >> s;
    for (long long i = 0; i < s.size(); i++) {
      if (s[i] == '0')
        v0.push_back(a[i]);
      else
        v1.push_back(a[i]);
    }
    if (v0.size()) sort(v1.begin(), v1.end());
    if (v1.size()) sort(v0.begin(), v0.end());
    for (auto x : v0) cout << x << " ";
    for (auto x : v1) cout << x << " ";
    cout << "\n";
  }
}
