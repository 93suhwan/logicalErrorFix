#include <bits/stdc++.h>
using namespace std;
bool dcmp(int x, int y) { return x > y; }
bool acmp(int x, int y) { return x < y; }
bool afcmp(pair<int, int> a, pair<int, int> b) { return a.first < b.first; }
bool dfcmp(pair<int, int> a, pair<int, int> b) { return a.first > b.first; }
bool ascmp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
bool dscmp(pair<int, int> a, pair<int, int> b) { return a.second > b.second; }
int aabs(int a) { return a < 0 ? -a : a; }
long long tmax(long long a, long long b, long long c) {
  return max(max(a, b), c);
}
long long tmin(long long a, long long b, long long c) {
  return min(min(a, b), c);
}
bool in_range(int x, int l, int r) { return x >= l && x <= r; }
bool is_prime(int val) {
  if (val == 2) {
    return true;
  }
  if (val % 2 == 0) {
    return false;
  }
  for (int i = 3; i * i <= val; i += 2) {
    if (val % i == 0) {
      return false;
    }
  }
  return true;
}
int lowbit(int x) { return x & (-x); }
inline long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }
inline long long lcm(long long x, long long y) { return x / gcd(x, y) * y; }
const int maxN = 4e4 + 5;
bool finished = false;
int N, a[maxN];
long long ans[maxN];
void reset() {
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    cin >> a[i];
  }
}
void solve() {
  reset();
  if (finished) {
    return;
  }
  long long sum = 0, coeff = 0;
  for (int i = 1; i <= N; ++i) {
    sum += a[i];
    coeff += i;
  }
  if (sum % coeff != 0) {
    cout << "NO" << '\n';
    return;
  } else {
    sum /= coeff;
  }
  for (int i = 1; i <= N; ++i) {
    int diff = a[i] - a[i == 1 ? N : i - 1];
    long long x = sum - diff;
    if (x % N == 0 && x / N > 0) {
      ans[i] = x / N;
    } else {
      cout << "NO" << '\n';
      return;
    }
  }
  cout << "YES" << '\n';
  for (int i = 1; i <= N; ++i) {
    cout << ans[i] << " ";
  }
  cout << '\n';
}
int main(void) {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
