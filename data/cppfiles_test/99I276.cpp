#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
inline string rs() {
  std::string second;
  unsigned int uc;
  int c;
  while ((uc = (unsigned int)getchar()) <= 32u)
    ;
  if (uc < 256u) second.push_back((char)uc);
  while ((c = getchar()) > 32) second.push_back((char)c);
  return second;
}
const int INF = 1 << 29;
const int N = 10000001;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n >> b) & 1; }
inline void set_bit(int& n, int b) { n |= two(b); }
inline void unset_bit(int& n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) {
  int res = 0;
  while (n && ++res) n -= n & (-n);
  return res;
}
template <class T>
void chmax(T& a, const T& b) {
  a = max(a, b);
}
template <class T>
void chmin(T& a, const T& b) {
  a = min(a, b);
}
template <class C, typename T>
bool contains(C&& c, T e) {
  return find(begin(c), end(c), e) != end(c);
};
long long extgcd(long long a, long long b, long long& x, long long& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  } else {
    int g = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
  }
}
long long modpow(long long a, long long b) {
  long long res = 1;
  a %= 1000000007;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % 1000000007;
    a = a * a % 1000000007;
  }
  return res;
}
void solve() {
  int n;
  scanf("%d", &n);
  string second = rs();
  int p[n];
  int prev = -1, init = 0;
  for (int i = 0; i < n; i++) {
    if (second[i] == '2') {
      if (prev == -1) {
        prev = i;
        init = i;
      } else {
        p[prev] = i;
        prev = i;
      }
    }
  }
  p[prev] = init;
  if (count(second.begin(), second.end(), '2') == 1) {
    printf("NO\n");
    return;
  }
  printf("YES\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        printf("X");
      } else if (second[i] == '1' || second[j] == '1') {
        printf("=");
      } else {
        if (p[i] == j) {
          printf("+");
        } else if (p[j] == i) {
          printf("-");
        } else {
          printf("=");
        }
      }
    }
    printf("\n");
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  scanf("%d", &T);
  for (int test = 1; test <= T; test++) {
    solve();
  }
  return 0;
}
