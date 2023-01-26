#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    string s;
    cin >> s;
    int cnt = 0;
    vector<int> big, small, old1, old0;
    for (int i = 0; i < s.size(); i++) {
      cnt += (s[i] == '1');
      (s[i] == '1' ? old1 : old0).push_back(a[i]);
    }
    sort(a, a + n);
    for (int i = n - 1; i >= 0; i--, cnt--) {
      if (cnt > 0)
        big.push_back(a[i]);
      else
        small.push_back(a[i]);
    }
    sort(old1.begin(), old1.end());
    sort(old0.begin(), old0.end());
    sort(big.begin(), big.end());
    sort(small.begin(), small.end());
    map<int, int> mp;
    for (int i = 0; i < old0.size(); i++) {
      mp[old0[i]] = small[i];
    }
    for (int i = 0; i < old1.size(); i++) {
      mp[old1[i]] = big[i];
    }
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        cout << mp[b[i]];
      } else {
        cout << mp[b[i]];
      }
      cout << " ";
    }
    cout << '\n';
  }
}
