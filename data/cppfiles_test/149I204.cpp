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
void in(vector<long long> &x) {
  int k;
  cin >> k;
  while (k--) {
    long long in;
    cin >> in;
    x.push_back(in);
  }
}
char a[2005];
vector<int> ar;
vector<long long> v;
long long n, k, x;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    v.clear();
    cin >> n >> k >> x;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] == 'a') {
        if (cnt) v.push_back(cnt * k);
        cnt = 0;
      } else
        cnt++;
    }
    if (cnt) v.push_back(cnt * k);
    vector<long long> b = v;
    for (int i = (int)b.size() - 2; i >= 1; i--) b[i] *= b[i + 1];
    deque<int> ans(v.size(), 0);
    for (int i = 0; i < v.size(); i++) {
      if (i == (int)v.size() - 1) {
        ans[i] = x - 1;
        break;
      }
      long long L = 0, r = v[i];
      long long j = 0;
      while (L <= r) {
        long long mid = (L + r) / 2;
        if ((b[i + 1] + 1) * mid < x) {
          j = max(j, mid);
          L = mid + 1;
        } else
          r = mid - 1;
      }
      x -= (b[i + 1] + 1) * j;
      ans[i] = j;
      if (x == 0) break;
    }
    for (int i = 1; i <= n; i++) {
      if (a[i] == 'a')
        cout << 'a';
      else {
        if (i == 1 || a[i] != a[i - 1]) {
          long long cur = ans.front();
          while (cur--) cout << 'b';
          ans.pop_front();
        }
      }
    }
    cout << endl;
  }
  return 0;
}
