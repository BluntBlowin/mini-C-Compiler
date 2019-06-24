#include "f.h"
int char_num(char c,int sze,CN *t)
{
    for (int i=0;i<sze;i++)
    {
        if(t[i].str==c)
           return t[i].ent;
    }
return -1; /**Cas d'erreur**/
}
/**___________Lecure àpartir d'un fichier ______________________________**/
void lectur_fichier(const char *filename)
{
    string c;
    ifstream file(filename);
    while(!file.eof())
        {
            file >> c;
            cout<<c<<endl;
        }
}

/**ANALYSE Lexical______________________________________________________**/
bool Token(int aut[27][37],int etat_fin[27],int len,CN *ind_j,int nbr_char,string c)
{
int i,j,etat_courant=0,erreur=0;
for(i=0;i<len;i++)
	{
		    j=char_num(c[i],nbr_char,ind_j);

			if(j==-1){if(c!="$")
					  {cout<<"la lettre '"<<c[i]<<"' dans le mot"<<c;
					  cout<<"n'existe pas dans l'alphbet"<<endl;}
					  return false;
					  }
			else{
				etat_courant=aut[etat_courant][j];

				if(etat_courant==-1){
									i=len;
									erreur=1;
									}
				}
	}
if(erreur==0 && etat_fin[etat_courant]==1)
    {
    return true;
    }

		return false;
}
void Lexer2(const char *code_source,CN *ind_j,int nbr_char,int *nbr_erreurs,string *lst_errs,string *unit_lex,string *cd_src,int *num_ligne)
{

	int num_line=0;
    int erreur1=0,i,j=0;
//automates des mots cles
                    //a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
int aef1[27][37]={  {-1,-1,-1, 9, 1, 4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,21,14,-1,-1,-1,-1,-1,-1},  //0
                    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},  //1
                    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 3,-1,-1,-1,-1,-1,-1},   //2
                    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},  //3
                    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},  //4
                    { 6,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},  //5
                    {-1,-1,-1,-1,-1,-1,-1,-1, 7,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},  //6
                    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 8,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},  //7
                    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},  //8
                    {-1,-1,-1,-1,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},  //9
                    {-1,-1,-1,-1,-1,11,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},  //10
                    {-1,-1,-1,-1,-1,-1,-1,-1,12,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},  //11
                    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},  //12
                    {-1,-1,-1,-1,26,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},  //13
                    {15,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},  //14
                    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,16,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},  //15
                    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,17,-1,-1,-1,-1,-1,-1},  //16
                    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,18,-1,-1,-1,-1,-1,-1,-1,-1,-1},  //17
                    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,19,-1,-1,-1,-1,-1},  //18
                    {-1,-1,-1,-1,20,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},  //19
                    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},  //20
                    {-1,-1,-1,-1,-1,-1,-1,-1,22,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},  //21
                    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,23,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},  //22
                    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,24,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},  //23
                    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,25,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},  //24
                    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},  //25
                    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},  //26
                    };
int etat_fin1[27];
for(int i=0;i<27;i++)etat_fin1[i]=0;
etat_fin1[3]=1;etat_fin1[8]=1;etat_fin1[26]=1;
etat_fin1[20]=1;etat_fin1[22]=1;etat_fin1[25]=1;

//automates des identificateurs
                  //a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  _
int aef2[3][37]=  {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                   {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, 1, 2},
                   {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, 1,-1},
                  };
int etat_fin2[3];
for(i=0;i<3;i++)etat_fin2[i]=0;
etat_fin2[1]=1;etat_fin2[2]=1;

//automates des npmbres
int aef3[2][37]= { {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,-1},
                  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,-1},
                };
