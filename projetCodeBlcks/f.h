#ifndef F_H_INCLUDED
#define F_H_INCLUDED
#include <tchar.h>
#include <windows.h>
#include <iostream>
#include <fstream>
#include<stdlib.h>
#include<string>
#include <cstring>
#include <iostream>
#include <stack>
#include<malloc.h>

#define ID_BUILD_ANALYSER                32771
#define ID_BUILD_EDIT1                34771
#define ID_BUILD_EDIT2                35771
#define ID_BUILD_EDIT3               36771
#define ID_FILE_NOUV  0
#define ID_FILE_OPEN 1
#define ID_FILE_SAVE 2
#define ID_FILE_QUIT 69
#define ID_EDIT_UNDO 3
#define ID_EDIT_REDO 4
#define ID_EDIT_COPY  5
#define ID_EDIT_CUT  6
#define ID_EDIT_PASTE 7
#define ID_EDIT_DELETE 8
#define ID_SETTINGS_POLICES 51
#define ID_SETTINGS_ANALYSER2 9
using namespace std;

typedef struct CN    /**Pour trouver l'indice j du char lu**/
{
    int ent;
    char str;
}CN;

void menu_create(HINSTANCE ,HWND ,HMENU ,HMENU );
void lectur_fichier(const char *filename);
bool Token(int aut[27][37],int etat_fin[27],int len,CN *ind_j,int nbr_char,string c);
int char_num(char c,int sze,CN *t);
void Lexer2(const char *code_source,CN *ind_j,int nbr_char,int *nbr_erreurs,string *lst_errs,string *unit_lex,string *cd_src,int *num_ligne);/**___________________________**/
int indice_j(string c);
int indice_i(string c);
int parser(string *,int *,HWND indication);
BOOL Open_Dialogue_Box(HWND ,int );
BOOL ouvrire_fichier(char *Nom_de_Fichier,HWND );
BOOL sauvegarder_fichier(char *NomFichier,HWND );


#endif // F_H_INCLUDED
