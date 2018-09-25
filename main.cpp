/* kanoume include tis klaseis sto kiriws programma */
#include "Planitis.h"
#include "Vasi.h"
#include "Robot.h"
#include "Edafos.h"
#include "Explore.h"
#include "Analyze.h"
#include "Rescue.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>

#include <vector>
#include <typeinfo>

using std::cout;
using std::cin;
using std::endl;
using std::setprecision;

using std::vector;



int main() 
{

srand((unsigned)time(NULL));
	
int time=0;	// xronometro

int i,j, x,y;	// metavlites gia xrisi se sintetagmenes xarti

int choice;	// metavliti pou xrisimopoioume sto menu epilogwn
int typeR,typeEp,typeEidos,typePlirof; 		// metavlites gia xrisi se menu kai eisagwgi xristi
int ir,pl,pala;		// xrisi se case gia tropopoihsh timwn 
int w,countVlaves,countEdafos;		// metavlites gia metrisi timwn se robot 	
bool katast,vlavi;	// metavlites gia elenxos katastasis kai vlaves
float sumEpikind=0,moEpikind=0;		// metavlites gia diafores times 
int Sunolo_ir=0, Sunolo_pl=0, Sunolo_pala=0,Sunolo_Fort=0, Sunolo_flag=0;	// metavlites gia emfanisi pliroforiwn stoixeiwn 	
int kinisi;	// int gia xrisi se kinisis

bool flag=false; 		//  metavliti gia elenxo adeiasma fortiou

Planitis *temp;		// voithitikos deiktis typou Planiti gia antimetathesi stoixeiwn 

Vasi *v_ptr=0;		// deiktes antikeimenwn gia elenxo vector 	
Robot *r_ptr=0;		// omoiws 
Edafos *ed_ptr=0;
Analyze *an_ptr=0;
Explore *exp_ptr=0;
Rescue *res_ptr=0;

	


	/* arxikopoihsh disdiastatou pinaka me stoixeia planiti */
	Planitis *Array[20][20];
	
	/* dilwsi vector pou tha periexei ola ta stoixeia tis efarmogis mas */
	vector <Planitis*> vec;
	
	/* dimiourgia arxikwn antikeimenwn */
		
	Vasi vas;				// antik typou vasis
	vec.push_back(&vas);		// eisagwgi antik vas sto vec
	
	
	Explore ex;
	vec.push_back(&ex);
	
	Analyze an;	
	vec.push_back(&an);

	Rescue res;
	vec.push_back(&res);	
	
	
	
	//dimiourgia xarti, me topothetisi se sigekrimena i,j ta antikimena tis vasis kai tou edafous
	
	
	for( i=0;i<20;i++ ){
		for( j=0;j<20;j++){  
			
			if(i<13 && i>7 && j<13 && j>7 )
				{
					Array[i][j]=vec[0];	//  antikeimeno vasis to vec0
				}   // end if (i<13&& i>7 && j<13 && j>7 )

			

			else{
					vec.push_back(new Edafos);
					Array[i][j]=vec.back();		// antikeimeno edafus se oles tis ipolipes tu pinaka
				}  // end else 

	
		}	//telos for(j)
	}	//telos for(i)



// tyxaia topothetisi robot, elenxos gia to an iparxei stoixeio vasis 
	cout<<"\nEnarxi Prosomoiwsis ! Automati topothetisi Robot!"<<endl;
					
			do{
                          v_ptr=dynamic_cast<Vasi *> (Array[x=rand()%19][y=rand()%19]);
                          }while(v_ptr!=0);
                          Array[x][y]=vec[1];
				
			do{
                          v_ptr=dynamic_cast<Vasi *> (Array[x=rand()%19][y=rand()%19]);
                          }while(v_ptr!=0);
                          Array[x][y]=vec[2];
	
			do{
                          v_ptr=dynamic_cast<Vasi *> (Array[x=rand()%19][y=rand()%19]);
                          }while(v_ptr!=0);
                          Array[x][y]=vec[3];
	


// emfanisi tou tis arxikis morfis tou planiti kai me ta katalila simvola 

	for( i=0;i<20;i++ ){

		cout<<"|";
   
		for( j=0;j<20;j++){


			Array[i][j]->PrintSymbol();
			
			
		}//telos for(j)
			
		cout<<"|"<<endl;   
    	}// telos for (i) 
	
do{ 

			/* menu epilogwn  */
	cout<<"\nPliktrologise 1 gia eisagwgi neou robot "<<endl;	
	cout<<"Pliktrologise 2 gia epeksergasia thesis edafous"<<endl;
	cout<<"Pliktrologise 3 gia epexergasia katastasis leitourgias robot"<<endl;
	cout<<"Pliktrologise 4 gia emfanisi pliroforiwn gia oxima i thesi edafous"<<endl;
	cout<<"Pliktrologise 5 gia emfanisi tis katastasis tu kosmou "<<endl;
	cout<<"Pliktrologise 6 gia pausi prosomiwsis"<<endl;
	cout<<"Pliktrologise 7 emfanisi genikwn pliroforiwn kosmou kai prosomoiwsis"<<endl;
	cout<<"Pliktrologise 8 gia termatismo efarmogis "<<endl;
	cout<<"Pliktrologise 9 gia sinexisi rohs efarmogis "<<endl;

	cin>>choice;   

// analisi case menu epilogwn me analoges entoles 

switch (choice){
		
/*  case 1, eisagwgi robot, dinete i dinatotita epilogis robot kai eisagwgis se tyxaia i sigekrimeni thesi. ginete elenxos gia to an iparxei antikimeno vasis stis sintetagmenes. elenxos gia oria pinaka, gia apofigi segm fault*/

	case 1:	

	cout<<"\nEpilexate na kanete eisagwgi neou robot!"<<endl;
	
		do{	
	
			cout<<"\nPatiste : \n1 gia eisagwgi Robot Analisis \n2 gia eisagwgi Robot Exereunisis \n3 gia eisagwgi Robot Diaswsis"<<endl;
	
			cin>>typeR;
	
		}while(typeR>3 || typeR<1);
	
			do{
		
				cout<<"\nPatiste : \n1 gia eisagwgi se tyxaia thesi \n2 gia na dwsete eseis sintetagmenes."<<endl;
				
				cin>>typeEp;
		
			}while(typeEp>2 || typeEp<1);
	
		
			switch(typeEp){

			 	case 1:   // typeEp

				switch(typeR){
	
					case 1:	// typeR

						vec.push_back(new Analyze);

						

						do{
                          			v_ptr=dynamic_cast<Vasi *> (Array[x=rand()%19][y=rand()%19]);
                          			}while(v_ptr!=0);
						Array[x][y]=vec.back();
						Array[x][y]->setTime(time);
						
						cout<<"\nH eisagwgi egine me epityxia!!"<<endl;
						break;
			    
					case 2:
						vec.push_back(new Explore);
						
						
								
						do{
                          			v_ptr=dynamic_cast<Vasi *> (Array[x=rand()%19][y=rand()%19]);
                          			}while(v_ptr!=0);						
                          			Array[x][y]=vec.back();
						Array[x][y]->setTime(time);
						
						cout<<"\nH eisagwgi egine me epityxia!!"<<endl;
						break;
			
					case 3:
						vec.push_back(new Rescue);

						
						do{
                          			v_ptr=dynamic_cast<Vasi *> (Array[x=rand()%19][y=rand()%19]);
                          			}while(v_ptr!=0);
                          			Array[x][y]=vec.back();
						Array[x][y]->setTime(time);
						
						cout<<"\nH eisagwgi egine me epityxia!!"<<endl;
						break;
			
					default: 
						cout<<"Lathos eisodos!"<<endl;
						break;

                	 	} //switch typeR


				break;	// case 1 typeEp
						
			case 2:

				do{
				cout<<"\nDwste sintetagmenes ENTOS oriwn xarth ( 0<=x<20 , 0<=y<20 ) kai EKTOS oriwn vasis ( 8<=x<=12 , 8<=y<=12 )"<<endl;
				cin>>x;
				cin>>y;
		
				}while(	x<0 || (x>7 && x<13) || x>19 || y<0 || (x>7 && x<13) || y>19 );	
	
				switch(typeR){
	
					case 1:
					vec.push_back(new Analyze);
					Array[x][y]=vec.back();
					
					cout<<"\nH eisagwgi egine me epityxia!!"<<endl;
					break;
			    
					case 2:
					vec.push_back(new Explore);
					Array[x][y]=vec.back();
					
					cout<<"\nH eisagwgi egine me epityxia!!"<<endl;
					break;
			
					case 3:
					vec.push_back(new Rescue);
					Array[x][y]=vec.back();
					
					cout<<"\nH eisagwgi egine me epityxia!!"<<endl;
					break;
			
					default: 
					cout<<"Lathos eisodos!"<<endl;
					break;

                	 	} //switch typeR

			break; // case 2 typeEp


			default: 
			cout<<"Lathos eisodos gr!"<<endl;
			break;
		
			}// switch typeEp
	
		
		break;  //case 1 menu
	



/* case 2, epilogi gia epexergasia stoixeiwn edafous. elenxos gia eisodo sintetagmenwn, kai tropopoihsh timwn me megisti periektikotita tis 100 monades */	

	case 2:
		cout<<"\nEpilexate tin epexergasia thesis edafous"<<endl;

		do{
	            	cout<<"Dwste suntetagmenes ENTOS oriwn ( 0<=i<20 , 0<=j<20 ) pou thelete na epexergasteite :"<<endl;
	            	cin>>x;
	            	cin>>y;
		}while(x<0 || x>=20 || y<0 || y>20);

	
		cout<<"\nEpexergasia periektikotitas Iridiou! Dwse nea timi int periektikotitas:"<<endl;
		do{	
			cin>>ir;
			
		        Array[x][y]->setIridium(ir);
             			
               
		cout<<"\nNea timi iridium: "<<Array[x][y]->getIridium()<<" monades"<<endl;
		    
			if( ir>100) cout<<"\n\nLathos Eisodos! (i periektokotita tou sinolu twn stoixeiwn prepei na einai <100)"<<endl;
		   }while(ir>100);

		cout<<"\nEpexergasia periektikotitas Leukoxrisou! Dwse nea timi int periektikotitas:"<<endl;
		do{	
                        cin>>pl;
		      
			Array[x][y]->setPlatinum(pl);
		 
	
		cout<<"\nNea timi Platinum: "<<Array[x][y]->getPlatinum()<<" monades"<<endl;
               
		 if( (ir+pl) >100 ) cout<<"\n\nLathos Eisodos! (i periektokotita tou sinolu twn stoixeiwn prepei na einai <100)"<<endl;		 
		}while( (ir+pl) >100);		

		cout<<"\nEpexergasia periektikotitas Palladiou ! Dwse nea timi int periektikotitas: "<<endl;
                  do{       
			cin>>pala;
			
			Array[x][y]->setPalladium(pala);
                     if( (ir+pl+pala) >100 ) cout<<"\n\nLathos Eisodos! (i periektokotita tou sinolu twn stoixeiwn prepei na einai <100)"<<endl; 
                    }while( (ir+pl+pala) >100 );

		cout<<"\nNea timi Palladium: "<<Array[x][y]->getPalladium()<<" monades"<<endl;
 
                cout<<"\nH tropopoihsh twn stoixeiwn egine me epitixia !!"<<endl;




	break; 	// case 2 menu


/* case 3, epexergasia katastasis robot, ean auto exei vlavi. elenxos gia antikimeno robot sto vector, emfanisi katalilwn stoixeiwn me sarwsi tu vector kai emfanisi tu onomatos me typeid gia ektipwsi onomatos tu antikeimenu. stoixeio polimorfismu !

	*/


	case 3:	// menu

		cout<<"\nEpilexate tin epexergasia katastasis leitourgias robot!"<<"\n\nSe pio Robot thelete na tropopoihsete tin katastasi tou?"<<endl;
		
		w=0;
		for( i=0;i<vec.size();i++){

			r_ptr=dynamic_cast<Robot *> (vec[i]);

			if(r_ptr!=0){	

//ean broume antikeimeno  ektupwnoume tin 8esi tou ston vector k to onoma tou me tin xrisi tou typeid() ektupwnoume to onoma tis klasis tou antikeimenou,stoixeio polumorfismou
 
				cout<<"\nPatise "<<i<<" gia Robot :"<<typeid(*vec[i]).name()<<endl;
				w++;
				

			}//telos if(r_ptr!=0)

		}//telos for i
                   
			//o xristis epilegei se poio antikeimeno thelei n tpothetisi blabi, ean kanei la8os, den ginete tipota kathws i setKatastasi einai virtual kai pratei analoga to eidos tu antikeimenu 

	if(w>0){
		
		cin>>typeEidos;
		katast=vec[typeEidos]->getKatastasi();

			if(katast==true){
	
				vec[typeEidos]->setKatastasi(false);
				
				cout<<"\nH epexergasia tis katastasis leitourgias egine me epitixia !"<<endl;
			}
			else{
				vec[typeEidos]->setKatastasi(true);
				
				cout<<"\nH epexergasia tis katastasis leitourgias egine me epitixia !"<<endl;
			}
	}//telos if w>0
	else{
		
		cout<<"\nDen iparxun diathesima Robot gia epexergasia tis katastasis leitourgias tous !!"<<endl;
	}//telos else
		
	break;	// case 3 menu
		

/* case 4, emfanisi pliroforiwn gia sigekrimeni thesi ston pinaka me xrisi virtual printinfo pou emfanizei gia kathe antikeimeno analoges plirofories*/		
	
	case 4:
		
	cout<<"\nEpileksate na deite plirofories 8esis"<<endl;
		do{
	            	cout<<"Dwste suntetagmenes ENTOS oriwn ( 0<=i<20 , 0<=j<20 )"<<endl;
	            	cin>>x;
	            	cin>>y;
		}while(x<0 || x>=20 || y<0 || y>20);
	            	Array[x][y]->PrintInfo();
	            	cout<<"\nH diadikasia egine me epityxia!"<<endl;


	break;	// case 4 menu

/* case 5, emfanisi sinolikis katastasis kosmou kai xroniki stigmi prosomoiwsis. xrisi virtual printsymbol gia emfanisi xexwristu symvolu gia kathe antikeimeno  */


	case 5:
		cout<<"\nEpilexate na deite tin sunoliki katastasi tou kosmou"<<endl;
   
		for(i=0;i<20;i++){
			cout<<"|";
			for( j=0;j<20;j++){
				Array[i][j]->PrintSymbol();
			}//telos for j
			cout<<"|"<<endl;   
    		}// telos for i 
		
		//Emfanisi trexousas wras 
		cout<<"Time : "<<time<<endl;

		cout<<"\nH diadikasia egine me epityxia!"<<endl;   


	break;	// case 5 menu

/* case 6, pausi prosomoiwsis */


	case 6:

		cout<<"\nProswrini pausi prosmoiwsis"<<endl;
		system("PAUSE");
		system("CLS");
		

	break;	// case 6 menu
	
/*  case 7, emfanisi genikwn pliroforiwn kosmou gia robot i edafos, opws autes mas zitunte stin ekfwnisi ( px sinoliki posotita stoixeiwn ston kosmo, mo epikindinotitas alla kai sinolo vlavwn kai allwn pliroforiwn. sarwsi vector gia pragmatopoihsh leiturgiwn */ 

              
	case 7:
		
		cout<<"\nEpilexate na deite genikes plirofories kosmou kai prosomoiwsis !"<<endl;
		cout<<"\nPliktrologiste:\n1 gia genikes plirofories Robot \n2 gia genikes plirofories edafous"<<endl;
		cin>>typePlirof;
		countVlaves=0;
		countEdafos=0;
		Sunolo_ir=0;
		Sunolo_pl=0;
		Sunolo_pala=0;
		Sunolo_Fort=0;
		Sunolo_flag=0;
		switch(typePlirof){
	
					case 1:
					cout<<"\nPlirofories Robot"<<endl;					
					
					
					for(i=0;i<vec.size();i++){

						r_ptr=dynamic_cast<Robot *> (vec[i]);
						
						an_ptr=dynamic_cast<Analyze *> (vec[i]);

						exp_ptr=dynamic_cast<Explore *> (vec[i]);
					
						if(an_ptr!=0){

							Sunolo_Fort=Sunolo_Fort + vec[i]->getCountFortio();			         						
												
						}	//telos if  an_ptr!=0
		
						if(exp_ptr!=0){
						
							Sunolo_flag=vec[i]->getCountFlags();
						
						}	//telos if exp_ptr!=0

						

						if(r_ptr!=0){	
							
							vlavi=vec[i]->getKatastasi();
						
								if(vlavi==false){
									countVlaves++; 

								} 	//if vlavi
						
						
						}	//telos if  r_ptr!=0

					}//telos for i	
			
					cout<<"\nArithmos Sinolikwn Vlavwn se Robot mexri auti ti stigmi: "<<countVlaves<<"\n\nSinoliko Fortio pou exoun sillexei ola ta Robot Analisis apo ton kosmo mexri auti ti stigmi: "<<Sunolo_Fort<<"\n\nArithmos sinolikwn Simaiwn Kindinou pou exoun topothetisei ta Robot Exereunisis ston kosmo mexri auti ti stigmi: "<<Sunolo_flag<<endl<<endl<<endl;




					break; // case 1 switch
			    

					case 2:
					cout<<"\nPlirofories Edafous"<<endl;
	

					for(i=0;i<vec.size();i++){

						ed_ptr=dynamic_cast<Edafos *> (vec[i]);


						if(ed_ptr!=0){	
							countEdafos++;
							
							sumEpikind=(vec[i]->getAccess()) + sumEpikind;
						
							moEpikind=sumEpikind/countEdafos;
								
							Sunolo_ir=Sunolo_ir + vec[i]->getIridium();
 							Sunolo_pl=Sunolo_pl + vec[i]->getPlatinum();
							Sunolo_pala=Sunolo_pala + vec[i]->getPalladium();
						
						}	//telos if  ed_ptr!=0

					}//telos for i	
			
					cout<<"\nM.O. epikindinotitas simeiwn edafous :"<<setprecision(2)<<moEpikind<<"\nSunolikos arithmos monadwn iridiou sto xarti: "<<Sunolo_ir<<"\nSunolikos arithmos monadwn Leukoxrusou sto xarti: "<<Sunolo_pl<<"\nSunolikos arithmos monadwn Palladiou sto xarti: "<<Sunolo_pala<<endl;


					break;	// case 2 switch
			
					
					default: 
					cout<<"\nLathos eisodos plir!"<<endl;
					break; // case default

                	 	} //switch typePlirof

	break;    // case 7




	case 8:

/*	termatismos programmatos */

            cout<<"\nEpilexate ton termatismo tis prosomoiwsis!"<<endl<<endl;

	break; // case 8

	case 9:		


// sinexisi rohs programmatos ,to programma sunexizete xwris kamia energeia na pragmatopoih8ei

            cout<<"\nEpileksate sunexisi rohs prosomoiwsis !"<<endl;
            

	break;  // case 9
       

	default:
            cout<<"\nDwsate lathos numero menu!"<<endl;
            
	break;  // case default menu


} 	// switch choice      
   




			// 	KINISI ANTIKEIMENWN 


/* sarwsi xarti gia euresi antikeimenwn robot. ginete sigxronismos twn antikeimenwn me to xronometro time wste na min ektelunte perisoteres kiniseis se kathe epanaliyi tis do while tu menu. pragmatopoiounte diaforoi elenxoi gia tin katastasi twn robot, tin ilikia, kai auxanetai kathe fora kai o arithmos kinisewn twn robot */

for(int i=0;i<20;i++){
	for(int j=0;j<20;j++){


		r_ptr=dynamic_cast<Robot *> (Array[i][j]);

	if(r_ptr!=0){

			// elenxos gia na ginete mia kinisi se ka8e gyro twn oximatwn, sigxronizontas tin time twn antikeimenwn me tin time tis main
		
			if(Array[i][j]->getTime()==time){

					Array[i][j]->setTime(Array[i][j]->getTime()+1);		// +1 time, auxisi xronou gia epomeno gyro
					Array[i][j]->setCountMoves(Array[i][j]->getCountMoves()+1);	// +1 kiniseis gia to robot stin prosomiwsi 
					Array[i][j]->setCreationTime(Array[i][j]->getCreationTime()+1);	//	ay3anoume ton xrono dimiourgias gia ilikia
					

					if(Array[i][j]->getAge()>=6){
                                          
							//ean to oxima exei ulikia megaliteri h' isi me 4 aposurete apo tin efarmogi kai diagrafete apo ton vector
						

						for(int k=0;k<vec.size();k++)
                                        	{
							if(Array[i][j]==vec[k]) vec.erase(vec.begin()+k);
						}//telos for(k)
 						
						vec.push_back(new Edafos);	// sti thesi tou dimiurgeite antikeimeno edafous

						Array[i][j]=vec.back();
					
					
						
						cout<<"\nEna Robot molis aposir8ike apo ton Planiti logw ilikias!"<<endl;

					}	//telos if(Array[i][j]->getAge()>=2)
			

		// elenxos gia katastasi oximatos, an true kinisi !
				if(Array[i][j]->getKatastasi()==false) 
				{

					//elenxos gia robot analisis, kai se periptwsi max fortiou epistrofi sti vasi gia adeiasma
				
					an_ptr=dynamic_cast<Analyze *>(Array[x][y]);
                                            

					if(an_ptr!=0){
						if(Array[i][j]->getCountFortio()>=100) 
						{	
							
	

                                    /* ean to oxima exei vlavi to katey8inoume pros tin vasi, theorontas pws oi 8eseis, oi opoies exoun geitoniko antikeimeno ston pinaka stoixeio typou Vasiseinai idanikes gia episkeues */


					x=i;
					y=j;

					if(i<=6) x++;
					if(i>=14) x--;
					if(j<=6) y++;
					if(j>=14) y--;
                                  


					if(x!=i || y!=j){	// ean to oxima den briskete stis  idanikes gia episkeui 8eseis to kateuthinoume pros ta ekei


					ed_ptr=dynamic_cast<Edafos *>(Array[x][y]);
                                            

						if(ed_ptr!=0){		//ean h thesi pou pame n to metakinisoume periexei antikeimeno typou Edafous tote ginete kanonika h kinisi

                                                            Array[i][j]->setCountMoves(Array[i][j]->getCountMoves()+1);                                
                                                                                                                    
                                                            temp=Array[x][y];
                                                            Array[x][y]=Array[i][j];
                                                            Array[i][j]=temp;
						
						}  // telos if ed_ptr


					}	//telos if ( x!=i || y!=j )
					


					else if (x==i && y==j) 		// an vrethei to Robot dipla stis idanikes theseis, tote afinei fortio
					{

						v_ptr=dynamic_cast<Vasi *>(Array[i-1][j-1]);
                                                if(v_ptr!=0) flag=true;
                                                v_ptr=dynamic_cast<Vasi *>(Array[i-1][j]);
                                                if(v_ptr!=0) flag=true;
                                                v_ptr=dynamic_cast<Vasi *>(Array[i][j-1]);
                                                if(v_ptr!=0) flag=true;
                                                v_ptr=dynamic_cast<Vasi *>(Array[i][j+1]);
                                                if(v_ptr!=0) flag=true;          
                                                v_ptr=dynamic_cast<Vasi *>(Array[i+1][j-1]);
                                                if(v_ptr!=0) flag=true;       
                                                v_ptr=dynamic_cast<Vasi *>(Array[i+1][j]);
                                                if(v_ptr!=0) flag=true;          
                                                v_ptr=dynamic_cast<Vasi *>(Array[i+1][j+1]);
                                                if(v_ptr!=0) flag=true;


						 if(flag==true)
						{
							Array[i][j]->setCountFortio(0);
							
							flag=false;
						}  // flag true
		

					}	//telos else if(x==i && y==j)

					
					}	// Array[i][j]->getCountFortio()==100


					} // if an_ptr

				}  	//if (Array[i][j]->getKatastasi()==false 
				
				else{		/* else getKatastasi		an den iparxei provlima vlavis	gia to robot, tote i kinisi pragmatopoieitai tyxaia analoga to me tus arithmus tis rand diladi px, an erthei to 1 me tin rand, tote to robot kateuthinete diagwniws katw aristera, an erthei to 9 kateuthinetai diagwniws panw dexia kai paei legontas... */

	
				kinisi=rand() % 9 + 1;
				//kinisi=1;

				switch(kinisi){

					case 1:		

					if(i+1<20 && j-1>=0){		//elenxos gia oria pinaka



					//operate rescue 

					r_ptr=dynamic_cast<Robot *> (Array[i+1][j-1]);	
						
					if(r_ptr!=0 ){ // && Array[i+1][j-1]->getKatastasi()==false  ){
			
						res_ptr=dynamic_cast<Rescue *> (Array[i][j]);
						
						if(res_ptr!=0){

						Array[i][j]->Operation( Array, i+1, j-1, i,j );

						} 	// end if res_ptr
					
						

						
					}	// telos ifr_ptr!=0 && Array[i+1][j-1]->getKatastasi()==false  OPERATE RESCUE

					

					ed_ptr=dynamic_cast<Edafos *>(Array[i+1][j-1]);		// elenxos gia iparxi antikeimenu Edafous stin thesi pou eprokeito na metakinithei 

						
						if(ed_ptr!=0){		// an iparxei Edafos tote Operate analoga to eidos tu Robot


						// operate sto array(i+1)(j-1)
						
						exp_ptr=dynamic_cast<Explore *> (Array[i][j]);			
					// Elenxos gia Explore Robot kai analogi klisi tis operate

						if(exp_ptr!=0 ){
								
							Array[i][j]->Operation( Array, i+1, j-1, i, j );
						
						}	// idf exp_ptr



			//Operate ANALYZE

					 an_ptr=dynamic_cast<Analyze *> (Array[i][j]);    
						
						if(an_ptr!=0)
						{           //elegxos gia iparxi robot analyze
						cout<<"\nOperation Analyze: "<<endl;
						Array[i][j]->Operation( Array ,i+1, j-1,i,j);
						}



						
					
        			// antimetathesi stoixeiwn pinaka
						temp=Array[i+1][j-1];
                                                Array[i+1][j-1]=Array[i][j];
                                                Array[i][j]=temp;

						}	// if ed_ptr

					} // if  (i+1<20 && j-1>=0)



					break; // 1

					// idios kwdikas, to mono p alazei einai i kateuthinsi tis kinisis twn robot

					case 2:

					if(i+1<20){

				
					//operate rescue 

					r_ptr=dynamic_cast<Robot *> (Array[i+1][j]);	
						
					if(r_ptr!=0 ){ // && Array[i+1][j-1]->getKatastasi()==false  ){
			
						res_ptr=dynamic_cast<Rescue *> (Array[i][j]);
						
						if(res_ptr!=0){

						Array[i][j]->Operation( Array, i+1, j, i,j );

						} 	// end if res_ptr
					
						

						
					}	// telos ifr_ptr!=0 && Array[i+1][j-1]->getKatastasi()==false  OPERATE RESCUE

					ed_ptr=dynamic_cast<Edafos *>(Array[i+1][j]);

						if(ed_ptr!=0){
							
						
						// operate EXPLORE
						
						exp_ptr=dynamic_cast<Explore *> (Array[i][j]);

						if(exp_ptr!=0 ){
								
							
							Array[i][j]->Operation( Array, i+1, j, i,j );
						
						

						}	// idf exp_ptr


				//operate ANALYZE

                                                an_ptr=dynamic_cast<Analyze *> (Array[i][j]);
						
						if(an_ptr!=0){
						cout<<"\nOperation Analyze: "<<endl;
						Array[i][j]->Operation( Array ,i+1, j,i,j);
						}
						

						temp=Array[i+1][j];
						Array[i+1][j]=Array[i][j];
						Array[i][j]=temp;

						} 	//if ed+_ptr

					} 	// end if i-1 && j-1


						

					break;	//2
			
					case 3:

					if(i+1<20 && j+1<20){

					//operate rescue 

					r_ptr=dynamic_cast<Robot *> (Array[i+1][j+1]);	
						
					if(r_ptr!=0 ){ // && Array[i+1][j-1]->getKatastasi()==false  ){
			
						res_ptr=dynamic_cast<Rescue *> (Array[i][j]);
						
						if(res_ptr!=0){

						Array[i][j]->Operation( Array, i+1, j+1, i,j );

						} 	// end if res_ptr
					
						

						
					}	// telos ifr_ptr!=0 && Array[i+1][j-1]->getKatastasi()==false  OPERATE RESCUE

                                                   
					ed_ptr=dynamic_cast<Edafos *>(Array[i+1][j+1]);

						if(ed_ptr!=0){


						// operate sto array(i+1)(j-1)
						
						exp_ptr=dynamic_cast<Explore *> (Array[i][j]);

						if(exp_ptr!=0 ){
								
							//cout<<"\noperate"<<endl;
							Array[i][j]->Operation( Array, i+1, j+1,i,j );
						
						//cout<<"\nafter operate"<<Array[i+1][j-+1]->getAccess()<<endl;

						}	// idf exp_ptr


					//operate ANALYZE


						 an_ptr=dynamic_cast<Analyze *> (Array[i][j]);
						
						if(an_ptr!=0){
						cout<<"\nOperation Analyze: "<<endl;
						Array[i][j]->Operation( Array ,i+1, j+1,i,j);
						}

                                                         
						temp=Array[i+1][j+1];
						Array[i+1][j+1]=Array[i][j];
						Array[i][j]=temp;
						}

					}


					break;//3

					case 4:

					if(j-1>=0){

			
					//operate rescue 

					r_ptr=dynamic_cast<Robot *> (Array[i][j-1]);	
						
					if(r_ptr!=0 ){ // && Array[i+1][j-1]->getKatastasi()==false  ){
			
						res_ptr=dynamic_cast<Rescue *> (Array[i][j]);
						
						if(res_ptr!=0){

						Array[i][j]->Operation( Array, i, j-1, i,j );

						} 	// end if res_ptr
					
						

						
					}	// telos ifr_ptr!=0 && Array[i+1][j-1]->getKatastasi()==false  OPERATE RESCUE
					
					ed_ptr=dynamic_cast<Edafos *>(Array[i][j-1]);		

						if(ed_ptr!=0){


						// operate sto array(i+1)(j-1)
						
						exp_ptr=dynamic_cast<Explore *> (Array[i][j]);

						if(exp_ptr!=0 ){
								
							
							Array[i][j]->Operation( Array, i, j-1, i,j  );
						
						//operate ANALYZE

						 an_ptr=dynamic_cast<Analyze *> (Array[i][j]);
						
						if(an_ptr!=0){
						cout<<"\nOperation Analyze: "<<endl;
						Array[i][j]->Operation( Array ,i, j-1,i,j);
						}
			
					



						}	// idf exp_ptr

					 	temp=Array[i][j-1];
						Array[i][j-1]=Array[i][j];
						Array[i][j]=temp;
						}	
					
					}

					break;//4

					case 5:


					break;//5


					case 6:

					if(j+1<20){


					//operate rescue 

					r_ptr=dynamic_cast<Robot *> (Array[i][j+1]);	
						
					if(r_ptr!=0 ){ // && Array[i+1][j-1]->getKatastasi()==false  ){
			
						res_ptr=dynamic_cast<Rescue *> (Array[i][j]);
						
						if(res_ptr!=0){

						Array[i][j]->Operation( Array, i, j+1, i,j );

						} 	// end if res_ptr
					
					}	// telos ifr_ptr!=0 && Array[i+1][j-1]->getKatastasi()==false  OPERATE RESCUE
					//operate explore
					ed_ptr=dynamic_cast<Edafos *>(Array[i][j+1]);		

						if(ed_ptr!=0){

						
						
						exp_ptr=dynamic_cast<Explore *> (Array[i][j]);

						if(exp_ptr!=0 ){
								
							
							Array[i][j]->Operation( Array, i, j+1, i,j );
						
						

						}	// idf exp_ptr


						//operate ANALYZE

						 an_ptr=dynamic_cast<Analyze *> (Array[i][j]);
						
						if(an_ptr!=0){
						cout<<"\nOperation Analyze: "<<endl;
						Array[i][j]->Operation( Array ,i, j+1,i,j);
						}


					 	temp=Array[i][j+1];
						Array[i][j+1]=Array[i][j];
						Array[i][j]=temp;
						}	
					
					}

					
					break; //6

	
					case 7:


					if(i-1>=0 && j-1>=0){


					//operate rescue 

					r_ptr=dynamic_cast<Robot *> (Array[i-1][j-1]);	
						
					if(r_ptr!=0 ){ // && Array[i+1][j-1]->getKatastasi()==false  ){
			
						res_ptr=dynamic_cast<Rescue *> (Array[i][j]);
						
						if(res_ptr!=0){

						Array[i][j]->Operation( Array, i-1, j-1, i,j );

						} 	// end if res_ptr
					
						

						
					}	// telos ifr_ptr!=0 && Array[i+1][j-1]->getKatastasi()==false  OPERATE RESCUE
                                                   
					ed_ptr=dynamic_cast<Edafos *>(Array[i-1][j-1]);

						if(ed_ptr!=0){

						// operate sto array
						
						exp_ptr=dynamic_cast<Explore *> (Array[i][j]);

						if(exp_ptr!=0 ){
								
							
							Array[i][j]->Operation( Array, i-1, j-1, i ,j );
						
						

						}	// idf exp_ptr


						//operate ANALYZE

						 an_ptr=dynamic_cast<Analyze *> (Array[i][j]);
						
						if(an_ptr!=0){
						cout<<"\nOperation Analyze: "<<endl;
						Array[i][j]->Operation( Array ,i-1, j-1,i,j);
						}

					
                                                         
						temp=Array[i-1][j-1];
						Array[i-1][j-1]=Array[i][j];
						Array[i][j]=temp;
						}

					}


					break; //7

						
					case 8:

					if(i-1>=0){

					//operate rescue 

					r_ptr=dynamic_cast<Robot *> (Array[i-1][j]);	
						
					if(r_ptr!=0 ){ // && Array[i+1][j-1]->getKatastasi()==false  ){
			
						res_ptr=dynamic_cast<Rescue *> (Array[i][j]);
						
						if(res_ptr!=0){

						Array[i][j]->Operation( Array, i-1, j, i,j );

						} 	// end if res_ptr
					
						

						
					}	// telos ifr_ptr!=0 && Array[i+1][j-1]->getKatastasi()==false  OPERATE RESCUE



					ed_ptr=dynamic_cast<Edafos *>(Array[i-1][j]);

						if(ed_ptr!=0){


						// operate sto array(i+1)(j-1)
						
						exp_ptr=dynamic_cast<Explore *> (Array[i][j]);

						if(exp_ptr!=0 ){
								
							
							Array[i][j]->Operation( Array, i-1, j, i,j );
						
						

						}	// idf exp_ptr


					//operate ANALYZE

						 an_ptr=dynamic_cast<Analyze *> (Array[i][j]);
						
						if(an_ptr!=0){
						cout<<"\nOperation Analyze: "<<endl;
						Array[i][j]->Operation( Array ,i-1, j,i,j);
						}



						temp=Array[i-1][j];
						Array[i-1][j]=Array[i][j];
						Array[i][j]=temp;

						}// end if i-1 && j-1

					}


					break; //8
					

					case 9:


					if(i-1>=0 && j+1<20){


					//operate rescue 

					r_ptr=dynamic_cast<Robot *> (Array[i-1][j+1]);	
						
					if(r_ptr!=0 ){ // && Array[i+1][j-1]->getKatastasi()==false  ){
			
						res_ptr=dynamic_cast<Rescue *> (Array[i][j]);
						
						if(res_ptr!=0){

						Array[i][j]->Operation( Array, i-1, j+1, i,j );

						} 	// end if res_ptr
					
						
					}	// telos ifr_ptr!=0 && Array[i+1][j-1]->getKatastasi()==false  OPERATE RESCUE


					ed_ptr=dynamic_cast<Edafos *>(Array[i-1][j+1]);

						if(ed_ptr!=0){

						// operate sto array(i+1)(j-1)
						
						exp_ptr=dynamic_cast<Explore *> (Array[i][j]);

						if(exp_ptr!=0 ){
								
							
							Array[i][j]->Operation( Array, i-1, j+1, i,j );
						
						

						}	// idf exp_ptr


					//operate ANALYZE

						 an_ptr=dynamic_cast<Analyze *> (Array[i][j]);
						
						if(an_ptr!=0){
						cout<<"\nOperation Analyze: "<<endl;
						Array[i][j]->Operation( Array ,i-1, j+1,i,j);
						}



						temp=Array[i-1][j+1];
						Array[i-1][j+1]=Array[i][j];
						Array[i][j]=temp;

						}
					
					}

					break; //9

					
					default:
						
					break;//def


				}//telos switch kinisi

			}	// telos else



			} 	// if getTime

		}	// telos if r_ptr=0
				
	}//telos for j kinisis
			
}// telos for i kinisis


++time;	// +1 gia ton xrono prosomoiwsis 

 }while(choice!=8); // telos programmatos

//system("PAUSE");
return 0;
} // end main



// TELOS

