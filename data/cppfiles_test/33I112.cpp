#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e9 + 7;
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
ll power(ll x, ll y) {
  ll res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
const int N = 100000;
int arr[N];
map<int, int> mn;
void solve() {
  int n;
  cin >> n;
  for (int i = (0); i < (n); i++) {
    cin >> arr[i];
  }
  mn[0] = 0;
  for (int i = (0); i < (n); i++) {
    if (mn.size() == 501) break;
    for (auto p : mn) {
      int x = p.first;
      if (arr[i] > mn[x]) {
        int y = arr[i] ^ x;
        if (mn[y] != 0)
          mn[y] = min(mn[y], arr[i]);
        else
          mn[y] = arr[i];
      }
    }
  }
  cout << mn.size() << '\n';
  for (auto x : mn) {
    cout << x.first << " ";
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
