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
bool cmp(pair<long long int, long long int> a,
         pair<long long int, long long int> b) {
  return a.second < b.second;
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
vector<long long int> v(sieve(10000));
set<long long int> st((v).begin(), (v).end());
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
bool fun(vector<bool> mark) {
  for (int i = 1; i <= mark.size(); i++)
    if (!mark[i]) return false;
  return true;
}
void solve() {
  int n;
  cin >> n;
  char ch;
  cin >> ch;
  string str;
  cin >> str;
  int odd = 0, ev = 0;
  int pos = -1;
  int count = 0;
  vector<long long int> in;
  for (long long int i = 0; i <= n - 1; i++) {
    if (str[i] == ch) {
      pos = i + 1;
      in.push_back(i + 1);
      count++;
    }
  }
  reverse((in).begin(), (in).end());
  if (count == n) {
    cout << 0 << "\n";
    return;
  }
  if (count == 0) {
    cout << 2 << "\n";
    cout << n - 1 << " " << n << "\n";
    return;
  }
  for (long long int i = 1; i <= n; i++) {
    if (i & 1 and str[i - 1] != ch) {
      odd++;
    } else if (i % 2 == 0 and str[i - 1] != ch) {
      ev++;
    }
  }
  if (odd == 0) {
    cout << 1 << "\n";
    if (n & 1)
      cout << n << "\n";
    else
      cout << n - 1 << "\n";
    return;
  }
  if (ev == 0) {
    cout << 1 << "\n";
    if (n & 1)
      cout << n - 1 << "\n";
    else
      cout << n << "\n";
    return;
  }
  if (pos == 1) {
    cout << 2 << "\n";
    cout << n - 1 << " " << n << "\n";
    return;
  }
  for (auto a : in) {
    bool ok = true;
    for (int i = 1; i <= n; i++) {
      if (str[i - 1] != ch and (i % a) == 0) {
        ok = false;
      }
    }
    if (ok) {
      cout << 1 << "\n";
      cout << a << "\n";
      return;
    }
  }
  cout << 2 << "\n";
  cout << n - 1 << " " << n << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
