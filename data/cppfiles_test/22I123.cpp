#include <bits/stdc++.h>
using namespace std;
struct Point {
  int x, y;
} a[200010];
int n, m, BIGans = 0;
int vis[200010];
int BSIZE = 500;
int val[400010];
int out[510][510];
void ins(int x, int tm) {}
void del(int x, int tm) {}
int getans(int tm) {
  int res = 0;
  for (int i = 1; i <= BSIZE; ++i) {
    res += out[i][tm % i];
  }
  return res;
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d %d", &a[i].x, &a[i].y);
  for (int TIME = 1; TIME <= m; TIME++) {
    int op, k;
    scanf("%d %d", &op, &k);
    BIGans += val[TIME];
    if (op == 1) {
      vis[k] = TIME;
      int MOD = a[k].x + a[k].y;
      if (MOD <= BSIZE) {
        int NOW = TIME % MOD;
        for (int i = 1; i <= a[k].y; i++)
          out[MOD][(a[k].x + NOW + i - 1) % MOD]++;
      } else {
        int tmp = vis[k];
        while (tmp <= m) {
          tmp += a[k].x;
          if (tmp <= m)
            val[tmp]++;
          else
            break;
          tmp += a[k].y;
          if (tmp <= m)
            val[tmp]--;
          else
            break;
        }
      }
    } else {
      int MOD = a[k].x + a[k].y;
      if (MOD <= BSIZE) {
        int NOW = vis[k] % MOD;
        for (int i = 1; i <= a[k].y; i++) {
          out[MOD][(NOW + a[k].x + i - 1) % MOD]--;
        }
      } else {
        int tmp = vis[k];
        while (tmp <= m) {
          tmp += a[k].x;
          if (tmp <= TIME) BIGans--;
          if (tmp <= m) val[tmp + a[k].x]--;
          tmp += a[k].y;
          if (tmp <= TIME) BIGans++;
          if (tmp <= m) val[tmp + a[k].x + a[k].y]++;
        }
      }
    }
    int SMALLans = 0;
    for (int i = 1; i <= BSIZE; i++) {
      SMALLans += out[i][TIME % i];
    }
    printf("%d\n", BIGans + SMALLans);
  }
}
