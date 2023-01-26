#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const int N = 1e6 + 7;
int n;
struct Node {
  int sm;
  int mn;
  Node() {
    sm = 0;
    mn = 0;
  }
  Node(int x) {
    sm = x;
    mn = min(x, 0);
  }
  Node(int sm_, int mn_) {
    sm = sm_;
    mn = mn_;
  }
  int ok() { return mn >= 0; }
  friend Node conq(const Node &l, const Node &r) {
    return Node(l.sm + r.sm, min(l.mn, l.sm + r.mn));
  }
};
namespace SegmentTree {
Node t[4 * N];
void pull(int v) { t[v] = conq(t[2 * v + 1], t[2 * v + 2]); }
void set(int v, int l, int r, int pos, int val) {
  if (l + 1 == r) {
    t[v] = Node(val);
  } else {
    int m = (r + l) >> 1;
    if (pos < m) {
      set(2 * v + 1, l, m, pos, val);
    } else {
      set(2 * v + 2, m, r, pos, val);
    }
    pull(v);
  }
}
void set(int pos, int val) { set(0, 0, n, pos, val); }
void solve(int v, int l, int r, int ql, int qr, Node &cur, int &ans,
           int &found) {
  if (qr <= l || r <= ql) {
    return;
  } else if (ql <= l && r <= qr) {
    if (conq(cur, t[v]).ok()) {
      cur = conq(cur, t[v]);
    } else {
      int m = (r + l) >> 1;
      if (l + 1 == r) {
        ans = l;
        found = 1;
      } else {
        if (conq(cur, t[2 * v + 1]).ok()) {
          cur = conq(cur, t[2 * v + 1]);
          solve(2 * v + 2, m, r, ql, qr, cur, ans, found);
        } else {
          solve(2 * v + 1, l, m, ql, qr, cur, ans, found);
        }
      }
    }
  } else {
    int m = (r + l) >> 1;
    if (!found) {
      solve(2 * v + 1, l, m, ql, qr, cur, ans, found);
    }
    if (!found) {
      solve(2 * v + 2, m, r, ql, qr, cur, ans, found);
    }
  }
}
int solve(int i) {
  Node cur;
  int ans = n;
  int found = 0;
  solve(0, 0, n, i, n, cur, ans, found);
  return ans;
}
}  // namespace SegmentTree
vector<int> OP[N];
vector<int> CL[N];
void add_segment(int l, int r, int val) {
  if (l <= r) {
    assert(r <= val);
    OP[l].push_back(val);
    CL[r].push_back(val);
  }
}
void process(vector<pair<int, int>> val) {
  for (auto [i, v] : val) {
    SegmentTree::set(i, v);
  }
  int prev = -1;
  for (auto [i, v] : val) {
    if (prev + 1 <= i - 1) {
      int pr = SegmentTree::solve(prev + 1);
      add_segment(prev + 1, i - 1, pr);
    }
    {
      int cr = SegmentTree::solve(i);
      add_segment(i, i, cr);
    }
    prev = i;
  }
  if (prev + 1 <= n - 1) {
    int pr = SegmentTree::solve(prev + 1);
    add_segment(prev + 1, n - 1, pr);
  }
  for (auto [i, v] : val) {
    SegmentTree::set(i, 0);
  }
}
vector<pair<int, int>> by_primes[N];
int prime[N];
int some[N];
void init() {
  fill(prime, prime + N, 1);
  for (int i = 2; i < N; i++) {
    if (prime[i]) {
      for (int j = 2 * i; j < N; j += i) {
        if (prime[j]) {
          prime[j] = 0;
          some[j] = i;
        }
      }
      some[i] = i;
    }
  }
}
void factorize(int x, int ind, int c) {
  while (x > 1) {
    int current_prime = some[x];
    int cnt = 0;
    while (x % current_prime == 0) {
      x /= current_prime;
      cnt++;
    }
    by_primes[current_prime].push_back({ind, c * cnt});
  }
}
int a[N];
int max_r[N];
void solve_segments() {
  multiset<int> S;
  for (int i = 0; i < n; i++) {
    for (auto x : OP[i]) {
      S.insert(x);
    }
    max_r[i] = *S.begin();
    for (auto x : CL[i]) {
      S.erase(S.find(x));
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  init();
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == '*') {
      factorize(a[i], i, 1);
    } else {
      factorize(a[i], i, -1);
    }
  }
  for (int p = 2; p < N; p++) {
    process(by_primes[p]);
  }
  solve_segments();
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += (max_r[i] - i);
  }
  cout << ans << '\n';
}
