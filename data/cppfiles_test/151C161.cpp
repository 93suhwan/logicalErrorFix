#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
#pragma GCC optimize(2)
using namespace std;
inline long long rd() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return f * x;
}
struct pair_hash {
  template <class T1, class T2>
  size_t operator()(pair<T1, T2> const &pair) const {
    size_t h1 = hash<T1>()(pair.first);
    size_t h2 = hash<T2>()(pair.second);
    return h1 ^ h2;
  }
};
int cmp(int first, int second) { return first > second; }
const int N = 1e6 + 10, INF = 0x3f3f3f3f, mod1 = 998244353, mod2 = 1e9 + 9;
long long qmi(long long d, long long k) {
  long long res = 1;
  while (k) {
    if (k & 1) res = res * d % mod1;
    k >>= 1;
    d = d * d % mod1;
  }
  return res;
}
long long gcd(long long first, long long second) {
  return second ? gcd(second, first % second) : first;
}
vector<pair<int, int> > vec;
int k = 1e6 + 10;
int first[N];
list<int> List[N];
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int q;
  cin >> q;
  vector<int> e;
  int cnt = 1;
  while (q--) {
    int p, x, y;
    cin >> p;
    if (p == 1) {
      cin >> x;
      List[x].push_back(cnt++);
    } else {
      cin >> x >> y;
      List[y].splice(List[y].end(), List[x]);
    }
  }
  for (int i = 1; i < 5e5 + 10; i++) {
    for (auto k : List[i]) {
      first[k] = i;
    }
  }
  for (int i = 1; i < cnt; i++) cout << first[i] << " ";
  cout << endl;
}
