#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;
long long get(vector<long long> arr, long long parity, long long n) {
  vector<long long> temp(n);
  temp[0] = parity;
  long long pointodd, pointeve;
  if (arr[0] == 1) {
    pointodd = 0;
    for (int i = 1; i < (n); i++) {
      if (arr[i] % 2 == 0) {
        pointeve = i;
        break;
      }
    }
  } else {
    pointeve = 0;
    for (int i = 1; i < (n); i++) {
      if (arr[i] % 2) {
        pointodd = i;
        break;
      }
    }
  }
  for (int i = 1; i < (n); i++) {
    if (temp[i - 1] == 0) {
      temp[i] = 1;
    } else {
      temp[i] = 0;
    }
  }
  long long ans = 0;
  for (int i = 0; i < (n); i++) {
    if (arr[i] != temp[i]) {
      if (temp[i] == 1) {
        ans += (pointodd - i);
        swap(arr[i], arr[pointodd]);
        for (int j = pointodd + 1; j < (n); j++) {
          if (arr[j] == 1) {
            pointodd = j;
            break;
          }
        }
      } else {
        ans += (pointeve - i);
        swap(arr[i], arr[pointeve]);
        for (int j = pointeve + 1; j < (n); j++) {
          if (arr[j] == 0) {
            pointeve = j;
            break;
          }
        }
      }
    } else {
      if (temp[i] == 1) {
        for (int j = pointodd + 1; j < (n); j++) {
          if (arr[j] == 1) {
            pointodd = j;
            break;
          }
        }
      } else {
        for (int j = pointeve + 1; j < (n); j++) {
          if (arr[j] == 0) {
            pointeve = j;
            break;
          }
        }
      }
    }
  }
  return ans;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> arr(n);
  long long odd = 0, eve = 0;
  for (int i = 0; i < (n); i++) {
    cin >> arr[i];
    arr[i] = arr[i] % 2;
    if (arr[i] & 1) {
      odd++;
    } else {
      eve++;
    }
  }
  if (abs(odd - eve) > 1) {
    cout << -1 << nl;
    return;
  } else if (odd == eve) {
    cout << min(get(arr, 0, n), get(arr, 1, n)) << nl;
  } else if (odd > eve) {
    cout << get(arr, 1, n) << nl;
  } else {
    cout << get(arr, 0, n) << nl;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
