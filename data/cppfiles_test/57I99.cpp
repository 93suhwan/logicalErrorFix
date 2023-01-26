#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159265358979323846, eps = 1e-9;
const long long M = 1e6, I = 1e17 + 5;
const int mxn = 2100, mxn1 = 2000, lg = 20;
int t, n;
vector<int> arr, ans;
void out() {
  for (int i : arr) cout << i << " ";
  cout << endl;
}
void solve() {
  arr.clear();
  ans.clear();
  cin >> n;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    arr.push_back(k);
    if (i % 2 == arr[i] % 2) {
      cout << -1 << endl;
      return;
    }
  }
  for (int i = n; i >= 3; i -= 2) {
    int ind = -1;
    for (int j = 0; j <= i; j++) {
      if (arr[j] == i) {
        ind = j;
        break;
      }
    }
    ans.push_back(ind + 1);
    reverse(arr.begin(), arr.begin() + ind + 1);
    for (int j = 0; j <= i; j++) {
      if (arr[j] == i - 1) {
        ind = j;
        break;
      }
    }
    ans.push_back(ind);
    reverse(arr.begin(), arr.begin() + ind);
    ans.push_back(ind + 2);
    reverse(arr.begin(), arr.begin() + ind + 2);
    ans.push_back(3);
    reverse(arr.begin(), arr.begin() + 3);
    ans.push_back(i);
    reverse(arr.begin(), arr.begin() + i);
  }
  cout << ans.size() << endl;
  for (int i : ans) cout << i << " ";
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  cin >> t;
  while (t--) solve();
}
