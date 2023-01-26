#include <bits/stdc++.h>
using namespace std;
void Fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  int sum = 0, sum1 = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    sum += v[i];
  }
  int mini;
  int avg = sum / n;
  int i = 0, j = n - 1;
  sort(v.begin(), v.end());
  while (i < j) {
    if (v[i] > avg) {
      int num = 0;
      for (int k = i; k < n; k++) {
        if (v[k] > avg) {
          sum1 += v[k];
          num++;
        }
      }
      int avg1 = sum1 / num;
      if (sum1 % num == 0) {
        mini = avg1 - v[0];
      } else {
        mini = avg1 - v[0] + 1;
      }
      break;
    } else if (v[i] != avg) {
      if (v[j] != avg) {
        int temp = v[i];
        v[i] += min(avg - temp, v[j] - avg);
        v[j] -= min(avg - temp, v[j] - avg);
      } else {
        j--;
      }
    } else {
      i++;
    }
    if (i < j) {
      mini = v[n - 1] - v[0];
    }
  }
  cout << mini << endl;
  return;
}
int main() {
  Fast();
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
