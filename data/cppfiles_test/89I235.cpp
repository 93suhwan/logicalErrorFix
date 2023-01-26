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
    int i;
    for (i = 1; i <= n; ++i) {
      cin >> ar[i];
      ar[i] %= i + 1;
    }
    bool flg = true;
    for (i = n; i >= 1; --i) {
      if (ar[i] == 0) {
        flg = false;
      } else {
        flg = true;
      }
    }
    if (flg == false) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}
