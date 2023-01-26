#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    map<long long, long long> vis;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      vis[a[i]] = 0;
    }
    string s;
    cin >> s;
    vector<long long> v;
    long long k = 1;
    for (long long i = 0; i < s.length(); i++) {
      if (s[i] == '0') {
        a[i] = k++;
      }
    }
    for (long long i = 0; i < n; i++) {
      if (s[i] == '1') {
        a[i] = k++;
      }
    }
    for (long long i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
