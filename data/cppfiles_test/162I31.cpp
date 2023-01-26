#include <bits/stdc++.h>
using namespace std;
stack<int> st;
queue<long long> q;
priority_queue<int> pq;
priority_queue<int, vector<int>, greater<int>> mpq;
int binarySearch(vector<string> arr, int l, int r, string x) {
  if (r >= l) {
    int mid = l + (r - l) / 2;
    if (arr[mid] == x) {
      return mid;
    }
    if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
    return binarySearch(arr, mid + 1, r, x);
  }
  return -1;
}
struct ss {
  long long a, b, c;
};
void solve() {
  int n;
  cin >> n;
  vector<long long> vec(n);
  for (int i = 0; i < n; i++) cin >> vec[i];
  long long ans = 1e18;
  vector<long long> minv(n), add(n, 0);
  minv[0] = vec[0];
  for (int i = 1; i < n; i++) {
    minv[i] = min(vec[i], minv[i - 1]);
  }
  int idx = -1, small = INT_MAX;
  for (int i = 0; i < n; i++) {
    if (vec[i] < small) {
      small = vec[i];
      idx = i;
    }
  }
  for (int i = n - 1; i >= 2; i--) {
    long long k = vec[i] / 3;
    if (!k) continue;
    long long start = 0, end = k, mid;
    while (start <= end) {
      mid = start + (end - start) / 2;
      if (vec[i] - 3 * mid + add[i] > minv[i]) {
        start = mid + 1;
      } else if (vec[i] - 3 * mid + add[i] <= minv[i]) {
        end = mid - 1;
      }
    }
    if (vec[i] - 3 * mid + add[i] <= minv[i]) {
      mid--;
    }
    add[i - 1] += mid;
    add[i - 2] += 2 * mid;
    vec[i] -= 3 * mid;
  }
  for (int i = 0; i < n; i++) {
    vec[i] += add[i];
    ans = min(ans, vec[i]);
  }
  ans = vec[idx];
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
