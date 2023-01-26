#include <bits/stdc++.h>
using namespace std;
const int PRIME = int(1e9 + 7);
void test() {
  int n;
  char ch;
  cin >> n >> ch;
  char s[n + 1];
  scanf("%s", s);
  vector<int> u;
  int good = -1;
  for (int i = 0; i < n; i++) {
    if (s[i] != ch)
      u.push_back(i + 1);
    else {
      if (i + 1 > (n + 1) / 2) good = i + 1;
    }
  }
  if (u.size() == 0u) {
    puts("0");
    return;
  }
  if (good == -1) {
    puts("2");
    cout << n << ' ' << 2 << '\n';
  } else {
    puts("1");
    cout << n << '\n';
  }
}
int main() {
  int T = 1;
  scanf("%d", &T);
  for (int tc = 0; tc < T; ++tc) {
    test();
  }
  return 0;
}
