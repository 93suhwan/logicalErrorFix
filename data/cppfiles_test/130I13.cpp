#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define var(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define mem(x, n) memset(x, n, sizeof(x))
#define all(x) x.begin(), x.end()
#define sz(x) ((int)x.size())
#define vec vector
#define endl "\n"

int ask(int a, int b, int c)
{
	assert(a != b && a != c);
	assert(b != c);

	//	assert( a> 0 && b > 0 && c > 0);
	cout << "? " << a << " " << b << " " << c << endl;
	cout.flush();

	int x;
	cin >> x;

	if (x == -1)
	{
		exit(0);
	}

	return x;
}

void print(vec<int> &imposters)
{
	cout << "! " << sz(imposters);

	for (auto &x : imposters)
	{
		cout << " " << x;
	}
	cout << endl;
	cout.flush();
}

void run_case([[maybe_unused]] const int &TC)
{
	int n;
	cin >> n;

	auto crew = vec(0, 0);

	auto imp = vec(0, 0);

	for (int i = 1; i <= n; i += 3)
	{
		if (ask(i, i + 1, i + 2))
		{
			crew = vec{i, i + 1, i + 2};
		}
		else
		{
			imp = vec{i, i + 1, i + 2};
		}
	}

	auto mark = vec(n + 1, -1);

	assert(sz(crew) && sz(imp));

	int a = imp[1], b = imp[2];

	vec<int> res(3, 0);

	for (int j = 0; j < 3; j++)
	{
		res[j] = ask(a, b, crew[j]);
	}

	if (*max_element(all(res)) == 1)
	{
		for (int j = 0; j < 3; j++)
		{
			mark[crew[j]] = res[j];
		}
		if (*min_element(all(res)) != 0)
		{
			mark[imp[0]] = 0;
		}
	}
	else
	{
		mark[a] = 0;
		mark[b] = 0;

		bool found = false;

		for (int i = 0; i < 2; i++)
		{
			int cr_a = crew[0], cr_b = crew[2];

			if (i == 0)
			{
				cr_a = crew[1], cr_b = crew[2];
			}

			if (ask(cr_a, cr_b, a))
			{
				mark[cr_a] = 1;
				mark[cr_b] = 1;
				found = true;
				break;
			}
		}

		if (!found)
		{
			mark[crew[0]] = 1;
			mark[crew[1]] = 1;
		}
	}

	int crew_ind = -1, imp_ind = -1;

	for (int i = 1; i <= n; i++)
	{
		if (mark[i] == 1)
		{
			crew_ind = i;
		}
		if (mark[i] == 0)
		{
			imp_ind = i;
		}
	}

	auto all_imps = vec(0, 0);

	for (int i = 1; i <= n; i++)
	{
		if (mark[i] == -1)
		{
			if (ask(crew_ind, imp_ind, i))
			{
				mark[i] = 1;
			}
			else
			{
				mark[i] = 0;
			}
		}

		if (mark[i] == 0)
		{
			all_imps.push_back(i);
		}
	}

	print(all_imps);
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0);

	int t = 1;
	cin >> t;

	for (int tc = 1; tc <= t; tc++)
		run_case(tc);

	return 0;
}