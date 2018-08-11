#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

FILE *in = fopen ("umbrella.in", "r"), *out = fopen ("umbrella.out", "w");

const int MAXN = 5005, MAXM = 100005;

int N, M, X [MAXN], min_len_cost [MAXM];
int dp [MAXN];

int main ()
{
    fscanf (in, "%d %d", &N, &M);

    for (int i = 0; i < N; i++)
        fscanf (in, "%d", X + i);

    sort (X, X + N);

    for (int i = 0; i < M; i++)
        fscanf (in, "%d", min_len_cost + i);

    for (int i = M - 2; i >= 0; i--)
        min_len_cost [i] = min (min_len_cost [i], min_len_cost [i + 1]);

    memset (dp, 63, sizeof (dp));
    dp [0] = 0;

    for (int n = 1; n <= N; n++)
        for (int i = 0; i < n; i++)
            dp [n] = min (dp [n], dp [i] + min_len_cost [X [n - 1] - X [i]]);

    fprintf (out, "%d\n", dp [N]);
    return 0;
}
