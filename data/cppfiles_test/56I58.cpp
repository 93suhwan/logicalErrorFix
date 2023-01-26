#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
//#include <queue>
//#include <stack>
//#include <cmath>
//#include <numeric>
//#include <cstring>
#include <cassert>

using namespace std;

#ifdef LOCAL_DEBUG
#include <local_debug.h>
#define DEBUG(...) DBG2::cprint(#__VA_ARGS__, __LINE__, __VA_ARGS__)
#else
#define DEBUG(...)
#endif

#define SZ(a) int((a).size())
#define REP(i,n) for(int i=0,_n=(n);i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)

typedef long long llong;
typedef vector<int> VI;
typedef vector<VI> VVI;

template<int MOD>
class ModInt {
   unsigned int x;

public:
   constexpr ModInt() : x(0) { }
   constexpr ModInt(int _x) { if ((x = _x % MOD) < 0) x += MOD; }
   constexpr ModInt(long long _x) { if ((x = _x % MOD) < 0) x += MOD; }

   explicit operator int() const { return x; }

   bool constexpr operator==(ModInt b) const { return x == b.x; }
   bool constexpr operator!=(ModInt b) const { return x != b.x; }

   ModInt operator+() const { return *this; }
   ModInt operator-() const { return ModInt(x ? MOD - x : 0); }

   ModInt constexpr& operator+=(ModInt r) {
      if ((x += r.x) >= MOD) x -= MOD;
      return *this;
   }
   ModInt constexpr& operator-=(ModInt r) {
      if ((x += MOD - r.x) >= MOD) x -= MOD;
      return *this;
   }
   ModInt constexpr& operator*=(ModInt r) {
      x = (x * static_cast<long long>(r.x)) % MOD;
      return *this;
   }
   ModInt inv() const {
      int a = x, b = MOD, ax = 1, bx = 0;
      while (b) {
         int q = a/b, t = a%b;
          a = b; b = t;
          t = ax - bx*q;
          ax = bx; bx = t;
      }
      assert(a == 1);
      if (ax < 0) ax += MOD;
      return ax;
   }
   ModInt constexpr& operator/=(ModInt r) {
      return *this *= r.inv();
   }
   ModInt pow(long long n) const {
      assert(0 <= n);
      ModInt ret = 1, a = *this;
      while (n) {
         if (n & 1)
            ret *= a;
         a *= a;
         n >>= 1;
      }
      return ret;
   }

   friend ModInt operator+(ModInt l, ModInt r) { return l += r; }
   friend ModInt operator-(ModInt l, ModInt r) { return l -= r; }
   friend ModInt operator*(ModInt l, ModInt r) { return l *= r; }
   friend ModInt operator/(ModInt l, ModInt r) { return l /= r; }
   ModInt operator^(long long n) const {
      return pow(n);
   }

   friend std::ostream& operator<<(std::ostream& os, ModInt m) {
      return os << m.x;
   }
   friend std::istream& operator>>(std::istream& is, ModInt m) {
      return is >> m.x;
   }
};

using mint = ModInt<1000000007>;


const string colors = "WGRBOY";

int index(char c) {
   return colors.find(c);
}

bool compatible(int c1, int c2) {
   if (c1 == c2) return false;
   switch (colors[c1]) {
      case 'W': return colors[c2] != 'Y';
      case 'G': return colors[c2] != 'B';
      case 'R': return colors[c2] != 'O';
      case 'B': return colors[c2] != 'G';
      case 'O': return colors[c2] != 'R';
      case 'Y': return colors[c2] != 'W';
   }
   assert(false);
}

mint DP[61][6];

map<int, char> special;
set<int> special_subtree;

map< pair<int, char>, mint > memo;
mint go(int node, int k, int cid) {
   if (memo.count({node, colors[cid]}))
      return memo[{node, colors[cid]}];

   if (k == 0) {
      if (special.count(node))
         return special[node] == colors[cid] ? 1 : 0;
      else
         return 1;
   }

   mint& res = memo[{node, colors[cid]}];

   if (!special_subtree.count(node)) {
      res = DP[k][cid];
      return res;
   }

   if (special.count(node)) {
      if (special[node] != colors[cid]) {
         res = 0;
         return res;
      }
   }

   REP(cl, 6) {
      if (!compatible(cid, cl)) continue;
      mint curL = go(node * 2, k-1, cl);
      REP(cR, 6) {
         if (!compatible(cid, cR)) continue;
         mint curR = go(node * 2 + 1, k-1, cR);
         res += curL * curR;
      }
   }
   
   return res;
}

int main(int argc, char* argv[]) {
   ios_base::sync_with_stdio(false); 
   cin.tie(nullptr);

   int K;
   cin >> K;

   int N;
   cin >> N;

   REP(i, N) {
      int v;
      string color;
      cin >> v >> color;
      special[v] = toupper(color[0]);

      for (int x = v; x >= 1; x /= 2)
         special_subtree.insert(x);
   }

   REP(c, 6)
      DP[0][c] = 1;

   FOR(k, 1, K-1) {
      REP(c, 6) {
         REP(cl, 6) {
            if (!compatible(c, cl)) continue;
            REP(cr, 6) {
               if (!compatible(c, cr)) continue;
               DP[k][c] += DP[k-1][cl] * DP[k-1][cr];
            }
         }
      }
   }

   mint res = 0;
   REP(c, 6) {
      res += go(1, K-1, c);
   }

   cout << res << '\n';

   return 0;
}
