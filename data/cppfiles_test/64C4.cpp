#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const long long inf64 = (1LL << 62) - 1;
const long double pi = acos(-1);
template <typename T>
inline T abs(T x) {
  return x < 0 ? -x : x;
}
template <typename T>
inline T sqr(T x) {
  return x * x;
}
template <typename T1, typename T2>
inline bool umx(T1& a, T2 b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T1, typename T2>
inline bool umn(T1& a, T2 b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
const int MINP = 1000 * 1000 * 1000 - 1000;
const int CNTP = 2;
vector<int> p;
bool IsPrime(int x) {
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}
vector<int> ZFunction(const string& s) {
  int n = ((int)(s).size());
  vector<int> z(n);
  z[0] = n;
  int ind = -1;
  for (int i = int(1); i < int(n); ++i) {
    if (ind != -1) {
      umx(z[i], min(ind + z[ind] - i, z[i - ind]));
    }
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      ++z[i];
    }
    if (ind == -1 || ind + z[ind] < i + z[i]) {
      ind = i;
    }
  }
  return z;
}
vector<int> x_mod;
vector<vector<int>> pow_10;
vector<vector<int>> s_pref_mod;
vector<int> SubMod(int l, int r) {
  vector<int> res(((int)(p).size()));
  for (int i = int(0); i < int(((int)(p).size())); ++i) {
    res[i] = (s_pref_mod[i][r + 1] -
              pow_10[i][r - l + 1] * (long long)s_pref_mod[i][l]) %
             p[i];
    res[i] = (res[i] < 0 ? res[i] + p[i] : res[i]);
  }
  return res;
}
string Sum(const string& a, const string& b) {
  string res = "";
  int add = 0;
  for (int i = int(0); i < int(max(((int)(a).size()), ((int)(b).size())));
       ++i) {
    if (i < ((int)(a).size())) {
      add += a[((int)(a).size()) - i - 1] - '0';
    }
    if (i < ((int)(b).size())) {
      add += b[((int)(b).size()) - i - 1] - '0';
    }
    res.push_back('0' + add % 10);
    add /= 10;
  }
  if (add > 0) {
    res.push_back('0' + add);
  }
  reverse((res).begin(), (res).end());
  return res;
}
void Solve(int ti) {
  string s, x;
  cin >> s >> x;
  int n = ((int)(s).size());
  int m = ((int)(x).size());
  vector<int> lcp(n);
  {
    string xs = x + "0" + s;
    vector<int> z = ZFunction(xs);
    for (int i = int(0); i < int(n); ++i) {
      lcp[i] = z[m + 1 + i];
    }
  }
  x_mod.resize(((int)(p).size()));
  for (int i = int(0); i < int(((int)(p).size())); ++i) {
    x_mod[i] = 0;
    for (int j = int(0); j < int(m); ++j) {
      x_mod[i] = (x_mod[i] * 10LL + (x[j] - '0')) % p[i];
    }
  }
  pow_10.resize(((int)(p).size()));
  s_pref_mod.resize(((int)(p).size()));
  for (int i = int(0); i < int(((int)(p).size())); ++i) {
    pow_10[i].resize(n + 1);
    pow_10[i][0] = 1;
    for (int j = int(0); j < int(n); ++j) {
      pow_10[i][j + 1] = (pow_10[i][j] * 10LL) % p[i];
    }
    s_pref_mod[i].resize(n + 1);
    s_pref_mod[i][0] = 0;
    for (int j = int(0); j < int(n); ++j) {
      s_pref_mod[i][j + 1] = (s_pref_mod[i][j] * 10LL + (s[j] - '0')) % p[i];
    }
  }
  vector<pair<int, int>> a, b;
  if (m >= 2) {
    for (int i = int(0); i < int(n - (2 * m - 3)); ++i) {
      a.push_back(make_pair(i, i + m - 2));
      b.push_back(make_pair(i + m - 1, i + 2 * m - 3));
    }
  }
  for (int i = int(0); i < int(n - m + 1); ++i) {
    for (int t = int(0); t < int(2); ++t) {
      int len = m - lcp[i] - t;
      if (len <= 0) {
        continue;
      }
      if (i >= len) {
        a.push_back(make_pair(i - len, i - 1));
        b.push_back(make_pair(i, i + m - 1));
      }
      if (i + m + len - 1 < n) {
        a.push_back(make_pair(i, i + m - 1));
        b.push_back(make_pair(i + m, i + m + len - 1));
      }
    }
  }
  for (int i = int(0); i < int(((int)(a).size())); ++i) {
    vector<int> a_mod = SubMod(a[i].first, a[i].second);
    vector<int> b_mod = SubMod(b[i].first, b[i].second);
    bool key = true;
    for (int j = int(0); j < int(((int)(p).size())); ++j) {
      if ((a_mod[j] + b_mod[j]) % p[j] != x_mod[j]) {
        key = false;
        break;
      }
    }
    if (!key) {
      continue;
    }
    string sa = s.substr(a[i].first, a[i].second - a[i].first + 1);
    string sb = s.substr(b[i].first, b[i].second - b[i].first + 1);
    string sum = Sum(sa, sb);
    if (sum == x) {
      cout << a[i].first + 1 << " " << a[i].second + 1 << "\n"
           << b[i].first + 1 << " " << b[i].second + 1 << "\n";
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  std::cin.tie(nullptr);
  for (int i = MINP; ((int)(p).size()) < CNTP; ++i) {
    if (IsPrime(i)) {
      p.push_back(i);
    }
  }
  int tc = 1;
  for (int ti = int(0); ti < int(tc); ++ti) {
    Solve(ti);
  }
  return 0;
}
