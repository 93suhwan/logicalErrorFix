#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const long long int N = 1e7 + 5;
void debugs() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a / gcd(a, b)) * b;
}
long long multiply(long long x, long long res[], long long ressize) {
  long long carry = 0;
  for (long long i = 0; i < ressize; i++) {
    long long product = res[i] * x + carry;
    res[i] = product % 10;
    carry = product / 10;
  }
  while (carry) {
    res[ressize] = carry % 10;
    carry = carry / 10;
    ressize++;
  }
  return ressize;
}
void bigfactorial(long long n) {
  long long ressize = 1;
  long long res[10000];
  res[0] = 1;
  for (long long i = 2; i <= n; i++) {
    ressize = multiply(i, res, ressize);
  }
  for (long long i = ressize - 1; i >= 0; i--) {
    cout << res[i];
  }
}
long long int inv(long long i) {
  if (i == 1) return 1;
  return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;
}
long long int mod_mul(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (((a * b) % mod) + mod) % mod;
}
long long int mod_add(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (((a + b) % mod) + mod) % mod;
}
void viewvector(vector<long long int> v) {
  long long int n = v.size();
  for (long long int i = 0; i < n; i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}
void viewarray(long long int a[], long long int n) {
  for (long long int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}
long long int fpow(long long int a, long long int p) {
  if (p == 0) return 1;
  long long int k = fpow(a, p / 2);
  if (p & 1) return (k * k % mod) * a % mod;
  return k * k % mod;
}
vector<long long int> phi(10000004);
void euler() {
  phi[0] = 0;
  phi[1] = 1;
  for (long long i = 2; i < 10000004; i++) {
    phi[i] = i;
  }
  for (long long i = 2; i < 10000004; i++) {
    if (phi[i] == i) {
      for (long long j = i; j < 10000004; j += i) {
        phi[j] -= phi[j] / i;
      }
    }
  }
  for (long long int i = 0; i < 10000004; i++) {
    phi[i] += phi[i - 1];
  }
}
long long paindrome(string s, char x) {
  long long ans = 0;
  long long int n = s.size();
  ;
  long long int i = 0;
  long long int j = n - 1;
  while (i <= j) {
    if (s[i] == s[j]) {
      i++;
      j--;
    } else if (s[i] == x) {
      ans++;
      i++;
    } else if (s[j] == x) {
      ans++;
      j--;
    } else {
      ans = n + 1;
      break;
    }
  }
  return ans;
}
long long permute(long long a) {
  long long int product = 1;
  for (long long int i = a; i > a - 2; i--) {
    product *= i;
  }
  product /= 2;
  return product;
}
void init_code() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
vector<long long int> alp(26);
vector<long long int> apl2(26);
signed main() {
  init_code();
  string s, t;
  cin >> s >> t;
  long long int n = s.size();
  long long int m = t.size();
  vector<long long int> ans;
  if (n > m) {
    cout << "-1" << endl;
  }
  long long int i = n - 1;
  long long int j = m - 1;
  bool p = true;
  i = n - 1;
  j = m - 1;
  while (j >= i && (j >= 0 && i >= 0)) {
    if (s[i] - '0' > t[j] - '0') {
      ans.push_back(((t[j - 1] - '0') * 10 + (t[j] - '0')) - (s[i] - '0'));
      j -= 2;
      i--;
      if (t[j + 1] != '1') {
        p = false;
      }
    } else {
      ans.push_back((t[j] - '0') - (s[i] - '0'));
      j--;
      i--;
    }
  }
  if (j < i || !p) {
    cout << "-1" << endl;
    continue;
  }
  string y = "";
  if (j >= 0) {
    if (t[j] != '1') {
      cout << "-1" << endl;
      continue;
    }
    for (long long int i1 = 0; i1 <= j; i1++) {
      y += t[i1];
    }
  }
  string as = "";
  for (long long int i = ans.size() - 1; i >= 0; i--) {
    as += to_string(ans[i]);
  }
  as = y + as;
  string ansd = "";
  long long int idx = 0;
  for (long long int i = 0; i < as.size(); i++) {
    if (as[i] != '0') {
      idx = i;
      break;
    }
  }
  for (long long int i = idx; i < as.size(); i++) {
    ansd += as[i];
  }
  cout << ansd << endl;
}
}
