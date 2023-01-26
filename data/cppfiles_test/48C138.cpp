#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n), cnt(n + 1);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      cnt[a[i]]++;
    }
    if (n == 1) {
      cout << "YES\n";
      continue;
    } else if (n == 2) {
      if (a[0] <= a[1])
        cout << "YES\n";
      else
        cout << "NO\n";
      continue;
    }
    bool done = false;
    for (int i = 1; i <= n; i++) {
      if (cnt[i] >= 2) {
        cout << "YES\n";
        done = true;
        break;
      }
    }
    if (done) continue;
    vector<int> ind(n + 1);
    for (int i = 0; i < n; i++) {
      ind[a[i]] = i;
    }
    for (int curr_ind = 0; curr_ind < n - 2; curr_ind++) {
      int idx1 = curr_ind;
      int idx2 = ind[curr_ind + 1];
      int idx3 = ind[curr_ind + 1] + 1;
      if (idx2 == n - 1) {
        idx3 = idx2;
        idx2--;
      }
      while (a[curr_ind] != curr_ind + 1) {
        swap(a[idx3], a[idx2]);
        swap(a[idx2], a[idx1]);
        ind[a[idx1]] = idx1;
        ind[a[idx2]] = idx2;
        ind[a[idx3]] = idx3;
      }
    }
    done = true;
    for (int i = 0; i < n - 1; i++) {
      if (a[i + 1] < a[i]) done = false;
    }
    if (done)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
