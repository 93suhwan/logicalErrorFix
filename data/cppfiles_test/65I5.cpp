#include <bits/stdc++.h>
using namespace std;
const int N = (int)2e5 + 7;
int n, a[N], who[N], dif;
string str;
vector<pair<string, int>> sol;
set<int> s;
void addl(int x) {
  dif += x;
  assert(s.count(x));
  s.erase(x);
  sol.push_back({"L", x});
}
void addr(int x) {
  dif -= x;
  assert(s.count(x));
  s.erase(x);
  sol.push_back({"R", x});
}
void bad() {
  cout << "-1\n";
  exit(0);
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  cin >> str;
  for (int i = 1; i <= n; i++) {
    if (str[i - 1] == 'L') {
      who[i] = 1;
    } else {
      assert(str[i - 1] == 'R');
      who[i] = 2;
    }
  }
  for (int i = 1; i <= n; i++) {
    s.insert(a[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (who[i] == 1) {
      auto it = s.lower_bound(dif);
      if (it != s.begin()) {
        it--;
        addr(*it);
      } else {
        it = s.lower_bound(1 - dif);
        if (it == s.end()) {
          bad();
        } else {
          addl(*it);
        }
      }
    } else {
      auto it = s.lower_bound(-dif);
      if (it != s.begin()) {
        it--;
        addl(*it);
      } else {
        it = s.lower_bound(dif + 1);
        if (it == s.end()) {
          bad();
        } else {
          addr(*it);
        }
      }
    }
    if (who[i] == 1) {
      assert(dif > 0);
    } else {
      assert(dif < -1);
    }
  }
  for (auto &it : sol) {
    cout << it.first << " " << it.second << "\n";
  }
  return 0;
}
