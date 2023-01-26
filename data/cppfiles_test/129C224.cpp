#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    set<int> done;
    vector<int> numsToChange;
    int temp;
    for (int i = 0; i < n; i++) {
      cin >> temp;
      if (temp <= n) {
        if (done.count(temp)) {
          numsToChange.push_back(temp);
        } else {
          done.insert(temp);
        }
      } else {
        numsToChange.push_back(temp);
      }
    }
    sort(numsToChange.begin(), numsToChange.end());
    int toChangePointer = 0;
    int ans = 0;
    bool works = true;
    for (int i = 1; i <= n; i++) {
      if (!done.count(i)) {
        int maxMod = (numsToChange[toChangePointer] + 1) / 2 - 1;
        if (maxMod >= i) {
          ans++;
          toChangePointer++;
        } else {
          cout << -1 << endl;
          works = false;
          break;
        }
      }
    }
    if (works) {
      cout << ans << endl;
    }
  }
}
