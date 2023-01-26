#include <bits/stdc++.h>
using namespace std;
const int N = 6e5 + 1067, md = 1e9 + 7;
vector<int> val, to[N];
map<int, int> mapVal;
int l[N], r[N], trai[N * 4], phai[N * 4], trace[N];
int n, m;
pair<int, int> it[N * 4], lz[N * 4];
pair<int, int> mp(int x, int y) { return make_pair(x, y); }
void minimize(pair<int, int> &x, pair<int, int> y) {
  if (x.first > y.first) {
    x.first = y.first;
    x.second = y.second;
  }
}
void build(int x, int l, int r) {
  trai[x] = l;
  phai[x] = r;
  it[x] = mp(-1, 0);
  if (l == r) return;
  int mid = (l + r) / 2;
  build(x * 2, l, mid);
  build(x * 2 + 1, mid + 1, r);
}
void down(int x) {
  int a = x * 2;
  minimize(it[a], lz[x]);
  minimize(lz[a], lz[x]);
  a += 1;
  minimize(it[a], lz[x]);
  minimize(lz[a], lz[x]);
}
void update(int x, int l, int r, pair<int, int> c) {
  if (trai[x] > r || phai[x] < l) return;
  if (trai[x] >= l && phai[x] <= r) {
    minimize(it[x], c);
    minimize(lz[x], c);
    return;
  }
  down(x);
  update(x * 2, l, r, c);
  update(x * 2 + 1, l, r, c);
  minimize(it[x], it[x * 2]);
  minimize(it[x], it[x * 2 + 1]);
}
pair<int, int> query(int x, int l, int r) {
  if (trai[x] > r || phai[x] < l) return mp(-1, 0);
  if (trai[x] >= l && phai[x] <= r) {
    return it[x];
  }
  pair<int, int> ans = mp(0, -1);
  minimize(ans, query(x * 2, l, r));
  minimize(ans, query(x * 2 + 1, l, r));
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int t;
    cin >> t >> l[i] >> r[i];
    to[t].push_back(i);
    val.push_back(l[i]);
    val.push_back(r[i]);
  }
  sort(val.begin(), val.end());
  vector<int> tmp;
  for (int i = 0; i <= val.size() - 1; i++)
    if (i == 0 || val[i] != val[i - 1]) tmp.push_back(val[i]);
  val = tmp;
  for (int i = 0; i <= val.size() - 1; i++) {
    mapVal[val[i]] = i;
  }
  for (int i = 1; i <= m; i++) l[i] = mapVal[l[i]], r[i] = mapVal[r[i]];
  build(1, 0, val.size() - 1);
  pair<int, int> ans = mp(n - 1, 1);
  for (int i = 1; i <= n; i++) {
    pair<int, int> cnt = mp(-1, 0);
    for (auto id : to[i]) {
      minimize(cnt, query(1, l[id], r[id]));
    }
    trace[i] = cnt.second;
    cnt.first += i;
    minimize(ans, mp(cnt.first + n - i, i));
    for (auto id : to[i]) {
      update(1, l[id], r[id], mp(cnt.first - i - 1, i));
    }
  }
  cout << ans.first << endl;
  int pos = ans.second;
  for (int i = pos + 1; i <= n; i++) cout << i << " ";
  while (pos != 0) {
    for (int i = trace[pos] + 1; i <= pos - 1; i++) cout << i << " ";
    pos = trace[pos];
  }
}
