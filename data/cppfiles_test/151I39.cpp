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
class stk {
 public:
  long long parent;
};
class Dsu {
 public:
  unordered_map<long long, stk> parent;
  void init(long long x) {
    stk temp;
    temp.parent = x;
    parent[x] = temp;
  }
  long long find(long long x) {
    if (parent[x].parent == x) {
      return x;
    }
    return (parent[x].parent = find(parent[x].parent));
  }
  void Union(long long x, long long y, bool f) {
    long long p1 = find(x);
    long long p2 = find(y);
    if (p1 == p2) {
      return;
    }
    parent[y].parent = p1;
  }
};
void solve() {
  long long q;
  cin >> q;
  long long count = 0;
  vector<long long> arr(600001);
  vector<pair<long long, long long>> brr(600001, {-1, -1});
  while (q--) {
    long long k;
    cin >> k;
    if (k == 2) {
      long long x, y;
      cin >> x >> y;
      brr[count] = {x, y};
      count++;
    } else {
      long long x;
      cin >> x;
      arr[count] = x;
      count++;
    }
  }
  vector<long long> ans;
  Dsu ds;
  for (int i = 1; i <= 500000; i++) ds.init(i);
  for (int i = count - 1; i >= 0; i--) {
    long long xx = brr[i].first;
    if (xx != -1) {
      ds.Union(brr[i].second, brr[i].first, 1);
    } else {
      long long p = arr[i];
      p = ds.find(p);
      ans.push_back(p);
    }
  }
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
