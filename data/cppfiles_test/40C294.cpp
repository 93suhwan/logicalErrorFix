#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int cats[100001];
bool vis[100001] = {};
vector<int> edges[100001];
long long ans = 0, m;
long long digi(long long n1, long long n2) {
  long long f = 0;
  while (n1 > 0) {
    n1 /= n2;
    f++;
  }
  return f;
}
bool isPrime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i < n; i++)
    if (n % i == 0) return false;
  return true;
}
void dfs(long long src, long long cnt) {
  if (cats[src] == 1)
    cnt++;
  else
    cnt = 0;
  if (cnt > m) return;
  vis[src] = true;
  for (auto ver : edges[src]) {
    if (!vis[ver])
      dfs(ver, cnt);
    else if (vis[ver] == true && edges[src].size() == 1)
      ans++;
  }
}
long long int c2(long long int n) { return (n * (n - 1)) / 2; }
long long SieveOfEratosthenes(long long n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (long long p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  long long f = 1;
  for (int p = 2; p <= n; p++) {
    if (prime[p] == true && p * 2 > n) {
      f++;
    }
  }
  return f;
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
void print(int n) {
  long long i = 0, sum = 0;
  for (i = 0; i < n; i++) {
    sum += i;
  }
  cout << sum << " ";
}
const int N = 2e5 + 5;
int cnt[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long i, n, m1, l1 = 0, n2, l2 = 0;
    cin >> n;
    vector<long long> v;
    long long a[n + 3], b[n + 3];
    for (i = 0; i < n; i++) cin >> a[i];
    for (i = 0; i < n; i++) {
      cin >> b[i];
      l1 += b[i];
    }
    l1 -= b[n - 1];
    v.push_back(l1);
    for (i = n - 2; i >= 0; i--) {
      l1 -= b[i];
      l2 += a[i + 1];
      v.push_back(max(l1, l2));
    }
    sort(v.begin(), v.end());
    cout << v[0] << endl;
  }
}
