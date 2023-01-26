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
const int maxn = 110;
const int mod = 998244353;
struct Group {
  vector<vector<Group*>> links;
  bitset<maxn> unassigned, all;
} all_group[maxn * 10];
int lall_group = 1;
Group* NewGroup() { return all_group + lall_group++; }
int n, m;
Group* top = all_group;
bool can = 1;
int Test(const bitset<maxn>& rb) {
  return bitnum(*(unsigned long long*)(&rb)) +
         bitnum(*((unsigned long long*)(&rb) + 1) & ((1ll << (maxn % 64)) - 1));
}
vector<Group*> Split(const bitset<maxn>& rb, Group* g) {
  if ((g->all & rb) == g->all) {
    return {g};
  }
  vector<int> tail, others;
  set<Group*> need_recur;
  int cnt_tail = 0;
  for (int i = 0; i < (int)g->links.size(); i++) {
    vector<int> have(g->links[i].size());
    int have_recur = 0;
    for (int j = 0; j < (int)g->links[i].size(); j++) {
      if ((rb & g->links[i][j]->all) == g->links[i][j]->all) {
        have[j] = 2;
      } else if (Test(rb & g->links[i][j]->all)) {
        have[j] = 1;
        need_recur.insert(g->links[i][j]);
        have_recur++;
      } else {
        have[j] = 0;
      }
    }
    if (have.back() > *have.begin()) {
      reverse(g->links[i].begin(), g->links[i].end());
      reverse(have.begin(), have.end());
    }
    for (int j = 0; j < (int)have.size() - 1; j++) {
      if (have[j] < have[j + 1]) {
        cerr << 1 << endl;
        can = 0;
        return {};
      }
    }
    if (*have.begin() == 0) continue;
    if (have_recur > 1) {
      cerr << 2 << endl;
      can = 0;
      return {};
    }
    cnt_tail += have.back() != 2;
    if (have.back() != 2) {
      tail.push_back(i);
    } else {
      others.push_back(i);
    }
  }
  if (tail.size() > 2) {
    cerr << 3 << endl;
    can = 0;
    return {};
  }
  if (tail.size() == 2 && (rb & g->all) != rb) {
    cerr << 4 << endl;
    can = 0;
    return {};
  }
  vector<Group*> new_link;
  auto push = [&](const int idx) {
    for (int j = 0; j < (int)g->links[idx].size(); j++) {
      if (need_recur.find(g->links[idx][j]) != need_recur.end()) {
        for (Group* rg : Split(rb, g->links[idx][j])) {
          new_link.push_back(rg);
        }
      } else {
        new_link.push_back(g->links[idx][j]);
      }
    }
  };
  Group* mid = NewGroup();
  mid->all = mid->unassigned = g->unassigned & rb;
  for (const int i : others) {
    mid->links.push_back(g->links[i]);
    for (Group* rg : g->links[i]) {
      mid->all |= rg->all;
    }
  }
  if (tail.size()) {
    push(tail[0]);
    reverse(new_link.begin(), new_link.end());
  }
  if (Test(mid->all)) new_link.push_back(mid);
  if (tail.size() > 1) {
    push(tail[1]);
  }
  for (int i = g->links.size() - 1; i >= 0; i--) {
    bool rm = 0;
    for (const auto it : tail)
      if (it == i) rm = 1;
    for (const auto it : others)
      if (it == i) rm = 1;
    if (rm) g->links.erase(g->links.begin() + i);
  }
  g->unassigned ^= mid->unassigned;
  if ((rb & g->all) != rb) {
    for (Group* rg : new_link) {
      g->all ^= rg->all;
    }
    new_link.push_back(g);
    return new_link;
  } else {
    g->links.push_back(new_link);
    return {g};
  }
  return {};
}
long long fac[maxn];
long long GetAns(Group* g) {
  long long ans = fac[Test(g->unassigned) + g->links.size()];
  for (int i = 0; i < (int)g->links.size(); i++) {
    for (Group* rg : g->links[i]) {
      ans *= GetAns(rg);
      ans %= mod;
    }
    if (g->links[i].size() >= 2) {
      ans *= 2;
      ans %= mod;
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  freopen("input.txt", "r", stdin);
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    top->unassigned.set(i, 1);
    top->all.set(i, 1);
  }
  vector<bitset<maxn>> all;
  for (int i = 0; i < m; i++) {
    int cnt = 0;
    scanf("%d", &cnt);
    bitset<maxn> rb;
    rb.reset();
    for (int j = 0; j < cnt; j++) {
      int num;
      scanf("%d", &num);
      num--;
      rb.set(num, 1);
    }
    Split(rb, top);
    all.push_back(rb);
    if (!can) break;
  }
  fac[0] = 1;
  for (int i = 1; i < maxn; i++) {
    fac[i] = fac[i - 1] * i % mod;
  }
  if (!can) {
    puts("0");
    return 0;
  } else {
    printf("%I64d\n", GetAns(top));
  }
  return 0;
}
