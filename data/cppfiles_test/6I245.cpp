#include <bits/stdc++.h>
typedef long long int ll;
const unsigned int MOD = 1000000007;

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


    int n,m;
    cin>>n>>m;

    int frnds[n]={0};

    int noble=n;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        if(x>y)
            swap(x,y);

        x--,y--;

        if(frnds[x]==0)
            noble--;

        frnds[x]++;        
    }

    int q;
    cin>>q;

    while(q--)
    {
        int qt;
        cin>>qt;

        if(qt==1)
        {
            int x, y;
            cin >> x >> y;
            if (x > y)
                swap(x, y);

            --x,--y;
            if (frnds[x] == 0)
                noble--;
            frnds[x]--;
        }

        if (qt == 2)
        {
            int x, y;
            cin >> x >> y;
            if (x > y)
                swap(x, y);

            --x, --y;

            frnds[x]--;
            if (frnds[x] == 0)
                noble++;
        }

        if (qt == 3)
        {
            cout << noble << '\n';
        }
    }
  
 
  return 0;
}