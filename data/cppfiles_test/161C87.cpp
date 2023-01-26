#include <bits/stdc++.h>
using namespace std;
struct segment {
  int l, r;
  bool ok;
} a[1005];
struct node {
  int x, i;
} cnt[1005];
bool operator<(segment a, segment b) { return a.r - a.l > b.r - b.l; }
bool operator<(node a, node b) { return a.x < b.x; }
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
      cnt[i].i = i;
      cnt[i].x = 0;
    }
    for (int i = 1; i <= N; i++) {
      cin >> a[i].l >> a[i].r;
      a[i].ok = false;
      for (int j = a[i].l; j <= a[i].r; j++) cnt[j].x++;
    }
    sort(a + 1, a + 1 + N);
    sort(cnt + 1, cnt + 1 + N);
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        if (a[j].l <= cnt[i].i && a[j].r >= cnt[i].i && !a[j].ok) {
          cout << a[j].l << " " << a[j].r << " " << cnt[i].i << endl;
          a[j].ok = true;
          break;
        }
      }
    }
    cout << endl;
  }
  return 0;
}
