#include <bits/stdc++.h>
using namespace std;
int n, m, aux;
int condominio[1001][1001];
string condominio_bin[1001][1001];
vector<int> salas;
string converte_dec_bin(int dec) {
  string pre_result = "", result = "";
  while (true) {
    if (dec == 0) {
      pre_result += "0";
      break;
    }
    if (dec % 2 == 0)
      pre_result += "0";
    else
      pre_result += "1";
    if (dec <= 1) break;
    dec /= 2;
  }
  for (int i = 4 - pre_result.size(); i > 0; i--) {
    result += '0';
  }
  for (int i = pre_result.size() - 1; i >= 0; i--) {
    result += pre_result[i];
  }
  return result;
}
int levantamento(int x, int y, int result) {
  condominio[x][y] = 1;
  if (x > 0 & condominio_bin[x][y][0] == '0' & condominio[x - 1][y] == 0)
    result = max(result, levantamento(x - 1, y, result + 1));
  if (y < (m - 1) & condominio_bin[x][y][1] == '0' & condominio[x][y + 1] == 0)
    result = max(result, levantamento(x, y + 1, result + 1));
  if (x < (n - 1) & condominio_bin[x][y][2] == '0' & condominio[x + 1][y] == 0)
    result = max(result, levantamento(x + 1, y, result + 1));
  if (y > 0 & condominio_bin[x][y][3] == '0' & condominio[x][y - 1] == 0)
    result = max(result, levantamento(x, y - 1, result + 1));
  return result;
}
int main() {
  scanf("%d %d", &n, &m);
  for (size_t i = 0; i < n; i++)
    for (size_t j = 0; j < m; j++) {
      scanf("%d", &aux);
      condominio_bin[i][j] = converte_dec_bin(aux);
      condominio[i][j] = 0;
    }
  for (size_t i = 0; i < n; i++)
    for (size_t j = 0; j < m; j++)
      if (condominio[i][j] == 0) salas.push_back(levantamento(i, j, 1));
  sort(salas.begin(), salas.end());
  reverse(salas.begin(), salas.end());
  for (int i = 0; i < salas.size(); i++) {
    printf("%d ", salas[i]);
  }
  printf("\n");
}
