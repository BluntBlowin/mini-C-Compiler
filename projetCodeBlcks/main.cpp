#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif


#include "f.h"
HINSTANCE hinst;

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;
    hinst=hThisInstance;     /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("Code::Blocks Template Windows App"),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           1050,                 /* The programs width */
           550,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{static HWND hEdit1,hEdit2,hEdit3,button;
 static HWND label1,label2,label3,label4,label5;
 HMENU hMenu,hSousMenu;
    switch (message)                  /* handle the messages */
    {  case WM_CREATE :{
                           menu_create(hinst,hwnd,hMenu,hSousMenu);
                           hEdit1 =CreateWindowEx(WS_EX_CLIENTEDGE,
                                "edit","",WS_CHILD |WS_VISIBLE |WS_HSCROLL |WS_VSCROLL |
                                 ES_MULTILINE | ES_AUTOHSCROLL |ES_AUTOVSCROLL | ES_WANTRETURN,
                                 0,0,400,300,
                                 hwnd, (HMENU)ID_BUILD_EDIT1,NULL,NULL);
						   hEdit2 =CreateWindowEx(WS_EX_CLIENTEDGE,
                                "edit","",WS_CHILD |WS_VISIBLE |WS_HSCROLL |WS_VSCROLL |
                                 ES_MULTILINE | ES_AUTOHSCROLL |ES_AUTOVSCROLL | ES_WANTRETURN,
                                 700,0,300,500,
                                 hwnd, (HMENU)ID_BUILD_EDIT2,NULL,NULL);
						   hEdit3 =CreateWindowEx(WS_EX_CLIENTEDGE,
                                "edit","",WS_CHILD |WS_VISIBLE |WS_HSCROLL |WS_VSCROLL |
                                 ES_MULTILINE | ES_AUTOHSCROLL |ES_AUTOVSCROLL | ES_WANTRETURN,
                                 0,310,400,200,
                                 hwnd,(HMENU)ID_BUILD_EDIT3,NULL,NULL);
                                 cout<<"helloworld";
						   label1 =CreateWindowExA(NULL,"Static","Resultats d'Analyse ",WS_VISIBLE|WS_CHILD|WS_GROUP,410,10,150,15,hwnd,
                                           NULL,NULL,NULL);
						   label2 =CreateWindowExA(NULL,"Static","Lexical : ",WS_VISIBLE|WS_CHILD|WS_GROUP,410,25,150,15,hwnd,
                                           NULL,NULL,NULL);
						   label3 =CreateWindowExA(NULL,"Static","",WS_VISIBLE|WS_CHILD|WS_GROUP,420,45,250,15,hwnd,
                                           NULL,NULL,NULL);
						   label4 =CreateWindowExA(NULL,"Static","Syntaxique : ",WS_VISIBLE|WS_CHILD|WS_GROUP,410,65,150,15,hwnd,
                                           NULL,NULL,NULL);
						   label5=CreateWindowExA(NULL,"Static","",WS_VISIBLE|WS_CHILD|WS_GROUP,420,85,150,15,hwnd,
                                          NULL,NULL,NULL);
                            button=CreateWindowExA(NULL,"Button","Analyser",WS_VISIBLE|WS_CHILD|WS_GROUP|BS_PUSHBUTTON,480,200,100,50,hwnd,
                            (HMENU)ID_BUILD_ANALYSER ,NULL,NULL);
                       }
            break;
        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                case ID_BUILD_ANALYSER :
        {
            /**_____________________________________________________**/
                    ofstream fichier("code.txt",ios::out  | ios::trunc);
                    if(fichier)
                    {
                    char a[500];
                    GetWindowText(hEdit1,a,500);
                    fichier<<a;
                    fichier.close();
                    }
            /**_____________________________________________________**/
            CN conver_char_str[37];
            conver_char_str[0].str='a';conver_char_str[1].str='b';conver_char_str[2].str='c';conver_char_str[3].str='d';
            conver_char_str[4].str='e';conver_char_str[5].str='f';conver_char_str[6].str='g';conver_char_str[7].str='h';
            conver_char_str[8].str='i';conver_char_str[9].str='j';conver_char_str[10].str='k';conver_char_str[11].str='l';
            conver_char_str[12].str='m';conver_char_str[13].str='n';conver_char_str[14].str='o';conver_char_str[15].str='p';
            conver_char_str[16].str='q';conver_char_str[17].str='r';conver_char_str[18].str='s';conver_char_str[19].str='t';
            conver_char_str[20].str='u';conver_char_str[21].str='v';conver_char_str[22].str='w';conver_char_str[23].str='x';
            conver_char_str[24].str='y';conver_char_str[25].str='z';
            conver_char_str[26].str='0';conver_char_str[27].str='1';conver_char_str[28].str='2';conver_char_str[29].str='3';
            conver_char_str[30].str='4';conver_char_str[31].str='5';conver_char_str[32].str='6';conver_char_str[33].str='7';
            conver_char_str[34].str='8';conver_char_str[35].str='9';conver_char_str[36].str='_';
            for(int i=0;i<37;i++)conver_char_str[i].ent=i;
            /**_____________________________________________________**/
            int *nbr_errs; nbr_errs=new (int); *nbr_errs=0;
            string *lst_errs,*unit_lex;unit_lex=new(string);*unit_lex="";lst_errs=new(string);*lst_errs="";
            string cd_src[100];
            int num_lignes[100];
            for(int i=0;i<100;i++) cd_src[i]="#";
            for(int i=0;i<100;i++) num_lignes[i]=0;
            SetWindowText(hEdit2,"");
            SetWindowText(hEdit3,"");
            /**_____________________________________________________**/
            Lexer2("code.txt",conver_char_str,37,nbr_errs,lst_errs,unit_lex,cd_src,num_lignes);
            if(*nbr_errs==0){cout<<"le code source :"<<endl;
                             for(int i=0;i<50;i++)cout<<cd_src[i]<<" ";
                             SetWindowText(label3,"Analyse Lexical Réussi");
                             char *y=new char[(*unit_lex).length()+1];
                             strcpy(y,(*unit_lex).c_str());
                             SetWindowText(hEdit2,y);


                             char indication[30];
                             int x=parser(cd_src,num_lignes,hEdit3);
                             if(x==-1)   SetWindowText(label5,"chaine correcte");
                             else       { SetWindowText(label5,"chaine Non correcte");
                                          /*char err_syntaxique[25]="erreur syntaxique ligne ";
                                          char  buf[10];sprintf(buf,"%d",*nbr_errs);
                                          strcat(err_syntaxique,buf);
                                          strcat(err_syntaxique,"\r\n");
                                          strcat(err_syntaxique,indication);
                                          SetWindowText(hEdit3,err_syntaxique);*/
                                        }


                            }
            else{
                char  buf[10];sprintf(buf,"%d",*nbr_errs);
                char message[27]="Erreurs Lexicales trouvées";
                strcat(buf," ");
                strcat(buf,message);
                SetWindowText(label5,buf);

                char *y=new char[(*lst_errs).length()+1];
                strcpy(y,(*lst_errs).c_str());
                SetWindowText(hEdit3,y);
                cout<<"les erreurs lexicales:"<<endl;
                  cout<<*lst_errs;
                }

        }

                    break;
        case ID_FILE_SAVE :Open_Dialogue_Box(hEdit1,1);break;
        case ID_FILE_NOUV:SetWindowText(hEdit1,""); break;
        case ID_FILE_OPEN:Open_Dialogue_Box(hEdit1,0);break;
            }
            return 0;

        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
