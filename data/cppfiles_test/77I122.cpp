#include <bits/stdc++.h>
typedef struct ivector {
  int *data;
  int size;
  int capacity;
} ivector;
ivector *initialize() {
  ivector *result = (ivector *)malloc(sizeof(ivector));
  result->data = (int *)malloc(sizeof(int) * 10);
  result->size = 0;
  result->capacity = 10;
  return result;
}
void push(ivector *vector, int element) {
  if (vector->size < vector->capacity)
    vector->data[vector->size++] = element;
  else {
    vector->capacity *= 2;
    int *tmp = (int *)malloc(sizeof(int) * vector->capacity);
    memmove(tmp, vector->data, sizeof(int) * vector->size);
    free(vector->data);
    vector->data = tmp;
  }
}
void merge(int *A, int start, int center, int end) {
  int lsize = center - start;
  int rsize = end - center;
  int *L = (int *)malloc(sizeof(int) * lsize);
  int *R = (int *)malloc(sizeof(int) * rsize);
  memmove(L, A + start, sizeof(int) * lsize);
  memmove(R, A + center, sizeof(int) * rsize);
  for (int i = start, j = 0, k = 0; i < end; i++) {
    if (j == lsize)
      A[i] = R[k++];
    else if (k == rsize)
      A[i] = L[j++];
    else if (L[j] > R[k])
      A[i] = L[j++];
    else
      A[i] = R[k++];
  }
  free(L);
  free(R);
}
void msort(int *A, int start, int end) {
  if (end - start > 1) {
    int center = (start + end) / 2;
    msort(A, start, center);
    msort(A, center, end);
    merge(A, start, center, end);
  }
}
void binary(int decimal, char *result) {
  int i = 3;
  while (decimal > 0) {
    result[i--] = decimal % 2;
    decimal /= 2;
  }
  while (i >= 0) result[i--] = 0;
}
int room(char ***tiles, int i, int j, char **explored) {
  explored[i][j] = 1;
  int total = 1;
  char *borders = tiles[i][j];
  if (!borders[0] && !explored[i - 1][j])
    total += room(tiles, i - 1, j, explored);
  if (!borders[1] && !explored[i][j + 1])
    total += room(tiles, i, j + 1, explored);
  if (!borders[2] && !explored[i + 1][j])
    total += room(tiles, i + 1, j, explored);
  if (!borders[3] && !explored[i][j - 1])
    total += room(tiles, i, j - 1, explored);
  return total;
}
int main() {
  int n, m, x;
  scanf("%d %d", &n, &m);
  char ***tiles = (char ***)malloc(sizeof(char **) * n);
  char **explored = (char **)malloc(sizeof(char *) * n);
  ivector *rooms = initialize();
  for (int i = 0; i < n; i++) {
    tiles[i] = (char **)malloc(sizeof(char *) * m);
    explored[i] = (char *)malloc(sizeof(char) * m);
    for (int j = 0; j < m; j++) {
      tiles[i][j] = (char *)malloc(sizeof(char) * 4);
      scanf("%d", &x);
      binary(x, tiles[i][j]);
      explored[i][j] = 0;
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (!explored[i][j]) push(rooms, room(tiles, i, j, explored));
  msort(rooms->data, 0, rooms->size);
  for (int i = 0; i < rooms->size; i++) printf("%d ", rooms->data[i]);
  return 0;
}
