#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3fll;
inline int read() {
  int ret = 0, sgn = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') sgn = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    ret = ret * 10 + ch - '0';
    ch = getchar();
  }
  return ret * sgn;
}
struct ui {
  int fir;
  int sec;
  bool operator<(const ui b) const { return this->fir < b.fir; }
};
const int maxn = 1005;
int sz = 0;
void dfs(map<int, int> &ma, vector<int> &lst, int now, int sum) {
  if (now == sz) {
    return;
  }
  dfs(ma, lst, now + 1, sum);
  sum += lst[now];
  ma[sum] += 1;
  dfs(ma, lst, now + 1, sum);
  sum -= lst[now];
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int idkvwo;
  cin >> idkvwo;
  while (idkvwo--) {
    int n;
    cin >> n;
    int tag = 0;
    int tmp = 0;
    map<int, int> ma;
    vector<int> lst;
    for (int i = 1; i <= n; ++i) {
      cin >> tmp;
      lst.push_back(abs(tmp));
      if (tmp == 0) {
        tag = 1;
      }
    }
    sz = lst.size();
    if (tag == 1) {
      cout << "YES" << endl;
      continue;
    }
    dfs(ma, lst, 0, 0);
    for (auto i : ma) {
      if (i.second >= 2) {
        tag = 1;
      }
    }
    if (tag)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
