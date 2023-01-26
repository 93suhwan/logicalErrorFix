#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int LM = 1e5 + 4;
int N;
int arr[LM];
vector<int> ans;
void solve() {
  ans.clear();
  int M = N;
  for (int i = 1; i < N; i += 2) {
    int p = -1, q = -1;
    for (int j = 1; j <= N; j++) {
      if (arr[j] == i) {
        p = j;
        break;
      }
    }
    ans.push_back(p);
    reverse(arr + 1, arr + p + 1);
    p = 1;
    for (int j = 1; j <= N; j++) {
      if (arr[j] == i + 1) {
        q = j;
        break;
      }
    }
    ans.push_back(q - 1);
    reverse(arr + 1, arr + q);
    p = q - 1;
    ans.push_back(p + 2);
    reverse(arr + 1, arr + p + 2 + 1);
    ans.push_back(3);
    reverse(arr + 1, arr + 3 + 1);
    ans.push_back(M);
    reverse(arr + 1, arr + M + 1);
    M -= 2;
  }
  ans.push_back(N);
  reverse(arr + 1, arr + N + 1);
  printf("%d\n", (int)ans.size());
  for (int idx : ans) printf("%d ", idx);
  puts("");
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d", arr + i);
    bool flag = 1;
    for (int i = 1; i <= N; i++) flag &= (arr[i] - i) % 2 == 0;
    if (!flag) {
      puts("-1");
      continue;
    }
    solve();
  }
  return 0;
}
