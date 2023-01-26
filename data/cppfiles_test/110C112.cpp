#include <bits/stdc++.h>
using namespace std;
vector<int> book[(200001)];
int status[(200001)];
int rTimes[(200001)];
void deepFind(int chapter, bool &deadLock) {
  if (deadLock) return;
  status[chapter] = (1);
  for (int i : book[chapter]) {
    switch (status[i]) {
      case (1):
        deadLock = true;
        return;
      case (0):
        deepFind(i, deadLock);
    }
  }
  status[chapter] = (2);
}
void readChapter(int chapter) {
  status[chapter] = (2);
  if (book[chapter].empty()) {
    rTimes[chapter] = 1;
    return;
  }
  for (int require : book[chapter]) {
    if (rTimes[require] == (0)) readChapter(require);
    if (require > chapter) {
      rTimes[chapter] = max(rTimes[chapter], rTimes[require] + 1);
    } else {
      rTimes[chapter] = max(rTimes[chapter], rTimes[require]);
    }
  }
}
void solve() {
  int chapters;
  cin >> chapters;
  for (int i = 1; i <= chapters; i++) {
    book[i].clear();
    status[i] = (0);
    rTimes[i] = 0;
    int amount, require;
    cin >> amount;
    for (int j = 0; j < amount; j++) {
      cin >> require;
      book[i].push_back(require);
    }
  }
  bool deadLock = false;
  for (int i = 1; i <= chapters; i++) {
    if (status[i] == 0) {
      deepFind(i, deadLock);
      if (deadLock) {
        cout << -1 << endl;
        return;
      }
    }
  }
  for (int i = 1; i <= chapters; i++) status[i] = (0);
  for (int i = 1; i <= chapters; i++) {
    if (status[i] == (0)) readChapter(i);
  }
  int result = 0;
  for (int i = 1; i <= chapters; i++) result = max(result, rTimes[i]);
  cout << result << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int cases;
  cin >> cases;
  for (int i = 0; i < cases; i++) solve();
}
