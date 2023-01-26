#include <bits/stdc++.h>
using namespace std;
long long mod = pow(10, 9) + 7;
int gcdExtended(int a, int b, int *x, int *y);
int modInverse(int b, int m) {
  int x, y;
  int g = gcdExtended(b, m, &x, &y);
  if (g != 1) return -1;
  return (x % m + m) % m;
}
int gcdExtended(int a, int b, int *x, int *y) {
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  int x1, y1;
  int gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
long long sumbincoef(int N, int k) {
  long long bincoef = 1, sum = 1;
  int i;
  for (i = 1; i < k; i++) {
    long long val = ((N - i + 1) % mod * modInverse(i, mod)) % mod;
    bincoef = (bincoef % mod * val) % mod;
    if (i % 2 == 0) sum = (sum + bincoef) % mod;
  }
  return sum % mod;
}
const int N = 300000 + 10;
long long factorialNumInverse[N + 1];
long long naturalNumInverse[N + 1];
long long fact[N + 1];
void InverseofNumber(long long p) {
  naturalNumInverse[0] = naturalNumInverse[1] = 1;
  for (int i = 2; i <= N; i++)
    naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
void InverseofFactorial(long long p) {
  factorialNumInverse[0] = factorialNumInverse[1] = 1;
  for (int i = 2; i <= N; i++)
    factorialNumInverse[i] =
        (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}
void factorial(long long p) {
  fact[0] = 1;
  for (int i = 1; i <= N; i++) {
    fact[i] = (fact[i - 1] * i) % p;
  }
}
long long Binomial(long long N, long long R, long long p) {
  long long ans =
      ((fact[N] * factorialNumInverse[R]) % p * factorialNumInverse[N - R]) % p;
  return ans;
}
vector<int> parent(300000 + 1), ran(300000 + 1);
void make_set(int v) {
  parent[v] = v;
  ran[v] = 0;
}
int find_set(int v) {
  if (v == parent[v]) return v;
  return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (ran[a] < ran[b]) swap(a, b);
    parent[b] = a;
    if (ran[a] == ran[b]) ran[a]++;
  }
}
string decimalToBinary(long long n) {
  string s = bitset<64>(n).to_string();
  const auto loc1 = s.find('1');
  if (loc1 != string::npos) return s.substr(loc1);
  return "0";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
  long long p = mod;
  InverseofNumber(p);
  InverseofFactorial(p);
  factorial(p);
  int t = 1;
  while (t > 0) {
    long long a, b;
    cin >> a >> b;
    string x, y;
    x = decimalToBinary(a);
    y = decimalToBinary(b);
    string temp1 = x;
    string temp2 = x;
    while (temp2[temp2.size() - 1] == '0') {
      temp2.erase(--temp2.end());
    }
    string rev1 = temp1, rev2 = temp2;
    reverse(rev1.begin(), rev1.end());
    reverse(rev2.begin(), rev2.end());
    int cnt = 0;
    bool ok = false;
    for (int i = 0; i < y.size(); i++) {
      if (y.substr(i, temp1.size()) == temp1) {
        bool lok = true;
        int f = cnt;
        for (int j = i + temp1.size(); j < y.size(); j++) {
          if (y[j] == '0') {
            lok = false;
            break;
          }
          f++;
        }
        if (lok) {
          ok = true;
          break;
        }
      }
      if (y.substr(i, temp2.size()) == temp2) {
        bool lok = true;
        int f = cnt;
        for (int j = i + temp2.size(); j < y.size(); j++) {
          if (y[j] == '0') {
            lok = false;
            break;
          }
          f++;
        }
        if (lok) {
          ok = true;
          break;
        }
      }
      if (y.substr(i, rev1.size()) == rev1) {
        bool lok = true;
        int f = cnt;
        for (int j = i + rev1.size(); j < y.size(); j++) {
          if (y[j] == '0') {
            lok = false;
            break;
          }
          f++;
        }
        if (lok) {
          ok = true;
          break;
        }
      }
      if (y.substr(i, rev2.size()) == rev2) {
        bool lok = true;
        int f = cnt;
        for (int j = i + rev2.size(); j < y.size(); j++) {
          if (y[j] == '0') {
            lok = false;
            break;
          }
          f++;
        }
        if (lok) {
          ok = true;
          break;
        }
      }
      cnt++;
      if (y[i] == '0') {
        break;
      }
    }
    if (ok) {
      cout << "YES"
           << "\n";
    } else {
      reverse(y.begin(), y.end());
      reverse(temp1.begin(), temp1.end());
      reverse(temp2.begin(), temp2.end());
      reverse(rev1.begin(), rev1.end());
      reverse(rev2.begin(), rev2.end());
      ok = false;
      for (int i = 0; i < y.size(); i++) {
        if (y.substr(i, temp1.size()) == temp1) {
          bool lok = true;
          int f = cnt;
          for (int j = i + temp1.size(); j < y.size(); j++) {
            if (y[j] == '0') {
              lok = false;
              break;
            }
            f++;
          }
          if (lok) {
            ok = true;
            break;
          }
        }
        if (y.substr(i, temp2.size()) == temp2) {
          bool lok = true;
          int f = cnt;
          for (int j = i + temp2.size(); j < y.size(); j++) {
            if (y[j] == '0') {
              lok = false;
              break;
            }
            f++;
          }
          if (lok) {
            ok = true;
            break;
          }
        }
        if (y.substr(i, rev1.size()) == rev1) {
          bool lok = true;
          int f = cnt;
          for (int j = i + rev1.size(); j < y.size(); j++) {
            if (y[j] == '0') {
              lok = false;
              break;
            }
            f++;
          }
          if (lok) {
            ok = true;
            break;
          }
        }
        if (y.substr(i, rev2.size()) == rev2) {
          bool lok = true;
          int f = cnt;
          for (int j = i + rev2.size(); j < y.size(); j++) {
            if (y[j] == '0') {
              lok = false;
              break;
            }
            f++;
          }
          if (lok) {
            ok = true;
            break;
          }
        }
        cnt++;
        if (y[i] == '0') {
          break;
        }
      }
      if (!ok)
        cout << "NO"
             << "\n";
      else {
        cout << "YES"
             << "\n";
      }
    }
    t--;
  }
}
