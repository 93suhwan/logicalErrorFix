#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll l1, l2, l3;
bool check(ll a, ll b, ll c) {
  if (b == c && a % 2 == 0) return true;
  if (a == b + c) return true;
  return false;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    string s;
    cin >> s;
    set<pair<int, int>> a;
    set<pair<int, int>> b;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0')
        a.insert({arr[i], i});
      else
        b.insert({arr[i], i});
    }
    int ans[n];
    int count = 1;
    for (auto elem : a) {
      ans[elem.second] = count;
      count++;
    }
    for (auto elem : b) {
      ans[elem.second] = count;
      count++;
    }
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
  }
}
