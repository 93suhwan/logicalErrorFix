#include <bits/stdc++.h>
using namespace std;
struct CHT {
  deque<pair<long long int, long long int> > d;
  long long int get(long long int x) {
    while (long long int((d).size()) >= 2) {
      long long int a = d[0].first * x + d[0].second;
      long long int b = d[1].first * x + d[1].second;
      if (a <= b) break;
      d.pop_front();
    }
    return d[0].first * x + d[0].second;
  }
  void add(pair<long long int, long long int> x) {
    while (long long int((d).size()) >= 2) {
      pair<long long int, long long int> y = d[long long int((d).size()) - 1];
      pair<long long int, long long int> z = d[long long int((d).size()) - 2];
      if ((x.second - y.second) * (z.first - y.first) >=
          (y.first - x.first) * (y.second - z.second))
        break;
      d.pop_back();
    }
    d.push_back(x);
  }
};
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int fastpowMOD(long long int a, long long int p, long long int MOD) {
  if (p == 0) return 1;
  long long int z = fastpowMOD(a, p / 2, MOD);
  z = (z * z) % MOD;
  if (p % 2) z = (z * a) % MOD;
  return z;
}
long long int fastpow(long long int a, long long int p) {
  if (p == 0) return 1;
  long long int z = fastpow(a, p / 2);
  z = (z * z);
  if (p % 2) z = (z * a);
  return z;
}
const long long int INF = 1e18;
vector<long long int> lazy;
vector<long long int> tree;
void updateRange(long long int node, long long int start, long long int end,
                 long long int l, long long int r, long long int val) {
  if (lazy[node] != 0) {
    tree[node] += (+1) * lazy[node];
    if (start != end) {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
  if (start > end or start > r or end < l) return;
  if (start >= l and end <= r) {
    lazy[node] += (+1) * val;
    if (start != end) {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    tree[node] += lazy[node];
    lazy[node] = 0;
    return;
  }
  long long int mid = (start + end) / 2;
  updateRange(node * 2, start, mid, l, r, val);
  updateRange(node * 2 + 1, mid + 1, end, l, r, val);
  tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}
long long int queryRange(long long int node, long long int start,
                         long long int end, long long int l, long long int r) {
  if (lazy[node] != 0) {
    tree[node] += (1) * lazy[node];
    if (start != end) {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
  if (start > end or start > r or end < l) return -INF;
  if (start >= l and end <= r) return tree[node];
  long long int mid = (start + end) / 2;
  if (r <= mid)
    return queryRange(node * 2, start, mid, l, r);
  else if (l >= mid + 1)
    return queryRange(node * 2 + 1, mid + 1, end, l, r);
  long long int p1 = queryRange(node * 2, start, mid, l, r);
  long long int p2 = queryRange(node * 2 + 1, mid + 1, end, l, r);
  return max(p1, p2);
}
void convert_reduce(long long int arr[], long long int n) {
  vector<pair<long long int, long long int> > v;
  for (long long int i = 0; i < n; i++) v.push_back(make_pair(arr[i], i));
  sort(v.begin(), v.end());
  long long int cnt = 0;
  for (long long int i = 0; i < n; i++) {
    arr[v[i].second] = cnt;
    long long int j = i;
    while (j < n && v[j].first == v[i].first) arr[v[j++].second] = cnt;
    i = j - 1;
    cnt++;
  }
}
vector<char> prime(1000000 + 5, true);
void sieve(long long int n) {
  prime[0] = prime[1] = false;
  for (long long int i = 2; i <= n; ++i) {
    if (prime[i]) {
      for (long long int j = 2 * i; j <= n; j += i) {
        prime[j] = false;
      }
    }
  }
}
long long int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool valid(long long int i, long long int j, long long int n, long long int m) {
  return i >= 1 && i <= n && j >= 1 && j <= m;
}
int main() {
  long long int q, i, j;
  cin >> q;
  while (q--) {
    long long int n;
    cin >> n;
    long long int a[n];
    for (i = 0; i < n; i++) cin >> a[i];
    long long int par[2];
    par[0] = par[1] = 0;
    for (i = 0; i < n; i++) par[a[i] % 2]++;
    if (n % 2) {
      if (par[0] - par[1] == 1) {
        long long int ans = 0;
        long long int prev = 0;
        for (i = 0; i < n; i++) {
          if (a[i] % 2 == 0) {
            ans += abs(i - prev);
            prev += 2;
          }
        }
        cout << ans << endl;
      } else if (par[1] - par[0] == 1) {
        long long int ans = 0;
        long long int prev = 0;
        for (i = 0; i < n; i++) {
          if (a[i] % 2 == 1) {
            ans += abs(i - prev);
            prev += 2;
          }
        }
        cout << ans << endl;
      } else {
        cout << -1 << endl;
      }
    } else {
      if (par[0] != par[1]) {
        cout << -1 << endl;
        continue;
      }
      long long int ans1 = 0, ans2 = 0;
      long long int prev1 = 0, prev2 = 0;
      for (i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
          ans1 += abs(i - prev1);
          prev1 += 2;
        } else {
          ans2 += abs(i - prev2);
          prev2 += 2;
        }
      }
      cout << min(ans1, ans2) << endl;
    }
  }
  return 0;
}
