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
void bfs(vector<vector<long long>>& edge, long long start,
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
long long dfs(vector<vector<long long>>& edge, long long start,
              vector<pair<bool, long long>>& visited) {
  long long curr = start;
  visited[curr].first = 1;
  long long ans = -1;
  if (edge[curr].empty()) {
    visited[curr].second = 1;
    return 1;
  }
  for (long long x : edge[curr]) {
    if (!visited[x].first) {
      long long temp = dfs(edge, x, visited);
      if (temp < 0) {
        visited[curr].second = -1;
        return -1;
      }
      if (x < curr) {
        ans = max(ans, temp);
      } else {
        ans = max(ans, temp + 1);
      }
    } else {
      if (visited[x].second < 0) {
        visited[curr].second = -1;
        return -1;
      }
      if (x < curr) {
        ans = max(ans, visited[x].second);
      } else {
        ans = max(ans, visited[x].second + 1);
      }
    }
  }
  visited[curr].second = ans;
  return ans;
}
void solve() {
  long long n;
  cin >> n;
  vector<pair<bool, long long>> visited(n + 1, {0, -1});
  vector<vector<long long>> edge(n + 1);
  long long count = 0;
  for (int i = 1; i <= n; i++) {
    long long k = 0;
    cin >> k;
    bool fg = 1;
    for (int j = 0; j < k; j++) {
      long long temp;
      cin >> temp;
      edge[i].push_back(temp);
      if (!visited[temp].first) {
        fg = 0;
      }
    }
    if (fg) {
      count++;
      visited[i].second = 1;
      visited[i].first = 1;
    }
  }
  if (count == 0) {
    cout << -1 << "\n";
    return;
  }
  long long ans = -1;
  for (int i = 1; i <= n; i++) {
    if (!visited[i].first) {
      long long tempxx = dfs(edge, i, visited);
      if (tempxx < 0) {
        cout << -1 << "\n";
        return;
      }
      ans = max(ans, tempxx);
    } else {
      if (visited[i].second == -1) {
        cout << -1 << "\n";
        return;
      }
      ans = max(ans, visited[i].second);
    }
    if (ans < 0) {
      cout << -1 << "\n";
      return;
    }
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
