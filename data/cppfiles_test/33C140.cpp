#include <bits/stdc++.h>
using namespace std;
const int M = 9;
const int N = 100100;
void minimize(int& x, int y) {
  if (x > y) {
    x = y;
  }
}
int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int& x : a) {
    scanf("%d", &x);
  }
  vector<int> b(n);
  iota(b.begin(), b.end(), 0);
  sort(b.begin(), b.end(), [&a](int i, int j) {
    return make_pair(a[i], -i) < make_pair(a[j], -j);
  });
  vector<int> minimum(1 << M, n);
  minimum[0] = -1;
  for (int i : b) {
    for (int j = 0; j < (1 << M); j++) {
      if (minimum[j] < i) {
        minimize(minimum[a[i] ^ j], i);
      }
    }
  }
  vector<int> answer;
  for (int j = 0; j < (1 << M); j++) {
    if (minimum[j] < n) {
      answer.push_back(j);
    }
  }
  cout << answer.size() << endl;
  for (int j : answer) {
    printf("%d ", j);
  }
  puts("");
}
