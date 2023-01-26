#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(T& x) {
  cin >> x;
}
template <class H, class... T>
void read(H& h, T&... t) {
  read(h);
  read(t...);
}
template <class A>
void read(vector<A>& x) {
  for (auto& a : x) read(a);
}
template <class H>
void print(vector<H>& x) {
  for (auto& a : x) cout << a << " ";
  cout << endl;
}
template <class P>
void debug(P h) {}
template <class W, class... V>
void debug(W h, V... t) {}
bool checkbitt(long long int num, int pos) { return (num >> pos) & 1; }
long long int setbitt(long long int num, long long int pos) {
  return (1 << pos) | num;
}
long long int resetbitt(long long int num, int pos) {
  if (!checkbitt(num, pos))
    return num;
  else
    return (1 << pos) ^ num;
}
long long int bigmod(long long int a, long long int b, long long int mod) {
  if (b == 0) return 1;
  if (b == 1) return a;
  if (b & 1) {
    return ((a % mod) * (bigmod(a, b - 1, mod) % mod)) % mod;
  }
  long long int x = bigmod(a, b / 2, mod);
  return (x * x) % mod;
}
long long int geti() {
  long long int x;
  read(x);
  return x;
}
long long int cdiv(long long int a, long long int b) {
  long long int ret = a / b;
  if (a % b) ret++;
  return ret;
}
const long long int mod = 1e9 + 7;
const long long int N = 2e5 + 10;
int dx[4] = {+0, +0, +1, -1};
int dy[4] = {-1, +1, +0, +0};
int solve() {
  long long int n, k;
  read(n, k);
  int conn[500];
  for (int i = 0; i < 300; i++) conn[i] = -1;
  vector<pair<int, int> > pairs;
  for (int i = 0; i < k; i++) {
    int x, y;
    read(x, y);
    if (x > y) swap(x, y);
    conn[x] = y;
    conn[y] = x;
    pairs.push_back({x, y});
  }
  vector<int> nc;
  for (int i = 1; i <= 2 * n; i++)
    if (conn[i] == -1) nc.push_back(i);
  int xx = (n - k);
  for (int i = 0, j = xx; i < xx; i++, j++) {
    conn[nc[i]] = nc[j];
    pairs.push_back({nc[i], nc[j]});
  }
  int res = 0;
  for (int i = 0; i < pairs.size(); i++) {
    pair<int, int> a = pairs[i];
    for (int j = i + 1; j < pairs.size(); j++) {
      pair<int, int> b = pairs[j];
      if (a.first > b.first && a.second < b.first &&
          !(a.first > b.second && a.second < b.second))
        res++;
      else if (a.first > b.second && a.second < b.second &&
               !(a.first > b.first && a.second < b.first))
        res++;
      else if (a.second > b.first && a.first < b.first &&
               !(a.second > b.second && a.first < b.second))
        res++;
      else if (a.second > b.second && a.first < b.second &&
               !(a.second > b.first && a.first < b.first))
        res++;
    }
  }
  cout << res << endl;
  return 0;
}
int main(int argc, char* argv[]) {
  if (argc <= 1) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
  }
  int cs = 1, cn = 1;
  read(cs);
  while (cs--) {
    solve();
  }
}