int etat_fin3[2];
etat_fin3[0]=0;etat_fin3[1]=1;
 ifstream file(code_source);
 string line;
 string c;
 if(file)
    {
	 while(!file.eof())
	   {
        getline(file,line);
		num_line++;
		cout<<"________________"<<endl<<"la line num "<<num_line<<" du code source "<<endl<<line<<endl<<"_________________"<<endl;

		char  buf[10];sprintf(buf,"%d",num_line);
		string b=buf;
		if(line[0]!='/'&&line[1]!='/')
            {
            ofstream fichier("E:tmp.txt",ios::out  | ios::trunc);
            if(!fichier){*nbr_erreurs=-70;cout<<"erreur d'ouverture l fichier temporaire"<<endl;}
            else
                {
                line+=" $"; fichier<<line;fichier.close();
                ifstream file2("E:tmp.txt");
                c="";
                if(!file2)*nbr_erreurs=-90;
                else
                while(c!="$")
				   {
				    file2>>c;
					int len;
					//cout<<"___________"<<"extraction du mot depuis le fichier temporaires "<<c<<endl;
					len=c.size();
					//cout<<"l'indice dans le code source:   "<<j<<endl;
                    if(c=="=" || c=="+" || c=="-"|| c=="*"|| c=="/" ||c=="<" ||c==">" ||c=="!") {cout<<c<<"    operateur"<<endl;
                                                                                                *unit_lex+=c+" :operateur \r\n";
                                                                                                cd_src[j]=c;
                                                                                                num_ligne[j]=num_line;
                                                                                                j++;}
                    else if(c=="," ||c==";" ||c=="(" ||c==")" ||c=="{" ||c=="}" )               {cout<<c<<"    sepaerateur"<<endl;
                                                                                                *unit_lex+=c+" :separateur  \r\n";
                                                                                                cd_src[j]=c;
                                                                                                num_ligne[j]=num_line;
                                                                                                j++;}

                    else if(c=="'*"){string chaine=c;
                                        while(c!="*'" && !file2.eof())
                                        {
                                         file2>>c;
                                         chaine+=c;
                                        }
                                        if(c=="*'"){cout<<chaine <<" chaine de caractere "<<endl;
                                                    *unit_lex+=chaine+" :chaine de caractere  \r\n";
                                                    chaine="2"+chaine;
                                                    cd_src[j]=chaine;
                                                    num_ligne[j]=num_line;
                                                    j++;
                                                    }
                                        else {
                                            cout<<"erreur symbole fin de chaine nn trouvé"<<endl;
                                        *lst_errs+=" erreur symbole fin de chaine nn trouvé:       line (" + b + ") \r\n";
                                            erreur1++;
                                             }

                                    }
                    else if(Token(aef1,etat_fin1,len,ind_j,nbr_char,c))
						 {
						  cout<<c<<"      "<<"mot cle"<<endl;
						 *unit_lex+=c+ " :mot clé \r\n";
						 cd_src[j]=c;num_ligne[j]=num_line;j++;
						  }
                    else if(c=="lire" || c=="ecrire")
                                        {
		                                  cout<<c<<"      "<<"mot cle"<<endl;
										  *unit_lex+=c+ " :mot clé \r\n";
										  cd_src[j]=c;num_ligne[j]=num_line;j++;
                                        }
                    else if(Token(aef3,etat_fin3,len,ind_j,nbr_char,c))
							{
						  //on commence les entiers par 0
						  cout<<c<<"  :nombre"<<endl;
						 *unit_lex+=c+ ": nombre \r\n";
						 c="0"+c;
						 cd_src[j]=c;num_ligne[j]=num_line;j++;
						  }
                    else if(Token(aef2,etat_fin2,len,ind_j,nbr_char,c))
						 {
					     //on commence les ids par1
						*unit_lex+=c+ " :identificateur \r\n";
						cout<<c<<" identificateur"<<endl;
						c="1"+c;
						cd_src[j]=c;num_ligne[j]=num_line;j++;
						}
                    else
						{   if(c!="$")
						    {cout<<c<<" erreur : line ("<<b<<") \n"<<endl;
						     *lst_errs+=c+ " Token non connu:       line (" + b + ") \r\n";
						    erreur1++;
                            }

						}
                    }
				   file2.close();
                }
            }
	   }
	     file.close();
	   *nbr_erreurs=erreur1;
	   cd_src[j]="#";
	   cout<<"le nombre des erreures lexicales est :"<<*nbr_erreurs<<endl;
    }
 else {cout<<"erreur d'ouverture le fichier CodeSource "<<endl;
 *nbr_erreurs=-80;}
}

//**_________________________
//**_________________________
/**Analyse syntaxique____________________________________**/
/**Fonction indice_i
on la donne le sommet de pile
elle return l'indice i dans la table d'analyse **/

