#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    set<int> vals;
    for (int i = 0; i < n; i++) vals.insert(arr[i]);
    map<int, int> comp;
    for (int a : vals) comp[a] = comp.size();
    for (int i = 0; i < n; i++) arr[i] = comp[arr[i]];
    int cnt = 0;
    for (int i = 1; i < n; i++)
      if (arr[i] - arr[i - 1] != 1) cnt++;
    cout << (cnt <= k - 1 ? "Yes\n" : "No\n");
  }
}
