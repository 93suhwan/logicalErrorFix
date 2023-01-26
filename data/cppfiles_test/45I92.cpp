#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC optimize("-O2")
using namespace std;
int mod = 1e9 + 7, gaymod = 998244353, MAX = 1000000000, pomod = 1073741824;
const int N = 2e5 + 5;
const int Z = 1e6 + 5;
int parent[N], ran[N];
void make_set(int v) {
  parent[v] = v;
  ran[v] = 0;
}
int find_set(int v) {
  if (v == parent[v]) return v;
  return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (ran[a] < ran[b]) swap(a, b);
    parent[b] = a;
    if (ran[a] == ran[b]) ran[a]++;
  }
}
template <typename T>
T gcd(T x, T y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
template <typename L>
L lcm(L x, L y) {
  L g = gcd(x, y);
  return x / g * y;
}
long long binexp(long long a, long long b) {
  if (b == 0) return 1;
  long long res = binexp(a, b / 2);
  if (b % 2)
    return ((res % mod) * (res % mod) * (a % mod));
  else
    return ((res % mod) * (res % mod));
}
bool secsort(const pair<char, int> &a, const pair<char, int> &b) {
  return (a.second < b.second);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  mt19937 rng(
      (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
  ;
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    set<int> od;
    set<int> ev;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      arr[i] %= 2;
      if (arr[i])
        od.insert(i);
      else
        ev.insert(i);
    }
    if (od.size() > (n + 1) / 2 || od.size() < n / 2) {
      cout << -1;
    } else {
      long long ans = 0;
      set<int> kutta;
      int cnt = 0;
      bool ok = true;
      for (int i = 0; i < n - 1; i++) {
        if (kutta.find(i) == kutta.end()) {
          if (arr[i] == arr[i + 1]) {
            if (arr[i] == 1) {
              auto it = ev.upper_bound(i);
              if (it == ev.end()) {
                ok = false;
                break;
              }
              if (*it != n - 1) {
                arr[*it] = arr[*it + 1];
                kutta.insert(*it);
              }
              ev.erase(it);
              ans += *it - i - 1 - cnt;
              cnt++;
            } else {
              auto it = od.upper_bound(i);
              if (it == od.end()) {
                ok = false;
                break;
              }
              if (*it != n - 1) {
                arr[*it] = arr[*it + 1];
                kutta.insert(*it);
              }
              ans += *it - i - 1 - cnt;
              od.erase(it);
              cnt++;
            }
          }
        } else
          cnt--;
      }
      if (ok)
        cout << ans;
      else
        cout << -1;
    }
    cout << "\n";
  }
  return 0;
}
