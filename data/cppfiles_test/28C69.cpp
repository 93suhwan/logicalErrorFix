#include <bits/stdc++.h>
using namespace std;
mt19937_64 rang(
    chrono::high_resolution_clock::now().time_since_epoch().count());
long long mpow(long long base, long long exp);
long long power(long long a, long long b);
const long long mod = 1000000007;
vector<int> g[1000005];
struct node {
  set<int> s;
};
struct segTree {
  long long arr[301];
  int res[1203];
  long long operation_arr[1203];
  long long NO_OPERATION = 0;
  void init(int x, int lo, int hi) {
    operation_arr[x] = NO_OPERATION;
    if (lo == hi) {
      res[x] = arr[lo];
      return;
    }
    int mid = (lo + hi) / 2;
    init(2 * x, lo, mid);
    init(2 * x + 1, mid + 1, hi);
    update_point(x);
  }
  long long merge_operation(long long a, long long b) { return (a ^ b); }
  int merge_results(int a, int b) { return a + b; }
  void point_modify(int x, int lo, int hi, int pos, long long val) {
    if (lo == hi) {
      res[x] = val;
      return;
    }
    int mid = (lo + hi) / 2;
    if (pos <= mid)
      point_modify(2 * x, lo, mid, pos, val);
    else
      point_modify(2 * x + 1, mid + 1, hi, pos, val);
    update_point(x);
  }
  void update_point(int x) { res[x] = res[2 * x] + res[2 * x + 1]; }
  int query(int x, int lo, int hi, int l, int r) {
    if (lo >= l && hi <= r) {
      return res[x];
    }
    int mid = (hi + lo) / 2;
    int res;
    if (r <= mid)
      res = query(2 * x, lo, mid, l, r);
    else if (l > mid)
      res = query(2 * x + 1, mid + 1, hi, l, r);
    else
      res = merge_results(query(2 * x, lo, mid, l, r),
                          query(2 * x + 1, mid + 1, hi, l, r));
    return res;
  }
};
struct FenwickTree {
  int arr[100];
  int n;
  void update(int i, int delta) {
    while (i <= n) {
      arr[i] += delta;
      i = i + (i & (-i));
    }
  }
  int sum(int i) {
    if (i == 0) return 0;
    int res = 0;
    while (i > 0) {
      res = res + arr[i];
      i -= (i & (-i));
    }
    return res;
  }
};
struct dsu {
  int par[1001];
  int size_set[1001];
  void init(int n) {
    for (int i = 0; i <= n; i++) par[i] = i, size_set[i] = 1;
  }
  int get_par(int u) {
    vector<int> temp;
    while (par[u] != u) {
      temp.push_back(u);
      u = par[u];
    }
    for (int i : temp) par[i] = u;
    return u;
  }
  void union_set(int a, int b) {
    a = get_par(a);
    b = get_par(b);
    if (a == b) return;
    if (size_set[a] < size_set[b]) {
      int temp = a;
      a = b;
      b = temp;
    }
    par[b] = a;
    size_set[a] += size_set[b];
  }
  int get_size(int u) {
    u = get_par(u);
    return size_set[u];
  }
};
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  if (b == 0) return a;
  return gcd(b, a % b);
}
bool contains_dup(string s) {
  int cnt[26];
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < s.size(); i++) {
    cnt[s[i] - 'a']++;
    if (cnt[s[i] - 'a'] > 1) return 1;
  }
  return 0;
}
bool isOverflow(long long a, long long b) {
  if (a == 0 || b == 0) return false;
  if (a <= LLONG_MAX / b)
    return false;
  else
    return true;
}
bool isOverflow_add(long long a, long long b) {
  long long res = a + b;
  if (res - a == b && res - b == a) return 0;
  return 1;
}
int d[200002];
long long N = (200000 + 1);
vector<long long> pr;
void seive(int N) {
  for (int i = 2; i < N; i++) d[i] = i;
  for (long long i = 2; i < N; i++) {
    if (d[i] == i) pr.push_back(i);
    for (long long j = 0;
         j < (long long)pr.size() && pr[j] <= d[i] && i * pr[j] < N; j++)
      d[i * pr[j]] = pr[j];
  }
}
bool is_prime(int n) {
  if (d[n] == n) return 1;
  return 0;
}
vector<pair<int, int> > fctorize(int n) {
  vector<pair<int, int> > res;
  while (n > 1) {
    int k = d[n];
    int cnt = 0;
    while (n > 1 && k == d[n]) n /= d[n], cnt++;
    res.push_back({k, cnt});
  }
  return res;
}
vector<pair<int, int> > prime_factorize(int n) {
  vector<pair<int, int> > res;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      int cnt = 0;
      while (n % i == 0) n /= i, cnt++;
      res.push_back({i, cnt});
    }
  }
  if (n > 1) res.push_back({n, 1});
  return res;
}
void solve() {
  long long a, b, c;
  cin >> a >> b >> c;
  long long x1 = 0, x2 = 0;
  x1 = 3 * (c / 2), x2 = 3 * (c - c / 2);
  if (c % 2 == 0) {
    if (b % 2 == 0) {
      if (a % 2 == 0) {
        cout << "0"
             << "\n";
      } else {
        cout << "1"
             << "\n";
      }
    } else {
      if (a % 2 == 0) {
        cout << "0"
             << "\n";
      } else {
        cout << "1"
             << "\n";
      }
    }
  } else {
    if (b % 2 == 0) {
      if (a % 2 == 0) {
        cout << "1"
             << "\n";
      } else {
        cout << "0"
             << "\n";
      }
    } else {
      if (a % 2 == 0) {
        cout << "1"
             << "\n";
      } else {
        cout << "0"
             << "\n";
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  int t = 1;
  cin >> t;
  int t1 = 1;
  while (t--) {
    solve();
    t1++;
  }
  return 0;
}
long long mpow(long long base, long long exp) {
  base %= mod;
  long long result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((long long)result * base) % mod;
    base = ((long long)base * base) % mod;
    exp >>= 1;
  }
  return result;
}
long long power(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b % 2 == 0) {
      b /= 2;
      if (isOverflow(a, a)) return LLONG_MAX;
      a = a * a;
    } else {
      if (isOverflow(res, a)) return LLONG_MAX;
      res = res * a;
      b--;
    }
  }
  return res;
}
