#include <iostream>
#include <queue>

using namespace std;

queue <int> cloc;
queue <int> antcloc;
queue <int> outced;

int n, k, m, outc, outa, a;
bool first;

int main ()
{
    while(cin >> n >> k >> m)
    {
        cin >> n >> k >> m;

        if(n == 0)
            return 0;

        first = true;

        for(int i = 1; i < n; i ++)
            antcloc.push(i);

        for(int i = n; i > 0; i--)
            cloc.push(i);

        while( n != 0)
        {
            if(!first)
            {
                printf(",");
            }
            else
            {
                first = false;
            }

            for(int i = 1; i < k; i++)
            {
                antcloc.push(antcloc.front());
                antcloc.pop();
            }

            outa = antcloc.front();
            antcloc.pop();
            n--;
            
            for(int i = 1; i < m; i++)
            {
                cloc.push(cloc.front());
                cloc.pop();
            }

            if(outa == cloc.front())
            {
                cloc.pop();
            }
            else
            {
                outc = cloc.front();
                cloc.pop();
                n--;
                for(a = 0; cloc.front() != outa; a++)
                {
                    cloc.push(cloc.front());
                    cloc.pop();
                }

                cloc.pop();

                for(a <= n; a++;)
                {
                    cloc.push(cloc.front());
                    cloc.pop();
                }

                for(a = 0; antcloc.front() != outc; a++)
                {
                    antcloc.push(antcloc.front());
                    antcloc.pop();
                }

                antcloc.pop();

                for(a <= n; a++;)
                {
                    antcloc.push(antcloc.front());
                    antcloc.pop();
                }
            }

        }
        
    }
}
