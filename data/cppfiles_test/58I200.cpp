#include <bits\stdc++.h>
using namespace std;
int main()
{
    int num;
    cin >> num;
    while (num--)
    {
        int len;
        cin >> len;
        vector<char> t1;
        vector<char> t2;
        for (int i = 0; i < len; i++)
        {
            char temp;
            cin >> temp;
            t1.push_back(temp);
        }
        for (int i = 0; i < len; i++)
        {
            char temp;
            cin >> temp;
            t2.push_back(temp);
        }
        for (int i = 0; i < len; i++)
        {
            if (t1[i] == '1' && t2[i] == '1')
            {
                cout << "NO" << endl;
                break;
            }
        }
        cout << "YES" << endl;
    }
    return 0;
}