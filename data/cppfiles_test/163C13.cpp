#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
struct Node {
  int x, y;
  int dx, dy;
  bool operator<(const Node& b) const {
    if (x != b.x) return x < b.x;
    if (y != b.y) return y < b.y;
    if (dx != b.dx) return dx < b.dx;
    return dy < b.dy;
  }
};
int N, M;
int RB, CB;
int RD, CD;
long long P;
set<Node> rem;
vector<Node> xu;
inline long long powMy(long long a, long long n) {
  long long ret = 1;
  for (; n; n >>= 1, (a *= a) %= mod)
    if (n & 1) (ret *= a) %= mod;
  return ret;
}
const long long ni100 = powMy(100, mod - 2);
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    rem.clear();
    xu.clear();
    scanf("%d %d %d %d %d %d %lld", &N, &M, &RB, &CB, &RD, &CD, &P);
    long long QQ = 100 - P;
    long long Q = (100 - P) * ni100 % mod;
    (P *= ni100) %= mod;
    Node now{RB, CB, 1, 1};
    if (now.x + now.dx < 1 || now.x + now.dx > N) now.dx *= -1;
    if (now.y + now.dy < 1 || now.y + now.dy > M) now.dy *= -1;
    while (1) {
      if (rem.count(now)) break;
      rem.insert(now);
      xu.push_back(now);
      now.x += now.dx;
      now.y += now.dy;
      if (now.x + now.dx < 1 || now.x + now.dx > N) now.dx *= -1;
      if (now.y + now.dy < 1 || now.y + now.dy > M) now.dy *= -1;
    }
    long long ans = 0, base = 1, k = 0;
    for (int i = 0; i < xu.size(); ++i)
      if (xu[i].x == RD || xu[i].y == CD) ++k;
    long long k100 = powMy(100, k);
    long long jqk =
        (k100 + mod - powMy(QQ, k)) % mod * powMy(k100, mod - 2) % mod;
    long long fjqk = powMy(jqk, mod - 2);
    long long fjqk2 = powMy(jqk * jqk % mod, mod - 2);
    long long qk = powMy(Q, k);
    for (int i = 0; i < xu.size(); ++i)
      if (xu[i].x == RD || xu[i].y == CD) {
        (ans += (P * base % mod) *
                ((i * fjqk % mod + xu.size() * qk % mod * fjqk2 % mod) % mod) %
                mod) %= mod;
        (base *= Q) %= mod;
      }
    printf("%lld\n", ans);
  }
  return 0;
}
