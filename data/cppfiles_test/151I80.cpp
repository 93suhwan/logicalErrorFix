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
long long mod_exp(long long x, long long y, long long p) {
  long long ans = 1LL, r = 1LL;
  x %= p;
  while (r > 0 && r <= y) {
    if (r & y) {
      ans *= x;
      ans %= p;
    }
    r <<= 1;
    x *= x;
    x %= p;
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
vector<long long> bfs(vector<vector<long long>>& edge, long long start,
                      long long n) {
  long long curr = start;
  vector<bool> visited(n + 1, 0);
  vector<long long> lvl(n + 1);
  lvl[curr] = 0;
  queue<long long> qq;
  qq.push(curr);
  visited[curr] = 1;
  while (!qq.empty()) {
    curr = qq.front();
    for (long long x : edge[curr]) {
      if (!visited[x]) {
        lvl[x] = 1 + lvl[curr];
        qq.push(x);
        visited[x] = 1;
      }
    }
    qq.pop();
  }
  return lvl;
}
vector<string> bor = {"YES", "NO"};
void solve() {
  long long n;
  cin >> n;
  long long k, x;
  cin >> k >> x;
  string s;
  cin >> s;
  string ans;
  ans.push_back(s[0]);
  vector<long long> arr;
  long long count = 0;
  if (s[0] == '*')
    count = (k + 1);
  else {
    arr.push_back(1);
  }
  for (int i = 1; i < n; i++) {
    if (s[i] == 'a') {
      if (s[i - 1] == '*') {
        arr.push_back(count);
      }
      ans.push_back(s[i]);
      count = 1;
      arr.push_back(1);
    } else {
      if (s[i] == s[i - 1])
        count += (k);
      else {
        ans.push_back(s[i]);
        count = k + 1;
      }
    }
  }
  if (count > 0) {
    arr.push_back(count);
  }
  n = ans.size();
  s = ans;
  ans.clear();
  vector<long long> dp(n, 1LL);
  dp[n - 1] = max(arr[n - 1], 1LL);
  for (int i = n - 2; i >= 0; i--) {
    if ((dp[i] * (arr[i])) > ((long long)(1e18))) {
      dp[i] = (long long)(1e18);
    } else {
      dp[i] = (dp[i + 1] * (arr[i]));
    }
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == 'a') {
      ans.push_back(s[i]);
    } else {
      if (i < n - 1) {
        long long temp = dp[i + 1];
        bool fg = 1;
        while (x > 0) {
          if (fg) {
            fg = 0;
            if (x - (temp) <= 0) break;
          } else {
            ans.push_back('b');
            if (x - (temp) <= 0) break;
          }
          x -= temp;
          arr[i]--;
        }
        if (x == 0) {
          for (int j = i + 1; j < n; j++) {
            if (s[j] == 'a') ans.push_back(s[j]);
          }
          cout << ans << "\n";
          return;
        }
      } else {
        x--;
        while (x > 0) {
          ans.push_back('b');
          x--;
        }
        cout << ans << "\n";
        return;
      }
    }
  }
  cout << ans << "\n";
  return;
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
