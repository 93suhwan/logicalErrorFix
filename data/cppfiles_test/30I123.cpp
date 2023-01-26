#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const int N = 2e5 + 5;
int n, m, t;
string a;
char res[N];
long long b, c;
bool vis[30];
int cnt[30];
int _gcd(int a, int b) { return b > 0 ? _gcd(b, a % b) : a; }
long long power(long long n, long long x) {
  long long res = 1;
  long long q = n;
  while (x) {
    if (x & 1) res = (res * q);
    q = q * q;
    x /= 2;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  long long sum1 = 0, sum2 = 0;
  while (t--) {
    sum1 = sum2 = 0;
    cin >> n;
    cin >> a;
    a = ' ' + a;
    long long ans = inf;
    for (int i = 0; i <= 29; i++) vis[i] = 0, cnt[i] = 0;
    for (int i = 1; i <= n; i++) {
      cnt[a[i] - 'a']++;
    }
    for (int i = 1; i <= n; i++) {
      bool f = true;
      if (!vis[a[i] - 'a']) {
        vis[a[i] - 'a'] = 1;
        int rescnt = 0;
        int mid = 1;
        for (int j = 1; j <= n; j++) {
          if (a[j] == a[i])
            ;
          else {
            res[++rescnt] = a[j];
          }
        }
        if (rescnt == 0) ans = 0;
        int k = 0;
        for (int j = n; j; j--) {
          if (a[j] != a[i]) {
            k++;
            mid = j;
          }
          if (k * 2 >= rescnt) break;
        }
        for (int j = 1; j * 2 <= n; j++) {
          if (res[j] == res[rescnt - j + 1])
            ;
          else {
            f = false;
            break;
          }
        }
        if (!f)
          ;
        else {
          long long ansres = 0;
          if (rescnt % 2 == 0) {
            int l = mid - 1, r = mid;
            while (l > 0 && r <= n) {
              if (a[l] == a[r]) {
                l--, r++;
              } else {
                if (a[l] == a[i])
                  l--;
                else
                  r++;
                ansres++;
              }
            }
            ansres += max(l, n - r + 1);
            ans = min(ans, ansres);
          } else {
            int l = mid - 1, r = mid + 1;
            while (l > 0 && r <= n) {
              if (a[l] == a[r]) {
                l--, r++;
              } else {
                if (a[l] == a[i])
                  l--;
                else
                  r++;
                ansres++;
              }
            }
            ansres += max(l, n - r + 1);
            ans = min(ans, ansres);
          }
        }
      }
    }
    if (ans != inf)
      cout << ans << endl;
    else
      cout << -1 << endl;
  }
  return 0;
}
