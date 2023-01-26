#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m;
struct node {
  int id;
  string s;
};
vector<node> v;
bool cmp(node a, node b) {
  for (int i = 0; i < m; i++) {
    if (i % 2 == 0) {
      if (a.s[i] == b.s[i]) continue;
      return a.s[i] < b.s[i];
    } else {
      if (a.s[i] == b.s[i]) continue;
      return a.s[i] > b.s[i];
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    v.push_back({i, s});
  }
  sort(v.begin(), v.end(), cmp);
  for (auto x : v) cout << x.id << " ";
  cout << endl;
  return 0;
}
