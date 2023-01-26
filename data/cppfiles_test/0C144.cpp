#include <bits/stdc++.h>
using namespace std;
long long int M = 1000000007;
long long int Boostpower(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int binarySearch(long long int arr[], long long int l,
                           long long int r, long long int x) {
  while (l <= r) {
    long long int m = l + (r - l) / 2;
    if (arr[m] == x) return m;
    if (arr[m] < x)
      l = m + 1;
    else
      r = m - 1;
  }
  return -1;
}
bool sortbysec(const pair<long long int, long long int> &a,
               const pair<long long int, long long int> &b) {
  return (a.second < b.second);
}
long long int Stoi(string s) {
  stringstream geek(s);
  long long int x = 0;
  geek >> x;
  return x;
}
long long int maxPrimeFactors(long long int n) {
  long long int maxPrime = -1;
  while (n % 2 == 0) {
    maxPrime = 2;
    n >>= 1;
  }
  for (long long int i = 3; i <= sqrt(n); i += 2) {
    while (n % i == 0) {
      maxPrime = i;
      n = n / i;
    }
  }
  if (n > 2) maxPrime = n;
  return maxPrime;
}
long long int leastdev(long long int n) {
  for (long long int i = 1; i <= n; i++) {
    if (n % i == 0) {
      return i;
    }
  }
  return 0;
}
bool isPrime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long int checkperfectsquare(long long int n) {
  if (ceil((double)sqrtl(n)) == floor((double)sqrtl(n))) {
    return 1;
  } else {
    return -1;
  }
}
long long int Ceil(long long int a, long long int b) {
  if (a < 0 || b < 0) {
    return a / b;
  }
  if (a % b) {
    return a / b + 1;
  }
  return a / b;
}
void primecount(long long int n) {
  map<long long int, long long int> mp;
  if (isPrime(n)) {
    mp[n] = 1;
  }
  long long int count = 0;
  while (!(n % 2)) {
    n >>= 1;
    count++;
  }
  if (count) {
    mp[2] = count;
  }
  for (long long i = 3; i <= sqrt(n); i += 2) {
    count = 0;
    while (n % i == 0) {
      count++;
      n = n / i;
    }
    if (count) {
      mp[i] = count;
    }
  }
  if (n > 2) {
    mp[n] = 1;
  }
}
void rotate(vector<long long int> &vec, long long int d) {
  if (d == 0) return;
  for (long long int i = 0; i < d; i++) {
    vec.push_back(vec[0]);
    vec.erase(vec.begin());
  }
}
long long int binpow(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long int mx = 2e5 + 5;
vector<long long int> fact(mx, 1), inv(mx, 1);
void precompute() {
  fact[0] = inv[0] = 1;
  fact[1] = inv[1] = 1;
  for (long long int i = 2; i < mx; i++) {
    fact[i] = i * fact[i - 1];
    fact[i] %= M;
    long long int inverse = binpow(i, M - 2);
    inverse %= M;
    inv[i] = inv[i - 1] * inverse;
    inv[i] %= M;
  }
}
long long int ncr(long long int n, long long int r) {
  long long int ans = (fact[n] * inv[n - r]);
  ans %= M;
  ans *= inv[r];
  ans %= M;
  ans += M;
  ans %= M;
  return ans;
}
long long int andOperator(long long int x, long long int y) {
  for (long long int i = 0; i < (long long int)log2(y) + 1; i++) {
    if (y <= x) {
      return y;
    }
    if (y & (1 << i)) {
      y &= ~(1UL << i);
    }
  }
  return y;
}
long long int ask(long long int l, long long int r) {
  cout << "? ";
  cout << l;
  cout << " ";
  cout << r;
  cout << endl;
  cout.flush();
  long long int x;
  cin >> x;
  return x;
}
long long int rangeSum(long long int i, long long int j, long long int pre[]) {
  if (i == 0) return pre[j];
  return pre[j] - pre[i - 1];
}
void output(long long int ans) {
  cout << "! ";
  cout << ans;
  cout << endl;
  cout.flush();
}
bool matching(char a, char b) {
  return ((a == '(' && b == ')') || (a == '[' && b == ']') ||
          (a == '{' && b == '}'));
}
bool comparator(pair<long long int, string> p1,
                pair<long long int, string> p2) {
  string s1 = p1.second;
  string s2 = p2.second;
  for (long long int i = 0; i < s1.size(); i++) {
    if (s1[i] != s2[i]) {
      long long int v1 = s1[i] - '0';
      long long int v2 = s2[i] - '0';
      if (i % 2) {
        if (v2 > v1) {
          return false;
        } else {
          return true;
        }
      } else {
        if (v1 > v2) {
          return false;
        } else {
          return true;
        }
      }
    }
  }
  return false;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  t = 1;
  string alphabet = "abcdefghijklmnopqrstuvwxyz";
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    vector<pair<long long int, string>> vp;
    for (long long int i = 0; i < n; i++) {
      string s1;
      cin >> s1;
      vp.push_back({i, s1});
    }
    sort(vp.begin(), vp.end(), comparator);
    for (auto x : vp) {
      cout << x.first + 1 << " ";
    }
    cout << "\n";
  }
}
