#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
const int Days[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
inline int read() {
  int ans = 0;
  bool f = 1;
  char ch = getchar();
  while (!isdigit(ch)) f ^= ch == '-', ch = getchar();
  while (isdigit(ch)) ans = ((ans << 2) + ans << 1) + (ch ^ 48), ch = getchar();
  return f ? ans : -ans;
}
int n, m, k;
long long pw[1000010];
int preop, curop;
map<pair<int, int>, int> op;
int row[1000010][2], col[1000010][2];
int r0, r1, c0, c1;
int cnt[2];
void calc1(int x, int y) {
  r0 -= ((row[x][0] == 0) != (row[x][1] == 0));
  r1 -= ((row[x][0] > 0) && (row[x][1] > 0));
  row[x][(y & 1) ^ preop]--;
  r0 += ((row[x][0] == 0) != (row[x][1] == 0));
  r1 += ((row[x][0] > 0) && (row[x][1] > 0));
  c0 -= ((col[y][0] == 0) != (col[y][1] == 0));
  c1 -= ((col[y][0] > 0) && (col[y][1] > 0));
  col[y][(x & 1) ^ preop]--;
  c0 += ((col[y][0] == 0) != (col[y][1] == 0));
  c1 += ((col[y][0] > 0) && (col[y][1] > 0));
  cnt[preop ^ ((x + y) & 1)]--;
}
void calc2(int x, int y) {
  r0 -= ((row[x][0] == 0) != (row[x][1] == 0));
  r1 -= ((row[x][0] > 0) && (row[x][1] > 0));
  row[x][(y & 1) ^ curop]++;
  r0 += ((row[x][0] == 0) != (row[x][1] == 0));
  r1 += ((row[x][0] > 0) && (row[x][1] > 0));
  c0 -= ((col[y][0] == 0) != (col[y][1] == 0));
  c1 -= ((col[y][0] > 0) && (col[y][1] > 0));
  col[y][(x & 1) ^ curop]++;
  c0 += ((col[y][0] == 0) != (col[y][1] == 0));
  c1 += ((col[y][0] > 0) && (col[y][1] > 0));
  cnt[curop ^ ((x + y) & 1)]++;
}
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  pw[0] = 1ll;
  for (int i = 1; i <= 1000010; i++)
    pw[i] = (long long)(pw[i - 1] * 2ll) % 998244353;
  cin >> n >> m >> k;
  while (k--) {
    int x, y;
    cin >> x >> y;
    cin >> curop;
    pair<int, int> pos = make_pair(x, y);
    if (op.count(pos) == 0) op[pos] = -1;
    preop = op[pos];
    if (preop != curop) {
      if (preop != -1) calc1(x, y);
      if (curop != -1) calc2(x, y);
    }
    cout << pw[n - r0] << ' ' << r1 << ' ' << pw[m - c0] << ' ' << c1 << endl;
    int ans = pw[n - r0] * (r1 == 0) + pw[m - c0] * (c1 == 0) - (cnt[0] == 0) -
              (cnt[1] == 0);
    cout << ans << endl;
    op[pos] = curop;
  }
  return 0;
}
