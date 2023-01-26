#include <bits/stdc++.h>
using namespace std;
void init_code() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
}
void _print(int a) { cerr << a; }
void _print(char a) { cerr << a; }
void _print(string a) { cerr << a; }
void _print(long long a) { cerr << a; }
void _print(bool a) { cerr << a; }
void _print(double a) { cerr << a; }
void _print(float a) { cerr << a; }
template <class T>
void _print(vector<T> v1) {
  cerr << "[";
  for (T i : v1) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class U>
void _print(unordered_map<T, U> m1) {
  for (auto i : m1) {
    cerr << "[";
    _print(i.first);
    cerr << ", ";
    _print(i.second);
    cerr << "] ";
  }
}
template <class T, class U>
void _print(map<T, U> m1) {
  for (auto i : m1) {
    cerr << "[";
    _print(i.first);
    cerr << ", ";
    _print(i.second);
    cerr << "] ";
  }
}
const long long MOD = 1000000007;
vector<long long> sieve(long long n) {
  vector<long long> vect(n + 1, 1);
  for (long long i = 2; i * i <= n; i++) {
    if (vect[i] == 1) {
      for (long long j = i * 2; j <= n; j += i) {
        vect[j] = 0;
      }
    }
  }
  return vect;
}
vector<long long> fact(1e6 + 5, 1);
void factorial(int n) {
  fact[0] = 1;
  for (int i = 1; i <= n; i++) {
    fact[i] = ((fact[i - 1]) * (i)) % MOD;
  }
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
int npr(int n, int r) {
  int k = 1;
  for (int i = n; i > n - r; i--) {
    k *= i;
  }
  return k;
}
long long nc2(int n) {
  long long p = n;
  p = (p - 1) * p;
  p /= 2;
  return p;
}
long long binexp(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long ans = binexp(a, b / 2);
  if (b % 2 == 0) return (ans * ans) % MOD;
  return ((ans * ans) % MOD * a) % MOD;
}
long long inverse(long long a) {
  return (binexp(a, MOD - 2) % MOD + MOD) % MOD;
}
long long ncr(long long a, long long b) {
  if (a < 0 || b < 0) return 0;
  return (((fact[a] * inverse(fact[b])) % MOD * inverse(fact[a - b])) % MOD +
          MOD) %
         MOD;
}
int main() {
  init_code();
  long long T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int n = s.size();
    if (n % 2 == 0) {
      int z = 0;
      for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n / 2 + i]) {
          z = 1;
          break;
        }
      }
      if (z == 1) {
        cout << "NO\n";
      } else {
        cout << "YES\n";
      }
    } else {
      cout << "NO\n";
    }
  }
}
