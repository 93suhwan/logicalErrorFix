#include <bits/stdc++.h>
using namespace std;
const long long int M = 1000000007;
long long int fact[200001] = {}, smallestPrimeFactor[200001] = {},
              isPrimeSieve[200001] = {};
mt19937_64 my_rand(chrono::steady_clock::now().time_since_epoch().count());
inline bool comp(long long int x, long long int y) { return x < y; }
inline long long int mod(long long int x) {
  long long int a1 = (x % M);
  if (a1 < 0) {
    a1 += M;
  }
  return a1;
}
inline long long int power(long long int x, unsigned long long int y,
                           long long int p = LLONG_MAX) {
  long long int res = 1;
  x = x % p;
  if (x == 0) {
    return 0;
  }
  while (y > 0) {
    if (y & 1) {
      res = (res * x) % p;
    }
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
inline long long int inversePrimeModular(long long int a, long long int p) {
  return power(a, p - 2, p);
}
inline void calcFact(long long int n) {
  fact[0] = 1;
  for (long long int i = 1; i <= n; i++) {
    fact[i] = fact[i - 1] * i;
    fact[i] = mod(fact[i]);
  }
}
inline long long int ncr(long long int n, long long int r) {
  if (n < r) return 0;
  return mod(inversePrimeModular(mod(fact[n - r] * fact[r]), M) * fact[n]);
}
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
void sieve(long long int n) {
  for (long long int i = 1; i <= n; i++) smallestPrimeFactor[i] = i;
  for (long long int i = 2; (i * i) <= n; i++) {
    if (smallestPrimeFactor[i] == i) {
      for (long long int j = (i * i); j <= n; j += i) {
        smallestPrimeFactor[j] = min(smallestPrimeFactor[j], i);
      }
    }
  }
  for (long long int i = 2; i <= n; i++) {
    if (smallestPrimeFactor[i] == i) isPrimeSieve[i] = 1;
  }
}
class Union {
 public:
  vector<long long int> _rank, par, leader;
  Union(long long int n) {
    _rank.assign(n + 1, 1);
    par.assign(n + 1, 0);
    leader.assign(n + 1, 0);
    for (long long int i = 0; i <= n; i++) {
      par[i] = i;
      leader[i] = i;
    }
  }
  long long int find(long long int a) {
    if (a == par[a]) return a;
    return par[a] = find(par[a]);
  }
  void merge(long long int a, long long int b) {
    a = find(a);
    b = find(b);
    if (_rank[a] < _rank[b]) swap(a, b);
    par[b] = a;
    _rank[a] += _rank[b];
    leader[a] = findLeader(a);
    leader[b] = findLeader(b);
  }
  long long int findLeader(long long int a) {
    a = find(a);
    return leader[a];
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, m, q;
  cin >> n >> m >> q;
  vector<pair<long long int, long long int>> vect;
  long long int sum = 0;
  for (long long int i = 0; i < n + m; i++) {
    long long int x;
    cin >> x;
    if (i < n)
      vect.push_back({x, 1}), sum += x;
    else
      vect.push_back({x, 0});
  }
  sort((vect).begin(), (vect).end());
  vector<long long int> pre(n + m, 0);
  pre[0] = vect[0].first;
  for (long long int i = 1; i < n + m; i++) {
    pre[i] = pre[i - 1] + vect[i].first;
  }
  vector<pair<long long int, long long int>> queries(q);
  for (long long int i = 0; i < queries.size(); i++) {
    cin >> queries[i].first;
    queries[i].second = i;
  }
  sort((queries).begin(), (queries).end());
  priority_queue<pair<long long int, long long int>,
                 vector<pair<long long int, long long int>>,
                 greater<pair<long long int, long long int>>>
      pq;
  for (long long int i = 1; i < n + m; i++) {
    long long int diff = vect[i].first - vect[i - 1].first;
    pq.push({diff, i});
  }
  Union u1(n + m);
  vector<long long int> ans(q);
  vector<long long int> val(n + m, 0);
  vector<long long int> sz(n + m, 0);
  for (long long int i = 0; i < vect.size(); i++) {
    if (vect[i].second == 1) {
      val[i] = vect[i].first;
      sz[i] = 1;
    }
  }
  for (long long int i = 0; i < queries.size(); i++) {
    long long int k = queries[i].first;
    while (pq.size() > 0 && (pq.top().first) <= k) {
      long long int left = pq.top().second - 1;
      long long int right = u1.findLeader(left + 1);
      u1.merge(left, right);
      long long int siz = sz[left] + sz[right];
      sz[right] = siz;
      sum -= val[left] + val[right];
      val[right] = pre[right] - pre[right - siz];
      sum += val[right];
      pq.pop();
    }
    ans[queries[i].second] = sum;
  }
  for (auto i : ans) {
    cout << i << "\n";
  }
  cerr << fixed << setprecision(10);
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
       << "\n";
  return 0;
}
