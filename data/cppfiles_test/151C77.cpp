#include <bits/stdc++.h>
using namespace std;
constexpr long long MAXX = 2e18;
constexpr long double EPS = 1e-9;
constexpr long long P = 1000000007;
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
template <typename T>
ostream& operator<<(ostream& output, const vector<T>& data) {
  for (const T& x : data) output << x << " ";
  return output;
}
template <typename T>
istream& operator>>(istream& input, vector<T>& data) {
  for (auto& item : data) {
    input >> item;
  }
  return input;
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
vector<long long> lp;
vector<long long> seive_op(long long n) {
  vector<long long> prime;
  lp.assign(n + 1, 0);
  long long m = 0;
  for (int i = 2; i <= n; i++) {
    if (lp[i] == 0) {
      lp[i] = i;
      prime.push_back(i);
      m++;
    }
    for (int j = 0; (j < m) && (prime[j] <= lp[i]) && (i * prime[j] <= n);
         j++) {
      lp[i * prime[j]] = prime[j];
    }
  }
  return prime;
}
map<long long, long long> primefactorisation(long long n) {
  map<long long, long long> mp;
  while (n != 1) {
    mp[lp[n]]++;
    n /= (lp[n]);
  }
  return mp;
}
long long mod_exp(long long x, long long y, long long p) {
  long long ans = 1LL, r = 1LL;
  x %= p;
  while (r > 0 && r <= y) {
    if (r & y) {
      ans *= x;
      ans %= p;
    }
    r = (r << 1LL);
    x *= x;
    x %= p;
  }
  return ans;
}
long long mod_inv(long long n, long long p) { return mod_exp(n, p - 2LL, p); }
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
vector<long long> fact;
void pre_fermat() {
  fact.assign(1000001, 1);
  fact[0] = 1;
  for (int i = 1; i <= (1000000); i++) {
    fact[i] = mod_mul(fact[i - 1], i, P);
  }
}
long long ncr(long long n, long long r, long long p) {
  if (n < r) {
    return 0LL;
  }
  if (r == 0) {
    return 1LL;
  }
  return (fact[n] * mod_inv(fact[r], p) % p * mod_inv(fact[n - r], p) % p) % p;
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
void dfs(vector<vector<long long>>& edge, long long curr, long long prev) {
  for (long long x : edge[curr]) {
    if (x != prev) {
      dfs(edge, x, curr);
    }
  }
}
vector<string> bor = {"YES", "NO"};
class stk {
 public:
  long long parent;
  long long rank;
};
class Dsu {
 public:
  unordered_map<long long, stk> parent;
  void init(long long x) {
    stk temp;
    temp.parent = x;
    temp.rank = 0;
    parent[x] = temp;
  }
  long long find(long long x) {
    if (parent[x].parent == x) {
      return x;
    }
    return (parent[x].parent = find(parent[x].parent));
  }
  void Union(long long x, long long y) {
    long long p1 = find(x);
    long long p2 = find(y);
    if (p1 == p2) {
      return;
    }
    if (parent[p1].rank >= parent[p2].rank) {
      parent[p2].parent = p1;
      parent[p1].rank++;
    } else {
      parent[p1].parent = p2;
      parent[p2].rank++;
    }
  }
};
void solve() {
  vector<long long> ans;
  long long q;
  cin >> q;
  vector<pair<long long, pair<long long, long long>>> arr(q);
  for (int i = 0; i < q; i++) {
    long long a;
    cin >> a;
    arr[i].first = a;
    if (a == 1) {
      long long b;
      cin >> b;
      arr[i].second.first = b;
    } else {
      long long x, y;
      cin >> x >> y;
      arr[i].second = {x, y};
    }
  }
  vector<long long> paint(500001);
  for (int i = 1; i <= (500000); i++) paint[i] = i;
  for (int i = q - 1; i >= 0; i--) {
    if (arr[i].first == 1) {
      long long temp = arr[i].second.first;
      ans.push_back(paint[temp]);
    } else {
      long long x = arr[i].second.first;
      long long y = arr[i].second.second;
      paint[x] = paint[y];
    }
  }
  reverse(ans.begin(), ans.end());
  cout << ans << "\n";
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
