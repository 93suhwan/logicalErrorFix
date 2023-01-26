#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> a, vector<int> b) {
  int n = (int)a.size(), m = (int)b.size();
  for (int i = 0; i < m; i++) {
    int j = i + n - 1;
    bool bo = true;
    for (int k = j + 1; k < m; k++) {
      if (b[k] != 1) {
        bo = false;
        break;
      }
    }
    if (!bo) {
      continue;
    }
    bool bo2 = true;
    for (int k = i; k <= j; k++) {
      if (a[k - i] != b[k]) {
        bo2 = false;
        break;
      }
    }
    if (bo2) {
      return true;
    }
    if (b[i] != 1) {
      break;
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long x, y;
  cin >> x >> y;
  vector<int> a, b;
  while (x > 0) {
    a.push_back(x % 2);
    x /= 2;
  }
  while (y > 0) {
    b.push_back(y % 2);
    y /= 2;
  }
  bool res = check(a, b);
  reverse(a.begin(), a.end());
  res |= check(a, b);
  while (a.back() == 0) {
    a.pop_back();
  }
  res |= check(a, b);
  reverse(a.begin(), a.end());
  res |= check(a, b);
  if (res) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}
