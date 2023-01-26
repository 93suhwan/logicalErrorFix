#include <bits/stdc++.h>
using namespace std;
inline long long rd() {
  long long x = 0;
  char c = getchar();
  bool f = 0;
  while (!isdigit(c)) {
    if (c == '-') f = 1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return f ? -x : x;
}
char ss[1 << 24], *A = ss, *B = ss;
inline char gc() {
  return A == B && (B = (A = ss) + fread(ss, 1, 1 << 24, stdin), A == B) ? EOF
                                                                         : *A++;
}
template <class T>
void maxa(T &x, T y) {
  if (y > x) x = y;
}
template <class T>
void mina(T &x, T y) {
  if (y < x) x = y;
}
template <class T>
void read(T &x) {
  int f = 1, c;
  while (c = gc(), c < 48 || c > 57)
    if (c == '-') f = -1;
  x = (c ^ 48);
  while (c = gc(), c > 47 && c < 58) x = x * 10 + (c ^ 48);
  x *= f;
}
const int mo = 1e9 + 7;
long long fsp(int x, int y) {
  if (y == 1) return x;
  long long ans = fsp(x, y / 2);
  ans = ans * ans % mo;
  if (y % 2 == 1) ans = ans * x % mo;
  return ans;
}
struct cp {
  long long x, y;
  cp operator+(cp B) { return (cp){x + B.x, y + B.y}; }
  cp operator-(cp B) { return (cp){x - B.x, y - B.y}; }
  long long operator*(cp B) { return x * B.y - y * B.x; }
  int half() { return y < 0 || (y == 0 && x < 0); }
};
struct re {
  int a, b, c;
};
const int N = 500;
char s[N][N];
int sum[N][N];
int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> (s[i] + 1);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) sum[i][j] = sum[i - 1][j] + s[i][j] - '0';
    int ans = 1e9;
    for (int i = 1; i <= n; i++)
      for (int j = i + 4; j <= n; j++) {
        int now = 0;
        for (int k = 1; k <= m; k++) {
          now = j - 1 - i - (sum[j - 1][k] - sum[i][k]);
          for (int t = k + 1; t <= m; t++) {
            if (t != k + 1)
              now += (2 - (s[i][t - 1] - '0' + s[j][t - 1] - '0'));
            if (t - k >= 3) {
              ans = min(ans, now + j - 1 - i - (sum[j - 1][t] - sum[i][t]));
            }
            now += (sum[j - 1][t] - sum[i][t]);
            if (now > 18) break;
          }
        }
      }
    cout << ans << endl;
  }
  return 0;
}
