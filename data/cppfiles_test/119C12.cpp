#include <bits/stdc++.h>
using namespace std;
vector<bool> seive;
int fact[100005];
int powerr[100005];
int mod = (int)(1e9 + 7);
long long powerf(long long a, long long b, long long mod);
void precomputeFactorial() {
  fact[0] = 1;
  fact[1] = 1;
  powerr[0] = 1;
  for (int i = 1; i <= 100005; i++) {
    fact[i] = i * fact[i - 1];
    powerr[i] = powerf(i, mod - 2, mod);
  }
}
int nCr(int n, int r) { return fact[n] / (fact[r] * fact[n - r]); }
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long powerf(long long a, long long b, long long mod) {
  if (b == 0) {
    return 1;
  }
  if (b % 2 == 0) {
    return powerf((a * a) % mod, b / 2, mod);
  }
  return (a * powerf((a * a) % mod, b / 2, mod)) % mod;
}
bool cmp(pair<int, int> p1, pair<int, int> p2) {
  if (p1.first < p2.first) {
    return true;
  } else if (p1.first == p2.first) {
    if (p1.second < p2.second) return true;
    return false;
  }
  return false;
}
int minChanges(string a, string b) {
  int i = 0;
  int j = 0;
  int same = 0;
  while (i < a.size() && j < b.size()) {
    if (a[i] == b[j]) {
      i++;
      j++;
      same += 2;
    } else {
      i++;
    }
  }
  return a.size() + b.size() - same;
}
bool isPrime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return false;
  return true;
}
void dfs(vector<int> adj[], int src, vector<bool> &isInc) {
  isInc[src] = true;
  for (int x : adj[src]) {
    if (isInc[x] == false) {
      dfs(adj, x, isInc);
    }
  }
}
bool isPerfectSquare(int b) {
  if (float(log2(b)) == ceil(log2(b))) {
    return true;
  }
  return false;
}
const int N = 3 * 1e5;
int xor_arr[N + 10];
void precompute() {
  xor_arr[0] = 0;
  for (int i = 1; i <= N + 5; i++) xor_arr[i] = (i ^ xor_arr[i - 1]);
}
bool comparator(pair<int, int> p1, pair<int, int> p2) {
  if (p1.first > p2.first) {
    return true;
  } else if (p1.first == p2.first) {
    if (p1.second < p2.second) {
      return true;
    } else {
      return false;
    }
  }
  return false;
}
bool comp(string s1, string s2) { return s1 + s2 < s2 + s1; }
bool isPossible(long long mid, long long arr[], long long n, long long h) {
  for (int i = 0; i < n - 1; i++) {
    h -= min(arr[i + 1] - arr[i], mid);
  }
  h -= mid;
  return h <= 0;
}
void solve() {
  int n;
  cin >> n;
  int arr[n];
  long long s = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    s += arr[i];
  }
  if (s % n == 0) {
    cout << 0 << endl;
  } else {
    cout << 1 << endl;
  }
}
signed main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
