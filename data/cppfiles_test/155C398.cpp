#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, ko, ab;
    cin >> n;
    ko = n;
    vector<long long> a, d, l;
    map<long long, long long> mp;
    for (int i = 0; i < n; i++) {
      cin >> ab;
      a.push_back(ab);
    }
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        d.push_back(a[i]);
        mp[a[i]] = i;
      }
      if (s[i] == '1') {
        l.push_back(a[i]);
        mp[a[i]] = i;
      }
    }
    sort(d.begin(), d.end());
    n = d.size();
    int j = 1;
    for (int i = 0; i < d.size(); i++) {
      a[mp[d[i]]] = j;
      j++;
    }
    sort(l.begin(), l.end());
    for (int i = 0; i < l.size(); i++) {
      a[mp[l[i]]] = j;
      j++;
    }
    for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
    cout << "\n";
  }
  return 0;
}
