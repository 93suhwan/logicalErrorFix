/*
MMMMMMMM               MMMMMMMM        KKKKKKKKK    KKKKKKK
M:::::::M             M:::::::M        K:::::::K    K:::::K
M::::::::M           M::::::::M        K:::::::K    K:::::K
M:::::::::M         M:::::::::M        K:::::::K   K::::::K
M::::::::::M       M::::::::::M        KK::::::K  K:::::KKK
M:::::::::::M     M:::::::::::M          K:::::K K:::::K
M:::::::M::::M   M::::M:::::::M          K::::::K:::::K
M::::::M M::::M M::::M M::::::M          K:::::::::::K
M::::::M  M::::M::::M  M::::::M          K:::::::::::K
M::::::M   M:::::::M   M::::::M          K::::::K:::::K
M::::::M    M:::::M    M::::::M          K:::::K K:::::K
M::::::M     MMMMM     M::::::M        KK::::::K  K:::::KKK
M::::::M               M::::::M        K:::::::K   K::::::K
M::::::M               M::::::M ...... K:::::::K    K:::::K
M::::::M               M::::::M .::::. K:::::::K    K:::::K
MMMMMMMM               MMMMMMMM ...... KKKKKKKKK    KKKKKKK
*/
#include <bits\stdc++.h>

using namespace std;

#define ll long long
#define dd double

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);
//-------------------------//

	int t;cin >> t;
	while (t--)
	{
		ll n;cin >> n;
		vector < ll > v(n + 1);
		for (int i = 1;i <= n;i++)
		{
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		ll ans = n, last = 0;
		for (int i = 1;i <= n;i++)
		{
			if (v[i] == i)
			{
				ans--;
				last = v[i];
			}
			else
				break;
		}
		for (int i = n - ans + 1;i <= n;i++)
		{
			last = max(last, v[i] / 2);
		}
		if (last >= n)
		{
			cout << ans << endl;
		}
		else
			cout << "-1" << endl;
	}
	return 0;
}