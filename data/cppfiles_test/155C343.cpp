#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(NULL), cin.tie(NULL), cout.tie(NULL);
  long long t, n;
  string s;
  cin >> t;
  while (t--) {
    cin >> n;
    long long count0 = 0;
    long long a[n];
    map<long long, long long> mp, valid;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      mp[a[i]] = i;
    }
    cin >> s;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') count0++;
    }
    vector<long long> v, r;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0' && a[i] > count0) {
        v.push_back(a[i]);
        valid[a[i]] = 0;
      } else if (s[i] == '0')
        valid[a[i]] = 1;
    }
    for (int i = 1; i <= count0; i++) {
      if (valid[i] == 0) r.push_back(i);
    }
    for (int i = v.size() - 1; i >= 0; i--) {
      a[mp[v[i]]] = r[i];
      a[mp[r[i]]] = v[i];
    }
    for (int i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    cout << "\n";
  }
}
