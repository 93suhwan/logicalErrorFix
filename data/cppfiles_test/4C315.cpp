#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a / gcd(a, b)) * b;
}
long long int egcd(long long int a, long long int b, long long int &x,
                   long long int &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long int x1, y1;
  long long int d = egcd(b, a % b, x1, y1);
  x = x1;
  y = x1 - (a / b) * y1;
  return d;
}
long long int sum_formula(long long int n) { return n * (n - 1) / 2; }
long long int BigMod(long long int base, long long int power,
                     long long int mod) {
  if (power == 0)
    return 1;
  else if (power % 2 == 1) {
    long long int a = base % mod;
    long long int b = BigMod(base, power - 1, mod) % mod;
    return (a * b) % mod;
  } else if (power % 2 == 0) {
    long long int a = BigMod(base, power / 2, mod) % mod;
    return (a * a) % mod;
  }
}
vector<long long int> vecprime;
bool primearr[1];
void sieve(long long int a) {
  primearr[0] = true;
  primearr[1] = true;
  for (long long int i = 2; i <= sqrt(a); i++) {
    if (primearr[i] == false) {
      for (long long int j = i * i; j <= a; j = i + j) {
        primearr[j] = true;
      }
    }
  }
  for (long long int i = 0; i <= a; i++) {
    if (primearr[i] == false) vecprime.push_back(i);
  }
}
void prime_factorization(long long int n) {
  for (long long int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      long long int cnt = 0;
      while (n % i == 0) {
        n = n / i;
        cnt++;
      }
      cout << i << "^" << cnt << endl;
    }
  }
  if (n != 1) {
    cout << n << "^" << endl;
  }
}
long long int phi[10];
bool visit[10];
void fphi(long long int n) {
  for (long long int i = 1; i <= n; i++) phi[i] = i;
  for (long long int i = 2; i <= n; i++) {
    if (visit[i]) continue;
    for (long long int j = i; j <= n; j = i + j) {
      visit[j] = true;
      phi[j] /= i;
      phi[j] *= (i - 1);
    }
  }
}
long long int fact_phi(long long int n) {
  long long int rest = n;
  for (long long int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      while (n % i == 0) {
        n = n / i;
      }
      rest = rest / i;
      rest = rest * (i - 1);
    }
  }
  if (n != 1) {
    rest = rest / n;
    rest = rest * (n - 1);
  }
  return rest;
}
int main() {
  int test;
  cin >> test;
  while (test--) {
    long long int p;
    cin >> p;
    long long int i = 2;
    long long int j = p;
    while (i < j) {
      long long int a = p % i;
      long long int b = p % j;
      if (a == b) {
        cout << i << " " << j << endl;
        break;
      } else
        j--;
    }
  }
  return 0;
}
