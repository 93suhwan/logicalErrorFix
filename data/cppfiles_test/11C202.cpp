#include <bits/stdc++.h>
using namespace std;
char s[400001];
vector<int> freq[6];
int f[6];
int main() {
  int Q, N;
  cin >> Q;
  while (Q--) {
    int ans = -1;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
      scanf("%s", s);
      for (int j = 0; j < 5; j++) f[j] = 0;
      for (int j = 0; j < strlen(s); j++) f[s[j] - 'a']++;
      for (int j = 0; j < 5; j++)
        freq[j].push_back(f[0] + f[1] + f[2] + f[3] + f[4] - 2 * f[j]);
    }
    for (int j = 0; j < 5; j++) {
      sort(freq[j].begin(), freq[j].end());
      int z = 0;
      for (int i = 0; i < N; i++) {
        z += freq[j][i];
        if (z >= 0) break;
        ans = max(ans, i);
      }
    }
    printf("%d\n", ans + 1);
    for (int j = 0; j < 5; j++) freq[j].clear();
  }
}
