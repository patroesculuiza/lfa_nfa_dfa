#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>
using namespace std;

ifstream f("date.in");
ofstream g("date.out");

struct nfa
{
    char sir2[31];
    int tip;
    struct muchii
    {
        char sir[31];
    }muchie[31];

}v[31],w[31];



void initializare(int &nr_stari, int &nr_muchii,nfa v[])
{


    f>>nr_stari;
    f>>nr_muchii;
    for(int i = 0 ; i < nr_stari ;i++)
    {
        v[i].sir2[0]='a'+i;
        f>>v[i].tip;
       for(int j = 0 ; j < nr_muchii ;j++)
       {

           f>>v[i].muchie[j].sir;

       }


    }
}

void dfa(int &nr_stari,int nr_muchii,nfa v[],nfa w[],int nr_stari_init)
{
   nr_stari=1;
    w[0]=v[0];
    for(int i = 0 ;i <nr_muchii;i++)
    {
       if(strcmp(w[0].sir2,w[0].muchie[i].sir))
        {
            nr_stari++;
            strcpy(w[nr_stari-1].sir2,w[0].muchie[i].sir);
        }
    }

    for(int i = 1 ;i <nr_stari+1;i++)
    {
        if(w[i].sir2[0]!='0'){
        for(int j = 0 ; j< nr_muchii;j++)
        {
         int temp[31]={0};
         int l=0;
         for(int p = 0 ; p <strlen(w[i].sir2);p++)
         {
            for(int l = 0 ; l < strlen(v[w[i].sir2[p]-'a'].muchie[j].sir);l++)
             temp[v[w[i].sir2[p]-'a'].muchie[j].sir[l]-'a']=1;
             l+=v[w[i].sir2[p]-'a'].tip;

         }
         if(l!=0) w[i].tip=1;
         int ok=1;l=0;
         for(int p = 0 ; p <nr_stari_init;p++)
         {
             if(temp[p]==1)  {w[i].muchie[j].sir[l]=p+'a';l++;ok=0;}

         }
        // g<<endl;
         if(ok==1) w[i].muchie[j].sir[0]='0';
          ok=1;
         for(int l = 0 ; l <nr_stari;l++)
         {
             if(strcmp(w[l].sir2,w[i].muchie[j].sir)==0) ok=0;
         }

         if(ok==1 && w[i].muchie[j].sir[0]!='0') {
           //  g<< w[i].muchie[j].sir<<" ";
                    nr_stari++;
                    strcpy(w[nr_stari-1].sir2,w[i].muchie[j].sir);
                                 }

        }
        }
    }
}


void afisare(nfa w[],int nr_muchii,int nr_stari)
{

    for(int i = 0 ; i < nr_stari ; i++)
    {
        g<<w[i].sir2<<" ";
        if(w[i].tip==1) g<<"f ";
        else g<<"n ";
        for(int j = 0 ; j < nr_muchii ; j++)
        {
            g<<j<<" "<<w[i].muchie[j].sir<<" ";
        }
        g<<endl;
    }

}
int main()
{
  int nr_muchii,nr_stari,nr_stari_w;
  initializare(nr_stari,nr_muchii,v);
  dfa(nr_stari_w,nr_muchii,v,w,nr_stari);
  afisare(w,nr_muchii,nr_stari_w);
}
