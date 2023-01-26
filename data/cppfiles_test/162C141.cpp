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
void solve() {
  int n;
  cin >> n;
  vector<long long> vec(n);
  int large = -1, small = INT_MAX;
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
    if (vec[i] < small) small = vec[i];
    if (vec[i] > large) large = vec[i];
  }
  int mid2;
  long long ans = 1e18;
  while (small < large) {
    bool flag = true;
    mid2 = small + (large - small + 1) / 2;
    vector<long long> temp = vec;
    long long k;
    for (int i = n - 1; i >= 2; i--) {
      k = min(vec[i], temp[i] - mid2) / 3;
      if (temp[i] < mid2) {
        flag = false;
        break;
      }
      temp[i - 1] += k;
      temp[i - 2] += 2 * k;
      temp[i] -= 3 * k;
    }
    if (!flag) {
      large = mid2 - 1;
    } else {
      if (temp[0] >= mid2 && temp[1] >= mid2) {
        small = mid2;
      } else {
        large = mid2 - 1;
      }
    }
  }
  cout << small << endl;
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
