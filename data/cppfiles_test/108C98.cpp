#include <bits/stdc++.h>
using namespace std;
long long T, n;
const long long N = 2e5 + 10;
long long ans[N];
struct node {
  long long id, x, y;
} a[N];
bool cmp(node a, node b) { return a.x > b.x; }
bool cmp2(node a, node b) { return a.y < b.y; }
signed main() {
  cin >> T;
  while (T--) {
    cin >> n;
    for (long long i = 1; i <= n; ++i) {
      long long x;
      cin >> x;
      a[i].id = i, a[i].x = x;
    }
    for (long long i = 1; i <= n; ++i) {
      long long x;
      cin >> x;
      a[i].y = x;
    }
    sort(a + 1, a + n + 1, cmp);
    ans[a[1].id] = 1;
    long long mn = a[1].y, newmn = 1e9 + 1;
    queue<long long> q;
    for (long long i = 2; i <= n; ++i) {
      if (a[i].y > mn) {
        while (q.size()) {
          ans[q.front()] = 1;
          q.pop();
        }
        ans[a[i].id] = 1;
        mn = min(mn, newmn);
        continue;
      } else {
        newmn = min(newmn, a[i].y);
        q.push(a[i].id);
      }
    }
    for (long long i = 1; i <= n; ++i) cout << ans[i], ans[i] = 0;
    cout << "\n";
  }
}
