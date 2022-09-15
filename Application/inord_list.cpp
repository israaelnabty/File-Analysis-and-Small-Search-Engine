/*
 * inord_list.cpp
 *
 *  Created on: 11 Apr 2016
 *      Author: Fatma Mostafa
 */
#include <iostream>
#include <string>
#include <cstring>
#include "inord_list.h"


inord_list :: inord_list()
{
	head=current=NULL;
}

bool inord_list :: insert ( const ListElementType & e , int & l )
{

	link addedNode;
	addedNode=new node;
	if (addedNode==NULL)
		return false;
	else
	{
		addedNode->elem =e;
		addedNode->line_num=l;

		if ( head==NULL || e<=head->elem )
		{
			if ( head!=NULL && e==head->elem )
			{
				addedNode->next=head->next;
				head->next=addedNode;
				return true;

			}
			else
			{
			addedNode->next=head;
			head=addedNode;
			return true;
			}

		}

		else
		{
			link pred;
			pred=head;
			while ( pred->next != NULL && pred->next->elem <=e )
			{
				pred = pred->next ;
			}
			if ( pred->next != NULL && e == pred->next->elem )
			{
				link pred2=pred->next;
				addedNode->next=pred2->next;
				pred2->next=addedNode;

			}
			else
			{
				addedNode->next = pred->next ;
				pred->next = addedNode ;
			}


			return true ;
		}
	}
}






bool inord_list :: first ( ListElementType & e  )
{

	if ( head==NULL ) return false;
	else
	{
		current = head ;
		e = current->elem ;
		return true ;

	}

}


bool inord_list :: next ( ListElementType & e  )
{

	if ( current == NULL || current->next == NULL ) return false;
	else
	{
		current = current->next ;
		e = current->elem ;
		return true ;
	}


}

/*void inord_list :: order ()
{
	link ord;
	ord=head;


}*/



string inord_list :: to_lower(ListElementType e  )


{
	string word;
	word=e;
	for ( int i = 0; i < word.size(); i++ )
	{


		if (isupper(word.at(i)))
			word.at(i)=tolower ( word.at(i) );


	}

return word;




}



int inord_list :: dist_word()
{
	link w1;

	int temp;
	temp=0;
	w1 = head ;
	while ( w1->next != NULL)

	{

		if ( w1->elem ==  w1->next->elem  )
		{
			temp++;

			while ( (w1->elem ==  w1->next->elem ) && ( w1->next->next !=NULL )  )
			{

				w1 = w1->next ;

				if ( w1->next->next == NULL )
				{
					cout<<"e"<<endl;
					if( w1 != w1->next )
						temp++;
				}


			}
			w1 = w1->next ;

		}
		else

			if ( ( w1->elem !=  w1->next->elem ) && ( w1->next->next == NULL ) )
			{


				temp=temp+2;
				w1 = w1->next ;
			}
			else
			if(	w1->elem !=  w1->next->elem )
			{

				temp++;
				w1 = w1->next ;
			}


	}




	return temp;



}




int inord_list ::countWord_Myword( ListElementType f )
{
	int j=0;
	link f1;
	f1=head;
	while ( f1 != NULL )
	{
		if ( f1->elem == f)
			j++;
		f1=f1->next;
	}



	return j;
}

void inord_list :: starting ( ListElementType  e )
{

	int i;
	int j=0;
	link f1;
	f1=head;
	while ( f1 != NULL)
	{

		i=e.size();
		if( f1->elem.substr(0,i) == e )
		{

			j=1;
			while ( f1->elem == f1->next->elem)
			{
				j++;
				f1=f1->next;
			}
			cout<<f1->elem<<": "<<j<<'\t';
			f1=f1->next;


		}
		else
			f1=f1->next;



    }


	cout<<endl;

}



void inord_list :: containing_mystr ( ListElementType  e )
{

	int j=0;
	link f1;
	f1=head;
	while ( f1 != NULL)
	{

		if ( f1->elem.find(e) != -1 )
		{

			j=1;
			while ( f1->elem == f1->next->elem)
			{
				j++;
				f1=f1->next;
			}
			cout<<f1->elem<<": "<<j<<'\t';
			f1=f1->next;

		}
		else
			f1=f1->next;



	}


	cout<<endl;
}

void inord_list :: search ( ListElementType  e )
{


	link f1;
	f1=head;
	while ( f1 != NULL)
	{

	if ( f1->elem.find(e) != -1 )
	{



		cout<<f1->elem<<":"<<'\t'<<"lines "<<f1->line_num<<" ";
		while ( f1->elem == f1->next->elem)
		{

			f1=f1->next;
			cout<<f1->line_num<<" ";


		}
		cout<<endl;

		f1=f1->next;

	}
	else
		f1=f1->next;



}





}




void inord_list :: freq_list ( inord_list & file2 )
{

	link freq1;
	freq1=head;
	int i=1;
	while ( freq1->next->next != NULL )
	{
		i=1;
		if ( freq1->elem != freq1->next->elem  )
		{
			if( freq1->elem != "a" && freq1->elem != "an" && freq1->elem != "the" && freq1->elem != "in" && freq1->elem != "on" && freq1->elem != "of" && freq1->elem != "and" && freq1->elem != "is" && freq1->elem != "are" )
			{

				file2.insert ( freq1->elem , i );


			}
			freq1 = freq1->next;

		}
		else
		{
			while ( freq1->elem == freq1->next->elem )
			{
				i++;
				freq1 = freq1->next;
			}
			if( freq1->elem != "a" && freq1->elem != "an" && freq1->elem != "the" && freq1->elem != "in" && freq1->elem != "on" && freq1->elem != "of" && freq1->elem != "and" && freq1->elem != "is" && freq1->elem != "are" )
			{
				file2.insert ( freq1->elem , i );


			}

			freq1 = freq1->next;


		}



	}



}


void inord_list :: freq_most (  )

{

	int most=0;
	link mostf =head;
	while ( mostf != NULL )
	{
		if ( mostf->line_num > most )
			most=mostf->line_num;
		mostf=mostf->next;
	}
	mostf=head;
	cout<<"Most frequent word is: ";
	while ( mostf != NULL )
		{
			if ( mostf->line_num == most )
				cout<<mostf->elem<<" ";
			mostf=mostf->next;
		}




cout<<endl;

}
