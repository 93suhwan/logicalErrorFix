#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int, int> arr[200001];
int cnt[501][501];
int chk[200001];
int del[200001];
int main(void) {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &arr[i].first, &arr[i].second);
  }
  int ret = 0;
  for (int i = 1; i <= m; i++) {
    int op, k;
    scanf("%d %d", &op, &k);
    op = (i + 1) % 2 + 1;
    k = 1;
    if (op == 1) {
      if (arr[k].first + arr[k].second <= 500) {
        int now = i + arr[k].first;
        for (int j = 0; j < arr[k].second; j++) {
          if (now >= (arr[k].first + arr[k].second)) {
            now -= arr[k].first + arr[k].second;
          }
          cnt[arr[k].first + arr[k].second][now]++;
          now++;
        }
      } else {
        for (int j = i; j <= m; j += arr[k].first + arr[k].second) {
          del[j]++;
        }
        for (int j = i + arr[k].first; j <= m;
             j += arr[k].first + arr[k].second) {
          del[j]--;
        }
      }
      chk[k] = i;
    } else {
      if (arr[k].first + arr[k].second <= 500) {
        int now = chk[k] + arr[k].first;
        for (int j = 0; j < arr[k].second; j++) {
          if (now >= (arr[k].first + arr[k].second)) {
            now -= arr[k].first + arr[k].second;
          }
          cnt[arr[k].first + arr[k].second][now]--;
          now++;
        }
      } else {
        int f0 = -1;
        int f1 = -1;
        for (int j = chk[k]; j <= m; j += arr[k].first + arr[k].second) {
          del[j]--;
          if (j < i) {
            f0 = j;
          }
        }
        for (int j = chk[k] + arr[k].first; j <= m;
             j += arr[k].first + arr[k].second) {
          del[j]++;
          if (j < i) {
            f1 = j;
          }
        }
        if (f0 > f1) {
          ret--;
        }
      }
    }
    ret += del[i];
    int val = ret;
    for (int j = 1; j <= 500; j++) {
      val += cnt[j][i % j];
    }
    printf("%d\n", val);
  }
}
