#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
void input() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
}
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  return x * f;
}
const int N = 1e6 + 10, M = N * 2, inf = 1e8;
int t, n;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    if (n == 1) {
      cout << 'a' << '\n';
      continue;
    }
    int k = 0;
    k = (n - 2) / 2;
    for (int i = 1; i <= k; i++) cout << 'a';
    if (n % 2 == 1)
      cout << "bc";
    else
      cout << 'b';
    for (int i = 1; i <= k + 1; i++) cout << 'a';
    cout << '\n';
  }
  return 0;
}
