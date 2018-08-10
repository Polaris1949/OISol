#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#define MAX_A 30
#define MAX_N 100
using namespace std;

int N, K, Npos;
int Nadj[MAX_A];
string adj[MAX_A][MAX_N];
string fj_list[MAX_N];

bool adjective_already_appears(int pos, string a)
{
  for (int i=0; i<Nadj[pos]; i++)
    if (adj[pos][i] == a) return true;
  return false;
}

int num_choices(int pos1, int pos2)
{
  int total = 1;
  for (int p=pos1; p<=pos2; p++)
    total *= Nadj[p];
  return total;
}

string get_kth_cow(int k)
{
  string s = "";
  for (int p=0; p<Npos; p++) {
    if (p>0) s = s + " ";
    s = s + adj[p][k / num_choices(p+1, Npos-1)];
    k = k % num_choices(p+1, Npos-1);
  }
  return s;
}

int num_before_on_fj_list(string s)
{
  int total = 0;
  for (int i=0; i<N; i++)
    if (fj_list[i] <= s) total++;
  return total;
}

int main(void)
{
  ifstream fin("nocow.in");
  fin >> N >> K;
  for (int i=0; i<N; i++) {
    string farmer, john, has, no, a;
    fin >> farmer >> john >> has >> no >> a;
    int pos = 0;
    fj_list[i] = "";
    while (a != "cow.") {
      if (pos > 0) fj_list[i] += " ";
      fj_list[i] += a;
      if (!adjective_already_appears(pos, a)) {
        adj[pos][Nadj[pos]] = a;
        Nadj[pos]++;
      }
      pos++;
      fin >> a;
    }
    Npos = pos;
  }
  fin.close();

  for (int pos=0; pos<Npos; pos++)
    sort (adj[pos], adj[pos]+Nadj[pos]);

  int k = K-1;
  while (k - num_before_on_fj_list(get_kth_cow(k)) < K-1)
    k++;

  ofstream fout("nocow.out");
  fout << get_kth_cow(k) << "\n";
  fout.close();

  return 0;
}
