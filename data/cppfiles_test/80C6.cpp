#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a, b;
vector<int> p;
vector<int> pref, suff;
void dnc(int ln, int rn, int lm, int rm) {
  if (ln > rn or lm > rm) return;
  int pm = (lm + rm) / 2;
  for (int i = ln; i <= rn; i++) {
    pref[i] = 0;
    suff[i] = 0;
  }
  for (int i = ln; i <= rn; i++) {
    if (a[i] > b[pm]) pref[i]++;
    if (i - 1 >= ln) pref[i] = pref[i] + pref[i - 1];
  }
  for (int i = rn; i >= ln; i--) {
    if (a[i] < b[pm]) suff[i]++;
    if (i + 1 <= rn) suff[i] = suff[i] + suff[i + 1];
  }
  int pos = -1, ans = INT_MAX;
  for (int i = ln; i <= rn; i++) {
    int r = 0;
    if (i - 1 >= ln) r = r + pref[i - 1];
    r = r + suff[i];
    if (r <= ans) {
      ans = r;
      pos = i;
    }
  }
  p[pm] = pos;
  dnc(ln, pos, lm, pm - 1);
  dnc(pos, rn, pm + 1, rm);
}
template <class T>
struct fenwick_tree {
 private:
  int _n;
  vector<T> arr;
  T query(long long x) {
    long long ans = 0;
    for (long long i = x; i >= 0; i = (i & (i + 1)) - 1) {
      ans += arr[i];
    }
    return ans;
  }

 public:
  fenwick_tree() : _n(0) {}
  fenwick_tree(int n) : _n(n), arr(n) {}
  void update(long long x, T val) {
    long long ans = 0;
    for (long long i = x; i < arr.size(); i = (i | (i + 1))) {
      arr[i] += (long long)(val);
    }
  }
  T query(int l, int r) { return query(r) - query(l - 1); }
};
void solve() {
  a.clear();
  b.clear();
  p.clear();
  cin >> n >> m;
  n++;
  a.resize(n, INT_MAX);
  b.resize(m);
  for (int i = 0; i < n - 1; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  pref.resize(n);
  suff.resize(n);
  p.resize(m);
  sort(b.begin(), b.end());
  dnc(0, n - 1, 0, m - 1);
  vector<int> arr;
  for (int i = 0, j = 0; i < n; i++) {
    while (j < m and p[j] <= i) {
      arr.push_back(b[j]);
      j++;
    }
    arr.push_back(a[i]);
  }
  arr.pop_back();
  n--;
  vector<pair<int, int>> sorted(n + m);
  for (int i = 0; i < n + m; i++) {
    sorted[i] = {arr[i], i};
  }
  sort(sorted.begin(), sorted.end());
  vector<int> res(n + m);
  for (int i = 0; i < n + m; i++) {
    res[sorted[i].second] = i;
  }
  fenwick_tree<long long> f(n + m + 1);
  long long ans = 0;
  for (int i = 0; i < n + m; i++) {
    ans = ans + f.query(res[i], n + m);
    f.update(res[i], 1);
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
}
