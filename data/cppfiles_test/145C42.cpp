#include <bits/stdc++.h>
const int N = 3e5 + 10;
const int M = 1e6;
using namespace std;
long long n, m, t, k;
struct node {
  long long x, y, z;
} a[N];
long long cmp1(node x, node y) { return x.x < y.x; }
map<long long, long long> Hang, Lie;
vector<node> hang[N], lie[N];
long long fa[N], minn[N];
long long find(long long x) {
  if (fa[x] == x)
    return x;
  else
    return fa[x] = find(fa[x]);
}
signed main() {
  cin >> t;
  while (t--) {
    cin >> n >> k;
    long long l = 0, h = 0;
    Lie.clear(), Hang.clear();
    for (long long i = 1; i <= n; i++) fa[i] = i;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i].x >> a[i].y >> a[i].z;
      if (!Lie[a[i].x]) Lie[a[i].x] = ++l;
      if (!Hang[a[i].y]) Hang[a[i].y] = ++h;
      minn[i] = a[i].z;
      hang[Hang[a[i].y]].push_back((node){a[i].x, a[i].z, i});
      lie[Lie[a[i].x]].push_back((node){a[i].y, a[i].z, i});
    }
    for (long long i = 1; i <= l; i++) {
      sort(lie[i].begin(), lie[i].end(), cmp1);
      for (long long j = 1; j < lie[i].size(); j++) {
        if (lie[i][j].x - lie[i][j - 1].x <= k) {
          long long x = find(lie[i][j].z);
          long long y = find(lie[i][j - 1].z);
          fa[x] = y;
          minn[y] = min(minn[y], minn[x]);
        }
      }
    }
    for (long long i = 1; i <= h; i++) {
      sort(hang[i].begin(), hang[i].end(), cmp1);
      for (long long j = 1; j < hang[i].size(); j++) {
        if (hang[i][j].x - hang[i][j - 1].x <= k) {
          long long x = find(hang[i][j].z);
          long long y = find(hang[i][j - 1].z);
          fa[x] = y;
          minn[y] = min(minn[y], minn[x]);
        }
      }
    }
    vector<long long> w;
    for (long long i = 1; i <= n; i++)
      if (find(i) == i) {
        w.push_back(minn[i]);
      }
    sort(w.begin(), w.end());
    reverse(w.begin(), w.end());
    long long ans = 0;
    for (long long i = 1; i < w.size(); i++) {
      if (w[i] <= ans)
        break;
      else
        ans++;
    }
    cout << ans << endl;
    for (long long i = 1; i <= l; i++) lie[i].clear();
    for (long long i = 1; i <= h; i++) hang[i].clear();
  }
  return 0;
}
