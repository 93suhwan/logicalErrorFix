#include <bits/stdc++.h>
using namespace std;
int num[101], key[101];
int main() {
  for (int i = 1; i <= 9; i++) {
    key[i + 1] = i * 9 + 1;
  }
  int T;
  cin >> T;
  while (T--) {
    long long s, n, sum = 0;
    cin >> s >> n;
    long long tmp = s, id = 1;
    while (tmp) {
      num[id] = tmp % 10;
      sum += num[id];
      tmp /= 10;
      id++;
    }
    int mx = id - 1;
    id = 2;
    while (sum < n) {
      while (!num[id]) id++;
      num[id]--;
      num[id - 1] += 10;
      sum += 9;
    }
    bool flag = false;
    tmp = sum = 0;
    if (n == 1) flag = 1;
    for (int i = 1; i <= mx; i++) {
      for (int j = 1; j <= num[i]; j++) {
        if (!flag) {
          cout << pow(10, i - 1) << " ";
          sum++;
          if (sum == n - 1) {
            flag = 1;
          }
        } else {
          tmp += pow(10, i - 1);
        }
      }
    }
    if (tmp != 0) cout << tmp;
    cout << endl;
  }
  return 0;
}
