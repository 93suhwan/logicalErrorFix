#include <bits/stdc++.h>
using namespace std;
void solve(int);
void queries() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) solve(i);
}
long long ceildiv(long long a, long long b) { return a / b + !!(a % b); }
template <class T>
T gcd(T a, T b) {
  return (b ? gcd(b, a % b) : a);
}
template <class T>
T lcm(T a, T b) {
  return a * b / gcd(a, b);
}
const int maxn = 200200;
const double pi = 3.14159265359;
const long long mod = 1000000007;
const long long hash_p = 101;
const long long hash_inv = 940594066;
const int ddx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int ddy[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
bool comp(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first != b.first) {
    return a.first < b.first;
  }
  return a.second > b.second;
}
template <class T>
class bit {
 private:
  vector<T> arr;
  int n;

 public:
  bit() {
    int maxval = 302;
    n = maxval;
    arr.resize(maxval);
  }
  void update(int pos, T val) {
    for (int i = pos; i < n; i += (i & -i)) {
      arr[i] += val;
    }
  }
  T query(int k) {
    T s = 0;
    for (int i = k; i >= 1; i -= (i & -i)) {
      s += arr[i];
    }
    return s;
  }
};
void solve(int id) {
  int n, m;
  cin >> n >> m;
  vector<long long> a(m * n + 1);
  vector<long long> srt(m * n + 1);
  vector<long long> pos(n * m + 1);
  map<long long, queue<long long> > mp;
  bit<long long> bt[302];
  for (int i = 1; i <= n * m; i++) {
    cin >> a[i];
    srt[i] = a[i];
    mp[a[i]].push(i);
  }
  sort(srt.begin(), srt.end());
  for (int i = 0; i < n; i++) {
    long long l = i * m + 1, r = (i + 1) * m;
    for (long long i = r; i >= l; i--) {
      int el = mp[srt[i]].front();
      mp[srt[i]].pop();
      pos[el] = i;
    }
  }
  long long rs = 0;
  for (int i = 1; i <= n * m; i++) {
    long long x = (pos[i] - 1) / m;
    long long y = (pos[i] - 1) % m;
    x++;
    y++;
    rs += bt[x].query(y - 1);
    bt[x].update(y, 1);
  }
  cout << (rs) << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << (fixed);
  cout << (setprecision(10));
  queries();
  return 0;
}
