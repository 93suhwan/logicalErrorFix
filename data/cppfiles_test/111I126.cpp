#include <bits/stdc++.h>
using namespace std;
vector<set<string>> v(51);
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  v[1].insert("()");
  for (int i = 2; i < 51; i++) {
    while (v[i].size() < i) {
      for (string cur : v[i - 1]) {
        v[i].insert(cur + "()");
        v[i].insert("()" + cur);
        v[i].insert("(" + cur + ")");
        if (v[i].size() >= i) break;
      }
    }
  }
  while (t--) {
    int n;
    cin >> n;
    for (string ans : v[n]) cout << ans << '\n';
  }
  return 0;
}
