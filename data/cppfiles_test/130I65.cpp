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

	auto save = vec(n + 1, 0);

	for (int i = 1; i <= n; i += 3)
	{
		if (ask(i, i + 1, i + 2))
		{
			save[i] = 1;
			crew = vec{i, i + 1, i + 2};
		}
		else
		{
			save[i] = 0;
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

	auto op = vec(n + 1, -1);

	if (*max_element(all(res)) == 1)
	{
		op[imp[1]] = imp[2];
		op[imp[2]] = imp[1];

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
				if (i != 0)
				{
					mark[crew[0]] = 0;
				}
				found = true;
				break;
			}
			else
			{
				op[cr_a] = cr_b;
				op[cr_b] = cr_a;
			}
		}

		if (!found)
		{
			mark[crew[0]] = 1;
			mark[crew[1]] = 1;
			mark[crew[2]] = 0;
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

	for (int i = 1; i <= n; i += 3)
	{
		auto unknown = vec(0, 0);
		auto known = vec(0, 0);

		for (int j = 0; j < 2; j++)
		{
			if (op[i + j] != -1 && mark[op[i + j]] != -1)
			{
				mark[i + j] = !mark[op[i + j]];
			}

			if (mark[i + j] == -1)
			{
				unknown.push_back(i + j);
			}
			else
			{
				known.push_back(i + j);
			}
		}

		while (sz(unknown) > 1)
		{
			if (ask(crew_ind, imp_ind, unknown.back()))
			{
				mark[unknown.back()] = 1;
			}
			else
			{
				mark[unknown.back()] = 0;
			}
			known.push_back(unknown.back());
			unknown.pop_back();
		}

		if (sz(unknown))
		{
			if (mark[known[0]] != mark[known[1]])
			{
				mark[unknown.back()] = save[i];
			}
			else
			{
				mark[unknown.back()] = ask(crew_ind, imp_ind, unknown.back());
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
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