#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <typename T>
inline T lowbit(T x) {
  return x & -x;
}
const int N = 2e5 + 10;
int n;
vector<int> vec;
int tr[N];
int a[N];
void modify(int x) {
  for (int i = x; i <= n; i += lowbit(i)) tr[i]++;
}
int query(int x) {
  int res = 0;
  for (int i = x; i >= 1; i -= lowbit(i)) res += tr[i];
  return res;
}
void init() {
  for (int i = 1; i <= n; ++i) tr[i] = 0;
}
void solve() {
  cin >> n;
  vec.clear();
  init();
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    a[i] = x;
    vec.push_back(x);
  }
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    int p = lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin() + 1;
    int x = query(p - 1);
    int y = query(n) - query(p);
    res += min(x, y);
    modify(p);
  }
  cout << res << endl;
}
int main() {
  int _;
  cin >> _;
  while (_--) solve();
  return 0;
}
