#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;

struct oil
{
    double cost, x;
    oil(double c, double n) : cost(c), x(n) {}
};

double d1, c, d2, D[10], P[10], ans, nc;
int n;
deque<oil> p;

int main()
{
    scanf("%lf%lf%lf%lf%d", &d1, &c, &d2, &P[0], &n);
    for(int i=1; i<=n; i++)
    {
        scanf("%lf%lf", &D[i], &P[i]);
        if(D[i] - D[i-1] > c * d2)
        {
            printf("No Solution\n");
            return 0;
        }
    }
    D[n+1] = d1;
    p.push_back(oil(P[0], nc = c));
    ans += P[0] * c;
    for(int i=1; i<=n+1; i++)
    {
        double nd = (D[i] - D[i-1]) / d2;
        while(!p.empty() && nd > 0)
        {
            oil front = p.front(); p.pop_front();
            if(front.x > nd)
            {
                nc -= nd;
                p.push_front(oil(front.cost, front.x - nd));
                break;
            }
            nc -= front.x; nd -= front.x;
        }
        if(i == n+1)
        {
            while(!p.empty())
            {
                ans -= p.front().cost * p.front().x;
                p.pop_front();
            }
            break;
        }
        while(!p.empty() && p.back().cost > P[i])
        {
            ans -= p.back().cost * p.back().x;
            nc -= p.back().x;
            p.pop_back();
        }
        ans += (c - nc) * P[i];
        p.push_back(oil(P[i], c - nc));
        nc = c;
    }
    printf("%.2lf\n", ans);
    return 0;
}
