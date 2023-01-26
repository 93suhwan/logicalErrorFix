#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
const int inf2 = 0x7fffffff;
const double eps = 1e-7;
const double pi = acos(-1.0);
const int mod = 1e9 + 7;
const int mod2 = 998244353;
int n;
vector<int> a(maxn);
string s;
struct node {
  int idx;
  int w;
};
vector<node> v1, v2;
int ans[maxn];
bool cmp(node &a, node &b) { return a.w < b.w; }
void solver() {
  memset(ans, 0, sizeof(ans));
  v1.clear(), v2.clear(), a.clear();
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      v1.push_back({i, a[i]});
    } else {
      v2.push_back({i, a[i]});
    }
  }
  sort((v1).begin(), (v1).end(), cmp), sort((v2).begin(), (v2).end(), cmp);
  int m = n;
  for (int i = ((int)(v2).size()) - 1; i >= 0; i--) {
    ans[v2[i].idx] = m--;
  }
  for (int i = ((int)(v1).size()) - 1; i >= 0; i--) {
    ans[v1[i].idx] = m--;
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " \n"[i == n - 1];
  }
}
int main() {
  int _ = 1;
  cin >> _;
  while (_--) {
    solver();
  }
  return 0;
}
