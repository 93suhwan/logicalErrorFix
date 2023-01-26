#include <bits/stdc++.h>
using namespace std;
static bool comp(pair<int, int> a, pair<int, int> b) {
  if (a.first < b.first) return true;
  if (a.first == b.first && (a.second > b.second)) return true;
  return false;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int m, n;
    cin >> m >> n;
    vector<pair<int, int> > a;
    long long int ans = 0;
    for (int i = 0; i < n; i++) {
      int temp;
      cin >> temp;
      a.push_back({temp, i});
    }
    sort(a.begin(), a.end(), comp);
    set<int> s;
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        s.insert(a[i].second);
      } else {
        for (auto it = s.begin(); it != s.end(); it++) {
          if (*it < a[i].second)
            ans++;
          else
            break;
        }
        s.insert(a[i].second);
      }
    }
    cout << ans << endl;
  }
}