int indice_i(string c)
{
	if(c=="0")return 0;
	else if(c== "1")return 1;
	else if(c== "2")return 2;
	else if(c== "3")return 3;
	else if(c== "4")return 4;
	else if(c== "5")return 5;
	else if(c== "6")return 6;
	else if(c== "7")return 7;
	else if(c== "8")return 8;
	else if(c== "9")return 9;
	else if(c== "10")return 10;
	else if(c== "11")return 11;
	else if(c== "12")return 12;
	else if(c== "13")return 13;
	else if(c== "14")return 14;
	else if(c== "15")return 15;
	else if(c== "16")return 16;
	else if(c== "17")return 17;
	else if(c== "18")return 18;
	else if(c== "19")return 19;
	else if(c== "20")return 20;
	else if(c== "21")return 21;
	else if(c== "22")return 22;
	else if(c== "23")return 23;
	else if(c== "24")return 24;
	else if(c== "25")return 25;
	else if(c== "26")return 26;
	else if(c== "27")return 27;
	else if(c== "28")return 28;
	else if(c== "29")return 29;
	else if(c== "30")return 30;
	else if(c== "31")return 31;
	else{
        return -1;
	    }
}
/**Fonction indice_j
on la donne le terme_courant
elle return l'indice j dans la table d'analyse **/
int indice_j(string c)
{
if(c[0]=='0') return 6;      //les termes des entiers commence par 0
else if(c[0]=='1') return 7; //les termes des ids commence par 1
else if(c=="define")return 0 ;
else if(c=="ent")return 1  ;
else if(c=="fmain")return 2  ;
else if(c=="tantque")return 3 ;
else if(c=="si")return  4;
else if(c=="sinon")return 5 ;
else if(c==",")return  8;
else if(c==";")return 9 ;
else if(c=="{")return  10;
else if(c==	"}")return 11 ;
else if(c=="(")return 12 ;
else if(c==")")return  13;
else if(c=="+")return 14 ;
else if(c=="-")return  15;
else if(c=="*")return 16 ;
else if(c=="/")return  17;
else if(c=="<")return 18 ;
else if(c==">")return  19;
else if(c=="=")return 20 ;
else if(c=="!")return 21 ;
else if(c=="lire")return 22 ;
else if(c=="ecrire")return 23 ;
else if(c[0]=='2')return 24 ;

}

