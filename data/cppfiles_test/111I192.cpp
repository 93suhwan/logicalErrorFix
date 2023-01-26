#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
typedef priority_queue<int, vector<int>, greater<int>> minpq;
typedef priority_queue<int> qp;
vector<string> ans;
void xo(int n, int o, int c, string s) {
  if (o > n || c > n) return;
  if (c > o) return;
  if (o + c == 2 * n) {
    ans.push_back(s);
    return;
  }
  xo(n, o + 1, c, s += '(');
  s.pop_back();
  xo(n, o, c + 1, s += ')');
  s.pop_back();
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    ans.clear();
    xo(n, 0, 0, "");
    for (auto it : ans) cout << it << endl;
  }
}
