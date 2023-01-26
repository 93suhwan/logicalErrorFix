#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
bool isPrime(long long a) {
  long long i;
  for (i = 2; i * i <= a; i++) {
    if (a % i == 0) {
      return 0;
    }
  }
  return (a != 1);
}
bool isPalindrom(const string& s, int l, int r) {
  for (int i = 0; i < (r - l + 1) / 2; i++) {
    if (s[l + i] != s[r - i]) {
      return 0;
    }
  }
  return 1;
}
template <class type1>
type1 gcd(type1 a, type1 b) {
  type1 t;
  while (b) {
    t = b;
    b = a % b;
    a = t;
  }
  return a;
}
long long positiveMod(long long v, long long md) {
  v = v % md;
  if (v < 0) {
    v += md;
  }
  return v;
}
vector<long long> dat;
vector<vector<long long> > infMin;
vector<vector<long long> > infMax;
vector<vector<long long> > infScore;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, i, j, a, b, c;
  unsigned long long res = 0;
  cin >> n;
  dat.push_back(0);
  for (i = 0; i < n; i++) {
    cin >> a;
    dat.push_back(a);
  }
  infMin.resize(n + 2, vector<long long>(n + 2, 0));
  infMax.resize(n + 2, vector<long long>(n + 2, 0));
  infScore.resize(n + 2, vector<long long>(n + 2, 0));
  for (i = 1; i <= n; i++) {
    long long val = 0;
    for (j = i; j <= n; j++) {
      if (j % 2 == 1) {
        val += dat[j];
      } else {
        val -= dat[j];
      }
      infMin[i][j] = min(infMin[i][j - 1], val);
      infMax[i][j] = max(infMax[i][j - 1], val);
      infScore[i][j] = val;
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = i + 1; j <= n; j++) {
      long long mn = infMin[i + 1][j - 1], mx = infMin[i + 1][j - 1],
                sc = infScore[i + 1][j - 1];
      long long sp = 0;
      if (i % 2 == 0) {
        continue;
      }
      if (j % 2 == 1) {
        continue;
      }
      long long v1 = dat[i];
      long long v2 = dat[j];
      v1 -= abs(mn);
      sc += abs(mn);
      sp += abs(mn);
      if (v1 < 0) {
        continue;
      }
      v2 -= sc;
      sp += sc;
      if (v2 < 0) {
        continue;
      }
      res += min(v1, v2);
      if (sp != 0) {
        res++;
      }
    }
  }
  cout << res << "\n";
  return 0;
}
