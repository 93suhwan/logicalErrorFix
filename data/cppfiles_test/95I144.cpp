#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
inline int readint() {
  int ans = 0;
  bool sign = true;
  char c;
  while (!isdigit(c = getchar()))
    if (c == '-') sign = false;
  while (isdigit(c)) {
    ans = (ans << 3) + (ans << 1) + (c ^ 48);
    c = getchar();
  }
  return ans * (sign ? 1 : -1);
}
inline void readint(int &x) { x = readint(); }
template <typename... Ts>
inline void readint(int &x, Ts &...y) {
  x = readint();
  readint(y...);
}
int quickPow(int a, int b, int mod = 1e9 + 7) {
  int res = 1;
  while (b) {
    if (b & 1) res = (long long)res * a % mod;
    a = (long long)a * a % mod;
    b >>= 1;
  }
  return res % mod;
}
const int INF = 0x3f3f3f3f;
const long long LLINF = ((long long)INF << 32) | INF;
const int mod = 1e9 + 7;
pair<int, int> f(int x) {
  string n = to_string(x);
  int n1 = quickPow(10, n.length() - 1, INT_MAX);
  if (n.length() == 1) {
    if (x == 0)
      return {0, 0};
    else
      return {1, x - 1};
  }
  if (n[0] == '1' &&
      all_of(n.begin() + 1, n.end(), [](char c) { return c == '0'; })) {
    n1 = quickPow(10, n.length() - 2, INT_MAX);
    return {n1, x - n1};
  }
  return {n1, x - n1};
}
int main() {
  ;
  int ___;
  cin >> ___;
  for (int tc = 1; tc <= ___; ++tc) {
    int s, n;
    readint(s, n);
    priority_queue<int> pq;
    pq.push(s);
    while (n--) {
      if (n == 0) {
        break;
      } else {
        int x = pq.top();
        pq.pop();
        auto [n1, n2] = f(x);
        pq.push(n1);
        pq.push(n2);
      }
    }
    while (!pq.empty()) {
      cout << pq.top() << ' ';
      pq.pop();
    }
    cout << '\n';
  }
  return 0;
}
