#include <bits/stdc++.h>
using namespace std;
vector<tuple<int, int, int, int> > v, u;
int p[500001], invp[500001], hsh[500001];
bool IsPrime(int n) {
  for (int x = 2; x * x <= n; ++x) {
    if (n % x == 0) {
      return false;
    }
  }
  return true;
}
int GetRandomPrime() {
  int n;
  while (true) {
    n = 1E9 + rand() % (int)(1E9 + 1);
    if (IsPrime(n)) {
      break;
    }
  }
  return n;
}
vector<int> ZFunction(string s) {
  int n = s.size();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r) {
      z[i] = min(r - i + 1, z[i - l]);
    }
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      ++z[i];
    }
    if (i + z[i] - 1 > r) {
      l = i, r = i + z[i] - 1;
    }
  }
  return z;
}
bool CheckBoundary(int n, int l, int r) { return 0 < l && l <= r && r <= n; }
void CheckAndAddCanditate(int n, int l1, int len1, int l2, int len2) {
  int r1 = l1 + len1 - 1, r2 = l2 + len2 - 1;
  if (CheckBoundary(n, l1, r1) && CheckBoundary(n, l2, r2)) {
    v.push_back({l1, r1, l2, r2});
  }
}
void InitialiseCanditates(string &x, string &s) {
  int n = x.size(), m = s.size();
  for (int i = 1; i <= m; ++i) {
    CheckAndAddCanditate(m, i, n - 1, i + n - 1, n - 1);
  }
  vector<int> z = ZFunction(x + "$" + s);
  for (int i = 1, k = n + 1; i <= m; ++i, ++k) {
    int lcp = z[k];
    CheckAndAddCanditate(m, i, n, i + n, n - lcp);
    CheckAndAddCanditate(m, i, n, i + n, n - lcp - 1);
    CheckAndAddCanditate(m, i - (n - lcp), n - lcp, i, n);
    CheckAndAddCanditate(m, i - (n - lcp - 1), n - lcp - 1, i, n);
  }
}
void InitialisePowers(int mod) {
  p[0] = 1;
  for (int i = 1; i < 500001; ++i) {
    p[i] = (1ll * 10 * p[i - 1]) % mod;
  }
}
int InitialiseHashes(int mod, string &x, string &s) {
  InitialisePowers(mod);
  int xhash = 0;
  for (char c : x) {
    xhash = (1ll * 10 * xhash + (c - '0')) % mod;
  }
  for (int i = 1, m = s.size(); i <= m; ++i) {
    hsh[i] = (1ll * 10 * hsh[i - 1] + (s[i - 1] - '0')) % mod;
  }
  return xhash;
}
int GetSubstringHash(int mod, int i, int j) {
  int h = (hsh[j] - ((1ll * p[j - i + 1] * hsh[i - 1]) % mod)) % mod;
  return (mod + h) % mod;
}
void UpdateCandidates(int mod, string &x, string &s) {
  int xhash = InitialiseHashes(mod, x, s);
  for (auto [l1, r1, l2, r2] : v) {
    if ((GetSubstringHash(mod, l1, r1) + GetSubstringHash(mod, l2, r2)) % mod ==
        xhash) {
      u.push_back({l1, r1, l2, r2});
    }
  }
  v.swap(u);
  u.clear();
}
int main() {
  srand(time(NULL));
  string s, x;
  cin >> s >> x;
  InitialiseCanditates(x, s);
  for (int k = 0; k < 10; ++k) {
    int mod = GetRandomPrime();
    UpdateCandidates(mod, x, s);
  }
  auto [l1, r1, l2, r2] = v.front();
  cout << l1 << ' ' << r1 << '\n';
  cout << l2 << ' ' << r2 << '\n';
  return 0;
}
