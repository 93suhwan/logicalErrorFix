#include <bits/stdc++.h>
using namespace std;
template <class T>
using vc = vector<T>;
template <class T>
using vvc = vc<vc<T>>;
template <class T>
void mkuni(vector<T> &v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}
template <class T>
void print(T x, int suc = 1) {
  cout << x;
  if (suc == 1)
    cout << '\n';
  else
    cout << ' ';
}
template <class T>
void print(const vector<T> &v, int suc = 1) {
  for (int i = 0; i < v.size(); i++)
    print(v[i], i == (int)(v.size()) - 1 ? suc : 2);
}
int x[20000];
char s[20][10004];
struct node {
  int x, id;
  bool operator<(const node &b) const { return x < b.x; }
} a[20000];
int anss[20000];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    for (int i = 1; i <= n; ++i) {
      cin >> (s[i] + 1);
    }
    int ans = 0;
    for (int i = 0; i < 1 << n; ++i) {
      int res = 0;
      for (int j = 1; j <= m; ++j) a[j].x = 0, a[j].id = j;
      for (int j = 0; j < n; ++j) {
        if (!(i >> j & 1)) {
          res += x[j + 1];
          for (int k = 1; k <= m; ++k) {
            if (s[j + 1][k] == '1') a[k].x -= 1;
          }
        } else {
          res -= x[j + 1];
          for (int k = 1; k <= m; ++k) {
            if (s[j + 1][k] == '1') a[k].x += 1;
          }
        }
      }
      sort(a + 1, a + 1 + m);
      for (int j = 1; j <= m; ++j) {
        res += j * a[j].x;
      }
      if (ans < res) {
        ans = res;
        for (int i = 1; i <= m; ++i) {
          anss[a[i].id] = i;
        }
      }
    }
    for (int i = 1; i <= m; ++i) cout << anss[i] << " ";
    cout << endl;
  }
}
