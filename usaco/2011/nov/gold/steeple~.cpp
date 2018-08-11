
#include <cstdio>
#include <cstring>
#include <vector>
#include <cassert>
using namespace std;

const int MAXN = 10005;

struct DfsMatch
{
    const static int MAXA = MAXN, MAXB = MAXN, INF = 1000000005;

    int A, B, elast [MAXA];
    int start, vis [MAXA], prev [MAXB];
    vector <int> eadj, eprev;

    inline DfsMatch ()
    {
        A = B = -1;
    }

    inline void init (int a, int b)
    {
        A = a; B = b;
        memset (elast, -1, A * sizeof (int));
        eadj.clear ();
        eprev.clear ();
    }

    inline void addedge (int a, int b)
    {
        eadj.push_back (b); eprev.push_back (elast [a]); elast [a] = eprev.size
() - 1;
    }

    bool dfs (int num)
    {
        if (vis [num] == start)
            return false;

        vis [num] = start;

        for (int i = elast [num]; i != -1; i = eprev [i])
            if (prev [eadj [i]] == -1)
            {
                prev [eadj [i]] = num;
                return true;
            }

        for (int i = elast [num]; i != -1; i = eprev [i])
            if (dfs (prev [eadj [i]]))
            {
                prev [eadj [i]] = num;
                return true;
            }

        return false;
    }

    int match ()
    {
        if (A == -1 && B == -1)
            return -INF;

        memset (prev, -1, B * sizeof (int));
        memset (vis, -1, A * sizeof (int));
        int total = 0;

        for (int i = 0; i < A; i++)
        {
            start = i;

            if (dfs (i))
                total++;
        }

        return total;
    }
};

FILE *in = fopen ("steeple.in", "r"), *out = fopen ("steeple.out", "w");

struct hseg
{
    int x1, x2, y;
};

struct vseg
{
    int x, y1, y2;
};

bool intersect (hseg h, vseg v)
{
    return (v.y1 <= h.y && h.y <= v.y2) && (h.x1 <= v.x && v.x <= h.x2);
}

int N, H, V;
hseg horiz [MAXN];
vseg vert [MAXN];
DfsMatch graph;

int main ()
{
    fscanf (in, "%d", &N);
    H = V = 0;

    for (int i = 0; i < N; i++)
    {
        int x1, y1, x2, y2;
        fscanf (in, "%d %d %d %d", &x1, &y1, &x2, &y2);
        assert ((x1 == x2) ^ (y1 == y2));

        if (x2 < x1)
            swap(x1, x2);
        if (y2 < y1)
            swap(y1, y2);

        if (y1 == y2)
            horiz [H++] = (hseg) {x1, x2, y1};
        else
            vert [V++] = (vseg) {x1, y1, y2};
    }

    graph.init (H, V);

    for (int i = 0; i < H; i++)
        for (int j = 0; j < V; j++)
            if (intersect (horiz [i], vert [j]))
                graph.addedge (i, j);

    fprintf (out, "%d\n", N - graph.match ());
    return 0;
}
