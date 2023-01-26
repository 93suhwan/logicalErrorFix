#include <bits/stdc++.h>
using namespace std;
void err() { cout << "\033[39;0m" << endl; }
template <class T, class... Ts>
void err(const T& arg, const Ts&... args) {
  cout << arg << " ";
  err(args...);
}
const int N = 200010;
int T, n, m, k, v[N];
void solve() {
  if (n % m == 0) {
    for (int p = int(1); p <= int(k); p++) {
      for (int j = int(1); j <= int(m); j++) {
        printf("%d ", n / m);
        for (int i = (j - 1) * (n / m) + 1; i <= j * (n / m); i++) {
          printf("%d ", i);
        }
        puts("");
      }
    }
    return;
  }
  int a = n % m, b = m - a;
  int up = n / m + 1;
  int down = n / m;
  int i = 1, num = a * up;
  for (int p = int(1); p <= int(k); p++) {
    for (int l = int(1); l <= int(n); l++) v[l] = 0;
    for (int j = int(1); j <= int(a); j++) {
      printf("%d ", up);
      for (int l = 1; l <= up; l++) {
        printf("%d ", i);
        v[i] = 1;
        i = i % n + 1;
      }
      puts("");
    }
    int cnt = 0;
    for (int l = int(1); l <= int(n); l++) {
      if (v[l] == 0) {
        if (cnt % down == 0) {
          if (cnt > 0) puts("");
          printf("%d ", down);
        }
        printf("%d ", l);
        cnt++;
      }
    }
    puts("");
  }
}
int main() {
  cin >> T;
  while (T--) {
    scanf("%d%d%d", &n, &m, &k);
    solve();
  }
}