int parser(string *cd_src,int *num_line,HWND edit)
{
    stack<string> pile;
    int etat_courant=1,i,j,k=0;
    string sommet_de_pile;
    string terme_courant;
    string indication="";
                       //define| ent|fmain|tantque| si |sinon|<entier> |<id>| ,   ;   {    }   (    )   +   -   *   /   <   >   =   !  lire  ecrire chaine
int table_d[32][25]={   {   -1 , -1 , -1  ,   -1  , -1 , -1  ,   -1    , -1 ,-1 , -1 ,-1 ,-1 , -1 ,-1 ,-1 ,-1 ,-1 , -1, -1, -1,-1 ,-1 , -1 ,   -1  ,  -1  }, //A 0
                        {    1 ,  2 ,  3  ,   -1  , -1 , -1  ,   -1    , -1 ,-1 , -1 ,-1 ,-1 , -1 ,-1 ,-1 ,-1 ,-1 , -1, -1, -1,-1 ,-1 , -1 ,   -1  ,  -1  },//B1
                        {   -1 ,  4 ,  5  ,   -1  , -1 , -1  ,   -1    , -1 ,-1 , -1 ,-1 ,-1 , -1 ,-1 ,-1 ,-1 ,-1 , -1, -1, -1,-1 ,-1 , -1 ,   -1  ,  -1  },//C2
                        {    6 , -1 , -1  ,   -1  , -1 , -1  ,   -1    , -1 ,-1 , -1 ,-1 ,-1 , -1 ,-1 ,-1 ,-1 ,-1 , -1, -1, -1,-1 ,-1 , -1 ,   -1  ,  -1  },//D3
                        {    7 ,  8 ,  8  ,   -1  , -1 , -1  ,   -1    , -1 ,-1 , -1 ,-1 ,-1 , -1 ,-1 ,-1 ,-1 ,-1 , -1, -1, -1,-1 ,-1 , -1 ,   -1  ,  -1  },//E4
                        {   -1 ,  9 , -1  ,   -1  , -1 , -1  ,   -1    , -1 ,-1 , -1 ,-1 ,-1 , -1 ,-1 ,-1 ,-1 ,-1 , -1, -1, -1,-1 ,-1 , -1 ,   -1  ,  -1  },//F5
                        {   -1 , -1 , -1  ,   -1  , -1 , -1  ,   -1    , -1 ,10 , 11 ,-1 ,-1 , -1 ,-1 ,-1 ,-1 ,-1 , -1, -1, -1,-1 ,-1 , -1 ,   -1  ,  -1  },//G6
                        {   -1 , 12 , 13  ,   -1  , -1 , -1  ,   -1    , -1 ,-1 , -1 ,-1 ,-1 , -1 ,-1 ,-1 ,-1 ,-1 , -1, -1, -1,-1 ,-1 , -1 ,   -1  ,  -1  },//H7
                        {   -1 , -1 , -1  ,   -1  , -1 , -1  ,   -1    , -1 ,14 , -1 ,-1 ,-1 , -1 ,-1 ,-1 ,-1 ,-1 , -1, -1, -1,-1 ,-1 , -1 ,   -1  ,  -1  },//I8
                        {   -1 , -1 , -1  ,   -1  , -1 , -1  ,   -1    , -1 ,15 , 16 ,-1 ,-1 , -1 ,-1 ,-1 ,-1 ,-1 , -1, -1, -1,-1 ,-1 , -1 ,   -1  ,  -1  },//J9
                        {   -1 , -1 , 17  ,   -1  , -1 , -1  ,   -1    , -1 ,-1 , -1 ,-1 ,-1 , -1 ,-1 ,-1 ,-1 ,-1 , -1, -1, -1,-1 ,-1 , -1 ,   -1  ,  -1  },//K10
                        {   -1 , -1 , -1  ,   -1  , -1 , -1  ,   -1    , -1 ,-1 , -1 ,18 ,-1 , -1 ,-1 ,-1 ,-1 ,-1 , -1, -1, -1,-1 ,-1 , -1 ,   -1  ,  -1  },//L11
                        {   -1 , -1 , -1  ,   19  , 19 , -1  ,   -1    , 19 ,-1 , -1 ,-1 ,-1 , -1 ,-1 ,-1 ,-1 ,-1 , -1, -1, -1,-1 ,-1 , 19 ,   19  ,  -1  },//M12
                        {   -1 , -1 , -1  ,   20  , 20 , -1  ,   -1    , 20 ,-1 , -1 ,-1 ,-1 , -1 ,-1 ,-1 ,-1 ,-1 , -1, -1, -1,-1 ,-1 , 20 ,   20  ,  -1  },//N13
                        {   -1 , -1 , -1  ,   21  , 21 , -1  ,   -1    , 21 ,-1 , -1 ,-1 ,22 , -1 ,-1 ,-1 ,-1 ,-1 , -1, -1, -1,-1 ,-1 , 21 ,   21  ,  -1  },//O14
                        {   -1 , -1 , -1  ,   24  , 23 , -1  ,   -1    , 25 ,-1 , -1 ,-1 ,-1 , -1 ,-1 ,-1 ,-1 ,-1 , -1, -1, -1,-1 ,-1 , 47 ,   48  ,  -1  },//P15
                        {   -1 , -1 , -1  ,   -1  , 26 , -1  ,   -1    , -1 ,-1 , -1 ,-1 ,-1 , -1 ,-1 ,-1 ,-1 ,-1 , -1, -1, -1,-1 ,-1 , -1 ,   -1  ,  -1  },//Q16
                        {   -1 , -1 , -1  ,   28  , 28 , 27  ,   -1    , 28 ,-1 , -1 ,-1 ,28 , -1 ,-1 ,-1 ,-1 ,-1 , -1, -1, -1,-1 ,-1 , 28 ,   28  ,  -1  },//R17
                        {   -1 , -1 , -1  ,   29  , -1 , -1  ,   -1    , -1 ,-1 , -1 ,-1 ,-1 , -1 ,-1 ,-1 ,-1 ,-1 , -1, -1, -1,-1 ,-1 , -1 ,   -1  ,  -1  },//S18
                        {   -1 , -1 , -1  ,   -1  , -1 , -1  ,   -1    , 30 ,-1 , -1 ,-1 ,-1 , -1 ,-1 ,-1 ,-1 ,-1 , -1, -1, -1,-1 ,-1 , -1 ,   -1  ,  -1  },//T19
                        {   -1 , -1 , -1  ,   -1  , -1 , -1  ,   31    , 31 ,-1 , -1 ,-1 ,-1 , 31 ,-1 ,-1 ,31 ,-1 , -1, -1, -1,-1 ,-1 , -1 ,   -1  ,  -1  },//U20
                        {   -1 , -1 , -1  ,   -1  , -1 , -1  ,   -1    , -1 ,-1 , 34 ,-1 ,-1 , -1 ,34 ,32 ,32 ,32 , 32, 33, 33,33 ,33 , -1 ,   -1  ,  -1  },//V21
                        {   -1 , -1 , -1  ,   -1  , -1 , -1  ,   35    , 36 ,-1 , -1 ,-1 ,-1 , 37 ,-1 ,-1 ,38 ,-1 , -1, -1, -1,-1 ,-1 , -1 ,   -1  ,  -1  },//W22
                        {   -1 , -1 , -1  ,   -1  , -1 , -1  ,   -1    , -1 ,-1 , -1 ,-1 ,-1 , -1 ,-1 ,39 ,40 ,41 , 42, -1, -1,-1 ,-1 , -1 ,   -1  ,  -1  },//X23
                        {   -1 , -1 , -1  ,   -1  , -1 , -1  ,   -1    , -1 ,-1 , -1 ,-1 ,-1 , -1 ,-1 ,-1 ,-1 ,-1 , -1, 43, 44,45 ,46 , -1 ,   -1  ,  -1  },//Y24
                        {   -1 , -1 , -1  ,   -1  , -1 , -1  ,   -1    , -1 ,-1 , -1 ,-1 ,-1 , -1 ,-1 ,-1 ,-1 ,-1 , -1, -1, -1,-1 ,-1 , 49 ,   -1  ,  -1  },//Z25
                        {   -1 , -1 , -1  ,   -1  , -1 , -1  ,   -1    , -1 ,-1 , -1 ,-1 ,-1 , -1 ,-1 ,-1 ,-1 ,-1 , -1, -1, -1,-1 ,-1 , -1 ,   50  ,  -1  },//AA26
                        {   -1 , -1 , -1  ,   -1  , -1 , -1  ,   52    , 52 ,-1 , -1 ,-1 ,-1 , 52 ,51 ,-1 ,52 ,-1 , -1, -1, -1,-1 ,-1 , -1 ,   -1  ,  52  },//BB27
                        {   -1 , -1 , -1  ,   -1  , -1 , -1  ,   -1    , -1 ,54 , -1 ,-1 ,-1 , -1 ,53 ,-1 ,-1 ,-1 , -1, -1, -1,-1 ,-1 , -1 ,   -1  ,  -1  },//CC28
                        {   -1 , -1 , -1  ,   -1  , -1 , -1  ,   -1    , -1 ,55 , -1 ,-1 ,-1 , -1 ,-1 ,-1 ,-1 ,-1 , -1, -1, -1,-1 ,-1 , -1 ,   -1  ,  -1  },//DD29
                        {   -1 , -1 , -1  ,   -1  , -1 , -1  ,   -1    , -1 ,56 , -1 ,-1 ,-1 , -1 ,57 ,-1 ,-1 ,-1 , -1, -1, -1,-1 ,-1 , -1 ,   -1  ,  -1  },//EE30
                        {   -1 , -1 , -1  ,   -1  , -1 , -1  ,   58    , 58 ,-1 , -1 ,-1 ,-1 , 58 ,-1 ,-1 ,58 ,-1 , -1, -1, -1,-1 ,-1 , -1 ,   -1  ,  59  },//FF31
                       //define| ent|fmain|tantque| si |sinon|<entier> |<id>| ,   ;   {    }   (    )   +   -   *   /   <   >   =   !  lire  ecrire chaine

                     };
pile.push("#");pile.push("1");
int l;
while(terme_courant != "#")
    {
terme_courant=cd_src[k];
sommet_de_pile=pile.top();
cout<<endl<<"terme_C :"<<terme_courant<<"     sommet :"<<sommet_de_pile;
if(sommet_de_pile == terme_courant || terme_courant[0]=='1' && sommet_de_pile=="id" ||terme_courant[0]=='0' && sommet_de_pile=="entier" ||terme_courant[0]=='2' && sommet_de_pile=="chaine" )                          //verifier si le terme courant et le sommet de pile sont les deux identificateurs;
    {
	 pile.pop();
	 k++;

	// terme_courant=code.front();
	 terme_courant=cd_src[k];
	 sommet_de_pile=pile.top();
                    cout<<"  avancer"<<endl;
	}

                    else
                        {
                            i=indice_i(sommet_de_pile);      //cout<<" "<<i<<endl;
                            j=indice_j(terme_courant);      //cout<<" "<<j<<endl;

	                             etat_courant=table_d[i][j]; cout<<" etat suivant :"<<etat_courant<<endl;
	                             pile.pop();
	                             switch(etat_courant)
	                             {
	                             case -1 :{
                                            cout<<endl<<"chaine non acceptée"<<endl;
                                            cout<<"erreur syntaxique dans la ligne num  "<<num_line[k]<<endl;
	                                        if(sommet_de_pile=="1"){indication="mot clé d'itroducton manque";}
                                            else if (sommet_de_pile=="2"){indication="mot clé d'itroducton manque";}
											else if (sommet_de_pile=="3"){indication="un separateur ou operateur manque";}
											else if (sommet_de_pile=="4"){indication="mot clé d'itroducton manque";}
											else if (sommet_de_pile=="5"){indication="mot clé d'itroducton manque";}
											else if (sommet_de_pile=="6"){indication="< ; > ou < , > manque  ";}
											else if (sommet_de_pile=="7"){indication=" fmain non trouvée ";}
											else if (sommet_de_pile=="8"){indication="< ; > ou < , > manque  ";}
											else if (sommet_de_pile=="9"){indication="< ; > ou < , > manque  ";}
											else if (sommet_de_pile=="10"){indication=" fmain non trouvée ";}
											else if (sommet_de_pile=="11"){indication=" < } >  manque";}
											else if (sommet_de_pile=="12"){indication="mot clé ou un identifiant qui manque  ";}
											else if (sommet_de_pile=="13"){indication="mot clé ou un identifiant qui manque  ";}
											else if (sommet_de_pile=="14"){indication="<sinon> sans <si> ";}
											else if (sommet_de_pile=="15"){indication="mot clé ou un identifiant qui manque  ";}
											else if (sommet_de_pile=="16"){indication="Condition  ";}
											else if (sommet_de_pile=="17"){indication="mot clé ou un identifiant qui manque  ";}
											else if (sommet_de_pile=="18"){indication="nAn  ";}
											else if (sommet_de_pile=="19"){indication="nAn  ";}
											else if (sommet_de_pile=="20"){indication="< { > qui manque  ";}
											else if (sommet_de_pile=="21"){indication="< ; > qui manque  ";}
											else if (sommet_de_pile=="22"){indication="nAn  ";}
											else if (sommet_de_pile=="23"){indication="nAn  ";}
											else if (sommet_de_pile=="24"){indication="nAn  ";}
											else if (sommet_de_pile=="25"){indication="nAn  ";}
											else if (sommet_de_pile=="26"){indication="nAn  ";}
											else if (sommet_de_pile=="27"){indication="nAn  ";}
											else if (sommet_de_pile=="28"){indication="nAn  ";}
											else if (sommet_de_pile=="29"){indication="nAn  ";}
											else if (sommet_de_pile=="30"){indication="nAn  ";}
											else if (sommet_de_pile=="31"){indication="nAn  ";}
											string message="erreur syntaxique  ligne num ";
											char  buf[5];sprintf(buf,"%d",num_line[k]);
											string num=buf;
											message+=num+"\r"+"\n"+indication;
											char *y=new char[message.length()+1];
                                            strcpy(y,message.c_str());
                                            //strcpy(y,num.c_str());
                                           // strcat(message,y);
											SetWindowText(edit,y);
                                            return 0;};break;
	                             case 1:pile.push("2");pile.push("3");cout<<" |2 | 3 "<<endl;break;
	                             case 2:pile.push("10");pile.push("5");cout<<" |10 | 5 "<<endl;break;
	                             case 3:pile.push("10");cout<<" |10 "<<endl;break;
	                             case 4:pile.push("5");cout<<"| 5 "<<endl;break;
	                             case 5:pile.push("10");cout<<" |10 "<<endl;break;
	                             case 6:pile.push("4");pile.push("entier");pile.push("id");pile.push("define");cout<<" |4 |entier|id|define "<<endl;break;
	                             case 7:pile.push("3");cout<<" |3"<<endl;break;
	                             case 8:cout<<"(depiler) ";break;
								 case 9:pile.push("6");pile.push("id");pile.push("ent");cout<<" |6|id|ent "<<endl;break;
	                             case 10:pile.push("7");pile.push(";");pile.push("8");cout<<" |7|;|8 "<<endl;break;
	                             case 11:pile.push("5");pile.push(";");cout<<" |5|; "<<endl;    break;
	                             case 12:pile.push("5");cout<<" |5"<<endl; break;
	                             case 13:cout<<"(depiler) ";break;
	                             case 14:pile.push("9");pile.push("id");pile.push(",");cout<<" |9|id|, "<<endl; break;
	                             case 15:pile.push("8");cout<<" |8 "<<endl; break ;
	                             case 16:cout<<"(depiler) "<<endl; break;
	                             case 17:pile.push("11");pile.push(")");pile.push("(");pile.push("fmain");cout<<" |11|)|(|fmain "<<endl; break;
	                             case 18:pile.push("12");pile.push("{");cout<<" |12|{ "<<endl; break;
	                             case 19:pile.push("}");pile.push("13");cout<<" |}|13 "<<endl; break;
	                             case 20:pile.push("14");pile.push("15");cout<<" |14|15 "<<endl; break;
	                             case 21:pile.push("13");cout<<" |13 "<<endl; break;
	                             case 22:cout<<"(depiler) "<<endl; break;
	                             case 23:pile.push("16");cout<<" |16 "<<endl; break;
	                             case 24:pile.push("18");cout<<" |18 "<<endl; break;
	                             case 25:pile.push("19");break;
	                             case 26:pile.push("17");pile.push("11");pile.push(")");pile.push("20");pile.push("(");pile.push("si");cout<<" |17|11|)20|(|si "<<endl;   break;
	                             case 27:pile.push("11");pile.push("sinon");cout<<" |11|sinon "<<endl; break;
	                             case 28:cout<<"(depiler) "<<endl; break;
	                             case 29:pile.push("11");pile.push(")");pile.push("20");pile.push("(");pile.push("tantque");cout<<" |11|)|20|(|tantque "<<endl;  break;
	                             case 30:pile.push(";");pile.push("20");pile.push("=");pile.push("id");cout<<" |;|20|=|id "<<endl;  break;
	                             case 31:pile.push("21");pile.push("22");cout<<" |21|22 "<<endl; break;
	                             case 32:pile.push("20");pile.push("23");cout<<" |20|23 "<<endl; break;
	                             case 33: pile.push("20");pile.push("24");cout<<" |20|24; "<<endl; break;
	                             case 34:cout<<"(depiler) "<<endl; break;
	                             case 35:pile.push("entier");cout<<" |entier "<<endl; break;
	                             case 36:pile.push("id");cout<<" |id "<<endl; break;
	                             case 37:pile.push(")");pile.push("20");pile.push("(");cout<<" |)|20|( "<<endl;  break;
	                             case 38: pile.push("22");pile.push("-");cout<<" |22|- "<<endl; break;
	                             case 39:pile.push("+");cout<<" |+ "<<endl; break;
	                             case 40:pile.push("-");cout<<" |- "<<endl; break;
	                             case 41: pile.push("*");cout<<" |* "<<endl; break;
	                             case 42:pile.push("/");cout<<" |/ "<<endl; break;
	                             case 43:pile.push("<");cout<<" |< "<<endl; break;
	                             case 44: pile.push(">");cout<<" |> "<<endl; break;
	                             case 45:pile.push("=");cout<<" |= "<<endl; break;
	                             case 46: pile.push("!");cout<<" |! "<<endl; break;
	                             case 47: pile.push("25"); cout<<" 47"<<endl;cout<<" |25|47 "<<endl; break;
	                             case 48: pile.push("26"); cout<<" 48"<<endl;cout<<" |26|48 "<<endl; break;
	                             case 49: pile.push(";"); pile.push(")");pile.push("id");pile.push("(");pile.push("lire");cout<<" 49"<<endl;cout<<" |;|)|id|(|lire "<<endl; break;
	                             case 50: pile.push("27");pile.push("(");pile.push("ecrire");cout<<" 50"<<endl;cout<<" |27|(|ecrire "<<endl; break;
	                             case 51: pile.push(";");pile.push(")");cout<<" |;|) "<<endl; break;
	                             case 52: pile.push("28");pile.push("31");cout<<" |28|31 "<<endl; break;
								 case 53: pile.push(";");pile.push(")");cout<<" |;|) "<<endl; break;
	                             case 54: pile.push(";");pile.push(")");pile.push("29");cout<<" |;|)|29 "<<endl; break;
	                             case 55: pile.push("30");pile.push("31");pile.push(",");cout<<" |30|31|, "<<endl; break;
	                             case 56: pile.push("29");cout<<" |29 "<<endl; break;
	                             case 57: cout<<"(depiler) ";break;
	                             case 58: pile.push("20");cout<<" |20 "<<endl; break;
	                             case 59: pile.push("chaine");cout<<" |chaine "<<endl; break;
	                             }
                         }
        }
	cout<<"fin d'analyse syntaxique"<<endl;
	if(terme_courant=="#" && sommet_de_pile=="#"){cout<<"chaine acceptée"<<endl;
                                                    char *c;


                                                  return -1;
                                                 }
    else if(sommet_de_pile=="#" || terme_courant=="#"){cout<<endl<<"chaine non acceptée"<<endl;
                                                        cout<<"erreur syntaxique dans la ligne num  "<<num_line[k]<<endl;
                                                        cout<<"sommet de pile :"<<sommet_de_pile<<endl;
                                                            if(sommet_de_pile=="1"){}
															else if (sommet_de_pile=="2"){}
															else if (sommet_de_pile=="3"){}
															else if (sommet_de_pile=="4"){}
															else if (sommet_de_pile=="5"){}
															else if (sommet_de_pile=="6"){}
															else if (sommet_de_pile=="7"){}
															else if (sommet_de_pile=="8"){}
															else if (sommet_de_pile=="9"){}
															else if (sommet_de_pile=="10"){}
															else if (sommet_de_pile=="11"){}
															else if (sommet_de_pile=="12"){}
															else if (sommet_de_pile=="13"){}
															else if (sommet_de_pile=="14"){}
															else if (sommet_de_pile=="15"){}
															else if (sommet_de_pile=="16"){}
															else if (sommet_de_pile=="17"){}
															else if (sommet_de_pile=="18"){}
															else if (sommet_de_pile=="19"){}
															else if (sommet_de_pile=="20"){}
															else if (sommet_de_pile=="22"){}
															else if (sommet_de_pile=="23"){}
															else if (sommet_de_pile=="24"){}
															else if (sommet_de_pile=="25"){}
															else if (sommet_de_pile=="26"){}
															else if (sommet_de_pile=="27"){}
															else if (sommet_de_pile=="28"){}
															else if (sommet_de_pile=="29"){}
															else if (sommet_de_pile=="30"){}
															else if (sommet_de_pile=="31"){}
                                                      return k;
                                                        }
}
void menu_create(HINSTANCE hinst,HWND hwnd,HMENU hMenu,HMENU hSubMenu)
{
   hMenu=CreateMenu();
               hSubMenu=CreatePopupMenu();
               AppendMenu(hSubMenu, MF_STRING, ID_FILE_NOUV, "New  ");
               AppendMenu(hSubMenu, MF_STRING, ID_FILE_OPEN, "Open  ");
               AppendMenu(hSubMenu, MF_STRING, ID_FILE_SAVE, "Save  ");
               AppendMenu(hSubMenu, MF_SEPARATOR, (UINT)NULL, "");//separateur
               AppendMenu(hSubMenu, MF_SEPARATOR, (UINT)NULL, "");//separateur
               AppendMenu(hSubMenu, MF_STRING, ID_FILE_QUIT, "Quit");
               AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, "File");

               hSubMenu = CreatePopupMenu();
               AppendMenu(hSubMenu, MF_STRING, ID_EDIT_UNDO, "Undo");
               AppendMenu(hSubMenu, MF_STRING, ID_EDIT_REDO, "Redo");
               AppendMenu(hSubMenu, MF_SEPARATOR, (UINT)NULL, "");//separateur
               AppendMenu(hSubMenu, MF_STRING, ID_EDIT_COPY, "Copy");
               AppendMenu(hSubMenu, MF_STRING, ID_EDIT_CUT, "Cut");
               AppendMenu(hSubMenu, MF_STRING, ID_EDIT_PASTE, "Paste");
               AppendMenu(hSubMenu, MF_STRING, ID_EDIT_DELETE, "Delete");
               AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, "Edit");

               hSubMenu = CreatePopupMenu();
               AppendMenu(hSubMenu, MF_STRING, ID_SETTINGS_POLICES, "Polices");
               AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, "Settings");

               hSubMenu = CreatePopupMenu();
               AppendMenu(hSubMenu, MF_STRING, ID_SETTINGS_ANALYSER2, "Analyser");
               AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, "Compiler");
               SetMenu(hwnd, hMenu);
}
BOOL Open_Dialogue_Box(HWND hnd,int commande)
{
 /*OPEN FILE NAME STRUCT**/
        OPENFILENAME ofn;
        char szFile[MAX_PATH]={0};
        ZeroMemory(&ofn, sizeof(OPENFILENAME));
        ofn.lStructSize  = sizeof(OPENFILENAME);
        szFile[0] = 0;
        ofn.hwndOwner    = hnd;
        ofn.lpstrFile    = szFile;
        ofn.lpstrFilter  = "Fichier texte(*.txt)\0*.txt;*.c;*.cpp\00";
        ofn.lpstrDefExt  = "txt";
        ofn.nFilterIndex = 1;
        ofn.nMaxFile     = MAX_PATH;

    if(commande == 0)
    {
    GetOpenFileName(&ofn);
    ouvrire_fichier(szFile,hnd);
      }
    if(commande == 1)
    {
     GetSaveFileName(&ofn);
     sauvegarder_fichier(szFile,hnd);
            }
 }

 BOOL ouvrire_fichier(char *NomFichier,HWND hEdit)
{
     HANDLE file=CreateFile(NomFichier,GENERIC_READ,
                          FILE_SHARE_READ,0,OPEN_EXISTING,0,0);
     DWORD Taille_Fichier;

     HGLOBAL Contenu;
     BOOL Read_File;
     DWORD Lu;
     Taille_Fichier = GetFileSize(file,NULL);
     if(Taille_Fichier != 0xFFFFFFFF)
     {
         Contenu = GlobalAlloc(GPTR,Taille_Fichier+1);
         if(Contenu != NULL)
         {
            Read_File = ReadFile(file,Contenu,Taille_Fichier,&Lu,NULL);
            if(Read_File != 0)
            {
                    SetWindowText(hEdit,(LPCSTR)Contenu);
                    GlobalFree(Contenu);
                    CloseHandle(file);
                    }
            }

     }else
     {
       MessageBox(hEdit,"No charged file","Eureur!",MB_ICONINFORMATION);
     }
 }


BOOL sauvegarder_fichier(char *NomFichier,HWND hEdit)
{

    DWORD file_size;
    DWORD nbrcharRead;
    BOOL Save_File;
    HANDLE file=CreateFile(NomFichier,GENERIC_WRITE,0,0,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,0);
    if(file != INVALID_HANDLE_VALUE)
    {
        file_size = GetWindowTextLength(hEdit);
        if(file_size > 0)
        {
           LPSTR Contenu;
           Contenu = (LPSTR)GlobalAlloc(GPTR,file_size+1);
           if(Contenu != NULL)
           {
            if(GetWindowText(hEdit,Contenu,file_size))
            {

              Save_File = WriteFile(file,Contenu,file_size,&nbrcharRead,NULL);
              if(Save_File != 0)
              {
                  GlobalFree(Contenu);
                  CloseHandle(file);
                           }
                          }

                      }
                   }
               }
         else
         {
          MessageBox(hEdit,"Impossible de Sauvegarder le fichier","Eureur!",MB_ICONINFORMATION);
         }



 }

