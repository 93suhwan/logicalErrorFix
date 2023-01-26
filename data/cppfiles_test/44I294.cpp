#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
void rotate(vector<int> arr, int n) {
  int x = arr[n - 1], i;
  for (i = n - 1; i > 0; i--) arr[i] = arr[i - 1];
  arr[0] = x;
}
void showlist(list<int> g) {
  list<int>::iterator it;
  for (it = g.begin(); it != g.end(); it++) cout << *it << " ";
  cout << "\n";
}
bool compare_function(string &s1, string &s2) {
  return (s1.length() > s2.length());
}
void showvec(vector<int> v) {
  vector<int>::iterator it;
  for (it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
}
void showset(set<int> s) {
  set<int>::iterator it;
  for (it = s.begin(); it != s.end(); it++) {
    cout << *it << " ";
  }
}
void swap(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
}
bool isPrime(int n) {
  for (int i = 2; i <= n / 2; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int findNextPrime(int n) {
  int nextPrime = n;
  bool found = false;
  while (!found) {
    nextPrime++;
    if (isPrime(nextPrime)) found = true;
  }
  return nextPrime;
}
int largest(int arr[], int n) { return *max_element(arr, arr + n); }
bool isPerfectSquare(long double x) {
  if (x >= 0) {
    long long sr = sqrt(x);
    return (sr * sr == x);
  }
  return false;
}
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
template <class T>
T gcd(T a, T b) {
  while (a != 0) {
    T temp = a;
    a = b % a;
    b = temp;
  }
  return b;
}
template <class T>
T egcd(T a, T b, T &x, T &y) {
  T gcd, xt, yt;
  if (a == 0) {
    gcd = b;
    x = 0, y = 1;
  } else {
    gcd = egcd(b % a, a, xt, yt);
    x = yt - (b / a) * xt;
    y = xt;
  }
  return gcd;
}
template <class T>
T expo(T base, T exp, T mod) {
  T res = 1;
  base = base % mod;
  while (exp > 0) {
    if (exp & 1) res = (res * base) % mod;
    exp = exp >> 1;
    base = (base * base) % mod;
  }
  return res;
}
template <class T>
T modinv(T a, T mod) {
  T x, y;
  egcd<T>(a, mod, x, y);
  while (x < 0) x += mod;
  while (x >= mod) x -= mod;
  return x;
}
template <class T>
T modinvfermat(T a, T mod) {
  return expo<T>(a, mod - 2, mod);
}
template <class T>
bool rev(T a, T b) {
  return a > b;
}
template <class T>
long long maxpower(T a, T b) {
  long long ans = 0;
  while (a > 0 && a % b == 0) {
    ans++;
    a /= b;
  }
  return ans;
}
template <class T>
T mceil(T a, T b) {
  if (a % b == 0)
    return a / b;
  else
    return a / b + 1;
}
template <class T>
T lcm(T a, T b) {
  return (a * b) / gcd<T>(a, b);
}
const long long infl = 1e18;
const int inf = 1e9 + 5;
int subsetsum(vector<long long> &v, long long n, long long sum) {
  int dp[n + 1][sum + 1];
  dp[0][0] = 1;
  for (long long i = (long long)(1); i < (long long)(n + 1); i++) {
    dp[i][0] = 1;
  }
  for (long long i = (long long)(1); i < (long long)(sum + 1); i++) {
    dp[0][i] = 0;
  }
  for (long long i = (long long)(1); i < (long long)(n + 1); i++) {
    for (long long j = (long long)(1); j < (long long)(sum + 1); j++) {
      if (v[i - 1] > j) {
        dp[i][j] = dp[i - 1][j];
      } else {
        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - v[i - 1]];
      }
    }
  }
  return dp[n][sum];
}
void dfs(int s, vector<int> g[], bool *vis) {
  vis[s] = true;
  cout << s << " ";
  for (int i = (int)(0); i < (int)g[s].size(); i++) {
    if (vis[g[s][i]] == false) {
      dfs(g[s][i], g, vis);
    }
  }
}
void bfs(int s, vector<int> adj[], bool vis[], int N) {
  queue<int> q;
  q.push(s);
  vis[s] = true;
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    cout << curr << " ";
    for (int i = (int)(0); i < (int)adj[curr].size(); i++) {
      if (vis[adj[curr][i]] == false) {
        q.push(adj[curr][i]);
        vis[adj[curr][i]] == true;
      }
    }
  }
}
int mincoin(vector<long long> &v, int n, int sum) {
  int dp[n + 1][sum + 1];
  for (long long i = (long long)(0); i < (long long)(n + 1); i++) {
    for (long long j = (long long)(0); j < (long long)(sum + 1); j++) {
      if (j == 0) {
        dp[i][j] = 0;
      } else if (i == 0) {
        dp[i][j] = INT_MAX - 1;
      } else if (v[i - 1] <= j) {
        dp[i][j] = min(1 + dp[i][j - v[i - 1]], dp[i - 1][j]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  return dp[n][sum] > INT_MAX - 1 ? -1 : dp[n][sum];
}
void solve() {
  long long c, d;
  cin >> c >> d;
  if (c > 0 && d > 0 && c == d) {
    cout << 1;
  } else if (c == 0 && d == 0) {
    cout << 0;
  } else if (c == 0 || d == 0) {
    cout << 2;
  } else if (abs(c - d) > 1) {
    cout << 2;
  } else
    cout << -1;
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  auto start = high_resolution_clock::now();
  cout << setprecision(15);
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  return 0;
}
