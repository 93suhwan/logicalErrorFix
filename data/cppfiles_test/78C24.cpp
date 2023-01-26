#include <bits/stdc++.h>
using namespace std;
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
vector<long long> to_binary(long long n) {
  int i = 7;
  vector<long long> ans(8);
  while (n >= 2) {
    ans[i] = n % 2;
    n /= 2;
    i--;
  }
  ans[i] = n;
  return ans;
}
map<long long, long long> primefactorisation(long long n) {
  map<long long, long long> mp;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      mp[i] = 0;
      while (n % i == 0) {
        mp[i]++;
        n /= i;
      }
    }
  }
  if (n > 1) {
    mp[n] = 1;
  }
  return mp;
}
vector<bool> seive(long long n) {
  vector<bool> arr(n + 1, true);
  for (int i = 2; i * i <= n; i++) {
    if (arr[i]) {
      for (int j = i * i; j <= n; j += i) {
        arr[j] = false;
      }
    }
  }
  return arr;
}
long long powM(long long x, long long y) {
  long long ans = 1, r = 1;
  x %= (long long)(1e9 + 7);
  while (r > 0 && r <= y) {
    if (r & y) {
      ans *= x;
      ans %= (long long)(1e9 + 7);
    }
    r <<= 1;
    x *= x;
    x %= (long long)(1e9 + 7);
  }
  return ans;
}
bool isprime(long long x) {
  for (long long i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}
bool cmp(pair<long long, long long> p1, pair<long long, long long> p2) {
  return (p1.first > p2.first);
}
void ipgraph(vector<set<long long>>& edge, long long v, long long e) {
  for (int i = 0; i < e; i++) {
    long long a, b;
    cin >> a >> b;
    edge[a].insert(b);
    edge[b].insert(a);
  }
}
void bfs(vector<vector<long long>> edge, long long start,
         vector<bool>& visited) {
  long long curr = start;
  queue<long long> qq;
  qq.push(curr);
  visited[curr] = 1;
  while (!qq.empty()) {
    curr = qq.front();
    for (long long x : edge[curr]) {
      if (!visited[x]) {
        qq.push(x);
        visited[x] = 1;
      }
    }
    qq.pop();
  }
}
vector<string> bor = {"YES", "NO"};
void solve() {
  long long l, r;
  cin >> l >> r;
  long long diff = r - l;
  if (l * 2 > r) {
    cout << r % l << "\n";
    return;
  }
  long long ans = l - 1;
  long long k = r / 2;
  if (k >= l) {
    long long x = (r - k - 1);
    if (r % 2 == 1) {
      x--;
    }
    long long y = r % (k + 1);
    ans = max(max(ans, x), y);
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
