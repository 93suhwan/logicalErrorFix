#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b;
  cin >> a >> b;
  set<int> answer;
  int n = a + b;
  if (b > a) swap(a, b);
  if (!(n & 1)) {
    int diff = a - n / 2;
    int cnt = 0;
    while (cnt <= b) {
      answer.insert(diff);
      diff += 2;
      ++cnt;
    }
  } else {
    a--;
    int diff = a - n / 2;
    int cnt = 0;
    while (cnt <= b) {
      answer.insert(diff);
      diff += 2;
      ++cnt;
    }
    a++;
    if (b >= 1) {
      b--;
      diff = a - n / 2 + 1;
      cnt = 0;
      while (cnt <= b) {
        answer.insert(diff);
        diff += 2;
        ++cnt;
      }
      b++;
    }
    if (b >= 1) {
      b--;
      diff = a - n / 2;
      cnt = 0;
      while (cnt <= b) {
        answer.insert(diff);
        diff += 2;
        ++cnt;
      }
      b++;
    }
    a--;
    diff = a - n / 2 + 1;
    cnt = 0;
    while (cnt <= b) {
      answer.insert(diff);
      diff += 2;
      ++cnt;
    }
  }
  cout << (int)answer.size() << "\n";
  for (auto x : answer) cout << x << " ";
  cout << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test_cases;
  cin >> test_cases;
  while (test_cases--) solve();
}
