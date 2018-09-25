#ifndef ROBOT_H
#define ROBOT_H

#include "Planitis.h"

#include <iostream>

#include <cstdlib>
#include <ctime>
#include <vector>

using std::cout;
using std::endl;


class Robot:public Planitis{
      public:

             Robot();		//constructor tis klasis Vasi
             
// dilwsi virtual sinartisewn, stoixeio polimorfismou wste na tropopoiounte oi leitourgies katalila sto kathe eidos robot

		virtual void PrintInfo() const;		// emfanisi pliroforiwn 
		virtual void PrintSymbol() const;	// emfanisi eikonidiou

// set kai get sinartiseis, wste na tropopoioun kai na prospelaunun tis antistoixes metavlites
//xrisi inline sinartisewn wste na epistrefun tis metavlites

		virtual void setCountMoves(int);	
		virtual void setKatastasi(bool);
		virtual void setAvailProsv(float);

		virtual inline int getCountMoves() const { return CountMoves; }
		virtual inline bool getKatastasi() const { return katastasi; }
		virtual inline float getAvailProsv() const { return AvailProsv; }
		virtual inline int getTime() const {return time;}
		
		virtual void setTime(int);
		
		virtual inline int getCreationTime() const {return CreationTime;}
		virtual void setCreationTime(int);
		
		virtual void setAge(int);
		virtual inline int getAge() const {return Age;}

		virtual void Operation(  Planitis *A[20][20], int, int, int, int ) ;


	private:

		
		bool katastasi;		// katastasi leiturgias robot
			
		int CountMoves;		// plithos kinisewn robot

		int time;		// xronos gia ti swsti diaxeirisi twn stoixeiwn kata ti diarkeia tis prosomeiwsis 
		int CreationTime;	// xronos dimiurgias robot, i age exartatai ap tin creationTime
	
		int Age;		// ilikia robot

		float AvailProsv;	// ikanotita prosvasis tou robot
		
};

// constructor, me katalili arxikopoihsh twn metavlitwn, xrisi tis rand gia tyxaia timi
	  
Robot::Robot()
{

	AvailProsv=static_cast<float>(rand()%10)/10;
	katastasi=true; // emfanizei 1
	CountMoves=0;
	time=0;
	CreationTime=0;
	Age=0;
}

      //sunartisi PrintInfo(), ektupwnei anagnwristiko munima antikeimenou

	void Robot::PrintInfo() const 
	{
		cout<<"\nTo Robot exei \nIkanotita Prosvasis : "<<AvailProsv<< "\nVlavi : "<<katastasi<<"\t\t(0 = me vlavi, 1 = xwris vlavi) \nPlithos Kinisewn ston kosmo : "<<CountMoves<<"\nIlikia Robot : "<<Age<<endl;
        }
		   
//sunartisi PrintSymbol(), xrisimopoieite gia tin eikoniki anaparastasi stoixiwn Robot  
    
	void Robot::PrintSymbol() const
        {
        
        } 

// orizei tin timi tis setCOuntMoves
		
	void Robot::setCountMoves(int CountMoves)
	{
		this->CountMoves=CountMoves;
	}

// omoiws gia katastasi

	void Robot::setKatastasi(bool katastasi)
	{
		this->katastasi=katastasi;
	}

//  omoiws 
	void Robot::setAvailProsv(float AvailProsv)
	{
		this->AvailProsv=AvailProsv;
	}

// orizei xrono prosomoiwsis

	void Robot::setTime(int time)
	{
     		this->time=time;         
     	}

//synartisi setAge(int), ay3anei tin hlikia tou antikeimenou stin prosomoiosi    

	void Robot::setAge(int Age)
	{
		this->Age=Age;
		if(Age%4==1){ katastasi=false;}//kathe 4 xronia to antikeimeno tithete ypo katastasi blabis
	}

// orizei to xrono ap ti stigmi dimiurgias tu antikimenu, kathe 10 xronikes stigmes, +1 etos

	void Robot::setCreationTime(int CreationTime)
	{
		this->CreationTime=CreationTime;
		if(CreationTime%10==0) (this->Age)++;
	}        

// sinartisi Operation, diaforetiki ilopoihsh analoga to eidos tou robot

	void Robot::Operation( Planitis *A[20][20], int x, int y, int d1, int d2  )
	{
			
		
	}



	


        
#endif
