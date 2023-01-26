#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
int n, a[200010], rec0 = inf, num[40], fstPos;
pair<int, pair<int, int> > ans;
pair<int, int> mx[40];
string s[200010];
bool h0;
void chmax(pair<int, int> &x, pair<int, int> y) {
  if (x.first < y.first) x = y;
}
namespace st {
int ls[8000000], rs[8000000], len = 1;
pair<int, int> dat[8000000][2];
int add(int k, int id, int cur) {
  if (k == 0) k = ++len;
  if (cur == 30) {
    dat[k][0] = dat[k][1] = make_pair(0, id);
    return k;
  }
  if (s[id][cur] == '0')
    ls[k] = add(ls[k], id, cur + 1);
  else
    rs[k] = add(rs[k], id, cur + 1);
  return k;
}
void build(int k) {
  if (ls[k] == 0 && rs[k] == 0) return;
  if (ls[k] > 0) {
    build(ls[k]);
    dat[k][0] = make_pair(dat[ls[k]][1].first + 1, dat[ls[k]][1].second);
    pair<int, int> val = dat[ls[k]][0];
    if (val.first == 0) ++val.first;
    chmax(dat[k][0], val);
  }
  if (rs[k] > 0) {
    build(rs[k]);
    dat[k][1] =
        make_pair(dat[rs[k]][0].first + (dat[rs[k]][0].first == 1 ? -1 : 0) + 1,
                  dat[rs[k]][0].second);
    pair<int, int> val = dat[rs[k]][1];
    if (val.first == 0) ++val.first;
    chmax(dat[k][1], val);
  }
}
void dfs(int k, int id, int cur) {
  if (cur > fstPos + 1 && s[id][cur] == '1' && ls[k] > 0) {
    pair<int, int> val = dat[k][0];
    ++val.first;
    if (dat[k][0].first == 1) --val.first;
    ans = max(ans, make_pair(val.first + num[cur], make_pair(id, val.second)));
  }
  if (cur == 29) return;
  if (s[id][cur] == '0')
    dfs(ls[k], id, cur + 1);
  else
    dfs(rs[k], id, cur + 1);
}
void dfs2(int k, int k2, int ty, int cur) {
  if (k == 0 || k2 == 0) return;
  if (cur == 30) {
    if (k != k2)
      ans = max(ans,
                make_pair(1, make_pair(dat[k][0].second, dat[k2][0].second)));
    return;
  }
  if (ty == 0) {
    dfs2(ls[k], ls[k2], 0, cur + 1);
    dfs2(rs[k], rs[k2], 1, cur + 1);
    return;
  }
  if (k != k2) {
    if (ls[k] > 0 && ls[k2] > 0)
      ans = max(ans, make_pair(dat[k][0].first + dat[k2][0].first + 1 -
                                   (dat[k][0].first == 1 ? 1 : 0) -
                                   (dat[k2][0].first == 1 ? 1 : 0),
                               make_pair(dat[k][0].second, dat[k2][0].second)));
    if (rs[k] > 0 && rs[k2] > 0)
      ans = max(ans, make_pair(dat[k][1].first + dat[k2][1].first + 1,
                               make_pair(dat[k][1].second, dat[k2][1].second)));
  }
  dfs2(ls[k], rs[k2], 1, cur + 1);
  dfs2(rs[k], ls[k2], 1, cur + 1);
}
}  // namespace st
int getNum(string t) {
  int ret = 0;
  for (int i = 0; i < t.size(); ++i)
    if (t[i] == '1' && (i == 0 || t[i - 1] == '0')) ++ret;
  return ret + ret - 1;
}
int main() {
  for (int i = 0; i < 7999995; ++i)
    st::dat[i][0] = st::dat[i][1] = make_pair(-inf, -inf);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] == 0) {
      h0 = true;
      rec0 = i;
      --i;
      --n;
      continue;
    }
    int x = a[i];
    for (int j = 0; j < 30; ++j) {
      s[i].push_back(x % 2 + '0');
      x /= 2;
    }
    st::add(1, i, 0);
  }
  st::dat[0][0] = st::dat[0][1] = make_pair(-inf, -inf);
  st::build(1);
  for (int i = 0; i < 35; ++i) mx[i] = make_pair(-inf, 0);
  for (int i = 0; i < n; ++i) {
    int id = __builtin_ctz(a[i]), val = getNum(s[i]);
    if (id < 29 && s[i][id + 1] == '1') ++val;
    chmax(mx[id], make_pair(val, i));
  }
  for (int i = 0; i < 30; ++i)
    for (int j = 0; j < 30; ++j) {
      if (mx[i].first == -inf || mx[j].first == -inf || i == j) continue;
      ans = max(ans, make_pair(mx[i].first + mx[j].first,
                               make_pair(mx[i].second, mx[j].second)));
    }
  if (h0) {
    pair<int, int> val = make_pair(0, 0);
    for (int i = 0; i < 30; ++i) chmax(val, mx[i]);
    ans = max(ans, make_pair(val.first, make_pair(val.second, -1)));
  }
  for (int i = 0; i < n; ++i) {
    fstPos = -1;
    for (int j = 0; j < s[i].size(); ++j)
      if (s[i][j] == '1') {
        fstPos = j;
        break;
      }
    for (int j = 0; j < s[i].size(); ++j) num[j] = getNum(s[i].substr(j));
    st::dfs(1, i, 0);
  }
  st::dfs2(1, 1, 0, 0);
  if (ans.second.first >= rec0)
    ++ans.second.first;
  else if (ans.second.first == -1)
    ans.second.first = rec0;
  if (ans.second.second >= rec0)
    ++ans.second.second;
  else if (ans.second.second == -1)
    ans.second.second = rec0;
  cout << ans.second.first + 1 << ' ' << ans.second.second + 1 << ' '
       << ans.first << endl;
  return 0;
}
