#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
const int MX_N = (int)2e5 + 5;
vector<vector<int> > adj;
priority_queue<int> q;
map<int, int> mp;
set<int> st;
string s;
int n, m, k, ar[MX_N];
bool p[MX_N];
void getPrime() {
  int i, j;
  for (i = 2; i * i <= MX_N; ++i) {
    if (!p[i]) {
      for (j = i + i; j <= MX_N; j += i) {
        p[j] = true;
      }
    }
  }
}
long long gcd(long long a, long long b) {
  if (a < b) {
    swap(a, b);
  }
  return b ? gcd(b, a % b) : a;
}
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
long long mPow(long long a, long long x, long long MOD) {
  long long ret = 1;
  while (x) {
    if (x & 1) {
      ret = (ret * a) % MOD;
    }
    a = (a * a) % MOD;
    x >>= 1;
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> n;
    int i, j, k = 1;
    for (i = 1; i <= n; ++i) {
      cin >> ar[i];
    }
    for (i = 1; i <= n; ++i) {
      bool flg = false;
      for (j = 2; j <= min(i + 1, 23); ++j) {
        if (ar[i] % j) {
          flg = true;
          break;
        }
      }
      if (!flg) {
        break;
      }
    }
    if (i <= n) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}
