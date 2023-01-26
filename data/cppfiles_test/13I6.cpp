#include <bits/stdc++.h>
using namespace std;
void leftRotatebyOne(vector<long long>& arr, long long l, long long r) {
  int temp = arr[l];
  for (long long i = l; i < r; i++) arr[i] = arr[i + 1];
  arr[r] = temp;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(b.begin(), b.end());
    vector<long long> vec;
    for (int i = 1; i <= n - 1; i++) {
      if (a[i - 1] == b[i - 1]) continue;
      long long x = LLONG_MAX, r = -1;
      for (long long j = i - 1; j < n; j++) {
        if (a[j] < x) {
          x = a[j];
          r = j;
        }
      }
      if (r - i + 1 != 0) {
        vec.push_back(i);
        vec.push_back(r + 1);
        vec.push_back(r - i + 1);
        for (long long j = 0; j < r - i + 1; j++) {
          leftRotatebyOne(a, i - 1, r);
        }
      }
    }
    cout << vec.size() / 3 << '\n';
    for (long long i = 0; i < vec.size(); i += 3) {
      cout << vec[i] << " " << vec[i + 1] << " " << vec[i + 2] << '\n';
    }
  }
  return 0;
}
