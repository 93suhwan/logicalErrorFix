#include <bits/stdc++.h>
int num2ch[6] = {'w', 'y', 'o', 'r', 'b', 'g'};
int ch2num[128];
std::unordered_set<long long> marked;
std::unordered_map<long long, int> col;
void e1(int n, int ret[6]) {
  int num = 6;
  for (; n > 0; n--) {
    num = (16LL * ((((long long)num) * num) % 1000000007)) % 1000000007;
    num = (((long long)166666668LL) * num) % 1000000007;
  }
  for (n = 6; n--;) ret[n] = (num * ((long long)166666668LL)) % 1000000007;
}
int dfs(int depth, long long node, int ret[6]) {
  int i, j1, j2, retval;
  int ret1[6];
  int ret2[6];
  if (depth > 0) {
    if (marked.find(node * 2) == marked.end())
      e1(depth - 1, ret1);
    else
      dfs(depth - 1, node * 2, ret1);
    if (marked.find(node * 2 + 1) == marked.end())
      e1(depth - 1, ret2);
    else
      dfs(depth - 1, node * 2 + 1, ret2);
    for (i = 0; i < 6; i++) {
      ret[i] = 0;
      for (j1 = 0; j1 < 6; j1++)
        for (j2 = 0; j2 < 6; j2++)
          if ((j1 >> 1) != (i >> 1) && (j2 >> 1) != (i >> 1)) {
            ret[i] += (((long long)ret1[j1]) * ret2[j2]) % 1000000007;
            ret[i] %= 1000000007;
          }
    }
  } else {
    for (i = 0; i < 6; i++) ret[i] = 0;
    ret[col[node] - 1] = 1;
  }
  if (col[node] > 0)
    for (i = 0; i < 6; i++)
      if (i != col[node] - 1) ret[i] = 0;
  retval = 0;
  for (i = 0; i < 6; i++) retval = (retval + ret[i]) % 1000000007;
  return retval;
}
char str[100];
int main() {
  int n, k;
  int nothing[6];
  long long i;
  for (i = 0; i < 6; i++) ch2num[num2ch[i]] = i;
  col.clear();
  marked.clear();
  scanf("%d%d", &n, &k);
  for (; k--;) {
    scanf("%lld %s", &i, str);
    col[i] = ch2num[(int)str[0]] + 1;
    while (i > 0) {
      marked.insert(i);
      i >>= 1;
    }
  }
  printf("%d\n", dfs(n - 1, 1, nothing));
  return 0;
}
