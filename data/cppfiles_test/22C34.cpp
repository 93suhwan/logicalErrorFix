#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize("-ffloat-store")
using namespace std;
const auto start_time = std::chrono::high_resolution_clock::now();
void aryanc403() {}
const long long int INF = 0xFFFFFFFFFFFFFFFL;
long long int seed;
mt19937 rng(seed = chrono::steady_clock::now().time_since_epoch().count());
inline long long int rnd(long long int l = 0, long long int r = INF) {
  return uniform_int_distribution<long long int>(l, r)(rng);
}
class CMP {
 public:
  bool operator()(pair<long long int, long long int> a,
                  pair<long long int, long long int> b) {
    return !(a.first < b.first || (a.first == b.first && a.second <= b.second));
  }
};
void add(map<long long int, long long int> &m, long long int x,
         long long int cnt = 1) {
  auto jt = m.find(x);
  if (jt == m.end())
    m.insert({x, cnt});
  else
    jt->second += cnt;
}
void del(map<long long int, long long int> &m, long long int x,
         long long int cnt = 1) {
  auto jt = m.find(x);
  if (jt->second <= cnt)
    m.erase(jt);
  else
    jt->second -= cnt;
}
bool cmp(const pair<long long int, long long int> &a,
         const pair<long long int, long long int> &b) {
  return a.first < b.first || (a.first == b.first && a.second < b.second);
}
const long long int mod = 1000000007L;
long long int T, n, i, j, k, in, cnt, l, r, u, v, x, y;
long long int m;
string s;
vector<long long int> a;
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  {
    cin >> n >> k;
    vector<pair<long long int, long long int> > s, t;
    s.push_back({0, (1LL << n) - 1});
    while (k--) {
      cin >> m;
      vector<long long int> a(m);
      long long int cur = 0;
      for (auto &x : a) {
        cin >> x;
        x--;
        cur |= 1LL << x;
      }
      sort(begin(a), end(a));
      vector<long long int> b(m + 1);
      for (int i = 0; i < m; ++i) b[i + 1] = b[i] | (1LL << a[i]);
      t.clear();
      for (const auto &z : s) {
        const long long int u = z.first & (~cur), v = z.second & (~cur);
        const int unassigned = (__builtin_popcountll(z.second & cur));
        const int one = (__builtin_popcountll(z.first & cur));
        for (int j = one; j <= one + unassigned; ++j) {
          t.push_back({u | b[j], v});
        }
      }
      s.swap(t);
      cerr << ((long long int)(s).size()) << "\n";
    }
    42;
    ;
    bool fl = true;
    {
      set<long long int> c;
      c.insert(0);
      for (long long int cur = 0, j = 0; j < n; ++j) {
        cur |= 1LL << j;
        c.insert(cur);
      }
      long long int cur = 0, j = 0;
      for (const auto &z : s) {
        if (!fl) break;
        if (z.second)
          fl = false;
        else if (!c.count(z.first))
          fl = false;
        cur |= 1LL << j;
        j++;
      }
    }
    if (n == 1) fl = true;
    cout << (fl ? "ACCEPTED" : "REJECTED") << "\n";
  }
  aryanc403();
  return 0;
}
