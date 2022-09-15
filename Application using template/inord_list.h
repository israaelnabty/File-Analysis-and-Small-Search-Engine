#ifndef INORD_LIST_H_INCLUDED
#define INORD_LIST_H_INCLUDED
#include<iostream>
#include <algorithm>
using namespace std;


template<class ListElemType>
class inord_list
{private: struct Node{ListElemType elem;
                       Node* Next;
                       int LineNo;
                       int Frequency;};
          typedef Node* Link;
          Link head,Tail,Current;
          int distinct;
          ListElemType Frequent;


public:
         inord_list();
         bool saving;
         bool Insert(const ListElemType&e,int LNo);
         bool First(ListElemType&e);
         bool next(ListElemType&e);
         void outdistinct();
         void frequentelement();
         int countWord(const ListElemType& e);
         void starting(const ListElemType& e);
         void containing(const ListElemType& e);
         void Search(const ListElemType& e);


};

inord_list<string> TextList1;

template<class ListElemType>
inord_list<ListElemType>::inord_list()
{head=Tail=Current=NULL;saving=false;distinct=0;}

template<class ListElemType>
bool inord_list<ListElemType>::Insert(const ListElemType&e,int LNo)
{Link AddedNode,pred;
AddedNode=new Node;
if(AddedNode==NULL){return false;}
AddedNode->elem=e;  AddedNode->LineNo=LNo; AddedNode->Frequency=1;
if((head==NULL)||(e<head->elem)){if(head==NULL){distinct=1;}
                                 else if(e<head->elem){distinct++;}
                                 AddedNode->Next=head;head=AddedNode;}
else{pred=head;
while((pred->Next!=NULL)&&(pred->Next->elem<=e))
      {if(pred->Next->elem==e){AddedNode->Frequency++;}
        pred=pred->Next;}
     if((pred->elem)<e){distinct++;}
     AddedNode->Next=pred->Next;
     pred->Next=AddedNode;}
return true;
}

template<class ListElemType>
bool inord_list<ListElemType>::First(ListElemType&e)
{if(head==NULL){return false;}
else{Current=head;e=Current->elem;return true;}}


template<class ListElemType>
bool inord_list<ListElemType>::next(ListElemType&e)
{if((Current==NULL) || (Current->Next==NULL))
    {return false;}
 else{Current=Current->Next;e=Current->elem;return true;}
}


template<class ListElemType>
void inord_list<ListElemType>::outdistinct()
{if(saving==false){distinct=0;}
cout<<distinct<<" distinct words"<<'\n';}


template<class ListElemType>
void inord_list<ListElemType>::frequentelement()
{int i=1;ListElemType k;
if(saving==true)
{Link pred=head;
if((head->Frequency>i)&&(head->elem!="a")&&(head->elem!="an")&&(head->elem!="the")&&(head->elem!="in")&&(head->elem!="on")&&(head->elem!="of")&&(head->elem!="and")&&(head->elem!="is")&&(head->elem!="are")){i=head->Frequency;}
while(pred->Next!=NULL)
      {pred=pred->Next;
      if((pred->Frequency>i)&&(pred->elem!="a")&&(pred->elem!="an")&&(pred->elem!="the")&&(pred->elem!="in")&&(pred->elem!="on")&&(pred->elem!="of")&&(pred->elem!="and")&&(pred->elem!="is")&&(pred->elem!="are")){i=pred->Frequency;}}
pred=head;
if((head->Frequency==i)&&(pred->elem!="a")&&(pred->elem!="an")&&(pred->elem!="the")&&(pred->elem!="in")&&(pred->elem!="on")&&(pred->elem!="of")&&(pred->elem!="and")&&(pred->elem!="is")&&(pred->elem!="are")){TextList1.Insert(head->elem,0);}
while(pred->Next!=NULL)
      {pred=pred->Next;
      if((pred->Frequency==i)&&(pred->elem!="a")&&(pred->elem!="an")&&(pred->elem!="the")&&(pred->elem!="in")&&(pred->elem!="on")&&(pred->elem!="of")&&(pred->elem!="and")&&(pred->elem!="is")&&(pred->elem!="are")){TextList1.Insert(pred->elem,0);}}
cout<<"Most frequent word is: ";
if(TextList1.First(k)){cout<<k;}
while(TextList1.next(k)){cout<<" "<<k;}
}
else if(saving==false){cout<<"Most frequent word is: ";}
cout<<endl;
}

