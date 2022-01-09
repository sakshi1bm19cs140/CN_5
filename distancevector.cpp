#include <iostream>
#include <stdio.h>
using namespace std;
struct router
{
    int dist[10];
    int next[10];
} router[10];

int main()
{
    int no;
    cout << "Enter number of router : " << endl;
    cin >> no;
    cout << "Enter adjacency matrix : " << endl;
    int vt[no][no];
    for (int i = 0; i < no; i++)
    {
        for (int j = 0; j < no; j++)
        {
            cin >> router[i].dist[j];
            router[i].next[j] = j;
        }
        cout << endl;
    }
    for (int i = 0; i < no; i++)
    {
        for (int j = 0; j < no; j++)
        {
            for (int k = 0; k < no; k++)
            {
                if (router[i].dist[j] > router[i].dist[k] + router[k].dist[j])
                {
                    router[i].dist[j] = router[i].dist[k] + router[j].dist[k];
                    router[i].next[j] = k;
                }
            }
        }
    }

    for (int i = 0; i < no; i++)
    {
        cout << "Router info for router: " << i + 1 << endl;
        cout << "Dest\tNext Hop\tDist" << endl;
        for (int j = 0; j < no; j++)
            printf("%d\t%d\t\t%d\n", j + 1, router[i].next[j] + 1, router[i].dist[j]);
    }
    return 0;
}