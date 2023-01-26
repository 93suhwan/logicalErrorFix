#include <bits/stdc++.h>
using namespace std;
set<pair<int, int> > s[1000005];
int bio[1000005], r[1000005], arr[1000005];
vector<pair<int, int> > veki[1000005];
char b[1000005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 2; i <= 1000000; i++) {
    if (!bio[i]) {
      for (int j = i; j <= 1000000; j += i) {
        bio[j] = 1;
        int v = j;
        int br = 0;
        while (v % i) {
          v /= i;
          br++;
        }
        veki[j].push_back(make_pair(i, br));
      }
    }
  }
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  long long sol = 0ll;
  for (int i = n; i > 0; i--) {
    if (b[i] == '/' and arr[i] > 1) {
      r[i] = i;
      continue;
    }
    if (b[i] == '*') {
      for (auto v : veki[arr[i]]) {
        s[i].insert(v);
      }
    }
    int j = i + 1;
    r[i] = i + 1;
    while (j <= n) {
      if (r[j] > j) {
        if (s[j].size() > s[i].size()) swap(s[i], s[j]);
        while (s[j].size()) {
          pair<int, int> p = *s[j].begin();
          s[j].erase(s[j].begin());
          auto it = s[i].lower_bound(make_pair(p.first, 0));
          if (it == s[i].end() or (*it).first > p.first)
            s[i].insert(p);
          else {
            p.second += (*it).second;
            s[i].erase(it);
            s[i].insert(p);
          }
        }
        j = r[j];
      } else {
        int tr = 1;
        for (auto v : veki[arr[j]]) {
          auto it = s[i].lower_bound(make_pair(v.first, 0));
          if (it == s[i].end() or (*it).first > v.first) {
            tr = 0;
            break;
          }
          if ((*it).second < v.second) {
            tr = 0;
            break;
          }
        }
        if (!tr) {
          break;
        } else {
          for (auto v : veki[arr[j]]) {
            auto it = s[i].lower_bound(make_pair(v.first, 0));
            pair<int, int> p = make_pair(v.first, (*it).second - v.second);
            s[i].erase(it);
            s[i].insert(p);
          }
          j++;
        }
      }
      r[i] = j;
    }
  }
  for (int i = 1; i <= n; i++) {
    sol += r[i] - i;
  }
  cout << sol;
  return 0;
}
