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
void solve() {
  long long n;
  cin >> n;
  vector<long long> arr(n);
  long long totale = 0, totalo = 0;
  queue<long long> odd, eve;
  for (int i = 0; i < (n); i++) {
    cin >> arr[i];
    if (arr[i] & 1) {
      arr[i] = 1;
      totalo++;
      odd.push(i);
    } else {
      arr[i] = 0;
      totale++;
      eve.push(i);
    }
  }
  if (abs(totale - totalo) > 1) {
    cout << -1 << nl;
    return;
  }
  long long ans = 0;
  if (totalo > totale) {
    long long start = 0, stam = 1;
    if (arr[0] == 0) {
      ans = odd.front();
      odd.pop();
      start++;
      for (long long j = odd.front(); j >= 1; j--) {
        swap(arr[j], arr[j - 1]);
      }
    }
    for (int i = start; i < (n - 1); i++) {
      if (arr[i] == arr[i + 1] && arr[i] & 1) {
        ans += (eve.front() - i - stam);
        for (long long j = eve.front(); j > i + 1; j--) {
          swap(arr[j], arr[j - 1]);
        }
        eve.pop();
        odd.pop();
      } else if (arr[i] == arr[i + 1] && (arr[i] % 2 == 0)) {
        ans += (odd.front() - i - stam);
        for (long long j = odd.front(); j > i + 1; j--) {
          swap(arr[j], arr[j - 1]);
        }
        odd.pop();
        eve.pop();
      }
      if ((int)(odd).size() <= 1) {
        break;
      }
    }
  } else if (totalo < totale) {
    long long start = 0, stam = 1;
    if (arr[0] == 1) {
      ans = eve.front();
      eve.pop();
      start++;
      for (long long j = eve.front(); j >= 1; j--) {
        swap(arr[j], arr[j - 1]);
      }
    }
    for (int i = start; i < (n - 1); i++) {
      if (arr[i] == arr[i + 1] && arr[i] & 1) {
        ans += (eve.front() - i - stam);
        stam++;
        for (long long j = eve.front(); j > i + 1; j--) {
          swap(arr[j], arr[j - 1]);
        }
        eve.pop();
        odd.pop();
      } else if (arr[i] == arr[i + 1] && (arr[i] % 2 == 0)) {
        ans += (odd.front() - i - stam);
        stam++;
        for (long long j = odd.front(); j > i + 1; j--) {
          swap(arr[j], arr[j - 1]);
        }
        odd.pop();
        eve.pop();
      }
      if ((int)(eve).size() <= 1) {
        break;
      }
    }
  } else {
    long long start = 0, stam = 1;
    for (int i = start; i < (n - 1); i++) {
      if (arr[i] == arr[i + 1] && arr[i] == 1) {
        ans += (eve.front() - i - stam);
        for (long long j = eve.front(); j > i + 1; j--) {
          swap(arr[j], arr[j - 1]);
        }
        eve.pop();
        odd.pop();
      } else if (arr[i] == arr[i + 1] && (arr[i] == 0)) {
        ans += (odd.front() - i - stam);
        for (long long j = odd.front(); j > i + 1; j--) {
          swap(arr[j], arr[j - 1]);
        }
        odd.pop();
        eve.pop();
      }
      if ((int)(odd).size() <= 1 || (int)(eve).size() <= 1) {
        break;
      }
    }
  }
  cout << ans << nl;
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
