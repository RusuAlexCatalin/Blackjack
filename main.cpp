#include <iostream>
#include <cstring>
#include <time.h>
#include <stdlib.h>
using namespace std;
int nr=51,s1=0,s2=0,y=1,i,x,ok=1,p1=1,p2=2;
struct Card{
                 int key;       //1, 2, ... or 52
                 char suit[20];      //cupa, romb, trefla or pica
                 int rank;      //1, 2, ... or 13
                 Card *next;
                 };
Card *ales,*da;
class CardDeck{
      private:
             struct Card *head;
             int numberOfCards;
      public:
             CardDeck(int k,char s[20],int r){
                    head=new Card;
                    head->key=k;
                    strcpy(head->suit,s);
                    head->rank=r;
                    head->next=NULL;
                    }
             ~CardDeck(){
                    while(head!=NULL)
                       {Card *el=head->next;
                    delete head;
                    head=el;
                     }
             }
             Card* popCard(int i){
                 Card *el=head;
                    while(el!=NULL && el->key!=i)
                        el=el->next;
                    return el;
                  }
                  void stergeelem(Card *elem)
                  {int j;
                      Card *elsterg=elem->next;
                      elem->next=elem->next->next;
                      delete elsterg;
                      j=elem->key+1;
                       while(elem->next !=NULL)
                        {elem->key=j-1;
                        j++;
                      elem=elem->next;}
                      if(elem->next==NULL)
                        elem->key=j-1;
                  }
                  void AdaugaFinal(int k,char s[20],int r)
                  {
                      Card *el=head;
                      while(el->next !=NULL)
                        el=el->next;
                      Card *nodnou=new Card;
                      nodnou->key=k;
                      strcpy(nodnou->suit,s);
                      nodnou->rank=r;
                      nodnou->next=NULL;
                      el->next=nodnou;
                  }
                  void afisarecarte(Card *ales)
                  {
                      if(ales->rank==1) cout<<"As de "<<ales->suit<<endl;
else if(ales->rank==12) cout<<"Valet de "<<ales->suit<<endl;
else if(ales->rank==13) cout<<"Dama de "<<ales->suit<<endl;
else if(ales->rank==14) cout<<"Popa de "<<ales->suit<<endl;
else cout<<ales->rank<<" de "<<ales->suit<<endl;
                  }
                  int suma(Card *el,int s)
                  {
                      if(el->rank>10) s=s+10;
                      else s=s+el->rank;
                      return s;
                  }
};
CardDeck mydeck(0,"joker",0);
int joc(int y,int p,int j,int s)
{while(y)
    {cout<<"Mai trageti o carte jucatorul "<<p<<"? 1/0"<<endl;
    cin>>y;
       if(y){ nr--;
        i=rand()%nr+1;
        ales=mydeck.popCard(i);
mydeck.afisarecarte(ales);
if(ales->rank==1) {cout<<"Ce valoare doriti sa aibe asul 1 sau 11?"<<endl;
cin>>x;s=s+x;}
else s=mydeck.suma(ales,s);
da=mydeck.popCard(i-1);
mydeck.stergeelem(da);
cout<<s<<endl;}
if(s>21) {cout<<"Jucatorul "<<j<<" a castigat!"<<endl;ok=0;return ok;}
    }
if(p==1) {s1=s;return s1;}
else {s2=s;return s2;}
}
int trage2carti(int s,int p)
{i=rand()%nr+1;
    ales=mydeck.popCard(i);
    mydeck.afisarecarte(ales);
        if(ales->rank==1) {cout<<"Ce valoare doriti sa aibe asul 1 sau 11?"<<endl;
                cin>>x;s=s+x;}
        else s=mydeck.suma(ales,s);
    da=mydeck.popCard(i-1);
    mydeck.stergeelem(da);
    nr--;
    i=rand()%nr+1;
ales=mydeck.popCard(i);
mydeck.afisarecarte(ales);
if(ales->rank==1) {cout<<"Ce valoare doriti sa aibe asul 1 sau 11?"<<endl;
cin>>x;s=s+x;}
else s=mydeck.suma(ales,s);
da=mydeck.popCard(i-1);
mydeck.stergeelem(da);
cout<<s<<endl;
nr--;
    if(p==1) {s1=s;return s1;}
else {s2=s;return s2;}
}
int main(){
for(i=1;i<=14;i++)
          {if(i<11) mydeck.AdaugaFinal(i,"pica",i);
             else if(i==11) i=11;
                else mydeck.AdaugaFinal(i-1,"pica",i);
          }
          for(i=14;i<=27;i++)
          {if(i<24) mydeck.AdaugaFinal(i,"cupa",i+1-14);
             else if(i==24) i=24;
               else mydeck.AdaugaFinal(i-1,"cupa",i+1-14);
          }
          for(i=27;i<=40;i++)
          {if(i<37) mydeck.AdaugaFinal(i,"trefla",i+1-27);
             else if(i==37) i=37;
              else  mydeck.AdaugaFinal(i-1,"trefla",i+1-27);
          }
          for(i=40;i<=53;i++)
          {if(i<50) mydeck.AdaugaFinal(i,"romb",i+1-40);
             else if(i==50) i=50;
             else   mydeck.AdaugaFinal(i-1,"romb",i+1-40);
          }
srand(time(NULL));
cout<<"Jucatorul 1 primeste carti:"<<endl;
trage2carti(s1,1);
cout<<"Jucatorul 2 primeste carti:"<<endl;
trage2carti(s2,2);
joc(y,p1,p2,s1);
    if(ok) y=1;
    joc(y,p2,p1,s2);
if(s1>s2 && ok) cout<<"Jucatorul 1 a castigat"<<endl;
else if(s2>s1 && ok) cout<<"Jucatorul 2 a castigat"<<endl;
else if(s1==s2 && ok) cout<<"Remiza"<<endl;
}
