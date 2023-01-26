#include <bits/stdc++.h>
using namespace std;
const double pi = acos(0.0) * 2.0;
const long double eps = 1e-10;
const int step[8][2] = {{-1, 0}, {0, 1}, {1, 0},  {0, -1},
                        {-1, 1}, {1, 1}, {1, -1}, {-1, -1}};
template <class T>
inline T abs1(T a) {
  return a < 0 ? -a : a;
}
template <typename t, typename t1>
t min1(t a, t1 b) {
  return a < b ? a : b;
}
template <typename t, typename... arg>
t min1(t a, arg... arr) {
  return min1(a, min1(arr...));
}
template <typename t, typename t1>
t max1(t a, t1 b) {
  return a > b ? a : b;
}
template <typename t, typename... arg>
t max1(t a, arg... arr) {
  return max1(a, max1(arr...));
}
inline int jud(double a, double b) {
  if (abs(a) < eps && abs(b) < eps)
    return 0;
  else if (abs1(a - b) / max(abs1(a), abs1(b)) < eps)
    return 0;
  if (a < b) return -1;
  return 1;
}
template <typename t>
inline int jud(t a, t b) {
  if (a < b) return -1;
  if (a == b) return 0;
  return 1;
}
template <typename it, typename t1>
inline int RangeFind(t1 val, it a, int na, bool f_small = 1, bool f_lb = 1) {
  if (na == 0) return 0;
  int be = 0, en = na - 1;
  if (*a <= *(a + na - 1)) {
    if (f_lb == 0)
      while (be < en) {
        int mid = (be + en + 1) / 2;
        if (jud(*(a + mid), val) != 1)
          be = mid;
        else
          en = mid - 1;
      }
    else
      while (be < en) {
        int mid = (be + en) / 2;
        if (jud(*(a + mid), val) != -1)
          en = mid;
        else
          be = mid + 1;
      }
    if (f_small && jud(*(a + be), val) == 1) be--;
    if (!f_small && jud(*(a + be), val) == -1) be++;
  } else {
    if (f_lb)
      while (be < en) {
        int mid = (be + en + 1) / 2;
        if (jud(*(a + mid), val) != -1)
          be = mid;
        else
          en = mid - 1;
      }
    else
      while (be < en) {
        int mid = (be + en) / 2;
        if (jud(*(a + mid), val) != 1)
          en = mid;
        else
          be = mid + 1;
      }
    if (!f_small && jud(*(a + be), val) == -1) be--;
    if (f_small && jud(*(a + be), val) == 1) be++;
  }
  return be;
}
template <class T>
inline T lowb(T num) {
  return num & (-num);
}
inline int bitnum(unsigned int nValue) { return __builtin_popcount(nValue); }
inline int bitnum(int nValue) { return __builtin_popcount(nValue); }
inline int bitnum(unsigned long long nValue) {
  return __builtin_popcountll(nValue);
}
inline int bitnum(long long nValue) { return __builtin_popcountll(nValue); }
inline int bitmaxl(unsigned int a) {
  if (a == 0) return 0;
  return 32 - __builtin_clz(a);
}
inline int bitmaxl(int a) {
  if (a == 0) return 0;
  return 32 - __builtin_clz(a);
}
inline int bitmaxl(unsigned long long a) {
  if (a == 0) return 0;
  return 64 - __builtin_clzll(a);
}
inline int bitmaxl(long long a) {
  if (a == 0) return 0;
  return 64 - __builtin_clzll(a);
}
long long pow(long long n, long long m, long long mod = 0) {
  if (m < 0) return 0;
  long long ans = 1;
  long long k = n;
  while (m) {
    if (m & 1) {
      ans *= k;
      if (mod) ans %= mod;
    }
    k *= k;
    if (mod) k %= mod;
    m >>= 1;
  }
  return ans;
}
template <class t1, class t2>
inline void add(t1& a, t2 b, int mod = -1) {
  if (mod == -1) mod = 1000000007;
  a += b;
  while (a >= mod) a -= mod;
  while (a < 0) a += mod;
}
template <class t>
void output1(t arr) {
  for (int i = 0; i < (int)arr.size(); i++) cerr << arr[i] << ' ';
  cerr << endl;
}
template <class t>
void output2(t arr) {
  for (int i = 0; i < (int)arr.size(); i++) output1(arr[i]);
}
struct sap {
  struct edge {
    int to, next;
    long long cap;
  } e[40010 * 2];
  int p, head[10010], h[10010], vh[10010];
  int n, m, s, t;
  long long maxFlow;
  inline void addedge(int a, int b, long long c) {
    e[p].to = b, e[p].cap = c, e[p].next = head[a], head[a] = p++;
    e[p].to = a, e[p].cap = 0, e[p].next = head[b], head[b] = p++;
  }
  long long dfs(int u, long long pre) {
    if (u == t) return pre;
    long long now, aug, tmp = pre;
    int mh = n + 10, to;
    for (now = head[u]; now; now = e[now].next) {
      to = e[now].to;
      if (e[now].cap) {
        if (pre && h[u] == h[to] + 1) {
          aug = dfs(to, min(pre, e[now].cap));
          pre -= aug;
          e[now].cap -= aug;
          e[now ^ 1].cap += aug;
          if (h[s] >= n) return tmp - pre;
        }
        mh = min(mh, h[to]);
      }
    }
    if (tmp - pre > 0) return tmp - pre;
    --vh[h[u]];
    if (!vh[h[u]]) {
      h[s] = n;
      return 0;
    }
    ++vh[h[u] = mh + 1];
    return 0;
  }
  vector<int> FindMinCut() {
    vector<int> ans;
    int q[10010], in[10010];
    memset(in, 0, sizeof(in));
    int lq = 0;
    in[s] = 1;
    q[lq++] = s;
    for (int i = 0; i < lq; i++) {
      int no = q[i];
      for (int re = head[no]; re; re = e[re].next)
        if (e[re].cap && !in[e[re].to]) {
          in[e[re].to] = 1;
          q[lq++] = e[re].to;
        }
    }
    for (int i = 0; i < lq; i++) {
      int no = q[i];
      for (int re = head[no]; re; re = e[re].next)
        if (!in[e[re].to]) {
          ans.push_back(re);
        }
    }
    return ans;
  }
  void init() {
    maxFlow = 0;
    memset(h, 0, sizeof(h));
    memset(vh, 0, sizeof(vh));
    vh[0] = n;
  }
  void SAP() {
    init();
    while (h[s] < n) maxFlow += dfs(s, 0x5fffffffffffLL);
  }
  void pre(int nn, int ss = -1, int tt = -1) {
    p = 2;
    memset(head, 0, sizeof(head));
    n = nn;
    if (ss == -1)
      s = 0;
    else
      s = ss;
    if (tt == -1)
      t = n - 1;
    else
      t = tt;
  }
} g;
const int maxn = 10010;
int n, m;
long long orig[maxn], val[maxn];
int arr_no[maxn];
vector<int> e[maxn];
int mp[maxn];
long long ans[maxn];
long long Dfs(int* arr, int rn, int be, int en) {
  if (rn <= 0) return 0;
  if (rn == 1) {
    if (orig[arr[0]] >= val[be] && orig[arr[0]] <= val[en]) {
      ans[arr[0]] = orig[arr[0]];
      return 0;
    }
    if (arr[0] < val[be])
      ::ans[arr[0]] = val[be];
    else
      ::ans[arr[0]] = val[en];
    return min(abs(val[be] - orig[arr[0]]), abs(val[en] - orig[arr[0]]));
  }
  if (be == en) {
    long long ans = 0;
    for (int i = 0; i < rn; i++) {
      ans += abs(val[be] - orig[arr[i]]);
      ::ans[arr[i]] = val[be];
    }
    return ans;
  }
  long long mid = (be + en) / 2;
  int src = rn, sink = src + 1;
  g.pre(rn + 2, src, sink);
  for (int i = 0; i < rn; i++) mp[arr[i]] = i;
  for (int i = 0; i < rn; i++) {
    int no = arr[i];
    if (orig[no] > val[mid])
      g.addedge(src, i, orig[no] - val[mid]);
    else
      g.addedge(i, sink, val[mid + 1] - orig[no]);
    for (const auto it : e[no]) {
      g.addedge(i, mp[it], 0x5fffffffffffLL);
    }
  }
  g.SAP();
  vector<int> cuts = g.FindMinCut();
  for (int i = 0; i < rn; i++) {
    mp[arr[i]] = bool(orig[arr[i]] > val[mid]);
  }
  for (const auto re : cuts) {
    int to = g.e[re].to, from = g.e[re ^ 1].to;
    if (to == sink) {
      assert(orig[arr[from]] <= val[mid]);
      mp[arr[from]] = 1;
    }
    if (from == src) {
      assert(orig[arr[to]] > val[mid]);
      mp[arr[to]] = 0;
    }
  }
  sort(arr, arr + rn,
       [&](const int& a, const int& b) { return mp[a] < mp[b]; });
  int mid_no = rn;
  for (int i = 0; i < rn; i++)
    if (mp[arr[i]] == 1) {
      mid_no = i;
      break;
    }
  for (int i = 0; i < mid_no; i++) {
    sort(e[arr[i]].begin(), e[arr[i]].end(),
         [&](const int& a, const int& b) { return mp[a] < mp[b]; });
    while (e[arr[i]].size() && mp[e[arr[i]].back()] == 1) e[arr[i]].pop_back();
  }
  for (int i = mid_no; i < rn; i++) {
    sort(e[arr[i]].begin(), e[arr[i]].end(),
         [&](const int& a, const int& b) { return mp[a] > mp[b]; });
    while (e[arr[i]].size() && mp[e[arr[i]].back()] == 0) e[arr[i]].pop_back();
  }
  long long ans = Dfs(arr, mid_no, be, mid);
  ans += Dfs(arr + mid_no, rn - mid_no, mid + 1, en);
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%I64d", orig + i);
    val[i] = orig[i];
    arr_no[i] = i;
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    e[a].push_back(b);
  }
  int nval = n;
  sort(val, val + n);
  nval = unique(val, val + n) - val;
  long long tans = Dfs(arr_no, n, 0, nval - 1);
  for (int i = 0; i < n; i++) {
    printf("%I64d ", ans[i]);
  }
  puts("");
  return 0;
}
