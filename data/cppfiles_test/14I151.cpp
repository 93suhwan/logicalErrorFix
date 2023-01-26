#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
struct node {
  int x;
  int pos;
} arr[maxn];
int a[maxn];
bool cmp(node z, node c) { return z.x < c.x; }
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int x, n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> arr[i].x;
      arr[i].pos = i;
    }
    sort(arr + 1, arr + 1 + n, cmp);
    for (int i = 1; i <= n; i++) {
      a[arr[i].pos] = i;
    }
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
      mp[a[i]] = i;
    }
    vector<pair<pair<int, int>, int> > arry;
    map<int, int>::iterator it;
    int pos = 1;
    for (it = mp.begin(); it != mp.end(); it++) {
      if (pos == n) break;
      if (it->second != pos) {
        int l = pos;
        int r = it->second;
        int d = r - l;
        arry.push_back(make_pair(make_pair(l, r), d));
        for (int i = l; i < r; i++) mp[a[i]]++;
        mp[a[r]] = pos;
        pos++;
      }
    }
    cout << arry.size() << endl;
    if (arry.size() == 0)
      cout << endl;
    else {
      for (int i = 0; i < arry.size(); i++) {
        cout << arry[i].first.first << " " << arry[i].first.second << " "
             << arry[i].second << endl;
      }
    }
  }
  return 0;
}
