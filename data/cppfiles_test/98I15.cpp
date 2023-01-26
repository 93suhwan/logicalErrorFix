#include <bits/stdc++.h>
int main() {
  int test_cases, word2[50];
  for (int i = 0; i < 50; ++i) word2[i] = 0;
  char keybord[27], word[51];
  scanf("%d", &test_cases);
  for (int i = 0; i < test_cases; ++i) {
    int result = 0;
    scanf("%s", keybord);
    scanf("%s", word);
    for (int j = 0; j < strlen(word); ++j) {
      for (int k = 0; k < 26; ++k) {
        if (word[j] == keybord[k]) {
          word2[j] = k + 1;
          break;
        }
      }
    }
    for (int l = 0; l < 50; ++l) {
      if (l > 0 && word2[l] != 0)
        result = result + abs(word2[l] - word2[l - 1]);
    }
    printf("%d\n", result);
  }
  return 0;
}
