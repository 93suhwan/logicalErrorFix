#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, t, k, x;
  int arr[200200];
  int ans[200200], top;
  cin >> t;
  while (t--) {
    cin >> n;
    x = 0;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      x += arr[i];
    }
    if (x % 2 == 1) {
      cout << "NO\n";
      continue;
    }
    top = 0;
    if (arr[0] == 1 && arr[n - 1] == 1) {
      for (k = 0; arr[k] == 1 && k < n; k++)
        ;
      if (k % 2 == 0) {
        if (k == n) {
          cout << "NO\n";
          continue;
        }
        for (int i = k - 1; i > 0; i -= 2) {
          ans[top++] = i;
          arr[i - 1] = 0;
          arr[i] = 0;
        }
      } else if (k + 1 < n && arr[k + 1] == 1) {
        ans[top++] = k;
        arr[k - 1] = 0;
        arr[k + 1] = 0;
        for (int i = k - 2; i > 0; i -= 2) {
          ans[top++] = i;
          arr[i - 1] = 0;
          arr[i] = 0;
        }
      } else {
        for (int i = k; i < n - 1; i += 2) {
          ans[top++] = i;
          x = arr[i - 1] ^ arr[i] ^ arr[i + 1];
          arr[i - 1] = x;
          arr[i] = x;
          arr[i + 1] = x;
          if (x == 0) {
            for (int j = i - 2; j > 0; j -= 2) {
              ans[top++] = j;
              arr[j] = 0;
              arr[j - 1] = 0;
            }
            break;
          }
        }
      }
    }
    if (arr[0] == 0) {
      for (int i = 1; i < n - 1; i++) {
        if (arr[i] == 1) {
          if (arr[i + 1] == 1) {
            ans[top++] = i;
            arr[i] = 0;
            arr[i + 1] = 0;
          } else if (arr[i + 2] == 1) {
            ans[top++] = i + 1;
            arr[i] = 0;
            arr[i + 2] = 0;
          } else {
            ans[top++] = i + 1;
            arr[top++] = i;
            arr[i] = 0;
            arr[i + 2] = 1;
            i++;
          }
        }
      }
    } else if (arr[n - 1] == 0) {
      for (int i = n - 2; i > 0; i--) {
        if (arr[i] == 1) {
          if (arr[i - 1] == 1) {
            ans[top++] = i;
            arr[i] = 0;
            arr[i - 1] = 0;
          } else if (arr[i - 2] == 1) {
            ans[top++] = i - 1;
            arr[i] = 0;
            arr[i - 2] = 0;
          } else {
            ans[top++] = i - 1;
            ans[top++] = i;
            arr[i] = 0;
            arr[i - 2] = 1;
            i--;
          }
        }
      }
    } else {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    cout << top << '\n';
    if (top == 0) continue;
    for (int i = 0; i < top; i++) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }
  cout << flush;
  return 0;
}
