#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
long long mul(long long a, long long b) { return (a * b) % (1000000007); }
long long add(long long a, long long b) { return (a + b) % (1000000007); }
long long sub(long long a, long long b) {
  return ((a - b) % (1000000007) + (1000000007)) % (1000000007);
}
void upd(long long &a, long long b) {
  a = (a % (1000000007) + b % (1000000007)) % (1000000007);
}
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
long long a[(50010)];
int main() {
  int t = read();
  while (t--) {
    int n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    set<int> S[11];
    S[1].insert(a[1]);
    S[1].insert(0);
    for (int i = 2; i <= n; i++) {
      for (auto t : S[i - 1]) {
        long long a1 = t;
        S[i].insert(t + a[i]);
        S[i].insert(t);
      }
    }
    bool fl = ((S[n]).size()) != (1 << n);
    puts(fl ? "YES" : "NO");
  }
  return 0;
}
