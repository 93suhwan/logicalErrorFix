#include <bits/stdc++.h>
using namespace std;
int query(int idx1, int idx2, bool isAnd) {
  cout << (isAnd ? "and " : "or ");
  cout << idx1 << " " << idx2 << endl;
  int res;
  cin >> res;
  if (res == -1) exit(0);
  return res;
}
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> ands(n + 1);
  for (int i = 2; i <= n; i++) {
    ands[i] = query(1, i, true);
  }
  vector<int> ors(n + 1);
  for (int i = 2; i <= n; i++) {
    ors[i] = query(1, i, false);
  }
  int twoAndThree = query(2, 3, true);
  int twoOrThree = query(2, 3, false);
  vector<int> arr(n + 1, 0);
  for (int bit = 0; bit <= 30; bit++) {
    vector<bool> currBits(4, false);
    vector<bool> currAnds(4);
    currAnds[1] = (twoAndThree & (1 << bit)) > 0;
    currAnds[2] = (ands[3] & (1 << bit)) > 0;
    currAnds[3] = (ands[2] & (1 << bit)) > 0;
    vector<bool> currOrs(4);
    currOrs[1] = (twoOrThree & (1 << bit)) > 0;
    currOrs[2] = (ors[3] & (1 << bit)) > 0;
    currOrs[3] = (ors[2] & (1 << bit)) > 0;
    if (currAnds[1] && currAnds[2] && currAnds[3]) {
      currBits[1] = true;
      currBits[2] = true;
      currBits[3] = true;
    } else if (!currOrs[1] && !currOrs[2] && !currOrs[3]) {
      currBits[1] = false;
      currBits[2] = false;
      currBits[3] = false;
    } else if (!currAnds[1] && !currAnds[2] && !currAnds[3]) {
      for (int i = 1; i <= 3; i++) {
        if (!currOrs[i]) {
          currBits[i] = true;
        }
      }
    } else {
      currBits.assign(4, true);
      for (int i = 1; i <= 3; i++) {
        if (currAnds[i]) {
          currBits[i] = false;
        }
      }
    }
    for (int i = 1; i <= 3; i++) {
      arr[i] |= (currBits[i] << bit);
    }
  }
  for (int i = 4; i <= n; i++) {
    for (int bit = 0; bit <= 30; bit++) {
      arr[i] = ands[i];
      if (((arr[1] & (1 << bit)) == 0) && (ors[i] & (1 << bit))) {
        arr[i] |= 1 << bit;
      }
    }
  }
  sort(arr.begin() + 1, arr.end());
  cout << "finish " << arr[k] << endl;
}
