#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.14159265359;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long randint(long long a, long long b) {
  return uniform_int_distribution<long long>(a, b)(rng);
}
template <typename... Args>
void logger(string vars, Args&&... values) {
  cout << vars << " = ";
  string delim = "";
  (..., (cout << delim << values, delim = ", "));
  cout << endl;
}
void print(vector<long long> v) {
  cout << "[";
  for (long long i = 0; i < v.size(); i++) {
    cout << v[i];
    if (i + 1 != v.size()) cout << ", ";
  }
  cout << "]" << endl;
}
void print(pair<long long, long long> p) {
  cout << "{" << p.first << ", " << p.second << "}" << endl;
}
vector<long long> Z(string& s) {
  long long n = s.length();
  vector<long long> z(n);
  for (long long i = 1, l = 0, r = 0; i < n; i++) {
    if (i < r) {
      z[i] = min(r - i, z[i - l]);
    }
    while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
      z[i]++;
    }
    if ((i + z[i]) >= r) {
      l = i;
      r = i + z[i];
    }
  }
  return z;
}
const long long mod1 = 1e9 + 9;
const long long mod2 = 1e9 + 7;
const long long mod3 = 90003047;
const long long qntdbase = 3;
const long long bases[qntdbase] = {mod1, mod2, mod3};
const long long base = 10;
const long long maxn = 1e6 + 10;
long long expBase[maxn][qntdbase];
void precalc() {
  for (long long j = 0; j < qntdbase; j++) {
    expBase[0][j] = 1;
    for (long long i = 1; i < maxn; i++) {
      expBase[i][j] = (expBase[i - 1][j] * base) % bases[j];
    }
  }
}
struct StringHash {
  vector<vector<long long>> hsh;
  StringHash() {}
  StringHash(string& _s) {
    hsh = vector<vector<long long>>(_s.length() + 1,
                                    vector<long long>(qntdbase, 0));
    for (long long j = 0; j < qntdbase; j++) {
      for (long long i = 0; i < _s.length(); i++) {
        hsh[i + 1][j] =
            ((hsh[i][j] * base) % bases[j] + (_s[i] - '0')) % bases[j];
      }
    }
  }
  vector<long long> get_value(long long a, long long b) {
    vector<long long> ans(qntdbase);
    for (long long j = 0; j < qntdbase; j++) {
      ans[j] = (bases[j] + hsh[b + 1][j] -
                ((hsh[a][j]) * expBase[b - a + 1][j]) % bases[j]) %
               bases[j];
    }
    return ans;
  }
};
StringHash sh;
vector<long long> criptog;
string s;
bool checa(long long l1, long long r1, long long l2, long long r2) {
  if (r2 >= (long long)s.size()) return 0;
  if (l2 > r2) return 0;
  if (r1 >= (long long)s.size()) return 0;
  if (l1 > r1) return 0;
  auto teste = sh.get_value(l1, r1);
  auto teste2 = sh.get_value(l2, r2);
  long long cont = 0;
  for (long long i = 0; i < qntdbase; i++) {
    if ((teste[i] + teste2[i]) % bases[i] == criptog[i]) cont++;
  }
  if (cont == qntdbase) {
    if (l1 < l2) {
      cout << l1 + 1 << " " << r1 + 1 << '\n';
      cout << l2 + 1 << " " << r2 + 1 << '\n';
    } else {
      cout << l2 + 1 << " " << r2 + 1 << '\n';
      cout << l1 + 1 << " " << r1 + 1 << '\n';
    }
    return 1;
  }
  return 0;
}
signed main() {
  cin.tie(NULL);
  cin.sync_with_stdio(false);
  cin >> s;
  string soma;
  cin >> soma;
  precalc();
  long long n = soma.length();
  if (n == 1) {
    long long i = 0;
    long long i2 = 1;
    long long ssoma = stoi(soma);
    while (i2 < s.length()) {
      if ((s[i] - '0') + (s[i2] - '0') == ssoma) {
        cout << i + 1 << " " << i + 1 << '\n';
        cout << i2 + 1 << " " << i2 + 1 << '\n';
        return 0;
      }
      i++;
      i2++;
    }
    return 0;
  }
  long long l1 = 0;
  long long r1 = n - 2;
  long long l2 = n - 1;
  long long r2 = n - 1 + n - 2;
  sh = StringHash(s);
  StringHash hashsoma(soma);
  criptog = hashsoma.get_value(0, soma.length() - 1);
  while (r2 < s.length()) {
    if (checa(l1, r1, l2, r2)) return 0;
    l1++;
    r1++;
    l2++;
    r2++;
  }
  long long l = 0;
  long long r = n - 1;
  auto sgamb = soma + '$' + s;
  auto zf = Z(sgamb);
  while (r < s.length()) {
    long long lcp = zf[n + l + 1];
    if (checa(l, r, r + 1, r + n - lcp)) return 0;
    if (checa(l, r, r + 1, r + n + lcp - 1)) return 0;
    l++;
    r++;
  }
  l = 0;
  while (l < s.length()) {
    long long lcp = zf[n + l + 1];
    long long R = l + n - 1 - lcp;
    if (checa(R + 1, R + 1 + n - 1, l, R)) return 0;
    if (checa(R, R + n - 1, l, R - 1)) return 0;
    l++;
  }
}
