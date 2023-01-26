#include <bits/stdc++.h>
using namespace std;
namespace number_theory {
int isprime(long long int a) {
  for (int i = 2; i * i <= a; i++) {
    if (a % i == 0) return 0;
  }
  return 1;
}
long long int binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long int binmod(long long int a, long long int b, long long int m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
int powersimple(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = (res * a);
      b--;
    }
    a = (a * a);
    b >>= 1;
  }
  return res;
}
void SieveOfEratosthenes(long long int n, bool prime[], bool primesquare[],
                         long long int a[]) {
  for (long long int i = 2; i <= n; i++) prime[i] = true;
  for (long long int i = 0; i <= (n * n + 1); i++) primesquare[i] = false;
  prime[1] = false;
  for (long long int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long int i = p * 2; i <= n; i += p) prime[i] = false;
    }
  }
  long long int j = 0;
  for (long long int p = 2; p <= n; p++) {
    if (prime[p]) {
      a[j] = p;
      primesquare[p * p] = true;
      j++;
    }
  }
}
long long int countDivisors(long long int n) {
  if (n == 1) return 1;
  bool prime[n + 1], primesquare[n * n + 1];
  long long int a[n];
  SieveOfEratosthenes(n, prime, primesquare, a);
  long long int ans = 1;
  for (long long int i = 0;; i++) {
    if (a[i] * a[i] * a[i] > n) break;
    long long int cnt = 1;
    while (n % a[i] == 0) {
      n = n / a[i];
      cnt = cnt + 1;
    }
    ans = ans * cnt;
  }
  if (prime[n])
    ans = ans * 2;
  else if (primesquare[n])
    ans = ans * 3;
  else if (n != 1)
    ans = ans * 4;
  return ans;
}
long long int ncr(long long int n, long long int k) {
  long long int ans = 1;
  if (k > n - k) {
    k = n - k;
  }
  for (int i = 1; i <= k; i++) {
    ans *= (n - i + 1), ans /= i;
  }
  return ans;
}
int power(int r, int y, int p) {
  int res = 1;
  r = r % p;
  while (y > 0) {
    if (y & 1) res = (res * r) % p;
    y = y >> 1;
    r = (r * r) % p;
  }
  return res;
}
int modInverse(int n, int p) { return power(n, p - 2, p); }
long long int divisionmodulo(long long int a, long long int b,
                             long long int mod) {
  return (a * binpow(b, mod - 2)) % mod;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int countoccurrences(int arr[], int n, int x) {
  int res = 0;
  for (int i = 0; i < n; i++)
    if (x == arr[i]) res++;
  return res;
}
}  // namespace number_theory
using namespace number_theory;
void crossoff(bool* flag, long long int prime, long long int maxi) {
  for (long long int i = prime * prime; i <= maxi; i += prime) {
    flag[i] = false;
  }
}
long long int getnextprime(bool* flag, long long int prime,
                           long long int maxi) {
  int next = prime + 1;
  while (next <= maxi && !flag[next]) {
    next++;
  }
  return next;
}
vector<long long int> sieveoferatosthenes(long long int maxi) {
  bool flag[maxi + 1];
  vector<long long int> primenum;
  primenum.push_back(2);
  flag[0] = false;
  flag[1] = false;
  for (long long int i = 2; i <= maxi; i++) flag[i] = true;
  int prime = 2;
  while (prime <= sqrt(maxi)) {
    crossoff(flag, prime, maxi);
    prime = getnextprime(flag, prime, maxi);
    primenum.push_back(prime);
  }
  return primenum;
}
long long int pair_sum(long long int arr[], long long int size,
                       long long int x) {
  long long int arr_0 = 0;
  long long int arr_1 = size - 1;
  long long int count = 0;
  while (arr_0 < arr_1) {
    if (arr[arr_0] + arr[arr_1] <= x) {
      count = count + (arr_1 - arr_0);
      arr_0++;
    } else {
      arr_1--;
    }
  }
  return count;
}
map<long long int, long long int> xs, ys;
long long int calc(long long int n) {
  long long int calculation = 5 * (binpow(2, n) - 1);
  return calculation;
}
string inttobit(long long int n) {
  string bit = "";
  while (n != 0) {
    char val = 48 + (n % 2);
    bit = bit + val;
    n /= 2;
  }
  return bit;
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string s;
    cin >> s;
    long long int flag = 0;
    long long int arr[n];
    memset(arr, (long long int)0, n * sizeof(long long int));
    set<long long int> element;
    long long int id2 = -1, id3 = -1, id5 = -1, id7 = -1, id1 = -1;
    long long int count2 = 0, count3 = 0, count5 = 0, count7 = 0;
    for (long long int i = 0; i < s.length(); i++) {
      long long int num = s[i] - 48;
      element.insert(num);
      if (num == 1 && id1 == -1) id1 = i;
      if (num == 2 && id2 == -1) id2 = i;
      if (num == 3 && id3 == -1) id3 = i;
      if (num == 5 && id5 == -1) id5 = i;
      if (num == 7 && id7 == -1) id7 = i;
      if (num == 2) count2++;
      if (num == 3) count3++;
      if (num == 5) count5++;
      if (num == 7) count7++;
      if (num == 1) {
        cout << 1 << endl;
        cout << num << endl;
        flag = 1;
        break;
      }
      if (num == 4) {
        cout << 1 << endl;
        cout << num << endl;
        flag = 1;
        break;
      }
      if (num == 6) {
        cout << 1 << endl;
        cout << num << endl;
        flag = 1;
        break;
      }
      if (num == 8) {
        cout << 1 << endl;
        cout << num << endl;
        flag = 1;
        break;
      }
      if (num == 9) {
        cout << 1 << endl;
        cout << num << endl;
        flag = 1;
        break;
      }
    }
    if (flag == 1) continue;
    if (element.find(2) != element.end() && element.find(7) != element.end()) {
      cout << 2 << endl;
      if (id2 < id7)
        cout << 27 << endl;
      else
        cout << 72 << endl;
    } else if (element.find(5) != element.end() &&
               element.find(7) != element.end()) {
      cout << 2 << endl;
      if (id5 > id7)
        cout << 75 << endl;
      else
        cout << 57 << endl;
    } else if (count2 >= 2) {
      cout << 2 << endl;
      cout << 22 << endl;
    } else if (count3 >= 2) {
      cout << 2 << endl;
      cout << 33 << endl;
    } else if (count7 >= 2) {
      cout << 2 << endl;
      cout << 77 << endl;
    } else if (count5 >= 2) {
      cout << 2 << endl;
      cout << 55 << endl;
    } else if (element.find(5) != element.end() &&
               element.find(3) != element.end()) {
      cout << 2 << endl;
      if (id5 > id3) cout << 35 << endl;
    } else if (element.find(2) != element.end() &&
               element.find(3) != element.end()) {
      cout << 2 << endl;
      if (id2 > id3) cout << 32 << endl;
    } else if (element.find(5) != element.end() &&
               element.find(2) != element.end()) {
      cout << 2 << endl;
      if (id2 > id5)
        cout << 52 << endl;
      else
        cout << 25 << endl;
    }
  }
  return 0;
}
