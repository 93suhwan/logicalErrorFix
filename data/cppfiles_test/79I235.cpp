#include <bits/stdc++.h>
using namespace std;
bool arr[10000];
void precmp() {
  memset(arr, true, sizeof(arr));
  for (int p = 2; p * p <= 10000; p++) {
    if (arr[p] == true) {
      for (int i = p * p; i <= 10000; i += p) arr[i] = false;
    }
  }
  arr[1] = true;
}
void solve() {
  long long k, sum = 0, cnt = 0;
  string n;
  cin >> k;
  cin >> n;
  for (int i = 0; i < k; i++) {
    string p = "";
    p = n[i];
    int l = stoi(p);
    if (!arr[l]) {
      cout << 1 << '\n';
      cout << l;
      return;
    }
  }
  for (int i = 0; i < k; i++) {
    for (int j = i + 1; j < k; j++) {
      if (i != j) {
        string sh = "";
        sh = n[i];
        sh += n[j];
        int m = stoi(sh);
        if (!arr[m]) {
          cout << 2 << '\n';
          cout << sh;
          return;
        }
      }
    }
  }
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t = 1;
  cin >> t;
  precmp();
  while (t--) {
    solve();
    cout << '\n';
  }
}
