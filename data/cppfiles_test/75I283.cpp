#include <bits/stdc++.h>
using namespace std;
void speed() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int msb(long long int n) {
  long long int t = -1;
  while (n) {
    n = n >> 1;
    ++t;
  }
  return t;
}
bool isPrime(long long int n) {
  for (long long int i = 2; i * i < n; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}
const long long int mod = 1e9 + 7;
long long int mypow(long long int a, long long int b) {
  long long int ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % mod;
    b /= 2;
    a = (ans * a) % mod;
  }
  return ans;
}
class comp {
 public:
  bool operator()(const pair<long long int, long long int>& p1,
                  const pair<long long int, long long int>& p2) {
    return p1.first > p2.first;
  }
};
bool is(long long int* a, long long int n, long long int x) {
  if (x != -1) {
    long long int t = a[x + 1];
    a[x + 1] = a[x];
    a[x] = t;
  }
  for (long long int i = 1; i < n; ++i) {
    if (a[i + 1] < a[i]) return false;
  }
  return true;
}
void solve() {
  long long int n;
  cin >> n;
  vector<vector<long long int>> grid(n);
  for (long long int i = 0; i < n; ++i) {
    long long int x;
    cin >> x;
    for (long long int j = 0; j < x; ++j) {
      long long int t;
      cin >> t;
      grid[i].push_back(t);
    }
  }
  vector<pair<long long int, long long int>> intervals;
  for (long long int i = 0; i < n; ++i) {
    long long int maxNum = INT_MIN;
    long long int ind;
    for (long long int j = 0; j < grid[i].size(); ++j) {
      if (grid[i][j] > maxNum) {
        maxNum = grid[i][j];
        ind = j;
      }
    }
    long long int t = maxNum - ind + 1;
    intervals.push_back({t, t + grid[i].size()});
  }
  sort(intervals.begin(), intervals.end());
  vector<long long int> left, right;
  for (long long int i = 0; i < intervals.size(); ++i) {
    left.push_back(intervals[i].first);
    right.push_back(intervals[i].second);
  }
  long long int c = left.size() - 1;
  while (true) {
    long long int x =
        lower_bound(right.begin(), right.end(), left[c]) - right.begin();
    if (x == c) {
      cout << left[c];
      break;
    }
    c = x;
  }
}
int main() {
  speed();
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
};
