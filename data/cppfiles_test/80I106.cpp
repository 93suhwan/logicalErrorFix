#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
const long long mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1.0);
inline long long read() {
  long long f = 1;
  long long x = 0;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
  return x * f;
}
struct node {
  long long sum;
  int id;
  bool operator<(const node &x) const { return sum > x.sum; }
};
long long a[maxn];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (long long i = 0; i <= n - 1; i++) {
      a[i + 1] = s[i] - '0';
    }
    int pos = n / 2 + 1;
    bool flag = 0;
    while (pos <= n) {
      if (a[pos] == 0) {
        flag = 1;
        break;
      }
      pos++;
    }
    if (flag == 1) {
      cout << 1 << " " << pos << " " << 1 << " " << pos - 1 << endl;
      continue;
    }
    int l = 1;
    int r = l + 1;
    int cnt = 0;
    while (l <= n && r <= n) {
      cnt = 0;
      int flag = -1;
      if (a[l] == 1)
        flag = 1, cnt++;
      else
        flag = 0;
      while (r - l + 1 <= n / 2) {
        if (flag == 1) cnt++;
        if (flag == 1 && a[r] == 0) {
          flag = -1;
          break;
        }
        if (flag == 0 && a[r] == 1) {
          cnt++;
          flag = 1;
        }
        r++;
      }
      r--;
      if (flag != -1)
        break;
      else {
        l++;
        r = l + 1;
      }
    }
    if (cnt == 0) cnt++;
    cout << l << " " << r + cnt << " " << l << " " << r << endl;
  }
  return 0;
}
