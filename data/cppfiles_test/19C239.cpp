#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
template <typename... Args>
void logger(string vars, Args &&...values) {
  cout << vars << " = ";
  string delim = "";
}
inline string toString(int x) {
  string ans = "";
  bool negtive = x < 0;
  x = abs(x);
  while (x) ans.push_back(x % 10 + '0'), x /= 10;
  if (ans.size() == 0) ans = "0";
  if (negtive) ans.push_back('-');
  for (int i = 0; i < ans.size() / 2; i++)
    swap(ans[i], ans[ans.size() - 1 - i]);
  return ans;
}
inline int toInt(const string &str) {
  int ans = 0;
  bool negtive = str[0] == '-';
  for (int i = negtive; i < str.size(); i++) ans = ans * 10 + str[i] - '0';
  if (negtive) ans *= -1;
  return ans;
}
inline int gcd(int x, int y) { return x ? gcd(y % x, x) : y; }
long long exgcd(long long a, long long b, long long &x, long long &y) {
  long long d = a;
  if (b == 0)
    x = 1, y = 0;
  else {
    d = exgcd(b, a % b, y, x), y -= a / b * x;
  }
  return d;
}
const int mod = 998244353;
inline int rd() {
  int ans = 0;
  char last = ' ', ch = getchar();
  while (!(ch >= '0' && ch <= '9')) last = ch, ch = getchar();
  while (ch >= '0' && ch <= '9')
    ans = (ans << 3) + (ans << 1) + ch - '0', ch = getchar();
  return ans;
}
inline int QPow(long long a, long long b) {
  long long ans = 1;
  if (b < 0) return 0;
  while (b) {
    if (b & 1) ans = ans * a;
    a = a * a;
    b >>= 1;
  }
  return ans;
}
inline int QPow(long long a, long long b, const int &mod) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
const double PI = 3.141592653589793115997963468544185161590576171875;
const double e = 2.718281828459045;
void ask(int x) {
  cout << '?' << ' ' << x << endl;
  cout.flush();
  ;
}
void decide(int x) {
  cout << "! " << x << endl;
  cout.flush();
  ;
}
short _min(short a, short b) { return a < b ? a : b; }
const int inf = 1e9;
const int inf2 = 10000;
const double eps = 5e-9;
int db_cmp(double x, double y) {
  if (fabs(x - y) < eps) return 0;
  if (x > y) return 1;
  return -1;
}
const int maxn = 400005;
int arr[maxn];
bool mp1[1000007 * 2], mp2[2000002];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int t, k;
  int n;
  cin >> t;
  while (t--) {
    cin >> n;
    bool flag = 0;
    for (int i = 1; i <= n; i++) cin >> arr[i], flag |= arr[i] == 0;
    for (int i = 0; i < (1 << n); i++) {
      unordered_map<int, int> mp;
      int sum = 0;
      if (i) mp[0] = 1;
      for (int j = 0; j < n; j++) {
        if ((1 << j) & i) sum += arr[j + 1];
      }
      unordered_map<int, int> mp1;
      for (int j = 0; j < (1 << n); j++) {
        if ((i ^ j) == (i | j)) {
          int tmp = 0;
          for (int k = 0; k < n; k++)
            if ((1 << k) & j) tmp += arr[k + 1];
          mp1[tmp] = 1;
        }
      }
      if (i != 0 && mp1.count(sum)) flag = 1;
      if (flag) break;
    }
    cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}
