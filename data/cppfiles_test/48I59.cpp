#include <bits/stdc++.h>
const long long mod = 1000000007;
const long long AM = 2e5 + 5;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (__typeof(0) i = 0; i < n; ++i) cin >> a[i];
    map<long long, long long> m, cnt;
    bool flag = 0;
    for (__typeof(0) i = 0; i < n; ++i) {
      m[a[i]] = i;
      cnt[a[i]]++;
      if (cnt[a[i]] > 1) {
        flag = 1;
        break;
      }
    }
    if (flag) {
      cout << "YES\n";
      continue;
    }
    vector<long long> b = a;
    sort((b).begin(), (b).end());
    long long c = 0;
    for (__typeof(0) i = 0; i < n; ++i) {
      if (b[i] != a[i]) {
        swap(a[m[b[i]]], a[i]);
        c++;
      }
    }
    if (c % 2 == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
