#ifndef RESCUE_H
#define RESCUE_H

#include "Robot.h"
#include "Planitis.h"
#include <iostream>

using std::cout;
using std::endl;


class Rescue:public Robot{
	public:
		Rescue();//constuctor

// sinartiseis pliroforiwn kai simvolwn 
	
		virtual void PrintInfo() const;
		virtual void PrintSymbol() const;

// sinartisi operation rescue

		virtual void Operation( Planitis *A[20][20], int, int, int, int);

// sinartisi gia epistrofi timwn speed kai countrepairs

		inline int getSpeed() const { return speed; }
		inline int getCountRepairs() const { return countRepairs;}
		 
		private:

		 static const int speed=90;	// taxitita
		 int countRepairs;		// plithos episkeywn pou exei pragmatopoihsei to rescue

};

// constructor me arxikopoihsh sto 0 tis countRepairs

Rescue::Rescue():Robot()
{
	countRepairs=0;
}

//sunartisi PrintInfo(), ektupwnei pliroforia kai kalei tin PrintInfo() tis yperklasis gia perisoteres plirofories 

	void Rescue::PrintInfo() const{

		cout<<"\nTo paron robot einai robot Diaswsis ! ( R ) me : \nTaxitita: "<<speed<<"\nSinolikes Epidiorthwseis pou exei pragmatopoihsei : "<<countRepairs<<endl;

           Robot::PrintInfo();
           }

//sunartisi PrintSymbol(), xrisimopoieite gia tin eikoniki anaparastasi      
 
	void Rescue::PrintSymbol() const
	{
		cout<<" R ";
	}      

/* operation rescue,  elenxei simfwna me ton typo pou mas dinete ap tin ekfwnisi, gia to an to sigekrimeno robot einai ikano na kanei tin operation, aliws tithete se katastasi vlavis.

ta robot rescue elenxun gia tin iparxi geitwnikwn robot me vlavi, kai an iparxun , ti diwrthwnun kai +1 countRepairs

*/
	void Rescue::Operation( Planitis *A[20][20], int x, int y, int d1, int d2)
	{

		float PithanVlavis;			
		PithanVlavis = ( A[x][y]->getAccess() * ( 1.0 - getAvailProsv() ) );

		if (PithanVlavis>0.7){
			
			A[d1][d2]->setKatastasi(false);
		}
		else{

			if( A[x][y]->getKatastasi()==false){

				cout<<"\nOperation Rescue: \nEgine episkeui geitonikou Robot me vlavi!"<<endl;	
				
				A[x][y]->setKatastasi(true);
				countRepairs++;	
				
			}

		}


		
	} 


#endif
