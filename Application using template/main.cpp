#include <iostream>
#include<fstream>
#include<string>
#include"inord_list.h"
using namespace std;

int LineNo1=0;int u;
string word,Lines;
string command,argument;
string b,f,g;
bool ok1=false;bool ok2=false;bool ok3=true;
ifstream filename;
ifstream commandsfile;

inord_list<string> TextList;


void Read_File1(char *argv[]);
void Read_File2(char *argv[]);
void CommandLines(char *argv[],string &comm,string &arg);
void wordCount(char *argv[]);
void charCount(char *argv[]);


int x;
int main(int argc,char *argv[])
{if(argc==3)
 {Read_File1(argv);
  Read_File2(argv);
  if(!(ok1&&ok2)){cout<<"File not found";}
  else {while(!commandsfile.eof())
        {CommandLines(argv,command,argument);
         if((command=="wordCount")&&(command[9]=='\0')){wordCount(argv);}
       else if((command=="distWords")&&(command[9]=='\0')){TextList.outdistinct();}
       else if((command=="charCount")&&(command[9]=='\0')){charCount(argv);}
       else if((command=="frequentWord")&&(command[12]=='\0')){TextList.frequentelement();}
       else if((command=="countWord")&&(command[9]=='\0')){if(argument[0]!='\0'){for(int j=0;argument[j]!='\0';j++)
                                                                {if((isdigit((argument[j])))||(!(isalpha(argument[j])))){}
                                                                  else if(islower(argument[j])){}
                                                                  else if(isupper(argument[j])){argument[j]+=32;}}
                                                                u=TextList.countWord(argument);
                                                                cout<<argument<<" is repeated "<<u<<" times\n";}
                                                          else{cout<<"Incorrect number of arguments\n";}}
       else if((command=="starting")&&(command[8]=='\0')){if(argument[0]!='\0'){for(int j=0;argument[j]!='\0';j++)
                                                                {if((isdigit((argument[j])))||(!(isalpha(argument[j])))){}
                                                                  else if(islower(argument[j])){}
                                                                  else if(isupper(argument[j])){argument[j]+=32;}}
                                                               TextList.starting(argument);}
                                                         else{cout<<"Incorrect number of arguments\n";}}
       else if((command=="containing")&&(command[10]=='\0')){if(argument[0]!='\0'){for(int j=0;argument[j]!='\0';j++)
                                                                {if((isdigit((argument[j])))||(!(isalpha(argument[j])))){}
                                                                  else if(islower(argument[j])){}
                                                                  else if(isupper(argument[j])){argument[j]+=32;}}
                                                                  TextList.containing(argument);}
                                                            else{cout<<"Incorrect number of arguments\n";}}
       else if((command=="search")&&(command[6]=='\0')){if(argument[0]!='\0'){for(int j=0;argument[j]!='\0';j++)
                                                                {if((isdigit((argument[j])))||(!(isalpha(argument[j])))){}
                                                                  else if(islower(argument[j])){}
                                                                  else if(isupper(argument[j])){argument[j]+=32;}}
                                                                  TextList.Search(argument);  }
                                                        else{cout<<"Incorrect number of arguments\n";}}

       else if(command[0]=='\0'){}
       else {cout<<"Undefined command\n";}}
}}

else{cout<<"Incorrect number of arguments";}
return 0;
}

void Read_File1(char *argv[])
{filename.open(argv[1],ios::in);TextList.saving=false;
 if((filename.is_open())&&(filename.good()))
  {ok1=true;string subline;int j;char aword[50];
  while(!filename.eof())
{getline(filename, Lines);
LineNo1++;
for(unsigned int i=0;i<Lines.length();i++)
{   j=0;aword[0]='\0';
    while((Lines[i]!=' ')&&(Lines[i]!='\0')&&(Lines[i]!='\t'))
    {aword[j]=Lines[i];i++;j++;
    if((Lines[i]==' ')||(Lines[i]=='\t')||(Lines[i]=='\0'))
        {aword[j]='\0';
        for(int j=0;aword[j]!='\0';j++)
        {if((isdigit((aword[j])))||(!(isalpha(aword[j])))){}
                                else if(islower(aword[j])){}
                                else if(isupper(aword[j])){aword[j]+=32;}
        // if(aword[j]=='.'&&aword[j]==';'&&aword[j]==','&&aword[j]=='-')
         //if(!isalnum(aword[j])){aword[j]='\0';}
         }
         subline=aword;
         TextList.Insert(subline,LineNo1);TextList.saving=true;
        }
    }
}
}  }

filename.close();
}

void Read_File2(char *argv[])
{commandsfile.open(argv[2],ios::in);
 if((commandsfile.is_open())&&(commandsfile.good()))
  {ok2=true;}
  }

void wordCount(char *argv[])
{int wordcounter=0;
filename.open(argv[1],ios::in);
while(filename>>word)
{wordcounter++;}
filename.close();
cout<<wordcounter<<" words\n";}



void charCount(char *argv[])
{int charcounter=0;char c;
filename.open(argv[1],ios::in);
{while(filename.get(c)){charcounter++;}

    /*getline(filename, Lines);
 for(unsigned i=0;i<Lines.length();i++)
    {charcounter++;}//charcounter=charcounter+Lines.length();*/
}
filename.close();
cout<<charcounter<<" characters\n";}


void CommandLines(char *argv[],string &comm,string &arg)
{int j;int r=0;char aword[50];comm[0]=arg[0]='\0';string arr[3];
   getline(commandsfile, Lines);
for(unsigned int i=0;i<Lines.length();i++)
{   j=0;aword[0]='\0';
    while((Lines[i]!=' ')&&(Lines[i]!='\0'))
    {aword[j]=Lines[i];i++;j++;
    if((Lines[i]==' ')||(Lines[i]=='\0'))
        {aword[j]='\0';
          arr[r]=aword;r++;}}
    comm=arr[0];
    arg=arr[1];
  if(Lines[i]!='\0'){ok3=false;}}
}
