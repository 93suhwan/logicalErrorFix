#include <bits/stdc++.h>
using namespace std;
int sum1, sum2;
unordered_set<int> diff;
void recur(int sum, int cur, int size, vector<int> &a) {
  if (cur == size) {
    diff.insert(sum);
    return;
  }
  recur(sum, cur + 1, size, a);
  sum1 = sum + a[cur];
  recur(sum1, cur + 1, size, a);
  sum2 = sum - a[cur];
  recur(sum2, cur + 1, size, a);
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    bool possible = false;
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
      if (arr[i] == 0) {
        possible = true;
      }
    }
    if (possible) {
      cout << "YES" << endl;
      continue;
    }
    vector<int> a;
    for (int i = 0; i < n; i++) {
      a.clear();
      for (int j = 0; j < n; j++) {
        if (i != j) {
          a.push_back(arr[j]);
        }
      }
      recur(0, 0, n - 1, a);
      if (diff.count(abs(arr[i]))) {
        possible = true;
        break;
      }
      diff.clear();
    }
    diff.clear();
    if (possible) {
      cout << "YES" << endl;
      continue;
    }
    cout << "NO" << endl;
  }
  return 0;
}