template<class ListElemType>
int inord_list<ListElemType>::countWord(const ListElemType& e)
{int j=0;
if(saving==true)
{Link pred=head;
if(pred->elem==e){j=pred->Frequency;}
while(pred->Next!=NULL)
      {pred=pred->Next;
      if(pred->elem==e){j=pred->Frequency;}}
}
else if(saving==false) {j=0;}
return j;
}


template<class ListElemType>
void inord_list<ListElemType>::starting(const ListElemType& e)
{if(saving==true)
    {Link pred=head;int j=0;ListElemType y;
if(pred->elem[0]==e[0] && pred->elem[1]==e[1])
    {y=pred->elem;
    j=countWord(y);
    cout<<y<<": "<<j;}
while(pred->Next!=NULL)
      {pred=pred->Next;
      if(pred->elem[0]==e[0] && pred->elem[1]==e[1])
        {if(pred->elem==y){}
         else{if(y[0]!='\0'){cout<<'\t';}
              y=pred->elem;
              j=countWord(y);
              cout<<y<<": "<<j;}}}
    }
else if(saving==false){cout<<" ";}
cout<<"\t\n";
}


template<class ListElemType>
void inord_list<ListElemType>::containing(const ListElemType& e)
{if(saving==true)
    {Link pred=head;int j=0;int i=0;int h=0;ListElemType y;bool ok=true;
for(i=0;pred->elem[i]!='\0'; )
{if(pred->elem[i]==e[0])
    {i++;for(h=1;(e[h]!='\0')&&(pred->elem[i] !='\0');h++)
        {if(pred->elem[i]!=e[h]){ok=false;break;}
          else{ok=true;i++;}}
     if(e[h]=='\0'){ok=true;break;} else if((e[h]!='\0')&&(pred->elem[i]=='\0')){ok=false;break;}
    }
 else{ok=false;i++;}

}
if(ok==true){y=pred->elem;
             j=countWord(y);
             cout<<y<<": "<<j;}

while(pred->Next!=NULL)
      {pred=pred->Next;
      for(i=0;pred->elem[i]!='\0';)
{if(pred->elem[i]==e[0])
    {i++;for(h=1;(e[h]!='\0')&&(pred->elem[i] !='\0');h++)
        {if(pred->elem[i]!=e[h]){ok=false;break;}
          else{ok=true;i++;}}
         if(e[h]=='\0'){ok=true;break;} else if((e[h]!='\0')&&(pred->elem[i]=='\0')){ok=false;break;}
    }
 else{ok=false;i++;}

}
if(ok==true){if(pred->elem==y){}
             else{if(y[0]!='\0'){cout<<'\t';}
                  y=pred->elem;
                  j=countWord(y);
                  cout<<y<<": "<<j;}}}
    }
else if(saving==false){cout<<" ";}

cout<<"\t\n";
}



template<class ListElemType>
void inord_list<ListElemType>::Search(const ListElemType& e)
{if(saving==true)
    {Link pred=head;int i=0;int h=0;ListElemType y;bool ok=true;
for(i=0;pred->elem[i]!='\0'; )
{if(pred->elem[i]==e[0])
    {i++;for(h=1;(e[h]!='\0')&&(pred->elem[i] !='\0');h++)
        {if(pred->elem[i]!=e[h]){ok=false;break;}
          else{ok=true;i++;}}
     if(e[h]=='\0'){ok=true;break;}
    }
 else{ok=false;i++;}

}
if(ok==true){y=pred->elem;
             cout<<y<<":\tlines "<<pred->LineNo;}

while(pred->Next!=NULL)
      {pred=pred->Next;
      for(i=0;pred->elem[i]!='\0';)
{if(pred->elem[i]==e[0])
    {i++;for(h=1;(e[h]!='\0')&&(pred->elem[i] !='\0');h++)
        {if(pred->elem[i]!=e[h]){ok=false;break;}
          else{ok=true;i++;}}
         if(e[h]=='\0'){ok=true;break;}
    }
 else{ok=false;i++;}

}
if(ok==true){if(pred->elem==y){cout<<" "<<pred->LineNo;}
             else{if(y[0]!='\0'){cout<<'\n';}
                  y=pred->elem;cout<<y<<":\tlines "<<pred->LineNo;}}}
    }
else if(saving==false){cout<<" ";}

cout<<endl;
}


#endif // INORD_LIST_H_INCLUDED
