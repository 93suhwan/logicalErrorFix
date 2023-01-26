#include <bits/stdc++.h>
char POW[70][30];
int N_POW = 63;
void generate_pow() {
  long long pow = 1;
  for (int i = 0; i < N_POW; i++) {
    sprintf(POW[i], "%lld", pow);
    pow <<= 1;
  }
}
int min_edit_distance(char number[]) {
  int num_len = strlen(number);
  int min_dist = num_len + 1;
  for (int j = 0; j < N_POW; j++) {
    int pow_len = strlen(POW[j]);
    int common = 0;
    int pow_i = 0, num_i = 0;
    while (pow_i < pow_len && num_i < num_len) {
      if (POW[j][pow_i] == number[num_i]) {
        common++;
        pow_i++;
        num_i++;
      } else {
        num_i++;
      }
    }
    int distance = 0;
    distance += (num_len - common);
    distance += (pow_len - common);
    if (min_dist > distance) {
      min_dist = distance;
    }
  }
  return min_dist;
}
void solve() {
  char n[12];
  scanf("%s", n);
  printf("%d\n", min_edit_distance(n));
}
int main() {
  generate_pow();
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
}
