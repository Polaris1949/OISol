#include <fstream>

using namespace std;
int n, w[20], best=0;

/* Can x and y be added with no carries? */
int check(int x, int y)
{
   for ( ; x>0 && y>0; x/=10,y/=10)
      if (x%10+y%10>=10) return 0;
   return 1;
}

/*
   x = index into w array we're currently considering (i.e., we have already
   added a subset of w[1...x-1] and are considering whether to add w[x]).
   sum = cumulative sum of subset added so far.
   count = number of elements in subset added so far.
*/
void rec(int x, int sum, int count)
{
   if (count>best) best=count;
   if (x>=n || count+n-x<=best) return;
   if (check(sum,w[x]))
      rec(x+1,sum+w[x],count+1);
   rec(x+1,sum,count);
}

int main()
{
   ifstream fin("escape.in");
   ofstream fout("escape.out");

   fin >> n;
   for (int i=0; i<n; i++)
      fin >> w[i];
   fin.close();

   rec(0,0,0);

   fout << best << endl;
   fout.close();
   return 0;
}
