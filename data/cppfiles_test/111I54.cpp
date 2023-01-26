#include<bits/stdc++.h>
#define lson (i<<1)
#define rson (i<<1|1)
#define repeat(i, s, n) for(int i = s; i <= n; ++i)
#define foreach(i,items) for(auto &i: items)
#define downrep(i, n, s) for(int i = n; i >= s; --i)
#define lowbit(x) (x&-x)
#define bzero(x) memset(x, 0, sizeof(x))
#define bzeron(x, n) memset(x, 0, (n) * sizeof *x)
#define gcd(a,b) __gcd(a,b)
#define brkline puts("")
#define spaceout putchar(' ')
#define all(a) a.begin(),a.end()
#define pb	push_back

// using i128=__int128; //这个是非标准，不一定支持
using i64 = long long;
using i32 = int;
const int INF = 0x3f3f3f3f;
const double tol = 1e-8;
const int P = 998244353;

int pop_count(i64 x) {
  return __builtin_popcountll(x);
}
int pop_count(int x) {
  return __builtin_popcount(x);
}

template<typename S, typename T>
bool check_and_save_min_in_lhs(S& lhs, const T& rhs) {
  return lhs < rhs ? 1 : lhs = rhs, 0;
}

template<typename S, typename T>
bool check_and_save_max_in_lhs(S& lhs, const T& rhs) {
  return lhs > rhs ? 1 : lhs = rhs, 0;
}
template<typename T>
T min_all(T ele) {
  return ele;
}

template<typename T, typename ...Args>
T min_all(T fst_el, Args ...others) {
  return min_all(fst_el, mins(others...));
}

template<typename T>
T maxs(T ele) {
  return ele;
}

template<typename T, typename ...Args>
T maxs(T fst_el, Args ...others) {
  return max(fst_el, maxs(others...));
}

template<typename T>
void read_int(T& num) {
  bool positive = true;
  char ch; num = 0;
  while (isspace(ch = getchar()));
  if (ch == '-')	positive = false;
  else num = ch - '0';
  while ((ch = getchar()) >= '0' && ch <= '9')
    num = num * 10 + ch - '0';
  if (!positive) num = -num;
}

void read_ints() {};
template <typename T, typename ...Args>
void read_ints(T& fst_el, Args&... others) { read_int(fst_el);read_ints(others...); }

template<typename T>
void int_out(T num) {
  if (num < 0) {
    putchar('-');
    num = -num;
  }
  if (num > 9)
    int_out(num / 10);
  putchar(num % 10 + '0');
}

void int_outs() { brkline; }
template<typename T, typename ...Args>
void int_outs(T fst_ele, Args ...others) {
  int_out(fst_ele);
  spaceout;
  int_outs(others...);
}
template<class T>
T qpow(T n, int k) {
  T res = 1;
  for (; k; k >>= 1, n *= n) {
    if (k & 1) {
      res *= n;
    }
  }
  return res;
}
template<int P = P>
struct ModInt {
  int x;
  ModInt(int x = 0) : x(mod(x)) {}
  int val() const {
    return x;
  }
  // assume -P <= x < 2P
  int mod(int x) {
    if (x < 0) {
      x += P;
    }
    if (x >= P) {
      x -= P;
    }
    return x;
  }
  void print(char seperator = ' ') {
    printf("%d%c", x, seperator);
  }
  void println() {
    printf("%d\n", x);
  }
  ModInt operator-() const {
    return ModInt(P - x);
  }
  ModInt<P> inv() const {
    assert(x != 0);
    return qpow(*this, P - 2);
  }
  ModInt<P>& operator*=(const ModInt& rhs) {
    x = i64(x) * rhs.x % P;
    return *this;
  }
  ModInt& operator+=(const ModInt& rhs) {
    x = mod(x + rhs.x);
    return *this;
  }
  ModInt& operator-=(const ModInt& rhs) {
    x = mod(x - rhs.x);
    return *this;
  }
  ModInt& operator/=(const ModInt& rhs) {
    return *this *= rhs.inv();
  }
  friend ModInt operator*(const ModInt& lhs, const ModInt& rhs) {
    ModInt res = lhs;
    res *= rhs;
    return res;
  }
  friend ModInt operator+(const ModInt& lhs, const ModInt& rhs) {
    ModInt res = lhs;
    res += rhs;
    return res;
  }
  friend ModInt operator-(const ModInt& lhs, const ModInt& rhs) {
    ModInt res = lhs;
    res -= rhs;
    return res;
  }
  friend ModInt operator/(const ModInt& lhs, const ModInt& rhs) {
    ModInt res = lhs;
    res /= rhs;
    return res;
  }
};
const int N = 2002, K = 51;

int low[N], up[N];
ModInt<P> fac[N], invfac[N], sum[N], d[2][K * 2][N];

int main() {
  int n, k;
  read_ints(n, k);
  repeat(i, 1, n) {
    int b;
    read_int(b);
    low[i] = std::max(b - k, 0);
    up[i] = std::min(b + k, i);
  }

  fac[0] = 1;
  repeat(i, 1, n) fac[i] = fac[i - 1] * i;
  invfac[n] = fac[n].inv();
  downrep(i, n, 1) invfac[i - 1] = invfac[i] * i;

  int cur = 0;
  bzero(d);
  d[0][0][0] = 1;
  repeat(i, 1, n) {
    cur ^= 1;
    // 滚动数组
    ModInt<P>(*dp1)[N] = d[cur], (*dp0)[N] = d[cur ^ 1];
    bzero(dp1);
    bzero(sum);

    int prev_mex = low[i - 1] - 1;
    repeat(mex, low[i], up[i]) {
      // 先求sum
      while (prev_mex < up[i - 1] && prev_mex < mex - 1) {
        ++prev_mex;
        repeat(big, 0, i - 1) {
          sum[prev_mex + big] += fac[big] * dp0[prev_mex - low[i - 1]][big];
        }
      }
      //dp  
      repeat(big, 0, i) {
        int x = mex - low[i], px = mex - low[i - 1];

        dp1[x][big] = invfac[big] * sum[mex + big - 1];
        if (0 <= px && mex <= up[i - 1]) {
          if (big) dp1[x][big] += dp0[px][big - 1];
          dp1[x][big] += dp0[px][big] * (mex + big);
        }
      }
    }
  }

  ModInt ans(0);
  repeat(mex, low[n], up[n]) {
    repeat(big, 0, n - mex) {
      ans += fac[n - mex] * invfac[n - mex - big] * d[cur][mex - low[n]][big];
    }
  }

  ans.println();

  return 0;
}