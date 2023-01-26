#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
inline int read() {
  int x = 0;
  char s = getchar();
  while (s < '0' || s > '9') s = getchar();
  while (s <= '9' && s >= '0') {
    x = (x << 1) + (x << 3) + s - '0';
    s = getchar();
  }
  return x;
}
priority_queue<int, vector<int>, greater<int> > q[2];
bool vis[maxn];
bool eql(int a, int b) { return (!((a & 1) ^ (b & 1))); }
int rev[maxn];
long long ans;
int c[maxn];
void msort(int b, int e) {
  if (b == e) return;
  int mid = (b + e) / 2, i = b, j = mid + 1, k = b;
  msort(b, mid), msort(mid + 1, e);
  while (i <= mid && j <= e)
    if (rev[i] <= rev[j])
      c[k++] = rev[i++];
    else {
      c[k++] = rev[j++];
      ans = ans + mid - i + 1;
    }
  while (i <= mid) c[k++] = rev[i++];
  while (j <= e) c[k++] = rev[j++];
  for (int l = b; l <= e; l++) rev[l] = c[l];
}
int main() {
  int t = read();
  while (t--) {
    ans = 0;
    memset(vis, 0, sizeof(vis));
    memset(rev, 0, sizeof(rev));
    memset(c, 0, sizeof(c));
    while (q[0].size()) {
      q[0].pop();
    }
    while (q[1].size()) {
      q[1].pop();
    }
    memset(a, 0, sizeof(a));
    int ji = 0, ou = 0;
    int n = read();
    for (int i = 1; i <= n; i++) {
      a[i] = read();
      if (a[i] & 1) {
        ji++;
        q[0].push(i);
      } else {
        ou++;
        q[1].push(i);
      }
    }
    if (abs(ji - ou) > 1) {
      cout << -1 << endl;
      continue;
    }
    bool flag = 0;
    if (ji > ou)
      flag = 1;
    else if (ji < ou)
      flag = 0;
    else
      flag = a[1] & 1;
    for (int i = 1; i <= n; i++) {
      rev[q[flag ^ 1].top()] = i;
      flag ^= 1;
      q[flag].pop();
    }
    msort(1, n);
    cout << ans << endl;
  }
  return 0;
}
