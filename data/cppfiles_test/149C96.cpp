#include <bits/stdc++.h>
using namespace std;
long long int n, k, x;
string s;
vector<int> vec, ans;
inline void init() {}
inline void input() {
  cin >> n >> k >> x >> s;
  x--;
}
inline void solve() {
  vec.clear();
  ans.clear();
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '*') {
      cnt++;
    } else {
      vec.push_back(cnt * k);
      cnt = 0;
    }
  }
  vec.push_back(cnt * k);
  for (int i = vec.size() - 1; i > -1; i--) {
    ans.push_back(x % (vec[i] + 1));
    x /= (vec[i] + 1);
  }
  int sr = ans.size();
  for (int i = sr; i < vec.size(); i++) ans.push_back(0);
  string fin = "";
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) {
    string str = string(ans[i], 'b');
    fin = fin + str;
    if (i != ans.size() - 1) fin = fin + 'a';
  }
  cout << fin << endl;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int q = 1;
  init();
  cin >> q;
  while (q--) {
    input();
    solve();
  }
  return 0;
}
