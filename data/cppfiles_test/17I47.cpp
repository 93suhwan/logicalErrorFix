#include <bits/stdc++.h>
using namespace std;
long long merge(vector<long long>& arr, long long l, long long mid,
                long long r) {
  long long temp[r - l + 1];
  long long k = 0;
  long long inv = 0;
  long long i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (arr[i] <= arr[j])
      temp[k++] = arr[i++];
    else {
      temp[k++] = arr[j++];
      inv += (mid - i + 1);
    }
  }
  while (i <= mid) temp[k++] = arr[i++];
  while (j <= r) temp[k++] = arr[j++];
  k = 0;
  for (long long i = l; i <= r; i++) arr[i] = temp[k++];
  return inv;
}
long long mergeSort(vector<long long>& arr, long long l, long long r) {
  long long inv = 0;
  if (l < r) {
    long long mid = l + (r - l) / 2;
    inv += mergeSort(arr, l, mid);
    inv += mergeSort(arr, mid + 1, r);
    inv += merge(arr, l, mid, r);
  }
  return inv;
}
long long inversionCount(vector<long long> arr) {
  return mergeSort(arr, 0, arr.size() - 1);
}
void solve() {
  long long n;
  cin >> n;
  deque<long long> dq;
  long long x;
  cin >> x;
  dq.push_back(x);
  for (long long i = 1; i < n; i++) {
    long long x;
    cin >> x;
    if (x >= dq.back())
      dq.push_back(x);
    else if (x <= dq.front())
      dq.push_front(x);
    else
      dq.push_front(x);
  }
  vector<long long> arr;
  for (auto x : dq) arr.push_back(x);
  cout << inversionCount(arr) << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) solve();
}
