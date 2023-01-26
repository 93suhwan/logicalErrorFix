#include <bits/stdc++.h>
using namespace std;
int arr[200011];
int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int i, j;
    set<int> st;
    for (i = 1; i <= n; i++) {
      cin >> arr[i];
      st.insert(arr[i]);
    }
    sort(arr + 1, arr + n + 1);
    for (i = 2; i <= n / 2 + 1; i++) {
      int a = arr[i], b = arr[1];
      cout << a << ' ' << b << '\n';
    };
  }
  return 0;
}
