#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int infi = INT32_MAX / 2;
const ll infl = INT64_MAX / 2;
const double pi = acos(-1);
vector<int> ans;
class Solve {
  string s;
  void set_value() { cin >> s; }
  int change;
  void judge() {
    change = 0;
    for (int i = (1); i < (s.size()); i++) {
      if (s[i] != s[i - 1]) ++change;
    }
  }
  void push() {
    if (change == 0)
      ans.push_back(1 - (s[0] - '0'));
    else if (change == 1)
      ans.push_back(1);
    else if (change == 2) {
      if (s[0] == '0')
        ans.push_back(2);
      else
        ans.push_back(1);
    } else
      ans.push_back(2);
  }

 public:
  Solve() : s(""), change(0){};
  ~Solve(){};
  void solve() {
    set_value();
    judge();
    push();
  }
};
int main() {
  int t;
  cin >> t;
  Solve problem;
  for (int i = (0); i < (t); i++) problem.solve();
  for (auto x : ans) cout << (x) << ("\n");
}
