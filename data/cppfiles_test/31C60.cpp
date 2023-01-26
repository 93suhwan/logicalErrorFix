#include <bits/stdc++.h>
using namespace std;
int A[(1 << 19) + 5];
int cnt[257][(1 << 14) + 5];
int len[257];
int sortA[(1 << 19) + 5];
void sort1(vector<int> &A, int N) {
  assert(N <= (1 << 14));
  for (int k = 0; k < 3; k++) {
    for (int j = 0; j < 256; j++) {
      len[j] = 0;
    }
    int mask = ((1 << (8 * (k + 1))) - 1);
    int shiftVal = 8 * k;
    for (int i = 0; i < N; i++) {
      int indx = (A[i] & mask) >> shiftVal;
      cnt[indx][len[indx]++] = A[i];
    }
    int cntIndx = 0;
    for (int j = 0; j < 256; j++) {
      for (int x = 0; x < len[j]; x++) {
        A[cntIndx++] = cnt[j][x];
      }
    }
    assert(cntIndx == N);
  }
}
int n, k;
int f[(1 << 19) + 5];
int f2[(1 << 19) + 5];
vector<int> group[(1 << 19) + 5];
int submaskAns[(1 << 19) + 5];
int submaskAns2[(1 << 19) + 5][20];
int main() {
  scanf("%d%d", &n, &k);
  vector<int> A2(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }
  if (n <= (1 << 8)) {
    for (int j = 0; j < (1 << (k - 1)); j++) {
      for (int i = 0; i < n; i++) {
        A2[i] = A[i] ^ j;
      }
      sort1(A2, n);
      int ans = (1 << k);
      for (int i = 1; i < n; i++) {
        ans = min(ans, A2[i] - A2[i - 1]);
      }
      f[j] = ans;
      f[j ^ ((1 << k) - 1)] = ans;
    }
    for (int j = 0; j < (1 << k); j++) {
      printf("%d ", f[j]);
    }
    printf("\n");
    return 0;
  }
  const int m =
      min(max((int)ceil(log2((((1 << k) - 1) / (n - 1)) + 1.5)), 0), k);
  const int maskM = (1 << m) - 1;
  for (int i = 0; i < n; i++) {
    group[A[i] >> m].push_back(A[i]);
  }
  for (int i = 0; i < (1 << m); i++) {
    submaskAns[i] = (1 << m);
  }
  vector<int> group1(n);
  for (int groupNum = 0; groupNum < (1 << (k - m)); groupNum++) {
    for (int j = 0; j < (1 << m); j++) {
      int N = (int)group[groupNum].size();
      for (int i = 0; i < N; i++) {
        group1[i] = group[groupNum][i] ^ j;
      }
      sort1(group1, N);
      int ans = (1 << k);
      for (int i = 1; i < N; i++) {
        ans = min(ans, group1[i] - group1[i - 1]);
      }
      submaskAns[j] = min(ans, submaskAns[j]);
    }
  }
  for (int i = 0; i < (1 << k); i++) {
    f[i] = submaskAns[i & maskM];
  }
  for (int i = 0; i < (1 << k); i++) {
    for (int j = 0; j <= k; j++) {
      submaskAns2[i][j] = (1 << m);
    }
  }
  for (int x = 1; x <= k - m; x++) {
    int maskX = (1 << x) - 1;
    for (int y = 0; y < (1 << (k - m)); y++) {
      int z = y ^ maskX;
      int xorval = y ^ (maskX >> 1);
      assert((y ^ xorval) - (z ^ xorval) == -1);
      int N = (int)group[y].size();
      int M = (int)group[z].size();
      int mask2 = (1 << (x + m)) - 1;
      for (int j = 0; j < (1 << m); j++) {
        int to_xor = (xorval << m) | j;
        int val1 = 0;
        for (int i = 0; i < N; i++) {
          val1 = max(val1, group[y][i] ^ to_xor);
        }
        int val2 = (1 << k);
        for (int i = 0; i < M; i++) {
          val2 = min(val2, group[z][i] ^ to_xor);
        }
        int ans = val2 - val1;
        submaskAns2[to_xor & mask2][x + m] =
            min(submaskAns2[to_xor & mask2][x + m], ans);
      }
    }
  }
  for (int j = 0; j < (1 << k); j++) {
    for (int i = 0; i <= k; i++) {
      f[j] = min(f[j], submaskAns2[j & ((1 << i) - 1)][i]);
    }
    assert(f[j] < (1 << m) && f[j] > 0);
    if (j >= (1 << (k - 1))) {
      assert(f[j] == f[(1 << k) - j - 1]);
    }
    printf("%d ", f[j]);
  }
  return 0;
}
