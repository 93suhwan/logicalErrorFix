#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 998244353;
int binarySearch(int arr[], int l, int r, int x) {
  if (r >= l) {
    int mid = l + (r - l) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
    return binarySearch(arr, mid + 1, r, x);
  } else {
    return -1;
  }
}
ll power(ll x, ll y, int p) {
  ll res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
const int N = 200000;
int cnt[N][5];
void solve() {
  int n;
  cin >> n;
  for (int i = (0); i < (n); i++) {
    string s;
    cin >> s;
    for (int j = (0); j < (5); j++) {
      cnt[i][j] = 0;
    }
    for (int j = (0); j < (s.size()); j++) {
      cnt[i][int(s[j] - 'a')]++;
    }
  }
  int ans = 0;
  for (int i = (0); i < (5); i++) {
    int curr = 0;
    priority_queue<int> q;
    for (int j = (0); j < (n); j++) {
      q.push(2 * cnt[j][i] - accumulate(cnt[j], cnt[j] + 5, 0));
    }
    int x = 0;
    while (!q.empty()) {
      if (x + q.top() > 0) {
        x += q.top();
        curr++;
        q.pop();
      } else
        break;
    }
    ans = max(ans, curr);
  }
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
