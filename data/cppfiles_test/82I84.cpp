#include <bits/stdc++.h>
using namespace std;
const int MX = 300005;
int n, q, k, a[MX], l[MX], r[MX], res[MX], sig[MX], mn[MX];
vector<int> pos[MX];
struct ST {
  long long sum[4 * MX], lz[4 * MX];
  void init(int n) {
    for (int i = 1; i <= 4 * n; i++) {
      sum[i] = lz[i] = 0;
    }
  }
  void push(int i, int j, int pos) {
    if (!lz[pos]) return;
    if (i < j) {
      lz[pos * 2] = lz[pos];
      lz[pos * 2 + 1] = lz[pos];
    }
    sum[pos] = 1ll * (j - i + 1) * lz[pos];
    lz[pos] = 0;
  }
  void update(int i, int j, int pos, int a, int b, long long k) {
    if (lz[pos]) push(i, j, pos);
    if (b < i || j < a) return;
    if (a <= i && j <= b) {
      lz[pos] = k;
      push(i, j, pos);
      return;
    }
    int m = (i + j) / 2;
    update(i, m, pos * 2, a, b, k);
    update(m + 1, j, pos * 2 + 1, a, b, k);
    sum[pos] = sum[pos * 2] + sum[pos * 2 + 1];
  }
  long long query(int i, int j, int pos, int a, int b) {
    if (lz[pos]) push(i, j, pos);
    if (b < i || j < a) return 0;
    if (a <= i && j <= b) return sum[pos];
    int m = (i + j) / 2;
    long long x = query(i, m, pos * 2, a, b);
    long long y = query(m + 1, j, pos * 2 + 1, a, b);
    return x + y;
  }
} st;
int ned(int l, int r) { return (r - l + 1 + k - 1) / k; }
void main_() {
  cin >> n >> q >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 0; i < int(q); i++) {
    cin >> l[i] >> r[i];
    pos[l[i]].push_back(i);
  }
  {
    map<int, int> st;
    st[0] = n + 1;
    for (int i = n; i >= 1; i--) {
      auto it = st.lower_bound(a[i]);
      it--;
      sig[i] = it->second;
      while (st.rbegin()->first >= a[i]) st.erase(st.rbegin()->first);
      st[a[i]] = i;
    }
  }
  {
    deque<pair<int, int> > d;
    for (int i = n; i >= 1; i--) {
      while (d.size() && d.back().first >= a[i]) d.pop_back();
      d.push_back({a[i], i});
      while (d.front().second >= i + k) d.pop_front();
      mn[i] = d.front().second;
    }
  }
  for (int i = 0; i < int(k); i++) {
    set<int> in;
    map<int, int> mp;
    for (int j = i, l = 1; j <= n; j += k, l++) {
      in.insert(j);
      mp[j] = l;
    }
    int m = in.size();
    if (!m) continue;
    st.init(m);
    int l = m;
    for (auto it = in.rbegin(); it != in.rend(); it++, l--) {
      st.update(1, m, 1, l, l, a[*it]);
      auto lb = in.lower_bound(sig[mn[*it]]);
      if (lb == in.end()) {
        if (l < m) st.update(1, m, 1, l + 1, m, a[mn[*it]]);
      } else {
        int to = mp[*lb];
        if (l + 1 <= to - 1) st.update(1, m, 1, l + 1, to - 1, a[mn[*it]]);
      }
      for (int i : pos[*it])
        res[i] = st.query(1, m, 1, l, l + ned(*it, r[i]) - 1);
    }
  }
  for (int i = 0; i < int(q); i++) cout << res[i] << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) main_();
  return 0;
}
