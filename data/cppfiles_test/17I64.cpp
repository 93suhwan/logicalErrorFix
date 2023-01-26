#include <bits/stdc++.h>
using namespace std;
template <typename T, typename T1>
T amax(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void read_input() {}
long long int _mergeSort(long long int arr[], long long int temp[],
                         long long int left, long long int right);
long long int merge(long long int arr[], long long int temp[],
                    long long int left, long long int mid, long long int right);
long long int mergeSort(long long int arr[], long long int array_size) {
  long long int temp[array_size];
  return _mergeSort(arr, temp, 0, array_size - 1);
}
long long int _mergeSort(long long int arr[], long long int temp[],
                         long long int left, long long int right) {
  long long int mid, inv_count = 0;
  if (right > left) {
    mid = (right + left) / 2;
    inv_count += _mergeSort(arr, temp, left, mid);
    inv_count += _mergeSort(arr, temp, mid + 1, right);
    inv_count += merge(arr, temp, left, mid + 1, right);
  }
  return inv_count;
}
long long int merge(long long int arr[], long long int temp[],
                    long long int left, long long int mid,
                    long long int right) {
  long long int i, j, k;
  long long int inv_count = 0;
  i = left;
  j = mid;
  k = left;
  while ((i <= mid - 1) && (j <= right)) {
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
      inv_count = inv_count + (mid - i);
    }
  }
  while (i <= mid - 1) temp[k++] = arr[i++];
  while (j <= right) temp[k++] = arr[j++];
  for (i = left; i <= right; i++) arr[i] = temp[i];
  return inv_count;
}
void solving() {
  long long int n;
  cin >> n;
  long long int a[n];
  deque<long long int> pq;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    if (i == 0)
      pq.push_back(a[i]);
    else if (a[i] > pq.back())
      pq.push_back(a[i]);
    else
      pq.push_front(a[i]);
  }
  long long int ans[n];
  long long int i = 0;
  while (pq.size() > 0) {
    ans[i] = (pq.front());
    i++;
    pq.pop_front();
  }
  i = 0;
  long long int result = mergeSort(ans, n);
  for (long long int i = 0; i < n; i++) {
    if (i == 0)
      pq.push_back(a[i]);
    else if (a[i] > pq.front())
      pq.push_back(a[i]);
    else
      pq.push_front(a[i]);
  }
  i = 0;
  while (pq.size() > 0) {
    ans[i] = (pq.front());
    i++;
    pq.pop_front();
  }
  result = min(result, mergeSort(ans, n));
  cout << result << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t = 1;
  cin >> t;
  for (long long int i = 1; i <= t; i++) {
    solving();
  }
  return 0;
}
