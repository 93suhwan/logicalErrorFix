#include <bits/stdc++.h>
namespace {
const int L = 30;
std::vector<int> GetBits(int x) {
  std::vector<int> r(L);
  for (int i = L - 1; i >= 0; --i) {
    r[i] = (x % 2);
    x /= 2;
  }
  return r;
}
int GetValue(const std::vector<int>& r) {
  int value = 0;
  for (int bit : r) {
    value = (2 * value) + bit;
  }
  return value;
}
std::vector<int> AskAnd(int x, int y) {
  printf("and %d %d\n", x, y);
  fflush(stdout);
  int answer;
  scanf("%d", &answer);
  return GetBits(answer);
}
void ApplyAndResult(std::vector<std::vector<int>>* a_ptr, int x, int y,
                    const std::vector<int>& and_r) {
  std::vector<std::vector<int>>& a = (*a_ptr);
  for (int k = 0; k < L; ++k) {
    if (and_r[k] == 1) {
      a[x][k] = a[y][k] = 1;
    } else {
      if (a[x][k] == 1) {
        a[y][k] = 0;
      } else if (a[y][k] == 1) {
        a[x][k] = 0;
      }
    }
  }
}
std::vector<int> AskOr(int x, int y) {
  printf("or %d %d\n", x, y);
  fflush(stdout);
  int answer;
  scanf("%d", &answer);
  return GetBits(answer);
}
void ApplyOrResult(std::vector<std::vector<int>>* a_ptr, int x, int y,
                   const std::vector<int>& or_r) {
  std::vector<std::vector<int>>& a = (*a_ptr);
  for (int k = 0; k < L; ++k) {
    if (or_r[k] == 0) {
      a[x][k] = a[y][k] = 0;
    } else {
      if (a[x][k] == 0) {
        a[y][k] = 1;
      } else if (a[y][k] == 0) {
        a[x][k] = 1;
      }
    }
  }
}
}  // namespace
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(L, -1));
  for (int i = 1; i + 2 <= n; i += 3) {
    std::vector<int> and_0_1 = AskAnd(i, i + 1);
    std::vector<int> or_0_1 = AskOr(i, i + 1);
    std::vector<int> and_1_2 = AskAnd(i + 1, i + 2);
    std::vector<int> or_1_2 = AskOr(i + 1, i + 2);
    ApplyAndResult(&a, i, i + 1, and_0_1);
    ApplyOrResult(&a, i, i + 1, or_0_1);
    ApplyAndResult(&a, i + 1, i + 2, and_1_2);
    ApplyOrResult(&a, i + 1, i + 2, or_1_2);
    ApplyAndResult(&a, i, i + 1, and_0_1);
    ApplyOrResult(&a, i, i + 1, or_0_1);
    std::vector<int> and_0_2 = AskAnd(i, i + 2);
    for (int k = 0; k < L; ++k) {
      if (a[i][k] >= 0) {
        continue;
      }
      if (and_0_2[k] == 0) {
        a[i][k] = 0;
        a[i + 1][k] = 1;
        a[i + 2][k] = 0;
      } else {
        a[i][k] = 1;
        a[i + 1][k] = 0;
        a[i + 2][k] = 1;
      }
    }
  }
  for (int i = n - (n % 3) + 1; i <= n; ++i) {
    std::vector<int> and_r = AskAnd(1, i);
    std::vector<int> or_r = AskOr(1, i);
    ApplyAndResult(&a, 1, i, and_r);
    ApplyOrResult(&a, 1, i, or_r);
  }
  std::vector<int> array;
  for (int i = 1; i <= n; ++i) {
    array.push_back(GetValue(a[i]));
  }
  std::sort(array.begin(), array.end());
  printf("finish %d\n", array[k - 1]);
  return 0;
}
