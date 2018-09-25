#ifndef EDAFOS_H
#define EDAFOS_H
#include "Planitis.h"

#include <iostream>

#include <cstdlib>
#include <ctime>


using std::cout;
using std::endl;

class Edafos:public Planitis{
	public:
		Edafos();		//constructor Edafos

// sinartiseis pliroforiwn kai simvolwn 
		virtual void PrintInfo() const;
		virtual void PrintSymbol() const;

// sinartiseis gia prospelasi kai tropopoihsh twn timwn twn stoixeiwn pou exei kathe antikeimeno edafus

		 void setIridium(int);
		 void setPlatinum(int);
		 void setPalladium(int);

		 inline int getIridium() const {return iridium;}
		 inline int getPlatinum() const {return platinum;}
		 inline int getPalladium() const {return palladium;}

		inline float getAccess() const {return access;}
		    	

		inline bool getDanger() const {return danger;}
		void setDanger(bool);

// dilwsi metavlitwn edafus

	private:
		int iridium;
		int platinum;
		int palladium;
		int sumElements;
		
		float access;
		bool danger;
		
			
	
	
};

//constructor edafos, dinei rand times se kathe antikeimeno edafus, me megisti periektikotita to 100. Episis dinei tixaia timi gia tin epikindinotita access kai orizei san true oles tis theseis edafus ( den exei simaia kindinou )
		 
Edafos::Edafos()
{
	iridium=rand()%60;
	platinum=rand()%(99-iridium);
	palladium=rand()%(99-iridium-platinum);
	sumElements=iridium+platinum+palladium;
	danger=true;
	access=static_cast<float>(rand()%10)/10;
}

//sunartisi PrintInfo(), ektupwnei pliroforia edafus

void Edafos::PrintInfo() const
{
	cout<<"\nEdw exoume stoixeio edafous me: \nSinoliki posotita stoixeiwn : "<<sumElements<< " monades\nIridio : "<<iridium<<" monades\nPlatinum: "<<platinum<<" monades\nPalladium: "<<palladium<<" monades"<<"\nEpikindinotita Prosvasis: "<<access<<"\nSimaia Kindinou: "<<danger<<"\t\t ( 1 = eukoli prosvasi, 0 = epikindini )"<<endl;
}

//sunartisi PrintSymbol(), xrisimopoieite gia tin eikoniki anaparastasi stoixiwn Edafous

void Edafos::PrintSymbol() const
{
    cout<<"   ";
}     


void Edafos::setIridium(int iridium){
	
	this->iridium=iridium;
	sumElements=iridium+platinum+palladium;
		
}

void Edafos::setPlatinum(int platinum){
	
	this->platinum=platinum;
	sumElements=iridium+platinum+palladium;
}

void Edafos::setPalladium(int palladium){
		
	this->palladium=palladium;
	sumElements=iridium+platinum+palladium;
}

void Edafos::setDanger(bool danger)
	{
		this->danger=danger;
	}


#endif
