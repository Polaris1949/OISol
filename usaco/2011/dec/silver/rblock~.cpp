#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

FILE *in = fopen ("rblock.in", "r"), *out = fopen ("rblock.out", "w");

const int MAXN = 505;

int N, M, edge [MAXN][MAXN], dist [MAXN], prev [MAXN];
bool visited [MAXN];

int best_path (int start, int end)
{
    memset (dist, 63, sizeof (dist));
    memset (visited, false, sizeof (visited));
    memset (prev, -1, sizeof (prev));
    dist [start] = 0;

    while (true)
    {
        int close = -1;

        for (int i = 0; i < N; i++)
            if (!visited [i] && (close == -1 || dist [i] < dist [close]))
                close = i;

        if (close == -1)
            break;

        visited [close] = true;

        for (int i = 0; i < N; i++)
        {
            int ndist = dist [close] + edge [close][i];

            if (ndist < dist [i])
            {
                dist [i] = ndist;
                prev [i] = close;
            }
        }
    }

    return dist [end];
}

int main ()
{
    memset (edge, 63, sizeof (edge));
    fscanf (in, "%d %d", &N, &M);

    for (int i = 0; i < M; i++)
    {
        int a, b, len;
        fscanf (in, "%d %d %d", &a, &b, &len);
        a--; b--;
        edge [a][b] = edge [b][a] = len;
    }

    int original = best_path (0, N - 1);
    vector <int> path;

    for (int i = N - 1; i != -1; i = prev [i])
        path.push_back (i);

    int most_doubled = original;

    for (int i = 0; i + 1 < (int) path.size (); i++)
    {
        int a = path [i], b = path [i + 1];
        edge [a][b] *= 2;
        edge [b][a] *= 2;
        most_doubled = max (most_doubled, best_path (0, N - 1));
        edge [a][b] /= 2;
        edge [b][a] /= 2;
    }

    fprintf (out, "%d\n", most_doubled - original);
    return 0;
}
