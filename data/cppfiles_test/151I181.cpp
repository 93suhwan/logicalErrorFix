#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
inline long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
inline int qpow(int a, int n) {
  int ans = 1;
  while (n) {
    if (n & 1) {
      ans *= a;
    }
    a *= a;
    n >>= 1;
  }
  return ans;
}
inline long long _qpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
inline long long ksm(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
const int maxnum = 5e5 + 5;
class UF {
  int *father;
  int _size;
  int *cot;

 public:
  int count;
  UF() {}
  UF(int N) {
    father = new int[N + 1];
    cot = new int[N + 1];
    for (int i = 1; i <= N; i++) {
      father[i] = i;
      cot[i] = 1;
    }
    this->count = N;
    _size = N;
  }
  int findFather(int x) {
    int tmp = x;
    while (x != father[x]) {
      x = father[x];
    }
    while (tmp != father[tmp]) {
      int t = tmp;
      tmp = father[tmp];
      father[t] = x;
    }
    return x;
  }
  void Union(int a, int b) {
    int Fa = findFather(a);
    int Fb = findFather(b);
    if (Fa != Fb) {
      count--;
      father[Fa] = Fb;
      cot[Fb] += cot[Fa];
    }
  }
  bool connect(int a, int b) { return findFather(a) == findFather(b); }
  void init() {
    for (int i = 1; i <= _size; i++) {
      father[i] = i;
    }
  }
  int Count(int x) { return cot[findFather(x)]; }
};
struct que {
  int op, x, y;
};
vector<int> ans;
vector<que> v;
int f[maxnum];
int op, x, y, q;
void slove() {
  UF uf = UF(maxnum);
  cin >> q;
  while (q--) {
    cin >> op;
    if (op == 1) {
      cin >> x;
      v.push_back({1, x, 0});
    } else {
      cin >> x >> y;
      v.push_back({2, x, y});
    }
  }
  for (int i = 0; i < maxnum; i++) f[i] = i;
  reverse(v.begin(), v.end());
  for (auto q : v) {
    op = q.op, x = q.x, y = q.y;
    if (op == 1)
      ans.push_back(uf.findFather(x));
    else
      uf.Union(x, y);
  }
  reverse(ans.begin(), ans.end());
  for (int x : ans) cout << x << " ";
  cout << "\n";
}
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  ;
  slove();
  return 0;
}
