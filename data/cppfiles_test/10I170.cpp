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
  queue<int> q;
  for (int i = (1); i <= (n); i++) {
    a = read();
    m[a]++;
    if (m[a] <= k)
      q.push(m[a]);
    else
      q.push(0);
  }
  printf("%d", q.front());
  q.pop();
  while (q.size()) {
    printf(" %d", q.front());
    q.pop();
  }
  puts("");
}
int main() {
  int _ = read();
  while (_--) {
    run_case();
  }
}
