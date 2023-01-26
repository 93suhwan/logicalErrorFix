#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e7 + 2;
vector<long long int> divisor(N, -1);
vector<bool> isprime(N, 1);
vector<long long int> lp(N, 0);
vector<long long int> hp(N, 0);
vector<long long int> sieve(int n) {
  int* arr = new int[n + 1]();
  vector<long long int> vect;
  for (int i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (int j = 2 * i; j <= n; j += i) arr[j] = 1;
    }
  return vect;
}
void prime() {
  isprime[0] = isprime[1] = 0;
  for (int i = 2; i < N; i++) {
    if (isprime[i]) {
      hp[i] = lp[i] = i;
      for (int j = 2 * i; j < N; j += i) {
        isprime[j] = false;
        hp[j] = i;
        if (lp[j] == 0) lp[j] = i;
      }
    }
  }
}
void primefacts(long long int n) {
  unordered_map<long long int, long long int> pf;
  while (n > 1) {
    long long int pff = hp[n];
    while (n % pff == 0) {
      n = n / pff;
      pf[pff]++;
    }
  }
  for (auto [key, value] : pf) cout << key << "^" << value << " ";
  cout << "\n";
}
long long int max(long long int a, long long int b) { return (a > b) ? a : b; }
long long int min(long long int a, long long int b) { return (a > b) ? b : a; }
long long int lg(long long int a, long long int n) {
  return log10(n) / log10(a);
}
bool ispower(long long int a, long long int n) {
  long long int c1 = log(n) / log(a);
  double c2 = log(n) / log(a);
  return c1 == c2;
}
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
void swap(long long int* p1, long long int* p2) {
  long long int t = *p1;
  *p1 = *p2;
  *p2 = t;
}
long long int sum(long long int n) {
  long long int ans = 0;
  while (n > 0) {
    ans++;
    n = n / 10;
  }
  long long int t = 0;
  while (ans--) {
    t = t * 10 + 1;
  }
  return t;
}
long long int digit(long long int n) {
  long long int c = 0;
  while (n > 0) {
    n = n / 10;
    c++;
  }
  return c;
}
bool cmpv(long long int a, long long int b) { return a > b; }
long long int mod_add(long long int a, long long int b, long long int m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long int mod_mul(long long int a, long long int b, long long int m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long int mod_sub(long long int a, long long int b, long long int m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
long long int pow_mod(long long int a, long long int b, long long int m) {
  a = a % m;
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % m;
    a = (a * a) % m;
    b = b >> 1;
  }
  return res;
}
bool pali(string str) {
  int i = 0;
  int j = str.size() - 1;
  while (i < j) {
    if (str[i] != str[j]) return false;
    i++;
    j--;
  }
  return 1;
}
long long int* fact = new long long int[200000 + 10];
long long int ncr(long long int n, long long int r) {
  long long int ans = fact[n] / (fact[n - r] * fact[r]);
  return ans;
}
long long int mul(long long int x, long long int y) {
  return (x * 1ll * y) % 998244353;
}
long long int inv(long long int x) {
  return pow_mod(x, 998244353 - 2, 998244353);
}
int divide(int x, int y) { return mul(x, inv(y)); }
int C(long long int n, long long int k) {
  return divide(fact[n], mul(fact[k], fact[n - k]));
}
bool check_vowel(char ch) {
  return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}
bool pos(vector<long long int> v, long long int mid) {
  int n = v.size();
  vector<long long int> dummy((v).begin(), (v).end());
  long long int carry1 = 0, carry2 = 0;
  for (int i = n - 1; i >= 2; i--) {
    if (dummy[i] < mid) {
      return false;
    }
    long long int d = ((dummy[i] - mid) / 3) * 3;
    d = min(d, v[i]);
    dummy[i] -= d;
    dummy[i - 1] += (d / 3);
    dummy[i - 2] += (d / 3) * 2;
  }
  return (dummy[0] >= mid and dummy[1] >= mid);
}
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> v(n);
  for (auto& A : v) cin >> A;
  long long int low = 0, ans;
  long long int high = INT_MAX;
  while (low <= high) {
    long long int mid = (low + high) >> 1;
    if (pos(v, mid)) {
      ans = mid;
      low = mid + 1;
    } else
      high = mid - 1;
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
