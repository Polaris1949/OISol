#include <iostream>
#include <iomanip>
#include <vector>

const double eps=0.0001;
int n, sum;
std::vector<int> a;

bool check(double x)
{
    int i;
    double res=a[1]-x, ans=a[1]-x;

    for (i=2; i<n-1; ++i)
    {
        if (res<0) res=0;
        res+=a[i]-x;
        if (res>ans) ans=res;
    }

    return ans>=sum-x*n;
}

int main()
{
    int i;
    std::cin >> n;
    a.resize(n);

    for (i=0; i<n; ++i)
    {
        std::cin >> a[i];
        sum+=a[i];
    }

    double l=1, r=100000000, mid;

    while (r-l>eps)
    {
        mid=(l+r)/2;
        if (check(mid)) r=mid;
        else l=mid;
    }

    std::cout << std::fixed << std::setprecision(3) << l << '\n';
    return 0;
}
