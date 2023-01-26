#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const int SZ = 3e5 + 100;
void initialize() {}
void test_case() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto &x : arr) {
    cin >> x;
    x -= 1;
  }
  vector<int> per(n + 1), e;
  for (int i = 0; i < n; i++) {
    if (arr[i] < n and per[arr[i]] == 0) {
      per[arr[i]] = 1;
    } else {
      e.push_back(arr[i]);
    }
  }
  vector<int> req;
  for (int i = 0; i < n; i++)
    if (per[i] == 0) req.push_back(i);
  assert(e.size() == req.size());
  sort(e.begin(), e.end());
  for (int i = req.size() - 1; i >= 0; i--) {
    int a = e.back() + 1;
    int b = req[i] + 1;
    int x = a - b;
    if (e.back() < req[i] or x == 0 or a % x != b) {
      cout << "-1\n";
      return;
    }
    e.pop_back();
  }
  cout << req.size() << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  srand(time(0));
  initialize();
  int t;
  cin >> t;
  while (t--) {
    test_case();
  }
}
