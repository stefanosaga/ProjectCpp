#ifndef ANALYZE_H
#define ANALYZE_H

#include "Robot.h"
#include "Planitis.h"
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

#include <typeinfo>


class Analyze:public Robot{
		public:
		Analyze();//constuctor

		virtual void PrintInfo() const;
		virtual void PrintSymbol() const;

		virtual void Operation( Planitis *A[20][20] , int,int,int,int );


		inline int getSpeed() const { return speed; }
		
		inline int getMaxFortio() const { return MaxFortio;}
		inline int getFortioIridium() const { return fortioIridium;}
		inline int getFortioPalladium() const { return fortioPalladium;}
		inline int getFortioPlatinum() const { return fortioPlatinum;}
		inline int getCountFortio() const { return countFortio;}


		virtual void setCountFortio(int) ;
		
				


	private:

		static const int speed=90;
		static const int MaxFortio=100;
		float fortioIridium;
		int fortioPalladium;
		int fortioPlatinum;
		int countFortio;
		int sunolikoIridium;
		int sunolikoPlatinum;
		int sunolikoPalladium;
};


Analyze::Analyze():Robot()
{
	fortioIridium=0;
	fortioPalladium=0;
	fortioPlatinum=0;
	countFortio=0;
	 sunolikoPlatinum=0;
        sunolikoIridium=0;  
	sunolikoPalladium=0;        
}
      //sunartisi PrintInfo(), ektupwnei pliroforia, kalei tin PrintInfo() tis yperklasis 

              
      void Analyze::PrintInfo() const{

		cout<<"\nTo paron robot einai robot Analisis ! ( A ) me : \nTaxitita: "<<speed<<"\nSinoliko Fortio pou exei silexei: "<<countFortio<<"\nMax Fortio pou mporei na silexei: "<<MaxFortio<<"\nSinoliko Fortio pou exei auti ti stigmi gia Iridium: "<<fortioIridium<<"\nSinoliko Fortio pou exei auti ti stigmi gia Palladium: "<<fortioPalladium<<"\nSinoliko Fortio pou exei auti ti stigmi gia Platinum: "<<fortioPlatinum<<endl;

		
           Robot::PrintInfo();
           }

       //sunartisi PrintSymbol(), xrisimopoieite gia tin eikoniki anaparastasi antikeimenwn Aeroplane     
 
	void Analyze::PrintSymbol() const
	{
		cout<<" A ";
	}    


	void Analyze::setCountFortio(int countFortio) 
	{
		this->countFortio=countFortio;
	} 




	void Analyze::Operation( Planitis *A[20][20],int x,int y,int d1,int d2 )    //ksekinima leitourgias
	{


               float PithanVlavis;			
		PithanVlavis = ( A[x][y]->getAccess() * ( 1.0 - getAvailProsv() ) );

		if (PithanVlavis>0.7){     //metakinhsh mono an pithanotita vlavis <0.7
			
			A[d1][d2]->setKatastasi(false);
			}

			else{
	                      if(countFortio <100){
                                 if( sunolikoIridium<60 ){     //eksoruksh iridioy

                                 sunolikoIridium=A[x][y]->getIridium();	    						
				fortioIridium=A[x][y]->getIridium()/10;	     //	eksoruksh tou 10% tou sunolikoy sth thesi	
				
				 A[x][y]->setIridium(sunolikoIridium-fortioIridium);
				
                                 
				countFortio=fortioIridium+countFortio;	//metritis sunolikoy fortiou toy robot 
                                

					}


				if (sunolikoPlatinum<(100-sunolikoIridium)){	          //eksoruksh Leukoxrusou

                                sunolikoPlatinum=A[x][y]->getPlatinum();
				fortioPlatinum=A[x][y]->getPlatinum()/10;			
					
				 A[x][y]->setPlatinum(sunolikoPlatinum-fortioPlatinum);
				 
                                 countFortio=countFortio+fortioPlatinum;		//metritis sunolikoy fortiou toy robot 	
				
			}
                    
		if (sunolikoPalladium<(100-sunolikoIridium-sunolikoPlatinum )){	      //eksoruksh palladiou
                                sunolikoPalladium=A[x][y]->getPalladium();
				fortioPalladium=A[x][y]->getPalladium()/10;			
					
				 A[x][y]->setPalladium(sunolikoPalladium-fortioPalladium);
				 
                                 countFortio=countFortio+fortioPalladium;   //metritis sunolikoy fortiou toy robot
         
				
             }

    cout<<"To robot exei mazepsei sunoliko fortio "<<countFortio<<" monadwn, me "<<fortioIridium<<" monades Iridio, "<<fortioPlatinum<<" monades Leukoxrisou kai "<<fortioPalladium<<" monades Palladio !"<<endl;    

 //sunoliko fortio se kathe kinhsh kai leitourgia



     }  //end if
  
          }  //end else
		
		}	//end operation


	        

#endif  
