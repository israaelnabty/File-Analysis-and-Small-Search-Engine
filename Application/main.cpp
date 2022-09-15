//============================================================================
// Name        : a2.cpp
// Author      : Fatma
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <cstring>
#include "inord_list.h"
using namespace std;

int main( int argc , char *argv[] )

{
	if ( argc != 3 )


		cout<<"Incorrect number of arguments"<<endl;



	else
	{
		inord_list file;
		inord_list file2;
		string line1,line2;
		ifstream txt1 ( argv [1]);
		ifstream txt2 ( argv [2]);
		int num=0;
		if ( !((txt1) && (txt2)) )
			cout<<"File not found"<<endl;
		else
		{
			int l=0;
			getline( txt1 , line1 );
			while ( txt1 )
			{

				bool ins=true;
				l++;


				stringstream word;
				word<<line1;
				string e;
				word>>e;
				while ( word && ins )
				{
					num++;
					e=file.to_lower(e);
					ins=file.insert( e , l  );
					word>>e;
				}
				getline( txt1 , line1 );



			}//end of reading the input file.

			file.freq_list (  file2 ); //list of frequent words.



			//txt1.close();
			getline( txt2 , line2 );
			while ( txt2 )
			{

				stringstream comm;
				comm<<line2;
				string f;
				comm>>f;


				//word count.
				if( f == "wordCount" )
				{
					comm>>f;
					if ( comm  )
						cout<<"Incorrect number of arguments"<<endl;
					else
						cout<<num<<" "<<"words"<<endl;
				}

				else
					//distWords.
					if( f == "distWords" )
					{
						comm>>f;
						if ( comm  )
							cout<<"Incorrect number of arguments"<<endl;
						else
						{
							int dist = file.dist_word();
							cout<<dist<<" "<<"distinct words"<<endl;
						}
					}
					else
						//charCount.
						if( f == "charCount" )
						{
							comm>>f;
							if ( comm  )
								cout<<"Incorrect number of arguments"<<endl;
							else
							{
								int charcount=0;
								char c;
								ifstream txt1 ( argv [1]);
								while (txt1.get(c))
									charcount++;
								cout<<charcount<<" "<<"characters"<<endl;
							}

						}
						else
							//frequentWord.
							if( f == "frequentWord" )
							{
								comm>>f;
								if ( comm  )
									cout<<"Incorrect number of arguments"<<endl;
								else
									file2.freq_most (  );
							}
							else
							{


								if( f == "countWord" )
								{
									string q;
									int k;
									comm>>f;
									q=file.to_lower(f);
									comm>>f;
									if ( comm  )
										cout<<"Incorrect number of arguments"<<endl;
									else
									{
										k=file.countWord_Myword(q);
										cout<<f<<" is repeated "<<k<<" times"<<endl;
									}

								}
								else
									if ( f == "starting" )
									{
										string q;
										comm>>f;
										if ( !comm  )
											cout<<"Incorrect number of arguments"<<endl;
										else
										{

											q=file.to_lower(f);
											comm>>f;

											if ( comm  )
												cout<<"Incorrect number of arguments"<<endl;
											else
											{
												file.starting(q);
											}
										}
									}
									else
										if ( f == "containing" )
										{
											string q;
											comm>>f;
											if ( !comm  )
												cout<<"Incorrect number of arguments"<<endl;
											else
											{
												q=file.to_lower(f);
												comm>>f;
												if ( comm  )
													cout<<"Incorrect number of arguments"<<endl;
												else
												{
													file.containing_mystr(q);
												}
											}


										}
										else
											if ( f == "search" )
											{
												string q;

												comm>>f;
												if ( !comm  )
													cout<<"Incorrect number of arguments"<<endl;
												else
												{
													q=file.to_lower(f);
													comm>>f;
													if ( comm  )
														cout<<"Incorrect number of arguments"<<endl;
													else
													{
														file.search(q);
													}
												}

											}


											else
											{
												cout<<"Undefined command"<<endl;
											}
							}
				getline( txt2 , line2 );






			}



		}













	}




	return 0;
}
