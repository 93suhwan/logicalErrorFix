#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using pii = pair<int, int>;
int main(int argc, const char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n), brr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      brr[i] = arr[i];
    }
    sort(brr.begin(), brr.end());
    int cnt = 0;
    vector<pii> res;
    for (int i = 0; i < n; i++) {
      if (arr[i] == brr[i]) continue;
      cnt++;
      int d;
      for (int j = 0; j < n; j++) {
        if (arr[j] == brr[i]) d = j;
      }
      res.push_back(pii(i + 1, d + 1));
      for (int j = d; j > i; j--) swap(arr[j], arr[j - 1]);
    }
    cout << cnt << "\n";
    for (auto t : res)
      cout << t.first << " " << t.second << " " << t.second - t.first << "\n";
  }
  return 0;
}
