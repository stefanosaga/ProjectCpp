#ifndef PLANITIS_H
#define PLANITIS_H
#include <vector>

using std::vector;
	class Planitis
	{
        	public:
              
			Planitis();  	// constructor planitis
			virtual ~Planitis();	// destructor planiti kai olwn twn ipoklasewn 

/* xrisi virtual sinartisewn me skopo ti diaxeirisi twn private metavlitwn alla kai diaforwn allwn liturgiwn. i xrisi tu virtual ginete me skopo na antimetwpizonte oi sinartiseis twn ipoklasewn san antikeimena vasis */
			
		 virtual void PrintInfo() const;
                 virtual void PrintSymbol() const;

		 virtual void setIridium(int);
		virtual void setPalladium(int);
		virtual void setPlatinum(int);

		virtual int getIridium() const;
		 virtual int getPalladium() const;
		 virtual int getPlatinum() const;

		virtual float getAccess() const ;

		virtual void setDanger(bool) ;
		virtual bool getDanger() const;

		virtual void setCountMoves(int) ;
		virtual void setKatastasi(bool) ;
		virtual void setAvailProsv(float) ;
		
		virtual int getCountMoves() const;
		virtual bool getKatastasi() const;
		virtual float getAvailProsv() const;

		virtual int getSpeed() const;

		virtual int getCountFlags() const;
		virtual void setCountFlags(int) ;

		virtual int getMaxFortio() const;
		virtual int getFortioIridium() const;
		virtual int getFortioPalladium() const;
		virtual int getFortioPlatinum() const;
		virtual int getCountFortio() const;

		virtual void setCountFortio(int) ;

		virtual int getCountRepairs() const;

		virtual int getTime() const;
                virtual void setTime(int);

		virtual int getCreationTime() const;
                virtual void setCreationTime(int);

		virtual void setAge(int);
		virtual int getAge() const; 


		virtual void Operation( Planitis *A[20][20], int, int, int, int ) ;

		
	};

Planitis::Planitis() {} 
Planitis::~Planitis() {}
               
void Planitis::PrintInfo() const {}  
void Planitis::PrintSymbol() const {} 

void Planitis::setIridium(int ir) {}
void Planitis::setPalladium(int pa) {}
void Planitis::setPlatinum(int pl) {}

int Planitis::getIridium() const {}
int Planitis::getPalladium() const {}
int Planitis::getPlatinum() const {}

float Planitis::getAccess() const {}

bool Planitis::getDanger() const {}
void Planitis::setDanger(bool k) {}

void Planitis::setCountMoves(int m) {}
void Planitis::setKatastasi(bool k) {}
void Planitis::setAvailProsv(float a) {}

int Planitis::getCountMoves() const {}
bool Planitis::getKatastasi() const {}
float Planitis::getAvailProsv() const {}

int Planitis::getSpeed() const {}
int Planitis::getCountFlags() const {}

void Planitis::setCountFlags(int c) {}

int Planitis::getMaxFortio() const {}
int Planitis::getFortioIridium() const {}
int Planitis::getFortioPalladium() const {}
int Planitis::getFortioPlatinum() const {}
int Planitis::getCountFortio() const {}

void Planitis::setCountFortio(int c) {}

int Planitis::getCountRepairs() const {}

void Planitis::setTime(int t){}
int Planitis::getTime() const{}  

void Planitis::setCreationTime(int t){}
int Planitis::getCreationTime() const{} 

void Planitis::setAge(int t){}
int Planitis::getAge() const{}

void Planitis::Operation( Planitis *A[20][20], int x, int y, int d1, int d2) {}


#endif
