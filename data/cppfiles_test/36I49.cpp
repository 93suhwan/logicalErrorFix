#include <bits/stdc++.h>
using namespace std;
bool composite_number(long long int x) {
  for (int i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) {
      return true;
      break;
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> v(n);
    bool flag = false;
    long long int sum = 0;
    for (auto &value : v) {
      cin >> value;
      sum += value;
    }
    if (composite_number(sum) == true) {
      cout << n << endl;
      for (int i = 0; i < n; i++) {
        cout << i + 1 << " ";
      }
      cout << endl;
    } else {
      long long int sum1 = sum;
      long long int sum2 = 0, sum3 = 0;
      long long int x, y, count1 = 0, count2 = 0;
      for (int i = 0; i < n; i++) {
        sum2 += v[i];
        count1++;
        if (composite_number(sum1 - sum2) == true) {
          x = i;
          break;
        }
      }
      for (int i = n - 1; i >= 0; i--) {
        sum3 += v[i];
        count2++;
        if (composite_number(sum1 - sum3) == true) {
          y = i;
          break;
        }
      }
      if (count1 > count2) {
        cout << n - count2 << endl;
        for (int i = 0; i < n; i++) {
          if (i == y)
            continue;
          else
            cout << i + 1 << " ";
        }
        cout << endl;
      } else {
        cout << n - count1 << endl;
        for (int i = 0; i < n; i++) {
          if (i == x)
            continue;
          else
            cout << i + 1 << " ";
        }
        cout << endl;
      }
    }
  }
  return 0;
}
