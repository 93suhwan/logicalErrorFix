#include <bits/stdc++.h>
using namespace std;
int t, n, p[222222];
vector<pair<int, int>> a, b;
string s;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> p[i];
    a.clear();
    b.clear();
    cin >> s;
    for (int i = 0; i < n; ++i)
      if (s[i] == '0')
        a.push_back(make_pair(p[i], i));
      else
        b.push_back(make_pair(p[i], i));
    sort(b.begin(), b.end());
    sort(a.begin(), a.end());
    swap(a, b);
    int m = b.size();
    int val = m ? b[m - 1].first : -1;
    int idx = lower_bound(a.begin(), a.end(), make_pair(val, 0)) - a.begin();
    reverse(b.begin(), b.end());
    for (int i = 0; i < idx && i < b.size(); ++i) {
      if (a[i].first > b[i].first) break;
      swap(p[a[i].second], p[b[i].second]);
    }
    for (int i = 0; i < n; ++i) {
      cout << p[i];
      if (i != n - 1) cout << " ";
    }
    cout << endl;
  }
  return 0;
}
