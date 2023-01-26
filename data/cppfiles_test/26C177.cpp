#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cout << t; }
void _print(int t) { cout << t; }
void _print(string t) { cout << t; }
void _print(char t) { cout << t; }
void _print(long double t) { cout << t; }
void _print(double t) { cout << t; }
void _print(unsigned long long t) { cout << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cout << "{";
  _print(p.first);
  cout << ",";
  _print(p.second);
  cout << "}";
}
template <class T>
void _print(vector<T> v) {
  cout << "[ ";
  for (T i : v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T>
void _print(set<T> v) {
  cout << "[ ";
  for (T i : v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T>
void _print(multiset<T> v) {
  cout << "[ ";
  for (T i : v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cout << "[ ";
  for (auto i : v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
long long gcd(long long a, long long b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long expo(long long a, long long b, long long mod) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return res;
}
void extendgcd(long long a, long long b, long long *v) {
  if (b == 0) {
    v[0] = 1;
    v[1] = 0;
    v[2] = a;
    return;
  }
  extendgcd(b, a % b, v);
  long long x = v[1];
  v[1] = v[0] - v[1] * (a / b);
  v[0] = x;
  return;
}
long long mminv(long long a, long long b) {
  long long arr[3];
  extendgcd(a, b, arr);
  return arr[0];
}
long long mminvprime(long long a, long long b) { return expo(a, b - 2, b); }
bool revsort(long long a, long long b) { return a > b; }
void swap(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
}
long long combination(long long n, long long r, long long m, long long *fact,
                      long long *ifact) {
  long long val1 = fact[n];
  long long val2 = ifact[n - r];
  long long val3 = ifact[r];
  return (((val1 * val2) % m) * val3) % m;
}
void google(int t) { cout << "Case #" << t << ": "; }
vector<long long> sieve(int n) {
  int *arr = new int[n + 1]();
  vector<long long> vect;
  for (int i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (int j = 2 * i; j <= n; j += i) arr[j] = 1;
    }
  return vect;
}
long long mod_add(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long mod_mul(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long mod_sub(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
long long mod_div(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (mod_mul(a, mminvprime(b, m), m) + m) % m;
}
long long phin(long long n) {
  long long number = n;
  if (n % 2 == 0) {
    number /= 2;
    while (n % 2 == 0) n /= 2;
  }
  for (long long i = 3; i <= sqrt(n); i += 2) {
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      number = (number / i * (i - 1));
    }
  }
  if (n > 1) number = (number / n * (n - 1));
  return number;
}
int ans = 0;
string s;
int cnt = 0;
void backtrack(int i, int t1, int t2, int k1, int k2) {
  if (i == 10) {
    return;
  }
  if (i % 2)
    k2--;
  else
    k1--;
  if (s[i] == '1') {
    if (i % 2 == 0)
      t1++;
    else
      t2++;
    if (t1 > t2) {
      if (t1 - t2 > k2) {
        ans = min(ans, i);
      } else {
        backtrack(i + 1, t1, t2, k1, k2);
      }
    } else {
      if (t2 - t1 > k1) {
        ans = min(ans, i);
      } else {
        backtrack(i + 1, t1, t2, k1, k2);
      }
    }
  } else if (s[i] == '?') {
    if (t1 - t2 > k2) {
      ans = min(ans, i);
    } else {
      backtrack(i + 1, t1, t2, k1, k2);
    }
    if (t2 - t1 > k1) {
      ans = min(ans, i);
    } else {
      backtrack(i + 1, t1, t2, k1, k2);
    }
    if (i % 2 == 0)
      t1++;
    else
      t2++;
    if (t1 > t2) {
      if (t1 - t2 > k2) {
        ans = min(ans, i);
      } else {
        backtrack(i + 1, t1, t2, k1, k2);
      }
    } else {
      if (t2 - t1 > k1) {
        ans = min(ans, i);
      } else {
        backtrack(i + 1, t1, t2, k1, k2);
      }
    }
  } else {
    if (t1 - t2 > k2) {
      ans = min(ans, i);
    } else {
      backtrack(i + 1, t1, t2, k1, k2);
    }
    if (t2 - t1 > k1) {
      ans = min(ans, i);
    } else {
      backtrack(i + 1, t1, t2, k1, k2);
    }
  }
}
void solve() {
  cin >> s;
  ans = 9;
  cnt = 0;
  backtrack(0, 0, 0, 5, 5);
  cout << ans + 1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
