#include <bits/stdc++.h>
using namespace std;
bool sortcol(const vector<long long> &v1, const vector<long long> &v2) {
  return v1[0] > v2[0];
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long bexp(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long bexpM(long long a, long long b, long long mod) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
const int P = 100000;
int prime[P + 1];
void sieve() {
  prime[0] = 0;
  prime[1] = 0;
  for (int i = 2; i <= P; i++) {
    prime[i] = 1;
  }
  for (int i = 2; i * i <= P; i++) {
    if (prime[i] == 1) {
      for (int j = i * i; j <= P; j += i) {
        prime[j] = 0;
      }
    }
  }
}
int vis[100001];
vector<vector<int>> ar(100001);
void dfs(int v) {
  vis[v] = 1;
  cout << v << "->";
  for (int child : ar[v])
    if (vis[child] == 0) dfs(child);
}
long long C(long long n, long long k) {
  long long res = 1;
  if (k > n - k) k = n - k;
  for (int i = 0; i < k; ++i) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}
long long factorialMOD(long long n, long long m) {
  long long res = 1;
  for (int i = 2; i <= n; i++) res = ((res % m) * (i % m)) % m;
  return res % m;
}
long long factorial(long long n) {
  long long res = 1;
  for (int i = 2; i <= n; i++) res = res * i;
  return res;
}
bool checkperfectsquare(long long n) {
  if (ceil((double)sqrt(n)) == floor((double)sqrt(n))) {
    return true;
  } else {
    return false;
  }
}
vector<long long> divisorsofanum(long long n) {
  vector<long long> v;
  for (int i = 2; i < sqrt(n); i++) {
    if (n % i == 0) {
      v.push_back(i);
      v.push_back(n / i);
    }
  }
  if (checkperfectsquare(n) == 1) {
    v.push_back(sqrt(n));
  }
  return v;
}
void precision(int a) { cout << setprecision(a) << fixed << endl; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<long long> great;
    vector<long long> less;
    for (int i = 0; i < n; i++) {
      if (a[i] < 0)
        less.push_back(a[i]);
      else
        great.push_back(a[i]);
    }
    sort(less.begin(), less.end(), greater<int>());
    sort(great.begin(), great.end());
    vector<long long> stops;
    if (less.size() > 0) {
      long long current = less.size() - 1;
      stops.push_back(-less[current]);
      current -= k;
      while (current >= 0) {
        stops.push_back(-less[current]);
        current -= k;
      }
    }
    if (great.size() > 0) {
      long long current = great.size() - 1;
      stops.push_back(great[current]);
      current -= k;
      while (current >= 0) {
        stops.push_back(great[current]);
        current -= k;
      }
    }
    sort(stops.begin(), stops.end());
    sort(stops.begin(), stops.end());
    long long final = 0;
    for (int i = 0; i < stops.size() - 1; i++) {
      final = final + 2 * stops[i];
    }
    final = final + stops[stops.size() - 1];
    cout << final << endl;
  }
}
