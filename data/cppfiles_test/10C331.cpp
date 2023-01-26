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
const int N = 4e5;
int b[N];
void run_case() {
  int n = read(), k = read();
  map<int, int> m;
  map<int, deque<int> > g;
  for (int i = (1); i <= (n); i++) {
    b[i] = read();
    m[b[i]]++;
  }
  int f = 0;
  map<int, int>::iterator it;
  for (it = m.begin(); it != m.end(); it++) {
    if (it->second == k) {
      for (int j = 1; j <= it->second; j++) {
        g[it->first].push_back((j % k == 0) ? k : j % k);
      }
    } else if (it->second > k) {
      for (int j = 1; j <= it->second; j++) {
        if (j <= k)
          g[it->first].push_back((j % k == 0) ? k : j % k);
        else
          g[it->first].push_back(0);
      }
    } else {
      for (int j = 1; j <= it->second; j++) {
        f++;
        g[it->first].push_back((f % k == 0) ? k : f % k);
      }
    }
  }
  int ff, tt;
  map<int, int>::reverse_iterator iter;
  if (f % k) {
    for (iter = m.rbegin(); iter != m.rend(); iter++) {
      if (iter->second < k) {
        ff = f;
        for (int j = 1; j <= iter->second; j++) {
          f--;
          g[iter->first].pop_back();
          if (f % k == 0) {
            tt = iter->first;
            goto end;
          }
        }
        for (int j = 1; j <= iter->second; j++) {
          g[iter->first].push_back(0);
        }
      }
    }
  end:
    for (int i = 1; i <= ff - f; i++) g[tt].push_back(0);
  }
  for (int i = 1; i <= n; i++) {
    if (i != 1) printf(" ");
    printf("%d", g[b[i]].front());
    g[b[i]].pop_front();
  }
  puts("");
}
int main() {
  int _ = read();
  while (_--) {
    run_case();
  }
}
