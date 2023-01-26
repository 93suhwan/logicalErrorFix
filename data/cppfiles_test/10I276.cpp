#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <typename T>
T lcm(T a, T b) {
  return a * b / gcd(a, b);
}
const int mod = 998244353;
const int MOD = 1e9 + 7;
inline long long read() {
  long long ans = 0;
  char ch = getchar(), las = ' ';
  while (!isdigit(ch)) las = ch, ch = getchar();
  while (isdigit(ch)) ans = (ans << 1) + (ans << 3) + ch - '0', ch = getchar();
  if (las == '-') ans = -ans;
  return ans;
}
inline void write(long long x) {
  if (x < 0) x = -x, putchar('-');
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
void run_case() {
  int n = read(), k = read(), a;
  map<int, int> m;
  deque<int> q;
  int j = 0;
  for (int i = (1); i <= (n); i++) {
    a = read();
    m[a]++;
    if (m[a] <= k) {
      j++;
      q.push_back((j % k == 0) ? k : j % k);
    } else
      q.push_back(0);
  }
  if (j % k) {
    int ct = 0, cct = 0;
    for (int i = 1;; i++) {
      if (q.back() != 0) ct++;
      q.pop_back();
      cct++;
      if (ct == j % k) break;
    }
    for (int i = 1; i <= cct; i++) q.push_back(0);
  }
  printf("%d", q.front());
  q.pop_front();
  while (q.size()) {
    printf(" %d", q.front());
    q.pop_front();
  }
  puts("");
}
int main() {
  int _ = read();
  while (_--) {
    run_case();
  }
}
