#ifndef VASI_H
#define VASI_H
#include "Planitis.h"

#include <iostream>

using std::cout;
using std::endl;

class Vasi:public Planitis{
      public:
             Vasi();		//constructor tis klasis Vasi
             virtual void PrintInfo() const;
             virtual void PrintSymbol() const;

// arxikopoihsh private metavlitwn stoixeiwn sto antikeimeno tis vasis analoga me tin sigentrwsi tous  se auti
	private:
		int iridium;	// stoixeio iridiu
		int palladium;	// paladio
		int platinum;	// plat
};
	  
// constructor, me arxikopoihsh timwn stoixeiwn vasis =0
Vasi::Vasi()
{
	iridium=0;		
	palladium=0;
	platinum=0;
	
}

//sunartisi PrintInfo(), ektupwnei minimata oson afora ti vasi 

        void Vasi::PrintInfo() const {
           cout<<"Edw exoume ti Vasi me apothikeumenes posotites stoixeiwn: \nIridium = "<<iridium<<"\nPlatinum = "<<platinum<<"\nPalladium = "<<palladium<<endl;
        }
		   
//sunartisi PrintSymbol(), xrisimopoieite gia tin eikoniki anaparastasi stoixiwn vasis 
    
		void Vasi::PrintSymbol() const
        {
        cout<<"VVV";
        }         
#endif
