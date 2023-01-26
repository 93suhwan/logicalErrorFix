#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,avx2")
#pragma GCC optimize("Ofast")
using namespace std;
const int MOD = 1000000007;
const int UNDEF = -1;
const int INF = 1 << 30;
template <typename T>
inline bool chkmax(T &aa, T bb) {
  return aa < bb ? aa = bb, true : false;
}
template <typename T>
inline bool chkmin(T &aa, T bb) {
  return aa > bb ? aa = bb, true : false;
}
template <typename T>
void makeunique(vector<T> &vx) {
  sort(vx.begin(), vx.end());
  auto it = unique(vx.begin(), vx.end());
  vx.resize(std::distance(vx.begin(), it));
}
int rint();
char rch();
long long rlong();
const int MAXN = 1e6 + 4;
const int MAXP = MAXN;
bool sieve_array[MAXP + 1];
int ap[MAXP + 1];
vector<int> gpv;
void sieve() {
  for (int i = 0; i <= MAXP; i++) {
    sieve_array[i] = true;
    ap[i] = 1 << 30;
  }
  sieve_array[0] = false;
  sieve_array[1] = false;
  int lim = (int)(ceil(sqrt(MAXP))) + 2;
  for (int i = 2; i <= lim; i++) {
    if (sieve_array[i]) {
      for (int j = i * i; j <= MAXP; j += i) {
        sieve_array[j] = false;
        ap[j] = i;
      }
    }
  }
  for (int i = 2; i <= MAXP; i++) {
    if (sieve_array[i]) {
      gpv.push_back(i);
      ap[i] = i;
    }
  }
}
pair<int, int> factorize_dest[500];
int factorize_tmp[500];
int factorize(int x) {
  const int power = 1;
  int tsz = 0;
  while (x >= MAXP) {
    bool found = false;
    for (auto &p : gpv) {
      if (p * (long long)p > x) break;
      while ((x % p) == 0) {
        x /= p;
        factorize_tmp[tsz++] = p;
        found = true;
      }
    }
    if (x < MAXP) break;
    if (!found) break;
  }
  if (x < MAXP) {
    while (x > 1) {
      int p = ap[x];
      x /= p;
      factorize_tmp[tsz++] = p;
    }
  }
  if (x > 1) factorize_tmp[tsz++] = x;
  sort(factorize_tmp, factorize_tmp + tsz);
  int didx = 0;
  for (int tidx = 0; tidx < tsz; tidx++) {
    int p = factorize_tmp[tidx];
    if (tidx == 0 || p != factorize_tmp[tidx - 1]) {
      factorize_dest[didx++] = make_pair(p, power);
    } else
      factorize_dest[didx - 1].second += power;
  }
  return didx;
}
class UnionFind {
 public:
  vector<int> ufParent;
  vector<int> rank;
  inline void ufreset(int x) {
    ufParent[x] = x;
    rank[x] = 0;
  }
  void init(int n) {
    ufParent.resize(n);
    rank.resize(n);
    for (int x = 0; x < n; x++) {
      ufreset(x);
    }
  }
  int ffind(int x) {
    if (ufParent[x] != x) {
      ufParent[x] = ffind(ufParent[x]);
    }
    return ufParent[x];
  }
  void funion(int _x, int _y) {
    int xr = ffind(_x);
    int yr = ffind(_y);
    if (xr == yr) return;
    if (rank[xr] > rank[yr]) swap(xr, yr);
    if (rank[xr] == rank[yr]) rank[yr]++;
    ufParent[xr] = yr;
  }
};
UnionFind uf;
set<pair<int, int> > sedge;
void insEdge(int x, int y) {
  if (x > y) swap(x, y);
  sedge.insert(make_pair(x, y));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  sieve();
  int n = rint();
  int qn = rint();
  vector<int> a(n);
  vector<vector<int> > vfac(n);
  uf.init(MAXN);
  for (int i = 0; i < n; i++) {
    a[i] = rint();
    int k = factorize(a[i]);
    for (int x = 0; x < k; x++) vfac[i].push_back(factorize_dest[x].first);
    for (int x = 1; x < k; x++) {
      uf.funion(factorize_dest[x].first, factorize_dest[x - 1].first);
    }
  }
  for (int i = 0; i < n; i++) {
    int k = factorize(a[i] + 1);
    int fac = vfac[i][0];
    int id = uf.ffind(fac);
    for (int x = 0; x < k; x++) {
      insEdge(id, uf.ffind(factorize_dest[x].first));
      for (int y = 0; y < x; y++) {
        insEdge(uf.ffind(factorize_dest[x].first),
                uf.ffind(factorize_dest[y].first));
      }
    }
  }
  for (int qi = 0; qi < qn; qi++) {
    int a = uf.ffind(vfac[rint() - 1][0]);
    int b = uf.ffind(vfac[rint() - 1][0]);
    if (a > b) swap(a, b);
    if (a == b) {
      printf("0\n");
    } else {
      if (sedge.count(make_pair(a, b))) {
        printf("1\n");
      } else {
        printf("2\n");
      }
    }
  }
}
static char stdinBuffer[1024];
static char *stdinDataEnd = stdinBuffer + sizeof(stdinBuffer);
static const char *stdinPos = stdinDataEnd;
void readAhead(size_t amount) {
  size_t remaining = stdinDataEnd - stdinPos;
  if (remaining < amount) {
    memmove(stdinBuffer, stdinPos, remaining);
    size_t sz = fread(stdinBuffer + remaining, 1,
                      sizeof(stdinBuffer) - remaining, stdin);
    stdinPos = stdinBuffer;
    stdinDataEnd = stdinBuffer + remaining + sz;
    if (stdinDataEnd != stdinBuffer + sizeof(stdinBuffer)) *stdinDataEnd = 0;
  }
}
int rint() {
  readAhead(16);
  int x = 0;
  bool neg = false;
  while (*stdinPos == ' ' || *stdinPos == '\n') ++stdinPos;
  if (*stdinPos == '-') {
    ++stdinPos;
    neg = true;
  }
  while (*stdinPos >= '0' && *stdinPos <= '9') {
    x *= 10;
    x += *stdinPos - '0';
    ++stdinPos;
  }
  return neg ? -x : x;
}
char rch() {
  readAhead(16);
  while (*stdinPos == ' ' || *stdinPos == '\n') ++stdinPos;
  char ans = *stdinPos;
  ++stdinPos;
  return ans;
}
long long rlong() {
  readAhead(32);
  long long x = 0;
  bool neg = false;
  while (*stdinPos == ' ' || *stdinPos == '\n') ++stdinPos;
  if (*stdinPos == '-') {
    ++stdinPos;
    neg = true;
  }
  while (*stdinPos >= '0' && *stdinPos <= '9') {
    x *= 10;
    x += *stdinPos - '0';
    ++stdinPos;
  }
  return neg ? -x : x;
}
