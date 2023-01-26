#include <bits/stdc++.h>
template <class T>
long long sqr(T a) {
  return 1LL * a * a;
}
template <class T>
void compress(T &a) {
  sort(a.begin(), a.end());
  a.resize(unique(all(a)) - a.begin());
}
using namespace std;
const int N = 2e5 + 10;
const int M = log2(N) + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const long long INFI = 1e18;
const double long pi = acos(-1.0);
const double long eps = 1e-9;
const double long e = exp(1.0);
struct Data {
  int x, y, pos;
};
Data a[N];
bool check[N];
pair<int, int> b[N];
bool cmp_x(Data A, Data B) { return (A.x == B.x) ? (A.y < B.y) : (A.x < B.x); }
bool cmp_y(Data A, Data B) { return (A.y == B.y) ? (A.x < B.x) : (A.y < B.y); }
int find_set(int x) {
  if (b[x].first != x) {
    b[x].first = find_set(b[x].first);
  }
  return b[x].first;
}
void union_set(int u, int v) {
  u = find_set(u);
  v = find_set(v);
  if (u != v) {
    b[v].first = u;
    b[u].second = min(b[u].second, b[v].second);
    b[v].second = min(b[u].second, b[v].second);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i].x >> a[i].y;
      b[i].first = i;
      cin >> b[i].second;
      a[i].pos = i;
    }
    sort(a + 1, a + n + 1, cmp_x);
    for (int i = 1; i < n; i++) {
      if (a[i].x == a[i + 1].x && a[i + 1].y - a[i].y <= k) {
        union_set(a[i].pos, a[i + 1].pos);
      }
    }
    sort(a + 1, a + n + 1, cmp_y);
    for (int i = 1; i < n; i++) {
      if (a[i].y == a[i + 1].y && a[i + 1].x - a[i].x <= k) {
        union_set(a[i].pos, a[i + 1].pos);
      }
    }
    int res = n - 1;
    int l = 0;
    int r = n - 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      for (int i = 1; i <= n; i++) {
        check[i] = 0;
      }
      int cnt = 0;
      for (int i = 1; i <= n; i++) {
        int x = find_set(b[i].first);
        if (!check[x]) {
          check[x] = 1;
          if (b[x].second > mid) {
            cnt++;
          }
        }
      }
      if (cnt <= mid + 1) {
        res = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    cout << res << "\n";
  }
  return 0;
}
