#include <bits/stdc++.h>
using namespace std;
long long SET(long long n, long long pos) { return n = n | (1 << pos); }
long long RESET(long long n, long long pos) { return n = n & ~(1 << pos); }
bool CHECK(long long n, long long pos) { return (bool)(n & (1 << pos)); }
vector<long long> v;
long long x, y, z, a, b, c, sum, ans, total, t, cnt, n, m, k, p, q, r, l, w,
    right, left, row, col, kase;
string s1, s2;
map<long long, long long> mp;
set<long long> s;
map<long long, long long>::iterator itr1, ptr1;
set<long long>::iterator itr, ptr;
long long arr[3000009], arr1[3000009], ind[3000009];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n;
    ans = INT_MIN;
    for (long long i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    ans = arr[0];
    p = arr[0];
    for (long long i = 1; i < n; i++) {
      arr[i] -= p;
      ans = max(ans, arr[i]);
      p += arr[i];
    }
    cout << ans << "\n";
  }
  return 0;
}
