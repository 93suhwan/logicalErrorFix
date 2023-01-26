#include <bits/stdc++.h>
using namespace std;
void solve(int tt, int t) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  if (n <= 1) {
    cout << "Alice" << endl;
    return;
  }
  int lastl = 0, lastr = n - 1;
  for (int i = 1; i < n; i++) {
    if (a[i] > a[i - 1])
      lastl = i;
    else
      break;
  }
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] > a[i + 1])
      lastr = i;
    else
      break;
  }
  vector<int> left, right;
  for (int i = 0; i <= lastl; i++) left.push_back(a[i]);
  for (int i = n - 1; i >= lastr; i--) right.push_back(a[i]);
  int idxl = 0, idxr = 0, cnt = 0;
  int szl = left.size(), szr = right.size();
  while (idxl < szl && idxr < szr) {
    if (left[idxl] > right[idxr]) {
      if ((szl - idxl) % 2 != 0) {
        if (cnt % 2 == 0) {
          cout << "Alice" << endl;
          return;
        } else {
          cout << "Bob" << endl;
          return;
        }
      } else {
        idxr += 1;
        cnt += 1;
        continue;
      }
    }
    if (right[idxr] > left[idxl]) {
      if ((szr - idxr) % 2 != 0) {
        if (cnt % 2 == 0) {
          cout << "Alice" << endl;
          return;
        } else {
          cout << "Bob" << endl;
          return;
        }
      } else {
        idxl += 1;
        cnt += 1;
        continue;
      }
    }
    if ((szr - idxr) % 2 != 0) {
      if (cnt % 2 == 0) {
        cout << "Alice" << endl;
        return;
      } else {
        cout << "Bob" << endl;
        return;
      }
    }
    if ((szl - idxl) % 2 != 0) {
      if (cnt % 2 == 0) {
        cout << "Alice" << endl;
        return;
      } else {
        cout << "Bob" << endl;
        return;
      }
    }
    if (cnt % 2 == 0) {
      cout << "Bob" << endl;
      return;
    } else {
      cout << "Alice" << endl;
      return;
    }
  }
  cnt += (szl - idxl);
  cnt += (szr - idxr);
  if (cnt % 2 != 0) {
    cout << "Alice" << endl;
    return;
  } else {
    cout << "Bob" << endl;
    return;
  }
  return;
}
int main(int argc, const char* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  t = 1;
  for (int tt = 0; tt < t; tt++) {
    solve(tt, t);
  }
  return 0;
}
