#ifndef EXPLORE_H
#define EXPLORE_H

#include "Robot.h"
#include "Planitis.h"
#include <iostream>
#include <vector>


using std::cout;
using std::endl;

class Explore:public Robot{
	public:

		Explore();//constuctor

// sinartiseis pliroforiwn kai simvolwn 

		virtual void PrintInfo() const;
		virtual void PrintSymbol() const;
		
// sinartisi operation rescue

		virtual void Operation( Planitis *A[20][20], int, int, int, int );

// sinartiseis gia prospelasi kai orismo timwn gia to explore

		virtual void setCountFlags(int) ;
		inline int getSpeed() const { return speed;}
		inline int getCountFlags() const { return countFlags;}
	
	private:

		 static const int speed=90;
		 int countFlags;	// plithos simaiwn kindinou p exei valei to explore 

};

// constructor me arxikopoihsh sto 0 tis countFlags

Explore::Explore():Robot()
{
           countFlags=0;        
}

//sunartisi PrintInfo(), ektupwnei pliroforia kai kalei tin PrintInfo() tis yperklasis gia perisoteres plirofories 
           
	void Explore::PrintInfo() const
	{
	
		cout<<"\nTo paron robot einai robot Exereunisis ! ( E ) me : \nTaxitita: "<<speed<<"\nArithmo Simaiwn Kindinou pou exei topothetisei: "<<countFlags<<endl;
				
		Robot::PrintInfo();
	}
//sunartisi PrintSymbol(), xrisimopoieite gia tin eikoniki anaparastasi 

	void Explore::PrintSymbol() const
	{
		cout<< " E ";
	}      

// orizei tin timi tis countFlags


	void Explore::setCountFlags(int countFlags) 
	{
		this->countFlags=countFlags;
	} 
	
/* operation tu explore, simfwna me auto p mas dinete stin ekfwnisi. elenxei simfwna me ton typo pou mas dinete ap tin ekfwnisi, gia to an to sigekrimeno robot einai ikano na kanei tin operation, aliws tithete se katastasi vlavis.

ta robot explore, elenxun tin timi prosvasis pou iparxei se ka8e 8esi tu pinaka, kai an xeperna ena orio, tote topothetun simaia kindinu gia na apofeugetai i sigekrimeni 8esi apo ta ipolipa robot 
*/


	void Explore::Operation( Planitis *A[20][20], int x, int y, int d1, int d2  )
	{

		float PithanVlavis;			
		PithanVlavis = ( A[x][y]->getAccess() * ( 1.0 - getAvailProsv() ) );

		if (PithanVlavis>0.7){
			
			A[d1][d2]->setKatastasi(false);
		}
		else{

			cout<<"\nTo Robot Exereunnisis metakinithike sti thesi tu pinaka me sintetagmenes x: "<<x<<" y: "<<y<<endl;
			
			
			if( A[x][y]->getAccess() > 0.6 ){
				
				cout<<"\nOperation Explore: \nTopothetisi Simaias Kindinou se thesi edafous!"<<endl;	
				
				A[x][y]->setDanger(false);

				

				countFlags++;
				
				
			}
		}



		

		

			
			
			
								
			
			
	

			
	} 


#endif
