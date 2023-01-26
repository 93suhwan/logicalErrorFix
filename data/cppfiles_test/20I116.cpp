#include <bits/stdc++.h>
using namespace std;
int N, K, arr[10005], cnt[105], pos[105][105];
int main() {
  cin >> N >> K;
  int sz = (N - 1) / (K - 1) + 1;
  vector<int> v;
  for (int i = 1; i <= N; ++i) {
    v.push_back(i);
  }
  for (int i = 1; i <= N * K; ++i) {
    cin >> arr[i];
    pos[arr[i]][cnt[arr[i]]++] = i;
  }
  for (int i = 1; v.size(); ++i) {
    sort(v.begin(), v.end(),
         [&](int a, int b) { return pos[a][i] > pos[b][i]; });
    for (int j = 0; j < sz && v.size(); ++j) {
      int cur = v.back();
      v.pop_back();
      cout << pos[cur][i - 1] << " " << pos[cur][i] << endl;
    }
  }
  return 0;
}
