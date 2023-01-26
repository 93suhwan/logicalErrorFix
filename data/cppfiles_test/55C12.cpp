#include <bits/stdc++.h>
using namespace std;
struct data {
  long long id, l, r;
  bool operator<(const data &a) const { return id < a.id; }
};
const long long N = 6e5 + 10;
long long n;
long long m;
data a[N];
struct Interval_Tree {
  pair<long long, long long> node[4 * N];
  pair<long long, long long> lazy[4 * N];
  Interval_Tree() {}
  void Down(long long i) {
    if (node[2 * i].first < lazy[i].first) {
      node[2 * i] = lazy[i];
    }
    if (node[2 * i + 1].first < lazy[i].first) {
      node[2 * i + 1] = lazy[i];
    }
    if (lazy[2 * i].first < lazy[i].first) {
      lazy[2 * i] = lazy[i];
    }
    if (lazy[2 * i + 1].first < lazy[i].first) {
      lazy[2 * i + 1] = lazy[i];
    }
    lazy[i] = {0, 0};
  }
  void update(long long i, long long l, long long r, long long x, long long y,
              long long val, long long id) {
    if (l > y || x > r) {
      return;
    }
    if (x <= l && r <= y) {
      if (node[i].first < val) {
        node[i] = {val, id};
      }
      if (lazy[i].first < val) {
        lazy[i] = {val, id};
      }
      return;
    }
    Down(i);
    long long mid = (l + r) / 2;
    update(2 * i, l, mid, x, y, val, id);
    update(2 * i + 1, mid + 1, r, x, y, val, id);
    if (node[2 * i].first < node[2 * i + 1].first) {
      node[i] = node[2 * i + 1];
    } else {
      node[i] = node[2 * i];
    }
  }
  pair<long long, long long> get(long long i, long long l, long long r,
                                 long long x, long long y) {
    if (l > y || x > r) {
      return {0, 0};
    }
    if (x <= l && r <= y) {
      return node[i];
    }
    Down(i);
    long long mid = (l + r) / 2;
    pair<long long, long long> tmp1 = get(2 * i, l, mid, x, y);
    pair<long long, long long> tmp2 = get(2 * i + 1, mid + 1, r, x, y);
    if (tmp1.first < tmp2.first) {
      return tmp2;
    } else {
      return tmp1;
    }
  }
} IT;
long long maxVal;
void compress() {
  vector<long long> rar;
  for (long long i = 1; i <= m; ++i) {
    rar.push_back(a[i].l);
    rar.push_back(a[i].r);
  }
  sort(rar.begin(), rar.end());
  rar.resize(unique(rar.begin(), rar.end()) - rar.begin());
  for (long long i = 1; i <= m; ++i) {
    a[i].l = lower_bound(rar.begin(), rar.end(), a[i].l) - rar.begin() + 1;
    a[i].r = lower_bound(rar.begin(), rar.end(), a[i].r) - rar.begin() + 1;
  }
  maxVal = (long long)rar.size() + 1;
}
vector<long long> V;
bool mark[N];
pair<long long, long long> dp[N];
void sol() {
  compress();
  sort(a + 1, a + m + 1);
  IT.update(1, 1, maxVal, 1, maxVal, 0, 0);
  for (long long l = 1; l <= m; ++l) {
    long long r = l;
    while (r <= m && a[r].id == a[l].id) {
      ++r;
    }
    --r;
    for (long long i = l; i <= r; ++i) {
      long long id = a[i].id;
      pair<long long, long long> tmp = IT.get(1, 1, maxVal, a[i].l, a[i].r);
      if (dp[id].first < tmp.first + 1) {
        dp[id] = {tmp.first + 1, tmp.second};
      }
    }
    for (long long i = l; i <= r; ++i) {
      long long id = a[i].id;
      IT.update(1, 1, maxVal, a[i].l, a[i].r, dp[id].first, id);
    }
    l = r;
  }
  long long res = 0;
  long long save = -1;
  for (long long i = 1; i <= n; ++i) {
    if (res < dp[i].first) {
      res = dp[i].first;
      save = i;
    }
  }
  while (save > 0) {
    mark[save] = true;
    save = dp[save].second;
  }
  for (long long i = 1; i <= n; ++i) {
    if (!mark[i]) {
      V.push_back(i);
    }
  }
  cout << V.size() << '\n';
  for (long long r : V) {
    cout << r << " ";
  }
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (fopen("input.txt", "r")) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  }
  cin >> n >> m;
  for (long long i = 1; i <= m; ++i) {
    long long id, l, r;
    cin >> id >> l >> r;
    a[i] = {id, l, r};
  }
  sol();
  return 0;
}
