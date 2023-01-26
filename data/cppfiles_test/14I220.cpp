int t, n, m, x;
int main() {
	scanf("%d", &t);
	while (t--) {
		int a[2001] = {}, e = -1;
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &x);
			for (int j = i; j--;) {
				if (a[j + 1] < a[j])
					a[j + 1] = a[j];
				if (x == i - j)
					a[j]++;
				if (a[j] >= m && e < 0)
					e = j;
			}
		}
		printf("%d\n", e);
	}
}