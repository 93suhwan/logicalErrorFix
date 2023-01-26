#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
using pii = pair<int, int>;
using vec = vector<int>;
using veg = vector<pii>;
using ull = unsigned long long;
template <typename T>
T read() {
  T x = 0;
  bool f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
  return f ? -x : x;
}
template <typename T>
void chkmax(T &x, const T &y) {
  x = x > y ? x : y;
}
template <typename T>
void chkmin(T &x, const T &y) {
  x = x < y ? x : y;
}
const int N = 1e6 + 10;
mt19937_64 rnd(time(NULL));
ull pri[N], all, b[N];
int n;
map<ull, int> s;
bool vis[N];
void output(const vec &ban) {
  for (int i = (1); i <= (n); i++) vis[i] = true;
  for (auto v : ban) vis[v] = false;
  vec pot;
  for (int i = (1); i <= (n); i++)
    if (vis[i]) pot.emplace_back(i);
  printf("%lu\n", pot.size());
  for (auto v : pot) printf("%d ", v);
  puts("");
  exit(0);
}
int main() {
  n = read<int>();
  for (int i = (2); i <= (n); i++) {
    pri[i] = rnd();
    int x = i;
    for (int j = (2); j <= (x); j++) {
      if (j * j > x) break;
      while (x % j == 0) b[i] ^= pri[j], x /= j;
    }
    if (x > 1) b[i] ^= pri[x];
    b[i] ^= b[i - 1];
    all ^= b[i];
  }
  if (all == 0) output({});
  for (int i = (2); i <= (n); i++) s[b[i]] = i;
  if (s.count(all)) output({s[all]});
  for (int i = (2); i <= (n); i++)
    if (s.count(all ^ b[i])) output({i, s[all ^ b[i]]});
  all ^= b[n];
  for (int i = (2); i <= (n - 1); i++)
    if (s.count(all ^ b[i])) output({i, s[all ^ b[i]], n});
  assert(0);
  return 0;
}
