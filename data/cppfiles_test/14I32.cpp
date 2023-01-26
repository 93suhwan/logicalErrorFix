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
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<pair<pair<int, int>, int> > arry;
    for (int i = 1; i <= n; i++) {
      int pos = i;
      for (int j = i; j <= n; j++) {
        if (a[j] < a[pos]) pos = j;
      }
      if (pos == i)
        continue;
      else {
        x = a[pos];
        arry.push_back(make_pair(make_pair(i, pos), pos - i));
        for (int j = pos; j > i; j--) {
          a[j] = a[j - 1];
        }
        a[i] = x;
      }
    }
    int len = arry.size();
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
