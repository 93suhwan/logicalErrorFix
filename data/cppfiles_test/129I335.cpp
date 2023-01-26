#include <bits/stdc++.h>
using namespace std;
inline void intxt() {}
inline void read(int &x) {
  int f = 1;
  x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
inline void read(long long &x) {
  long long f = 1;
  x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
const long long mod = 998244353;
const int N = 4e5 + 5;
const int M = 1e6 + 5;
int n, m, k;
int a[N];
bool vis[N];
set<int> cup;
int main() {
  intxt();
  int casen;
  scanf("%d", &casen);
  for (int LP = 1; LP <= casen; ++LP) {
    cin >> n;
    cup.clear();
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      vis[i] = 0;
    }
    sort(a + 1, a + 1 + n);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] >= 1 && a[i] <= n && vis[a[i]] == 0) {
        vis[a[i]] = 1;
      } else {
        cup.insert(a[i]);
      }
    }
    for (int i = 1; i <= n; i++) {
      if (vis[i] == 0) {
        int tem = *cup.begin();
        cup.erase(tem);
        if (tem - i > i) {
          ans++;
        } else {
          ans = -1;
          break;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
