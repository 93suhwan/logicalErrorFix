#include <bits/stdc++.h>
using namespace std;
long long int factorial(long long int n) {
  return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
}
const int MOD = 1000000007;
int Binary(int arr[], int low, int high, int key) {
  while (low <= high) {
    long long int mid = (low + high) / 2;
    if (arr[mid] > key) {
      high = mid - 1;
    } else if (arr[mid] < key) {
      low = mid + 1;
    } else {
      return mid;
    }
  }
  return -1;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string s;
    cin >> s;
    vector<long long int> v;
    long long int sum = 0;
    long long int c = 0;
    for (long long int i = 0; i < s.length(); i++) {
      v.push_back((s[i] - 48));
    }
    for (long long int i = 0; i < v.size(); i++) {
      if (v[i] != 0) {
        sum += v[i];
        if (i != (v.size() - 1)) {
          sum++;
        }
      }
    }
    cout << sum << endl;
  }
  return 0;
}
