#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int ioo = 1000000000;
long long loo = 1000000000000000000;
void add_self(int &x, int y) {
  if ((x += y) >= mod) x -= mod;
}
int add(int x, int y) { return add_self(x, y), x; }
void sub_self(int &x, int y) {
  if ((x -= y) < 0) x += mod;
}
int sub(int x, int y) { return sub_self(x, y), x; }
int mul(int x, int y) { return (long long)x * y % mod; }
long long po(long long k, long long n) {
  long long res = 1;
  while (n) {
    if (n % 2) res *= k;
    k *= k;
    n /= 2;
  }
  return res;
}
long long pom(long long k, long long n) {
  long long res = 1;
  while (n) {
    if (n % 2) res = mul(res, k);
    k = mul(k, k);
    n /= 2;
  }
  return res;
}
char a[2005];
vector<long long> v;
long long n, k, x;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    v.clear();
    scanf("%lld%lld%lld", &n, &k, &x);
    scanf("%s", a);
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == 'a') {
        if (cnt) v.push_back(cnt * k);
        cnt = 0;
      } else
        cnt++;
    }
    if (cnt) v.push_back(cnt * k);
    vector<long long> b = v;
    if (!b.empty()) b.back()++;
    int idx = b.size();
    for (int i = (int)b.size() - 2; i >= 1; i--) {
      if (b[i] + 1 <= (loo * 2) / b[i + 1])
        b[i] = (b[i] + 1) * b[i + 1];
      else {
        idx = i;
        break;
      }
    }
    if (idx != b.size())
      for (int i = idx; i >= 0; i--) b[i] = loo * 2;
    deque<long long> ans(v.size(), 0);
    for (int i = 0; i < v.size(); i++) {
      if (i == (int)v.size() - 1)
        ans[i] = x - 1;
      else {
        long long steps = min((x - 1) / b[i + 1], v[i]);
        ans[i] = steps;
        x -= steps * b[i + 1];
      }
    }
    for (int i = 0; i < n; i++) {
      if (a[i] == 'a')
        printf("a");
      else {
        if (i == 0 || a[i] != a[i - 1]) {
          long long cur = ans.front();
          while (cur--) printf("b");
          ans.pop_front();
        }
      }
    }
    printf("\n");
  }
  return 0;
}
