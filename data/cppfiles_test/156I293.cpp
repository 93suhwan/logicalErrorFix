#include <bits/stdc++.h>
using namespace std;
void _cout(int x) { cout << x; }
void _cout(char x) { cout << x; }
void _cout(long long int x) { cout << x; }
void _cout(string x) { cout << x; }
void _cout(bool x) { cout << x; }
template <class T>
void _cout(vector<T> &arr) {
  cout << "[ ";
  for (T item : arr) {
    _cout(item);
    cout << " ";
  }
  cout << "]";
}
void init() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
long long int foo(long long int sum, vector<long long int> &sufsum,
                  long long int k, vector<int> &arr, long long int i, int n) {
  long long int tsum = sum;
  tsum -= i;
  long long int f = (arr[0] * 1LL) - i;
  long long int count = i;
  bool can = false;
  if (tsum <= k) {
    can = true;
    return count;
  }
  for (int j = n - 1; j > 0; j--) {
    long long int nsum = tsum - (sufsum[j] - (f * (n - j)));
    if (nsum <= k) {
      can = true;
      count += (n - j);
      break;
    }
  }
  if (can) {
    return count;
  }
  return 1e18;
}
void solve() {
  int n;
  long long int k;
  cin >> n >> k;
  vector<int> arr(n);
  long long int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  if (n == 1) {
    cout << max(0LL, ((arr[0] * 1LL) - k)) << "\n";
    return;
  }
  sort(arr.begin(), arr.end());
  vector<long long int> sufsum(n);
  sufsum[n - 1] = arr[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    sufsum[i] = sufsum[i + 1] + arr[i];
  }
  long long int ans = 1e18;
  long long int lw = 0, hg = 1e18;
  while (lw <= hg) {
    long long int mid = (lw + hg) / 2;
    long long int count = foo(sum, sufsum, k, arr, mid, n);
    if (count < ans) {
      hg = mid - 1;
      ans = count;
    } else {
      lw = mid + 1;
    }
  };
  ;
  ;
  cout << ans;
  cout << "\n";
}
int main(int argc, char const *argv[]) {
  init();
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
