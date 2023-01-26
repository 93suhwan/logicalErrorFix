#include <bits/stdc++.h>
using namespace std;
const int N = 110;
const int mod = 1e9 + 7;
pair<int, int> a[N];
int used[500];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    n = n * 2;
    for (int i = 1; i <= n; i++) {
      used[i] = i;
      a[i].first = 0;
      a[i].second = 0;
    }
    for (int i = 1; i <= k; i++) {
      cin >> a[i].first >> a[i].second;
      if (a[i].first > a[i].second) {
        int temp = a[i].first;
        a[i].first = a[i].second;
        a[i].second = temp;
      }
      used[a[i].first] = 1000;
      used[a[i].second] = 1000;
    }
    sort(used + 1, used + n + 1);
    int mid = (n - k * 2) / 2;
    for (int i = k + 1; i <= k + mid; i++) {
      a[i].first = used[i - k];
      a[i].second = used[mid + i - k];
    }
    sort(a + 1, a + n / 2 + 1);
    int cnt = 0;
    for (int i = 1; i <= n / 2 - 1; i++) {
      for (int j = i + 1; a[j].first < a[i].second && j <= n / 2; j++) {
        if (a[j].second > a[i].second) {
          cnt++;
        }
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
