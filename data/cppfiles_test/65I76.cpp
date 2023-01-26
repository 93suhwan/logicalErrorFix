#include <bits/stdc++.h>
using namespace std;
int N;
int A[202020];
char S[202020];
vector<pair<int, int>> ans_base;
int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) scanf("%d", A + i);
  scanf("%s", S);
  sort(A, A + N);
  bool skip_last = false;
  if (N % 2 == 1) {
    skip_last = true;
    ++N;
    A[N] = 1001001001;
    S[N] = 'L';
  }
  int sign = S[0] == 'R' ? 1 : -1;
  ans_base.push_back({0, sign});
  if (S[1] == S[0]) {
    ans_base.push_back({-1, -sign});
  } else {
    ans_base.push_back({1, -sign});
    sign *= -1;
  }
  int low = min(ans_base[0].first, ans_base[1].first);
  int high = max(ans_base[0].first, ans_base[1].first);
  for (int i = 2; i < N; i += 2) {
    if (S[i] == S[i - 1] && S[i + 1] == S[i - 1]) {
      ans_base.push_back({--low, sign});
      ans_base.push_back({--low, -sign});
    } else if (S[i] == S[i - 1] && S[i + 1] != S[i - 1]) {
      ans_base.push_back({--low, sign});
      ans_base.push_back({++high, -sign});
      sign = -sign;
    } else if (S[i] != S[i - 1] && S[i + 1] == S[i - 1]) {
      ans_base.push_back({++high, -sign});
      ans_base.push_back({++high, sign});
    } else {
      ans_base.push_back({++high, -sign});
      ans_base.push_back({--low, sign});
      sign = -sign;
    }
  }
  for (int i = 0; i < N - (skip_last ? 1 : 0); ++i) {
    printf("%d %c\n", A[ans_base[i].first - low],
           ans_base[i].second == 1 ? 'R' : 'L');
  }
  return 0;
}
