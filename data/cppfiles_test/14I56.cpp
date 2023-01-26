#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
int a[maxn];
int main() {
  ios::sync_with_stdio(false);
  int n, x, t;
  cin >> t;
  while (t--) {
    int x;
    cin >> n;
    vector<pair<int, int> > arr;
    for (int i = 1; i <= n; i++) {
      cin >> x;
      arr.push_back(make_pair(x, i));
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
      a[arr[i].second] = i + 1;
    }
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
      mp[a[i]] = i;
    }
    vector<pair<pair<int, int>, int> > arry;
    map<int, int>::iterator it;
    int pos = 1;
    for (it = mp.begin(); it != mp.end(); it++) {
      if (pos == n) continue;
      if (it->second != pos) {
        int l = pos;
        int r = it->second;
        int d = r - l;
        arry.push_back(make_pair(make_pair(l, r), d));
        for (int i = l; i < r; i++) mp[a[i]]++;
        mp[a[r]] = pos;
      }
      pos++;
    }
    int len = 0;
    for (int i = 0; i < arry.size(); i++) {
      if (arry[i].second == -1) break;
      len++;
    }
    cout << len << endl;
    if (len == 0)
      cout << endl;
    else {
      for (int i = 0; i < len; i++)
        cout << arry[i].first.first << " " << arry[i].first.second << " "
             << arry[i].second << endl;
    }
  }
  return 0;
}
