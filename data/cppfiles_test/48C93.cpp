#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
struct node {
  int x, id;
  bool operator<(const node& y) const { return x < y.x; }
} a[maxn];
bool cmp(const node& x, const node& y) { return x.id < y.id; }
bool v[maxn];
int c[maxn];
int n;
void add(int x) {
  while (x <= n) {
    c[x]++;
    x += ((x) & (-(x)));
  }
}
int sum(int x) {
  int ans = 0;
  while (x >= 1) {
    ans += c[x];
    x -= ((x) & (-(x)));
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i].x;
      a[i].id = i;
      v[i] = 0;
      c[i] = 0;
    }
    bool flag = 0;
    for (int i = 1; i <= n; ++i) {
      if (v[a[i].x]) {
        flag = 1;
        break;
      }
      v[a[i].x] = 1;
    }
    if (flag) {
      cout << "YES" << endl;
    } else {
      int ans = 0;
      for (int i = 1; i <= n; ++i) {
        ans += sum(n) - sum(a[i].x);
        add(a[i].x);
      }
      cout << ((ans & 1) ? "NO" : "YES") << endl;
    }
  }
  return 0;
}
