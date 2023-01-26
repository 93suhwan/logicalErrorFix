#include <bits/stdc++.h>
using namespace std;
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
const long long inf = 1e18;
const double pi = 3.14159265358979323846264338327950288419716939937510;
const long long mod = 1e9 + 7;
const long long mod2 = 998244353;
const double eps = (0.00000000001);
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  a %= b;
  return gcd(b, a);
}
long long gcdExtended(long long, long long, long long*, long long*);
long long gcdExtended(long long a, long long b, long long* x, long long* y) {
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  long long x1, y1;
  long long gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
long long powerForInverse(long long x, long long y, long long m) {
  if (y == 0) return 1;
  long long temp = powerForInverse(x, y / 2, m);
  temp = (temp * temp) % m;
  if (y & 1) temp = ((temp % m) * (x % m)) % m;
  return temp;
}
long long modInverse(long long a, long long m) {
  return powerForInverse(a, m - 2, m);
}
long long nCr(long long n, long long r) {
  if (r > n) return 0;
  if (r > n - r) r = n - r;
  long long ans = 1;
  for (long long i = 1; i < r + 1; i++) {
    ans *= (n - i + 1);
    ans *= modInverse(i, mod);
  }
  return ans;
}
long long nCrM(long long n, long long r) {
  if (r > n) return 0;
  if (r > n - r) r = n - r;
  long long ans = 1;
  for (long long i = 1; i < r + 1; i++) {
    ans *= (n - i + 1);
    ans %= mod;
    ans *= modInverse(i, mod);
    ans %= mod;
  }
  return ans;
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
long long binpowM(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a % mod;
  long long res = binpowM(a, b / 2) % mod;
  if (b % 2 == 1)
    return (((res * res) % mod) * a) % mod;
  else
    return (res * res) % mod;
}
long long binpow(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long res = binpow(a, b / 2);
  if (b % 2 == 1)
    return (((res * res)) * a);
  else
    return (res * res);
}
void sieve(vector<long long>& primes, long long n, vector<long long>& touched) {
  primes.clear();
  long long arr[n + 1];
  for (long long i = 0; i < n + 1; i++) arr[i] = i;
  touched[0] = true;
  touched[1] = true;
  for (long long i = 2; i < (int)sqrt(n) + 1; i++) {
    if (!touched[i]) {
      touched[i] = true;
      primes.push_back(i);
      for (long long j = i * i; j < n + 1; j++) {
        touched[j] = true;
        j--;
        j += i;
      }
    }
  }
  for (long long i = (int)sqrt(n) + 1; i < n; i++) {
    if (!touched[i]) primes.push_back(i);
  }
}
long long binary_search(long long arr[], long long n, long long elem) {
  long long l = 0, r = n - 1;
  while (r >= l) {
    long long mid = (l + r) / 2;
    if (arr[mid] > elem)
      r = mid - 1;
    else if (arr[mid] < elem)
      l = mid + 1;
    else
      return mid;
  }
  return -1;
}
long long binary_search_vector(vector<long long>& arr, long long elem) {
  long long n = arr.size();
  long long l = 0, r = n - 1;
  while (r >= l) {
    long long mid = (l + r) / 2;
    if (arr[mid] > elem)
      r = mid - 1;
    else if (arr[mid] < elem)
      l = mid + 1;
    else
      return mid;
  }
  return -1;
}
long long factorial(long long n) {
  long long res = 1;
  for (long long i = 2; i < n + 1; i++) res *= i;
  return res;
}
long long factorialM(long long n) {
  long long res = 1;
  for (long long i = 2; i < n + 1; i++) res = (res * i) % mod;
  return res % mod;
}
bool checkPrime(long long n) {
  long long count = 0;
  for (long long i = 2; i < 1 + (long long)sqrt(n); i++) {
    if (n % i == 0) count++;
  }
  if (count > 0)
    return false;
  else
    return true;
}
bool compare(pair<long long, long long> p1, pair<long long, long long> p2) {
  if (p1.second > p2.second)
    return true;
  else if (p1.second == p2.second)
    return p1.first < p2.first;
  else
    return false;
}
class Graph {
 public:
  vector<vector<long long> > adj;
  vector<bool> visited;
  Graph(long long n) {
    adj.resize(n + 1);
    visited.resize(n + 1);
  }
  void addEdge(long long first, long long second, bool directed = false);
  void dfs(long long start);
  void check(long long ans[], long long n);
};
void Graph::addEdge(long long first, long long second, bool directed) {
  adj[first].push_back(second);
  if (!directed) adj[second].push_back(first);
}
void Graph::dfs(long long start) {
  visited[start] = true;
  cout << start << " ";
  for (long long i = 0; i < adj[start].size(); i++) {
    if (!visited[adj[start][i]]) dfs(adj[start][i]);
  }
}
void Graph::check(long long ans[], long long n) {
  for (long long i = 0; i < adj.size(); i++) {
    ans[adj[i].size()]++;
  }
}
long long noOfDigits(long long x) {
  long long digits = 0;
  while (x > 0) {
    x /= 10;
    digits++;
  }
  return digits;
}
long long sumOfDigits(long long n) {
  long long sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
  return a.first < b.first;
}
void reverse(string& str, long long start, long long end) {
  for (long long i = start; i < start + ((end - start + 1) / 2); i++) {
    swap(str[i], str[end + start - i]);
  }
}
long long findGCD(long long arr[], long long n) {
  long long result = arr[0];
  for (int i = 1; i < n; i++) {
    result = gcd(arr[i], result);
    if (result == 1) {
      return 1;
    }
  }
  return result;
}
long long findGCD1(long long arr[], long long n, long long i1, long long i2) {
  long long result;
  if (i1 == 0) {
    result = arr[0] * arr[i2];
  } else {
    result = arr[0];
  }
  for (int i = 1; i < n; i++) {
    if (i == i1) {
      result = gcd(arr[i] * arr[i2], result);
    } else if (i == i2) {
      result = gcd(arr[i] * arr[i1], result);
    } else {
      result = gcd(arr[i], result);
    }
    if (result == 1) {
      return 1;
    }
  }
  return result;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  srand(time(NULL));
  long long t;
  cin >> t;
  for (long long tc = 1; tc <= t; tc++) {
    long long n;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
    };
    sort(arr, arr + n);
    if (n == 1) {
      cout << arr[0] << "\n";
      continue;
    }
    long long ans = INT_MIN;
    ans = max(ans, arr[0]);
    for (long long i = 0; i < n - 1; i++) {
      ans = max(ans, arr[i + 1] - arr[i]);
    }
    cout << ans << "\n";
  }
  return 0;
}
