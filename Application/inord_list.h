/*
 * inord_list.h
 *
 *  Created on: 11 Apr 2016
 *      Author: Fatma Mostafa
 */

#ifndef INORD_LIST_H_
#define INORD_LIST_H_

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <cctype>
#include <stdio.h>
#include <ctype.h>

using namespace std;




typedef string  ListElementType;

class inord_list
{
private:
	struct node;
	typedef node * link;
	struct node
	{
		ListElementType elem;
		int line_num;
		int freq;
		link next;
	};

	link head,current;


public:

	inord_list();
	bool insert ( const ListElementType & e , int & l );
	bool first ( ListElementType & e  );
	bool next ( ListElementType & e  );
	string to_lower( ListElementType  e );
	int dist_word();
	int countWord_Myword( ListElementType f );
	void starting ( ListElementType  e );
	void containing_mystr ( ListElementType  e );
	void search (  ListElementType  e );
	void freq_list ( inord_list &  file2 );
	void freq_most (  );
	//void order ();




};








#endif /* INORD_LIST_H_ */
