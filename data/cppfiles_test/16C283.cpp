#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    multiset<pair<int, int>> s;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x != 0) {
        s.insert(make_pair(x, i + 1));
      }
    }
    int ct = 0;
    vector<pair<int, int>> ans;
    auto it1 = s.begin();
    auto it2 = s.rbegin();
    while (s.size() != 1 && s.size() != 0) {
      if (it1->first > 0) {
        ct++;
        ans.push_back(make_pair(it1->second, it2->second));
        int x1 = it1->first;
        int ind1 = it1->second;
        int x2 = it2->first;
        int ind2 = it2->second;
        s.erase(it1);
        s.erase(make_pair(it2->first, it2->second));
        if (x1 - 1 > 0) {
          s.insert(make_pair(x1 - 1, ind1));
        }
        if (x2 - 1 > 0) {
          s.insert(make_pair(x2 - 1, ind2));
        }
        it1 = s.begin();
        it2 = s.rbegin();
        if (s.size() == 0 || s.size() == 1) {
          break;
        }
      } else {
        it1++;
      }
    }
    cout << ct << endl;
    for (auto it : ans) {
      cout << it.first << " " << it.second << endl;
    }
  }
  return 0;
}
