#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using dl = double;
using ld = long double;
using ull = unsigned long long;
const long N = 3e5 + 10;
const long maxn = 5e5 + 10;
ll aarray[N];
ll magic[510][510];
vector<ll> primes;
bool check[1000001];
ll large[10000005];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
ll vis[N];
map<ll, ll> mp;
void solve() {
  ll i, j, k, m, n, l, r, q, p, ans, sum = 0;
  string str;
  bool yes = true;
  vector<ll> v;
  cin >> n;
  l = 1;
  ll col = 0;
  ll pre = 0;
  while (sum < n) {
    col++;
    sum += l;
    l += 2;
  }
  if (sum == n) {
    cout << col << " " << 1 << "\n";
    return;
  }
  pre = sum - (l - 2);
  if (pre + col == n) {
    cout << col << " " << col << "\n";
    return;
  }
  if (pre + col > n) {
    cout << n - pre << " " << col << "\n";
    return;
  }
  pre += col;
  ll dif = n - pre;
  cout << col << " " << col - dif << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string str;
  ll i, j, n, m, k, t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
