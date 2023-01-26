#include <bits/stdc++.h>
using namespace std;
int n, K;
int qtd[42];
int vec[42][42];
int v[42];
void go(int k) {
  if (k == K) {
    int q1 = (v[0] == 1);
    for (int i = 1; i < n; i++)
      if (v[i] < v[i - 1] || (q1 += v[i] == 1) == 2) {
        printf("REJECTED\n");
        exit(0);
      }
    return;
  }
  int t = qtd[k];
  vector<int> pos, val;
  for (int i = 0; i < t; i++) {
    int a = vec[k][i];
    pos.push_back(a);
    val.push_back(v[a]);
  }
  sort(val.begin(), val.end());
  vector<int> opt;
  for (int i = 0; i < pos.size(); i++) {
    v[pos[i]] = val[i];
    if (val[i] == 1) opt.push_back(pos[i]), v[pos[i]] = 2;
  }
  go(k + 1);
  for (int i = 0; i < opt.size(); i++) {
    v[opt[i]] = 0;
    go(k + 1);
  }
}
int main() {
  scanf("%d%d", &n, &K);
  for (int i = 0; i < n; i++) v[i] = 1;
  for (int i = 0; i < K; i++) {
    scanf("%d", qtd + i);
    for (int j = 0; j < qtd[i]; j++) scanf("%d", &vec[i][j]), vec[i][j]--;
  }
  go(0);
  printf("ACCEPTED\n");
}
