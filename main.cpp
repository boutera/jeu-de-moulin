#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <conio.h>
#include <time.h>

typedef struct _point
{
    int casex;
    int casey;
}Case;
Case c_i,c_f,c,d,e,cm,dm,cm_i,cm_f; Case t1[36],t2[36];
int test,test1,i,j,r,r2,s2,s,rs,ss,ct,ri,rf,si,sf;
int comteur=0,comteur2=0,comteur3=0;
int u,v,u2,v2,m2,n2,k,a=0,somme=0,ligne,m,n;
int joueur1=1;
int joueur2=0;
int merelle[7][7];
int voisinnage[24][4];


SDL_Surface *ecran = NULL, *imageDeFond = NULL,*fondnoir = NULL, *menu = NULL, *perdre=0, *instructions = NULL,*vide = NULL, *pionrouge1 = NULL,*pionrouge2 = NULL,*pionrouge3 = NULL,*pionrouge4 = NULL,*pionrouge5 = NULL,*pionrouge6 = NULL,*pionrouge7 = NULL,*pionrouge8 = NULL,*pionrouge9 = NULL, *pionblanc1 = NULL, *pionblanc2 = NULL, *pionblanc3 = NULL, *pionblanc4 = NULL, *pionblanc5 = NULL, *pionblanc6 = NULL, *pionblanc7 = NULL, *pionblanc8 = NULL, *pionblanc9 = NULL;
SDL_Rect positionFond       = {0, 0, 0, 0};
SDL_Rect positionCase={0,0,0,0};
SDL_Rect positionCase1={0,0,0,0};





void affiche(int merelle[7][7],SDL_Surface* ecran,SDL_Rect positionFond);
int Test_moulin(int merelle[7][7],int j_c,Case c);
int code(int i,int j);
void initialiser(int (*merelle)[7]);
int score2(int merelle[7][7]);
int score1(int merelle[7][7]);
int move_ci_cf(int voisinnage[24][4],Case c_i,Case c_f);
void case_voisin(int (*voisin)[4]);
void move(int (*merelle)[7],Case c_i,Case c_f,int j_c );
void supprimer(int (*merelle)[7],Case c,int j_c);
void supprimerpionjaune(int s,int j_c);
void code_1(int a,Case c);
int scorepassif(int merelle[7][7],int j_c);
void supprimerespace(SDL_Surface *ecran,int comteur,int j_c);





int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) == -1) // Démarrage de la SDL. Si erreur :
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); // Écriture de l'erreur
        return EXIT_FAILURE; // On quitte le programme
    }
    SDL_Surface *ecran = NULL, *imageDeFond = NULL,*etat=NULL,*niveu=NULL,*texte = NULL ,*gagner = NULL,*fondnoir = NULL, *menu = NULL, *instructions = NULL, *pionrouge1 = NULL,*pionrouge2 = NULL,*pionrouge3 = NULL,*pionrouge4 = NULL,*pionrouge5 = NULL,*pionrouge6 = NULL,*pionrouge7 = NULL,*pionrouge8 = NULL,*pionrouge9 = NULL, *pionblanc1 = NULL, *pionblanc2 = NULL, *pionblanc3 = NULL, *pionblanc4 = NULL, *pionblanc5 = NULL, *pionblanc6 = NULL, *pionblanc7 = NULL, *pionblanc8 = NULL, *pionblanc9 = NULL;
    SDL_Surface *espacejaune1=0;
    SDL_Surface *espaceblue1=0;
    SDL_Event event; SDL_WaitEvent(&event);
    int continuer = 1;



    SDL_Rect positionFond,positioninstructions,positionfondnoir,positionniveu,positionTexte,positionetat, positionpionrouge1, positionpionblanc1, positionpionrouge2, positionpionblanc2, positionpionrouge3, positionpionblanc3, positionpionrouge4, positionpionblanc4, positionpionrouge5, positionpionblanc5, positionpionrouge6,positionpionblanc6, positionpionblanc7, positionpionrouge7, positionpionblanc8, positionpionrouge8, positionpionblanc9, positionpionrouge9, positionmenu;
    SDL_Rect pstjn1,pstjn2,pstjn3,pstjn4,pstjn5,pstjn6,pstjn7,pstjn8,pstjn9;
    SDL_Rect pstbl1,pstbl2,pstbl3,pstbl4,pstbl5,pstbl6,pstbl7,pstbl8,pstbl9;
    positionfondnoir.x=0;
    positionfondnoir.y=0;
    positioninstructions.x=0;
    positioninstructions.y=0;
    positionmenu.x = 0;
    positionmenu.y = 0;
    positionFond.x = 70;
    positionFond.y = 70;
    positionTexte.x=100;
    positionTexte.y=0;
    positionetat.x=0;
    positionetat.y=0;
    positionniveu.x=0;
    positionniveu.y=0;
    positionpionrouge1.x =0;pstjn1.x=0;
    positionpionrouge1.y =0;pstjn1.y=0;
    positionpionblanc1.x = 550;pstbl1.x=550;
    positionpionblanc1.y = 0;pstbl1.y=0;
    positionpionrouge2.x =0;pstjn2.x=0;
    positionpionrouge2.y = 50;pstjn2.y=50;
    positionpionblanc2.x = 550;pstbl2.x=550;
    positionpionblanc2.y = 50;pstbl2.y=50;
    positionpionrouge3.x = 0;pstjn3.x=0;
    positionpionrouge3.y = 100;pstjn3.y=100;
    positionpionblanc3.x = 550;pstbl3.x=550;
    positionpionblanc3.y = 100;pstbl3.y=100;
    positionpionrouge4.x = 0;pstjn4.x=0;
    positionpionrouge4.y = 150;pstjn4.y=150;
    positionpionblanc4.x = 550;pstbl4.x=550;
    positionpionblanc4.y = 150;pstbl4.y=150;
    positionpionrouge5.x = 0;pstjn5.x=0;
    positionpionrouge5.y = 200;pstjn5.y=200;
    positionpionblanc5.x = 550;pstbl5.x=550;
    positionpionblanc5.y = 200;pstbl5.y=200;
    positionpionrouge6.x = 0;pstjn6.x=0;
    positionpionrouge6.y = 250;pstjn6.y=250;
    positionpionblanc6.x = 550;pstbl6.x=550;
    positionpionblanc6.y = 250;pstbl6.y=250;
    positionpionrouge7.x = 0;pstjn7.x=0;
    positionpionrouge7.y = 300;pstjn7.y=300;
    positionpionblanc7.x = 550;pstbl7.x=550;
    positionpionblanc7.y = 300;pstbl7.y=300;
    positionpionrouge8.x = 0;pstjn8.x=0;
    positionpionrouge8.y = 350;pstjn8.y=350;
    positionpionblanc8.x = 550;pstbl8.x=550;
    positionpionblanc8.y = 350;pstbl8.y=350;
    positionpionrouge9.x = 0;pstjn9.x=0;
    positionpionrouge9.y = 398;pstjn9.y=400;
    positionpionblanc9.x = 550;pstbl9.x=550;
    positionpionblanc9.y = 391;pstbl9.y=400;
//ces positios Rect qui sont des structures Case permettent d'initialiser ou fixer les positions des pions jaunes et bleus aussi que les
//les espace espaceblues et espacejaunes lors de la pose .
    SDL_Init(SDL_INIT_VIDEO);
   // SDL_WM_SetIcon(SDL_LoadBMP("cb.bmp"), NULL);
    ecran = SDL_SetVideoMode(600, 600, 32, SDL_HWSURFACE); // Ouverture de la fenêtre
    if( ecran == NULL ){
        return EXIT_FAILURE;
    }
    SDL_WM_SetCaption("Jeu de Moulin", NULL);
        menu = SDL_LoadBMP("MENU1.bmp");
        fondnoir = SDL_LoadBMP("fondnoir.bmp");
        imageDeFond = SDL_LoadBMP("moulin.bmp");
        etat=SDL_LoadBMP("etat.bmp");
        niveu=SDL_LoadBMP("niveu.bmp");
        pionrouge1 = SDL_LoadBMP("pionrouge1.bmp");espacejaune1=SDL_LoadBMP("jn1.bmp");
        pionblanc1 = SDL_LoadBMP("pionblanc1.bmp");espaceblue1=SDL_LoadBMP("bl1.bmp");
    SDL_BlitSurface(menu, NULL, ecran, &positionmenu);
loop:
    comteur=0,comteur2=0,comteur3=0;
    while (continuer)
 {
    SDL_WaitEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_MOUSEBUTTONUP:  // Calcule la position de la souris pourafficher le cadre de selection!
                if (  (event.button.y >= 225 && event.button.y<282 && event.button.x <204))

                {  SDL_BlitSurface(etat,NULL,ecran,&positionetat);
                   SDL_Flip(ecran);
                  while (continuer)
                            {
                               SDL_WaitEvent(&event);
                                switch(event.type)
                                {
                                    case SDL_QUIT:
                                         continuer = 0;
                                         break;
                                    case SDL_MOUSEBUTTONUP:
                        if (  (event.button.y >=211  && event.button.y<269 && event.button.x < 419&& event.button.x>156))
{

                    initialiser(merelle);
                    case_voisin(voisinnage);

  //                  fondnoir = SDL_LoadBMP("fondnoir.bmp");
                    SDL_BlitSurface(fondnoir, NULL, ecran, &positionfondnoir);

   //                 imageDeFond = SDL_LoadBMP("moulin.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

     //               pionrouge1 = SDL_LoadBMP("pionrouge1.bmp");

   					 SDL_BlitSurface(pionrouge1, NULL, ecran, &positionpionrouge1);
  		//			  pionblanc1 = SDL_LoadBMP("pionblanc1.bmp");
  					  SDL_BlitSurface(pionblanc1, NULL, ecran, &positionpionblanc1);
  			//		  pionrouge1 = SDL_LoadBMP("pionrouge1.bmp");

    SDL_BlitSurface(pionrouge1, NULL, ecran, &positionpionrouge2);
 //   pionblanc1 = SDL_LoadBMP("pionblanc1.bmp");

    SDL_BlitSurface(pionblanc1, NULL, ecran, &positionpionblanc2);
 //   pionrouge1 = SDL_LoadBMP("pionrouge1.bmp");

    SDL_BlitSurface(pionrouge1, NULL, ecran, &positionpionrouge3);
 //   pionblanc1 = SDL_LoadBMP("pionblanc1.bmp");

    SDL_BlitSurface(pionblanc1, NULL, ecran, &positionpionblanc3);
   // pionrouge1 = SDL_LoadBMP("pionrouge1.bmp");

    SDL_BlitSurface(pionrouge1, NULL, ecran, &positionpionrouge4);
  //  pionblanc1 = SDL_LoadBMP("pionblanc1.bmp");
    SDL_BlitSurface(pionblanc1, NULL, ecran, &positionpionblanc4);
    //pionrouge1= SDL_LoadBMP("pionrouge1.bmp");

    SDL_BlitSurface(pionrouge1, NULL, ecran, &positionpionrouge5);
  //  pionblanc1 = SDL_LoadBMP("pionblanc1.bmp");

    SDL_BlitSurface(pionblanc1, NULL, ecran, &positionpionblanc5);
  //  pionrouge1 = SDL_LoadBMP("pionrouge1.bmp");

    SDL_BlitSurface(pionrouge1, NULL, ecran, &positionpionrouge6);
    //pionblanc1 = SDL_LoadBMP("pionblanc1.bmp");

    SDL_BlitSurface(pionblanc1, NULL, ecran, &positionpionblanc6);
   // pionrouge1 = SDL_LoadBMP("pionrouge1.bmp");

    SDL_BlitSurface(pionrouge1, NULL, ecran, &positionpionrouge7);
    //pionblan17 = SDL_LoadBMP("pionblanc1.bmp");

    SDL_BlitSurface(pionblanc1, NULL, ecran, &positionpionblanc7);
   // pionrouge1 = SDL_LoadBMP("pionrouge1.bmp");

    SDL_BlitSurface(pionrouge1, NULL, ecran, &positionpionrouge8);
    //pionblanc1 = SDL_LoadBMP("pionblanc1.bmp");

    SDL_BlitSurface(pionblanc1, NULL, ecran, &positionpionblanc8);
   // pionrouge1 = SDL_LoadBMP("pionrouge1.bmp");

    SDL_BlitSurface(pionrouge1, NULL, ecran, &positionpionrouge9);
   // pionblanc1= SDL_LoadBMP("pionblanc1.bmp");

    SDL_BlitSurface(pionblanc1, NULL, ecran, &positionpionblanc9);
    initialiser(merelle);
    affiche(merelle,ecran,positionFond);

    //affiche(merelle);  // 2- on affiche d'abord le damier et les pions

   SDL_Flip(ecran); /* Mise à jour de l'écran avec sa nouvelle couleur */
    SDL_FreeSurface(imageDeFond);

      // Libération de la surface de la mémoire

 texte = SDL_LoadBMP("deposer.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);
                    //affiche du message déposer vos pions
    srand(time(NULL));
    int premierjoueur=rand()%2+0;
    premierjoueur=1;
    joueur1=premierjoueur;
    joueur2=1-premierjoueur;

//generation d'un entier aleatoire pour savoir qui va etre le premierjoueur
  while (continuer)
 {
    SDL_WaitEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_MOUSEBUTTONUP:
        	if(comteur2!=1){ //on est encore dans la phase de la pose
             if(premierjoueur==1){
                    if(comteur3==0)// si le comteur =9 on a introduit cet algorithme pour supprimer le dernier pion si on aurait moulin
                        {
            	if(joueur1==1 && comteur!=9)

            	{

            		for(i=0;i<7;i++){

						for(j=0;j<7;j++){
                            positionCase.x=i*450/7 +70;
                            positionCase.y=j*450/7 +70;



            				if ( event.button.x >(i*(450/7))+70   && event.button.x <((i+1)*(450/7))+70
                    			 && event.button.y > (j*(450/7))+70 && event.button.y <((j+1)*(450/7))+70 ){
                    		 		test=Test_moulin(merelle,1,c);

							 		if(test==0){
							 			if(merelle[i][j]==0){

								 			c.casex=i;
								 			c.casey=j;
                    		 				merelle[i][j]=1;
                                           // pionrouge1 = SDL_LoadBMP("pionrouge1.bmp");
                                            //SDL_BlitSurface(pionrouge1, NULL, ecran, &positionCase);
                                           // SDL_Flip(ecran);
                                           affiche(merelle,ecran,positionFond);
                                           comteur++;

      supprimerespace(ecran,comteur,1);



           SDL_Flip(ecran);

                    		 				test=Test_moulin(merelle,1,c);
                    		 				if(test==0){

            									joueur1=0;
            									joueur2=1;
            									           //changement du tour du joueur
            									                    texte = SDL_LoadBMP("JOUEUR2.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);


                                                printf("joueur2, votre tour ");


           									} else{ texte = SDL_LoadBMP("SUPRIMER1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);
           									     if(comteur==9)
           									comteur3=1;

           									// aller à comteur3 pour supprimer un pion}

           								}
           							}
                    			 }
           						else{

           							if(merelle[i][j]==-1){
                                    d.casex=i;
                                    d.casey=j;
                                      test=Test_moulin(merelle,-1,d);
                                      if(test==0){
                                        printf("joueur1, vous avez droit de supprimmer un pion blanc ");

           								merelle[i][j]=0;
                                       // vide = SDL_LoadBMP("vide.bmp");
                                        //SDL_BlitSurface(vide, NULL, ecran, &positionCase);
                                        //SDL_Flip(ecran);
                                        affiche(merelle,ecran,positionFond);
       SDL_Flip(ecran);
            							joueur1=0;
            							joueur2=1;
            							                    texte = SDL_LoadBMP("JOUEUR2.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);


                                    printf("joueur2, votre tour ");


                                      }
								   }
								}

            			}
            		}





            	}
}
           	else
				{
				 	 if(joueur2==1 )
            		{

            			for(i=0;i<7;i++){

							for(j=0;j<7;j++){
                                positionCase.x=i*450/7 +70;
                                positionCase.y=j*450/7 +70;



            					if ( event.button.x >(i*(450/7))+70   && event.button.x <((i+1)*(450/7))+70
                    			 && event.button.y > (j*(450/7))+70 && event.button.y <((j+1)*(450/7))+70 ){
                    				 	test=Test_moulin(merelle,-1,c);
							 			if(test==0){
							 				if(merelle[i][j]==0){
									 			c.casex=i;
									 			c.casey=j;


                    		 					merelle[i][j]=-1;
                                             //   pionblanc1 = SDL_LoadBMP("pionblanc1.bmp");
                                               // SDL_BlitSurface(pionblanc1, NULL, ecran, &positionCase);
                                                //SDL_Flip(ecran);
                                                affiche(merelle,ecran,positionFond);
                    		 					test=Test_moulin(merelle,-1,c);
                    		 					if(test==0){

            										joueur2=0;
            										joueur1=1;
                                                texte = SDL_LoadBMP("JOUEUR1.bmp");
                                                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                                                 SDL_Flip(ecran);


            										if(comteur==9){
                                                    comteur2=1;
                                                    joueur1=1;
                                                    joueur2=0;
                                                    texte = SDL_LoadBMP("JOUEUR1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);



                                                    c_i.casex=9;
                                                    c_i.casey=9;
                                                    c_f.casex=9;
                                                    c_f.casey=9;
                                                    }
           									}else{
           									texte = SDL_LoadBMP("SUPRIMER2.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);}
           								}
           							}
           						else{

           								if(merelle[i][j]==1){
                                           d.casex=i;
                                           d.casey=j;
								 			test=Test_moulin(merelle,1,d);
								 			if (test==0){
           								    printf("joueur2, vous avez droit de supprimmer un pion blanc ");
                                          //  vide = SDL_LoadBMP("vide.bmp");
                                            //SDL_BlitSurface(vide, NULL, ecran, &positionCase);
                                            //SDL_Flip(ecran);

           									merelle[i][j]=0;
                                            affiche(merelle,ecran,positionFond);

            								joueur1=1;
            								joueur2=0;
                                            texte = SDL_LoadBMP("JOUEUR1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);}

            								if(comteur==9){
           									comteur2=1;
           									joueur1=1;
           									joueur2=0;

                                            c_i.casex=9;
                                            c_i.casey=9;
                                            c_f.casex=9;
                                            c_f.casey=9;

										   }
           								}
								   }
            					}
            				}
            			}

            	supprimerespace(ecran,comteur,-1);}


   }
                    }
                    else{ if(joueur1==1){
                    for(i=0;i<7;i++){

						for(j=0;j<7;j++){
                            positionCase.x=i*450/7 +70;
                            positionCase.y=j*450/7 +70;



            				if ( event.button.x >(i*(450/7))+70   && event.button.x <((i+1)*(450/7))+70
                    			 && event.button.y > (j*(450/7))+70 && event.button.y <((j+1)*(450/7))+70 ){
                    			      if(merelle[i][j]==-1){
                     d.casex=i;
                     d.casey=j;
                     test=Test_moulin(merelle,-1,d);
                     if (test==0){
                                        printf("joueur1, vous avez droit de supprimmer un pion blanc ");
           								merelle[i][j]=0;
           								affiche(merelle,ecran,positionFond);
                                        joueur2=1;
                                        joueur1=0;

                                        }} }}}}
                            else{   if(ct==0) { for(i=0;i<7;i++){

						for(j=0;j<7;j++){
                            positionCase.x=i*450/7 +70;
                            positionCase.y=j*450/7 +70;



            				if ( event.button.x >(i*(450/7))+70   && event.button.x <((i+1)*(450/7))+70
                    			 && event.button.y > (j*(450/7))+70 && event.button.y <((j+1)*(450/7))+70 ){
                    			      if(merelle[i][j]==0){
                                          merelle[i][j]=-1;
                                          affiche(merelle,ecran,positionFond);
                                           SDL_BlitSurface(espaceblue1, NULL, ecran, &pstbl9);
                                           SDL_Flip(ecran);
                                        c.casex=i;c.casey=j;
                                        if(Test_moulin(merelle,-1,c)==0){comteur2=1;joueur2=0;joueur1=1;}
                                        else
                                            ct=1;
                                   }}}}}
                                    else{
                                        for(i=0;i<7;i++){

						for(j=0;j<7;j++){
                            positionCase.x=i*450/7 +70;
                            positionCase.y=j*450/7 +70;



            				if ( event.button.x >(i*(450/7))+70   && event.button.x <((i+1)*(450/7))+70
                    			 && event.button.y > (j*(450/7))+70 && event.button.y <((j+1)*(450/7))+70 ){
                    			      if(merelle[i][j]==1){  d.casex=i;
                     d.casey=j;
                     test=Test_moulin(merelle,1,d);
                     if (test==0){
                                        printf("joueur1, vous avez droit de supprimmer un pion blanc ");
           								merelle[i][j]=0;
           								affiche(merelle,ecran,positionFond);
                                        joueur2=0;
                                        joueur1=1;
                                        comteur2=1; }}}}
                                    }
             }}}}
   else{ if(comteur3==0) {
    if(joueur2==1 && comteur!=9)

            	{


            		for(i=0;i<7;i++){

						for(j=0;j<7;j++){
                            positionCase.x=i*450/7 +70;
                            positionCase.y=j*450/7 +70;



            				if ( event.button.x >(i*(450/7))+70   && event.button.x <((i+1)*(450/7))+70
                    			 && event.button.y > (j*(450/7))+70 && event.button.y <((j+1)*(450/7))+70 ){
                    		 		test=Test_moulin(merelle,-1,c);
							 		if(test==0){
							 			if(merelle[i][j]==0){

								 			c.casex=i;
								 			c.casey=j;
                    		 				merelle[i][j]=-1;
                                           // pionrouge1 = SDL_LoadBMP("pionrouge1.bmp");
                                            //SDL_BlitSurface(pionrouge1, NULL, ecran, &positionCase);
                                           // SDL_Flip(ecran);
                                           affiche(merelle,ecran,positionFond);
                                           comteur++;
supprimerespace(ecran,comteur,-1);
                    		 				test=Test_moulin(merelle,-1,c);
                    		 				if(test==0){

            									joueur1=1;
            									joueur2=0;
            									                    texte = SDL_LoadBMP("JOUEUR1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);


                                                printf("joueur1, votre tour ");


           									}else{
           									     texte = SDL_LoadBMP("SUPPRIMER2.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);
           									    if(comteur==9)
           									comteur3=1;}
           								}
           							}
           						else{

                    if(merelle[i][j]==1) {
                     d.casex=i;
                     d.casey=j;
                     test=Test_moulin(merelle,1,d);
                    if (test==0){
                                        printf("joueur2, vous avez droit de supprimmer un pion blanc ");

           								merelle[i][j]=0;
                                       // vide = SDL_LoadBMP("vide.bmp");
                                        //SDL_BlitSurface(vide, NULL, ecran, &positionCase);
                                        //SDL_Flip(ecran);
                                        affiche(merelle,ecran,positionFond);

            							joueur1=1;
            							joueur2=0;
            							                    texte = SDL_LoadBMP("JOUEUR1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);


                                    printf("joueur1, votre tour ");

                    }

								   }
								}
            				}
            			}
            		}





            	}
            	else
				{
				 	 if(joueur1==1 )
            		{

            			for(i=0;i<7;i++){

							for(j=0;j<7;j++){
                                positionCase.x=i*450/7 +70;
                                positionCase.y=j*450/7 +70;



            					if ( event.button.x >(i*(450/7))+70   && event.button.x <((i+1)*(450/7))+70
                    			 && event.button.y > (j*(450/7))+70 && event.button.y <((j+1)*(450/7))+70 ){
                    				 	test=Test_moulin(merelle,1,c);
							 			if(test==0){
							 				if(merelle[i][j]==0){
									 			c.casex=i;
									 			c.casey=j;


                    		 					merelle[i][j]=1;
                                             //   pionblanc1 = SDL_LoadBMP("pionblanc1.bmp");
                                               // SDL_BlitSurface(pionblanc1, NULL, ecran, &positionCase);
                                                //SDL_Flip(ecran);
                                                affiche(merelle,ecran,positionFond);
                    		 					test=Test_moulin(merelle,1,c);
                    		 					if(test==0){

            										joueur1=0;
            										joueur2=1;
                                                texte = SDL_LoadBMP("JOUEUR2.bmp");
                                                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                                                 SDL_Flip(ecran);


            										if(comteur==9){
                                                    comteur2=1;
                                                    joueur1=0;
                                                    joueur2=1;
                                                    texte = SDL_LoadBMP("JOUEUR2.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);



                                                    c_i.casex=9;
                                                    c_i.casey=9;
                                                    c_f.casex=9;
                                                    c_f.casey=9;
                                                    }
           									}else{		     texte = SDL_LoadBMP("SUPPRIMER1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran); }
           								}
           							}
           						else{

           								if(merelle[i][j]==-1){
                                        d.casex=i;
                                        d.casey=j;
                                        test=Test_moulin(merelle,-1,d);
                                        if(test==0){

           								    printf("joueur1, vous avez droit de supprimmer un pion blanc ");
                                          //  vide = SDL_LoadBMP("vide.bmp");
                                            //SDL_BlitSurface(vide, NULL, ecran, &positionCase);
                                            //SDL_Flip(ecran);

           									merelle[i][j]=0;
                                            affiche(merelle,ecran,positionFond);

            								joueur1=0;
            								joueur2=1;
                                            texte = SDL_LoadBMP("JOUEUR2.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);
                                        }
            								if(comteur==9){
           									comteur2=1;
           									joueur1=0;
           									joueur2=1;

                                            c_i.casex=9;
                                            c_i.casey=9;
                                            c_f.casex=9;
                                            c_f.casey=9;

										   }
           								}
								   }
            					}
            				}
            			}


            	supprimerespace(ecran,comteur,1);}


   }

}     else{ if(joueur2==1){
                    for(i=0;i<7;i++){

						for(j=0;j<7;j++){
                            positionCase.x=i*450/7 +70;
                            positionCase.y=j*450/7 +70;



            				if ( event.button.x >(i*(450/7))+70   && event.button.x <((i+1)*(450/7))+70
                    			 && event.button.y > (j*(450/7))+70 && event.button.y <((j+1)*(450/7))+70 ){
                    			      if(merelle[i][j]==1){
                     d.casex=i;
                     d.casey=j;
                     test=Test_moulin(merelle,1,d);
                     if (test==0){
                                        printf("joueur1, vous avez droit de supprimmer un pion blanc ");
           								merelle[i][j]=0;
           								affiche(merelle,ecran,positionFond);
                                        joueur2=0;
                                        joueur1=1;

                                        }} }}}}
                            else{   if(ct==0) { for(i=0;i<7;i++){

						for(j=0;j<7;j++){
                            positionCase.x=i*450/7 +70;
                            positionCase.y=j*450/7 +70;



            				if ( event.button.x >(i*(450/7))+70   && event.button.x <((i+1)*(450/7))+70
                    			 && event.button.y > (j*(450/7))+70 && event.button.y <((j+1)*(450/7))+70 ){
                    			      if(merelle[i][j]==0){
                                          merelle[i][j]=1;
                                          affiche(merelle,ecran,positionFond);
                                           SDL_BlitSurface(espacejaune1, NULL, ecran, &pstjn9);
                                           SDL_Flip(ecran);
                                        c.casex=i;c.casey=j;
                                        if(Test_moulin(merelle,1,c)==0){comteur2=1;joueur2=1;joueur1=0;}
                                        else
                                            ct=1;
                                   }}}}}
                                    else{
                                        for(i=0;i<7;i++){

						for(j=0;j<7;j++){
                            positionCase.x=i*450/7 +70;
                            positionCase.y=j*450/7 +70;



            				if ( event.button.x >(i*(450/7))+70   && event.button.x <((i+1)*(450/7))+70
                    			 && event.button.y > (j*(450/7))+70 && event.button.y <((j+1)*(450/7))+70 ){
                    			      if(merelle[i][j]==-1){  d.casex=i;
                     d.casey=j;
                     test=Test_moulin(merelle,-1,d);
                     if (test==0){
                                        printf("joueur1, vous avez droit de supprimmer un pion blanc ");
           								merelle[i][j]=0;
           								affiche(merelle,ecran,positionFond);
                                        joueur2=1;
                                        joueur1=0;
                                        comteur2=1; }}}}
                                    }
             }}}
        	}    }
            else{



               // c_i.casex=9;
                //c_i.casey=9;
                //c_f.casex=9;
                //c_f.casey=9;



            	if(joueur1==1)         //ayant merelle i j = 1 pion rouge


{int u,v,k,a=0,somme=0,ligne;
Case e;
 for(u=0;u<7;u++){
         for(v=0;v<7;v++){
             if (merelle[u][v]==1){
                               ligne=code(u,v);

                               for(k=0;k<4;k++){
            int m,n;
 if(voisinnage[ligne][k]==24){e.casex=0;
          e.casey=2;}
          else {
                                for(m=0;m<7;m++){
        for(n=0;n<7;n++){
            if(code(m,n)==voisinnage[ligne][k]){
                    e.casex=m;
                    e.casey=n;

                    }}} }


                                    if(merelle[e.casex][e.casey]!=0){
                                       a++;
                            }
                            }
                            if (a==4) {
                                    somme++;
                                    a=0;

                            }
                            }

                             }

  }if(somme==score1(merelle)){   gagner = SDL_LoadBMP("gagner.bmp");

                                                            SDL_BlitSurface(gagner, NULL, ecran, &positionmenu);
                                                            texte = SDL_LoadBMP("JOUEUR2.bmp");
                                                            SDL_BlitSurface(texte, NULL, ecran, &positionFond);
                                                            SDL_Flip(ecran);break;

                                                        } else {somme=0;

                                                        }


            		for(i=0;i<7;i++){

						for(j=0;j<7;j++){

                               // positionCase.x=i*450/7 +70;
                                //positionCase.y=j*450/7 +70;



            				if ( event.button.x >(i*(450/7))+70   && event.button.x <((i+1)*(450/7))+70
                    			 && event.button.y > (j*(450/7))+70 && event.button.y <((j+1)*(450/7))+70 ){


                                    if(joueur1==1){
                                        if(merelle[i][j]==1){
                                            c_i.casex=i;
                                            c_i.casey=j;
                                                               texte = SDL_LoadBMP("DESTINER.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);

                                            printf("joueur1, choisissez mtn une case destiné");
                                            break;

                                           // vide = SDL_LoadBMP("vide.bmp");
                                           // SDL_BlitSurface(vide, NULL, ecran, &positionCase);
                                           // SDL_Flip(ecran);

 //                                       merelle[i][j]=0;
	//							 			affiche(merelle,ecran,positionFond);
//								 			joueur1=1;
	//							 			joueur2=0.5;


                                            }
                                            else{


                                                if(merelle[i][j]==-1 && Test_moulin(merelle,1,c_f)==1  && c_f.casex!=9 && c_f.casey!=9){
                                                    d.casex=i;
                                                    d.casey=j;
                                                      if (Test_moulin(merelle,-1,d)==0){
                                                    c_i.casex=i;
                                                    c_i.casey=j;
                                                    supprimer(merelle,c_i,1);
                                                    affiche(merelle,ecran,positionFond);
                                                    c_i.casex=9;
                                                    c_i.casey=9;
                                                    c_f.casex=9;
                                                    c_f.casey=9;
                                                    if(score1(merelle)>2 && score2(merelle)>2){

                                                    joueur1=0;
                                                    joueur2=1;
                                                                      texte = SDL_LoadBMP("JOUEUR2.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);

                                                    }
                                                    else{
                                                        if(score1(merelle)<2){
                                                            gagner = SDL_LoadBMP("gagner.bmp");

                                                            SDL_BlitSurface(gagner, NULL, ecran, &positionmenu);
                                                            texte = SDL_LoadBMP("JOUEUR2.bmp");
                                                            SDL_BlitSurface(texte, NULL, ecran, &positionFond);
                                                            SDL_Flip(ecran);

                                                        }
                                                        else{
                                                            gagner = SDL_LoadBMP("gagner.bmp");

                                                            SDL_BlitSurface(gagner, NULL, ecran, &positionmenu);
                                                            texte = SDL_LoadBMP("JOUEUR1.bmp");
                                                            SDL_BlitSurface(texte, NULL, ecran, &positionFond);
                                                            SDL_Flip(ecran);

                                                        }
                                             }



                                                }
                                            }
                                            else{
                                        if(merelle[i][j]==0){
                                            c_f.casex=i;
                                            c_f.casey=j;
                                            if(move_ci_cf(voisinnage,c_i,c_f)==1){
                                                move(merelle,c_i,c_f,1);
                                                affiche(merelle,ecran,positionFond);
                                                if(Test_moulin(merelle,1,c_f)!=0){
                                                    c_i.casex=9;
                                                    c_i.casey=9;
                                                                             texte = SDL_LoadBMP("SUPRIMER1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);


                                                }
                                                else{


                                                    c_i.casex=9;
                                                    c_i.casey=9;
                                                    c_f.casex=9;
                                                    c_f.casey=9;
                                                    if(score1(merelle)>2 && score2(merelle)>2){

                                                        joueur2=1;
                                                        joueur1=0;
                                                                          texte = SDL_LoadBMP("JOUEUR2.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);


                                                    }
                                                    else{
                                                        if(score1(merelle)<2){
                                                            gagner = SDL_LoadBMP("gagner.bmp");

                                                            SDL_BlitSurface(gagner, NULL, ecran, &positionmenu);
                                                            texte = SDL_LoadBMP("JOUEUR2.bmp");
                                                            SDL_BlitSurface(texte, NULL, ecran, &positionFond);
                                                            SDL_Flip(ecran);

                                                        }
                                                        else{
                                                            gagner = SDL_LoadBMP("gagner.bmp");

                                                            SDL_BlitSurface(gagner, NULL, ecran, &positionmenu);
                                                            texte = SDL_LoadBMP("JOUEUR1.bmp");
                                                            SDL_BlitSurface(texte, NULL, ecran, &positionFond);
                                                            SDL_Flip(ecran);

                                                        }
                                                    }

                                                }
                                            }
                                        }
                                    }
                                            }
                                    }

                    		 	}

                           }

					}







            	}
            	else {
            	    if(joueur2==1)


     {       int u,v,k,a=0,somme=0,ligne;
Case e;
 for(u=0;u<7;u++){
         for(v=0;v<7;v++){
             if (merelle[u][v]==-1){
                               ligne=code(u,v);

                               for(k=0;k<4;k++){
            int m,n;
 if(voisinnage[ligne][k]==24){e.casex=0;
          e.casey=2;}
          else {
                                for(m=0;m<7;m++){
        for(n=0;n<7;n++){
            if(code(m,n)==voisinnage[ligne][k]){
                    e.casex=m;
                    e.casey=n;

                    }}} }


                                    if(merelle[e.casex][e.casey]!=0){
                                       a++;
                            }
                            }
                            if (a==4) {
                                    somme++;
                                    a=0;

                            }
                            }}

  }if(somme==score2(merelle)){   gagner = SDL_LoadBMP("gagner.bmp");

                                                            SDL_BlitSurface(gagner, NULL, ecran, &positionmenu);
                                                            texte = SDL_LoadBMP("JOUEUR1.bmp");
                                                            SDL_BlitSurface(texte, NULL, ecran, &positionFond);
                                                            SDL_Flip(ecran);break;

                                                        } else {somme=0;}	        //ayant merelle i j = -1 pion blanc


            		for(i=0;i<7;i++){

						for(j=0;j<7;j++){

                               // positionCase.x=i*450/7 +70;
                                //positionCase.y=j*450/7 +70;



            				if ( event.button.x >(i*(450/7))+70   && event.button.x <((i+1)*(450/7))+70
                    			 && event.button.y > (j*(450/7))+70 && event.button.y <((j+1)*(450/7))+70 ){
                                    if(joueur2==1){

                                        if(merelle[i][j]==-1){
                                            c_i.casex=i;
                                            c_i.casey=j;
                                                                texte = SDL_LoadBMP("DESTINER.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);

                                            printf("joueur2, choisissez mtn une case destiné");
                                           // vide = SDL_LoadBMP("vide.bmp");
                                           // SDL_BlitSurface(vide, NULL, ecran, &positionCase);
                                           // SDL_Flip(ecran);

 //                                       merelle[i][j]=0;
	//							 			affiche(merelle,ecran,positionFond);
//								 			joueur1=1;
	//							 			joueur2=0;

                                            }
                                            else{


                                                if(merelle[i][j]==1 && Test_moulin(merelle,-1,c_f)!=0 && c_f.casex!=9 && c_f.casey!=9){
                                                        d.casex=i;
                                                d.casey=j;
                                                if (Test_moulin(merelle,1,d)==0){
                                                    c_i.casex=i;
                                                    c_i.casey=j;
                                                    supprimer(merelle,c_i,-1);
                                                    affiche(merelle,ecran,positionFond);
                                                    c_i.casex=9;
                                                    c_i.casey=9;
                                                    c_f.casex=9;
                                                    c_f.casey=9;
                                                    if(score2(merelle)>2 && score1(merelle)>2){



                                                    joueur2=0;
                                                    joueur1=1;
                                                                         texte = SDL_LoadBMP("JOUEUR1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);}


                                                    else{
                                                        if(score1(merelle)<2){
                                                            gagner = SDL_LoadBMP("gagner.bmp");

                                                            SDL_BlitSurface(gagner, NULL, ecran, &positionmenu);
                                                            texte = SDL_LoadBMP("JOUEUR2.bmp");
                                                            SDL_BlitSurface(texte, NULL, ecran, &positionFond);
                                                            SDL_Flip(ecran);

                                                        }
                                                        else{
                                                            gagner = SDL_LoadBMP("gagner.bmp");

                                                            SDL_BlitSurface(gagner, NULL, ecran, &positionmenu);
                                                            texte = SDL_LoadBMP("JOUEUR1.bmp");
                                                            SDL_BlitSurface(texte, NULL, ecran, &positionFond);
                                                            SDL_Flip(ecran);

                                                        }

                                                    }

                                                }
                                            }   else{
                                        if(merelle[i][j]==0){
                                            c_f.casex=i;
                                            c_f.casey=j;
                                            if(move_ci_cf(voisinnage,c_i,c_f)==1){
                                                move(merelle,c_i,c_f,-1);
                                                affiche(merelle,ecran,positionFond);
                                                if(Test_moulin(merelle,-1,c_f)!=0){
                                                    c_i.casex=9;
                                                    c_i.casey=9;
                                                                             texte = SDL_LoadBMP("SUPRIMER2.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);


                                                }
                                                else{

                                                    c_i.casex=9;
                                                    c_i.casey=9;
                                                    c_f.casex=9;
                                                    c_f.casey=9;
                                                    if(score2(merelle)>2 && score1(merelle)>2){


                                                        joueur1=1;
                                                        joueur2=0;

                     texte = SDL_LoadBMP("JOUEUR1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);

                                                    }

                                                   else{
                                                    if(score1(merelle)<2){
                                                            gagner = SDL_LoadBMP("gagner.bmp");

                                                            SDL_BlitSurface(gagner, NULL, ecran, &positionmenu);
                                                            texte = SDL_LoadBMP("JOUEUR2.bmp");
                                                            SDL_BlitSurface(texte, NULL, ecran, &positionFond);
                                                            SDL_Flip(ecran);

                                                    }
                                                    else{
                                                            gagner = SDL_LoadBMP("gagner.bmp");

                                                            SDL_BlitSurface(gagner, NULL, ecran, &positionmenu);
                                                            texte = SDL_LoadBMP("JOUEUR1.bmp");
                                                            SDL_BlitSurface(texte, NULL, ecran, &positionFond);
                                                            SDL_Flip(ecran);

                                                    }
                                                   }
                                                }
                                            }
                                        }
                                    }}
                                    }

                    		 	}
                            }
                            }
						}



                    }
            	}

  if (  (event.button.y >=550 &&  event.button.x>385)){

    goto loop;break;
  }


            break;


    }
    //Affichage:


 }
 break;
   }

 else{ if (event.button.y >=328  && event.button.y<385 && event.button.x < 419&& event.button.x>156)

    {
      SDL_BlitSurface(niveu,NULL,ecran,&positionetat);
                   SDL_Flip(ecran);
                  while (continuer)
                            {
                               SDL_WaitEvent(&event);
                                switch(event.type)
                                {
                                    case SDL_QUIT:
                                         continuer = 0;
                                         break;
                                    case SDL_MOUSEBUTTONUP:
                        if (  (event.button.y >=200 && event.button.y<256 && event.button.x < 398&& event.button.x>214))



                {
                    initialiser(merelle);
                    case_voisin(voisinnage);



  //                  fondnoir = SDL_LoadBMP("fondnoir.bmp");
                    SDL_BlitSurface(fondnoir, NULL, ecran, &positionfondnoir);

   //                 imageDeFond = SDL_LoadBMP("moulin.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

     //               pionrouge1 = SDL_LoadBMP("pionrouge1.bmp");

   					 SDL_BlitSurface(pionrouge1, NULL, ecran, &positionpionrouge1);
  		//			  pionblanc1 = SDL_LoadBMP("pionblanc1.bmp");
  					  SDL_BlitSurface(pionblanc1, NULL, ecran, &positionpionblanc1);
  			//		  pionrouge2 = SDL_LoadBMP("pionrouge1.bmp");

    SDL_BlitSurface(pionrouge1, NULL, ecran, &positionpionrouge2);
 //   pionblanc2 = SDL_LoadBMP("pionblanc1.bmp");

    SDL_BlitSurface(pionblanc1, NULL, ecran, &positionpionblanc2);
 //   pionrouge3 = SDL_LoadBMP("pionrouge1.bmp");

    SDL_BlitSurface(pionrouge1, NULL, ecran, &positionpionrouge3);
 //   pionblanc3 = SDL_LoadBMP("pionblanc1.bmp");

    SDL_BlitSurface(pionblanc1, NULL, ecran, &positionpionblanc3);
   // pionrouge4 = SDL_LoadBMP("pionrouge1.bmp");

    SDL_BlitSurface(pionrouge1, NULL, ecran, &positionpionrouge4);
  //  pionblanc4 = SDL_LoadBMP("pionblanc1.bmp");
    SDL_BlitSurface(pionblanc1, NULL, ecran, &positionpionblanc4);
    //pionrouge5 = SDL_LoadBMP("pionrouge1.bmp");

    SDL_BlitSurface(pionrouge1, NULL, ecran, &positionpionrouge5);
  //  pionblanc5 = SDL_LoadBMP("pionblanc1.bmp");

    SDL_BlitSurface(pionblanc1, NULL, ecran, &positionpionblanc5);
  //  pionrouge6 = SDL_LoadBMP("pionrouge1.bmp");

    SDL_BlitSurface(pionrouge1, NULL, ecran, &positionpionrouge6);
    //pionblanc6 = SDL_LoadBMP("pionblanc1.bmp");

    SDL_BlitSurface(pionblanc1, NULL, ecran, &positionpionblanc6);
   // pionrouge7 = SDL_LoadBMP("pionrouge1.bmp");

    SDL_BlitSurface(pionrouge1, NULL, ecran, &positionpionrouge7);
    //pionblanc7 = SDL_LoadBMP("pionblanc1.bmp");

    SDL_BlitSurface(pionblanc1, NULL, ecran, &positionpionblanc7);
   // pionrouge8 = SDL_LoadBMP("pionrouge1.bmp");

    SDL_BlitSurface(pionrouge1, NULL, ecran, &positionpionrouge8);
    //pionblanc8 = SDL_LoadBMP("pionblanc1.bmp");

    SDL_BlitSurface(pionblanc1, NULL, ecran, &positionpionblanc8);
   // pionrouge9 = SDL_LoadBMP("pionrouge1.bmp");

    SDL_BlitSurface(pionrouge1, NULL, ecran, &positionpionrouge9);
   // pionblanc9 = SDL_LoadBMP("pionblanc1.bmp");

    SDL_BlitSurface(pionblanc1, NULL, ecran, &positionpionblanc9);
    initialiser(merelle);
    affiche(merelle,ecran,positionFond);

    //affiche(merelle);  // 2- on affiche d'abord le damier et les pions

   //SDL_Flip(ecran); /* Mise à jour de l'écran avec sa nouvelle couleur */
    SDL_FreeSurface(imageDeFond); // Libération de la surface

 texte = SDL_LoadBMP("deposer.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);
    srand(time(NULL));
    int premierjoueur=rand()%2+0;
    joueur1=premierjoueur;
    joueur2=1-premierjoueur;
    premierjoueur=1;

   if( premierjoueur==0){
                      do             		{

                      r=rand()%7+0;
                      s=rand()%7+0;            	}
                       while(merelle[r][s]!=0) ;
                      	merelle[r][s]=-1;
                      	      affiche(merelle,ecran,positionFond);
     texte = SDL_LoadBMP("JOUEUR1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    supprimerespace(ecran,1,-1);
                    SDL_Flip(ecran);
   }

  while (continuer)
 {
    SDL_WaitEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_MOUSEBUTTONUP:
        	if(comteur2!=1){

             if(premierjoueur==1){
                    if (comteur3==0){
            	if( comteur!=9 )
            	{

            		for(i=0;i<7;i++){

						for(j=0;j<7;j++){
                            positionCase.x=i*450/7 +70;
                            positionCase.y=j*450/7 +70;



            				if ( event.button.x >(i*(450/7))+70   && event.button.x <((i+1)*(450/7))+70
                    			 && event.button.y > (j*(450/7))+70 && event.button.y <((j+1)*(450/7))+70 ){





                    		 		test=Test_moulin(merelle,1,c);
							 		if(test==0){
							 			if(merelle[i][j]==0){

								 			c.casex=i;
								 			c.casey=j;
                    		 				merelle[i][j]=1;
                                           // pionrouge1 = SDL_LoadBMP("pionrouge1.bmp");
                                            //SDL_BlitSurface(pionrouge1, NULL, ecran, &positionCase);
                                           // SDL_Flip(ecran);
                                           affiche(merelle,ecran,positionFond);
                                           comteur++;



                                      supprimerespace(ecran,comteur,1);


                   		 				test=Test_moulin(merelle,1,c);
                    		 				if(test==0){

            									                    texte = SDL_LoadBMP("JOUEUR2.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);


                                                printf("joueur2, votre tour ");
                                                  srand(time(NULL));

            		    do             		{

                      r=rand()%7+0;
                      s=rand()%7+0;            	}
                       while(merelle[r][s]!=0) ;
cm.casex=r;
									 			cm.casey=s;




                    		 					merelle[r][s]=-1;
                                             //   pionblanc1 = SDL_LoadBMP("pionblanc1.bmp");
                                               // SDL_BlitSurface(pionblanc1, NULL, ecran, &positionCase);
                                                //SDL_Flip(ecran);
                                                affiche(merelle,ecran,positionFond);
                    		 					test=Test_moulin(merelle,-1,cm);
                    		 					if(test==0){


                                                texte = SDL_LoadBMP("JOUEUR1.bmp");
                                                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                                                 SDL_Flip(ecran);


            										if(comteur==9){
                                                    comteur2=1;
                                                    joueur1=1;
                                                    joueur2=0;
                                                    texte = SDL_LoadBMP("JOUEUR1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);



                                                    c_i.casex=9;
                                                    c_i.casey=9;
                                                    c_f.casex=9;
                                                    c_f.casey=9;
                                                    }
           							}
           						else{
            		    do             		{

                      rs=rand()%7+0;
                      ss=rand()%7+0;
                         dm.casex=rs;
                                           dm.casey=ss;         	}
                       while(merelle[rs][ss]!=1  || Test_moulin(merelle,1,dm)==1) ;



           								    printf("joueur2, vous avez droit de supprimmer un pion blanc ");
                                          //  vide = SDL_LoadBMP("vide.bmp");
                                            //SDL_BlitSurface(vide, NULL, ecran, &positionCase);
                                            //SDL_Flip(ecran);

           									merelle[rs][ss]=0;
                                            affiche(merelle,ecran,positionFond);


                                            texte = SDL_LoadBMP("JOUEUR1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);

            								if(comteur==9){
           									comteur2=1;
                                                     joueur1=1;
                                                    joueur2=0;

                                            c_i.casex=9;
                                            c_i.casey=9;
                                            c_f.casex=9;
                                            c_f.casey=9;

										   }

								   }




            	supprimerespace(ecran,comteur,-1);


           									}
                                  else {
                                        texte = SDL_LoadBMP("SUPRIMER1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);
                                            if (comteur==9){
                                                comteur3=1;

                                            }
                                  }
           								}
           							}
           						else{

           							if(merelle[i][j]==-1){
                                    d.casex=i;
                                    d.casey=j;
                                      test=Test_moulin(merelle,-1,d);
                                      if(test==0){
                                        printf("joueur1, vous avez droit de supprimmer un pion blanc ");

           								merelle[i][j]=0;
                                       // vide = SDL_LoadBMP("vide.bmp");
                                        //SDL_BlitSurface(vide, NULL, ecran, &positionCase);
                                        //SDL_Flip(ecran);
                                        affiche(merelle,ecran,positionFond);


c.casex=9;
c.casey=9;

            		     srand(time(NULL));

            		    do             		{

                      rs=rand()%7+0;
                      ss=rand()%7+0;            	}
                       while(merelle[rs][ss]!=0) ;
cm.casex=rs;
									 			cm.casey=ss;


                    		 					merelle[rs][ss]=-1;
                                             //   pionblanc1 = SDL_LoadBMP("pionblanc1.bmp");
                                               // SDL_BlitSurface(pionblanc1, NULL, ecran, &positionCase);
                                                //SDL_Flip(ecran);
                                                affiche(merelle,ecran,positionFond);

                    		 					test=Test_moulin(merelle,-1,cm);
                    		 					if(test==0){


                                                texte = SDL_LoadBMP("JOUEUR1.bmp");
                                                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                                                 SDL_Flip(ecran);

            										if(comteur==9){
                                                    comteur2=1;
                                                    joueur1=1;
                                                    joueur2=0;
                                                    texte = SDL_LoadBMP("JOUEUR1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);



                                                    c_i.casex=9;
                                                    c_i.casey=9;
                                                    c_f.casex=9;
                                                    c_f.casey=9;
                                                    }
           									}


           						else{  do             		{

                      rs=rand()%7+0;
                      ss=rand()%7+0;
                         dm.casex=rs;
                                           dm.casey=ss;         	}
                       while(merelle[rs][ss]!=1  || Test_moulin(merelle,1,dm)==1) ;


                                           dm.casex=rs;
                                           dm.casey=ss;

           								    printf("joueur2, vous avez droit de supprimmer un pion blanc ");
                                          //  vide = SDL_LoadBMP("vide.bmp");
                                            //SDL_BlitSurface(vide, NULL, ecran, &positionCase);
                                            //SDL_Flip(ecran);

           									merelle[rs][ss]=0;
                                            affiche(merelle,ecran,positionFond);


                                            texte = SDL_LoadBMP("JOUEUR1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);

            								if(comteur==9){
           									comteur2=1;


                                            c_i.casex=9;
                                            c_i.casey=9;
                                            c_f.casex=9;
                                            c_f.casey=9;

										   }

								   }




            	 supprimerespace(ecran,comteur,-1);




            							                    texte = SDL_LoadBMP("JOUEUR2.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);


                                    printf("joueur2, votre tour ");


                                      }
								   }
								}
            				}
            			}
            		}





            	}

 }
            else{for(i=0;i<7;i++){

						for(j=0;j<7;j++){
                            positionCase.x=i*450/7 +70;
                            positionCase.y=j*450/7 +70;



            				if ( event.button.x >(i*(450/7))+70   && event.button.x <((i+1)*(450/7))+70
                    			 && event.button.y > (j*(450/7))+70 && event.button.y <((j+1)*(450/7))+70 ){

                    if(merelle[i][j]==-1){
                                    d.casex=i;
                                    d.casey=j;
                                      test=Test_moulin(merelle,-1,d);
                                      if(test==0){
                                        printf("joueur1, vous avez droit de supprimmer un pion blanc ");

           								merelle[i][j]=0;
                                       // vide = SDL_LoadBMP("vide.bmp");
                                        //SDL_BlitSurface(vide, NULL, ecran, &positionCase);
                                        //SDL_Flip(ecran);
                                        affiche(merelle,ecran,positionFond);


c.casex=9;
c.casey=9;

            		     srand(time(NULL));

            		    do             		{

                      r=rand()%7+0;
                      s=rand()%7+0;            	}
                       while(merelle[r][s]!=0) ;
cm.casex=r;
									 			cm.casey=s;


                    		 					merelle[r][s]=-1;
                                             //   pionblanc1 = SDL_LoadBMP("pionblanc1.bmp");
                                               // SDL_BlitSurface(pionblanc1, NULL, ecran, &positionCase);
                                                //SDL_Flip(ecran);
                                                affiche(merelle,ecran,positionFond);

                    		 					test=Test_moulin(merelle,-1,cm);
                    		 					if(test==0){


                                                texte = SDL_LoadBMP("JOUEUR1.bmp");
                                                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                                                 SDL_Flip(ecran);

           									}


           						else{  do             		{

                      rs=rand()%7+0;
                      ss=rand()%7+0;
                         dm.casex=rs;
                                           dm.casey=ss;         	}
                       while(merelle[rs][ss]!=1  || Test_moulin(merelle,1,dm)==1) ;


                                           dm.casex=rs;
                                           dm.casey=ss;

           								    printf("joueur2, vous avez droit de supprimmer un pion blanc ");
                                          //  vide = SDL_LoadBMP("vide.bmp");
                                            //SDL_BlitSurface(vide, NULL, ecran, &positionCase);
                                            //SDL_Flip(ecran);

           									merelle[rs][ss]=0;
                                            affiche(merelle,ecran,positionFond);


                                            texte = SDL_LoadBMP("JOUEUR1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);


								   }
                            supprimerespace(ecran,comteur,-1);
 		comteur2=1;
								               joueur1=1;
                                                    joueur2=0;
                                                    texte = SDL_LoadBMP("JOUEUR1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);






                                      }
						  }





              } }}}}
              else {    if(premierjoueur==0){
                    if (comteur3==0){
            	if( comteur!=9 )
            	{

            		for(i=0;i<7;i++){

						for(j=0;j<7;j++){
                            positionCase.x=i*450/7 +70;
                            positionCase.y=j*450/7 +70;



            				if ( event.button.x >(i*(450/7))+70   && event.button.x <((i+1)*(450/7))+70
                    			 && event.button.y > (j*(450/7))+70 && event.button.y <((j+1)*(450/7))+70 ){





                    		 		test=Test_moulin(merelle,1,c);
							 		if(test==0){
							 			if(merelle[i][j]==0){

								 			c.casex=i;
								 			c.casey=j;
                    		 				merelle[i][j]=1;
                                           // pionrouge1 = SDL_LoadBMP("pionrouge1.bmp");
                                            //SDL_BlitSurface(pionrouge1, NULL, ecran, &positionCase);
                                           // SDL_Flip(ecran);
                                           affiche(merelle,ecran,positionFond);
                                           comteur++;



                                      supprimerespace(ecran,comteur,1);


                   		 				test=Test_moulin(merelle,1,c);
                    		 				if(test==0){

            									                    texte = SDL_LoadBMP("JOUEUR2.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);


                                                printf("joueur2, votre tour ");
                                                  srand(time(NULL));

            		    do             		{

                      r=rand()%7+0;
                      s=rand()%7+0;            	}
                       while(merelle[r][s]!=0) ;
cm.casex=r;
									 			cm.casey=s;




                    		 					merelle[r][s]=-1;
                                             //   pionblanc1 = SDL_LoadBMP("pionblanc1.bmp");
                                               // SDL_BlitSurface(pionblanc1, NULL, ecran, &positionCase);
                                                //SDL_Flip(ecran);
                                                affiche(merelle,ecran,positionFond);
                    		 					test=Test_moulin(merelle,-1,cm);
                    		 					if(test==0){


                                                texte = SDL_LoadBMP("JOUEUR1.bmp");
                                                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                                                 SDL_Flip(ecran);


            										if(comteur==9){
                                                      	merelle[r][s]=0;
                                                     affiche(merelle,ecran,positionFond);
                                                    comteur2=1;

                                                    texte = SDL_LoadBMP("JOUEUR1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);

 texte = SDL_LoadBMP("DEPLACER.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);



                                                    c_i.casex=9;
                                                    c_i.casey=9;
                                                    c_f.casex=9;
                                                    c_f.casey=9;
                                                    }


           							}
           						else{
            		    do             		{

                      rs=rand()%7+0;
                      ss=rand()%7+0;
                         dm.casex=rs;
                                           dm.casey=ss;         	}
                       while(merelle[rs][ss]!=1  || Test_moulin(merelle,1,dm)==1) ;



           								    printf("joueur2, vous avez droit de supprimmer un pion blanc ");
                                          //  vide = SDL_LoadBMP("vide.bmp");
                                            //SDL_BlitSurface(vide, NULL, ecran, &positionCase);
                                            //SDL_Flip(ecran);

           									merelle[rs][ss]=0;
                                            affiche(merelle,ecran,positionFond);


                                            texte = SDL_LoadBMP("JOUEUR1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);

            								if(comteur==9){
           									comteur2=1;


                                            c_i.casex=9;
                                            c_i.casey=9;
                                            c_f.casex=9;
                                            c_f.casey=9;

										   }

								   }




            	supprimerespace(ecran,comteur+1,-1);


           									}
                                  else {texte = SDL_LoadBMP("SUPIMER1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);
                                            if (comteur==9){
                                                comteur3=1;

                                            }
                                  }
           								}
           							}
           						else{

           							if(merelle[i][j]==-1){
                                    d.casex=i;
                                    d.casey=j;
                                      test=Test_moulin(merelle,-1,d);
                                      if(test==0){
                                        printf("joueur1, vous avez droit de supprimmer un pion blanc ");

           								merelle[i][j]=0;
                                       // vide = SDL_LoadBMP("vide.bmp");
                                        //SDL_BlitSurface(vide, NULL, ecran, &positionCase);
                                        //SDL_Flip(ecran);
                                        affiche(merelle,ecran,positionFond);


c.casex=9;
c.casey=9;

            		     srand(time(NULL));

            		    do             		{

                      r=rand()%7+0;
                      s=rand()%7+0;            	}
                       while(merelle[r][s]!=0) ;
cm.casex=r;
									 			cm.casey=s;


                    		 					merelle[r][s]=-1;
                                             //   pionblanc1 = SDL_LoadBMP("pionblanc1.bmp");
                                               // SDL_BlitSurface(pionblanc1, NULL, ecran, &positionCase);
                                                //SDL_Flip(ecran);
                                                affiche(merelle,ecran,positionFond);

                    		 					test=Test_moulin(merelle,-1,cm);
                    		 					if(test==0){


                                                texte = SDL_LoadBMP("JOUEUR1.bmp");
                                                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                                                 SDL_Flip(ecran);

            										if(comteur==9){
                                                    comteur2=1;
                                                    joueur1=0;
                                                    joueur2=1;
                                                    texte = SDL_LoadBMP("JOUEUR1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);



                                                    c_i.casex=9;
                                                    c_i.casey=9;
                                                    c_f.casex=9;
                                                    c_f.casey=9;
                                                    }
           									}


           						else{  do             		{
                                  		     srand(time(NULL));
                      rs=rand()%7+0;
                      ss=rand()%7+0;
                         dm.casex=rs;
                                           dm.casey=ss;         	}
                       while(merelle[rs][ss]!=1  || Test_moulin(merelle,1,dm)==1) ;


                                           dm.casex=rs;
                                           dm.casey=ss;

           								    printf("joueur2, vous avez droit de supprimmer un pion blanc ");
                                          //  vide = SDL_LoadBMP("vide.bmp");
                                            //SDL_BlitSurface(vide, NULL, ecran, &positionCase);
                                            //SDL_Flip(ecran);

           									merelle[rs][ss]=0;
                                            affiche(merelle,ecran,positionFond);


                                            texte = SDL_LoadBMP("JOUEUR1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);

            								if(comteur==9){
           									comteur2=1;


                                            c_i.casex=9;
                                            c_i.casey=9;
                                            c_f.casex=9;
                                            c_f.casey=9;

										   }

								   }




            	 supprimerespace(ecran,comteur+1,-1);




            							                    texte = SDL_LoadBMP("JOUEUR2.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);


                                    printf("joueur2, votre tour ");


                                      }
								   }
								}
            				}
            			}
            		}





            	}

 }
            else{for(i=0;i<7;i++){

						for(j=0;j<7;j++){
                            positionCase.x=i*450/7 +70;
                            positionCase.y=j*450/7 +70;



            				if ( event.button.x >(i*(450/7))+70   && event.button.x <((i+1)*(450/7))+70
                    			 && event.button.y > (j*(450/7))+70 && event.button.y <((j+1)*(450/7))+70 ){

                    if(merelle[i][j]==-1){
                                    d.casex=i;
                                    d.casey=j;
                                      test=Test_moulin(merelle,-1,d);
                                      if(test==0){
                                        printf("joueur1, vous avez droit de supprimmer un pion blanc ");

           								merelle[i][j]=0;
                                       // vide = SDL_LoadBMP("vide.bmp");
                                        //SDL_BlitSurface(vide, NULL, ecran, &positionCase);
                                        //SDL_Flip(ecran);
                                        affiche(merelle,ecran,positionFond);


c.casex=9;
c.casey=9;




 		comteur2=1;

                                                  texte = SDL_LoadBMP("DEPLACER.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);







                                      }
						  }





              } }}}
              if(comteur2==1){
                r=0;s=0;
         for(u=0;u<7;u++){
         for(v=0;v<7;v++){
             if (merelle[u][v]==-1){
                               ligne=code(u,v);

                               for(k=0;k<4;k++){



                                for(m=0;m<7;m++){
        for(n=0;n<7;n++){
            if(code(m,n)==voisinnage[ligne][k]){
                    if(merelle[m][n]==0){
                            t2[s].casex=m;
                            t2[s].casey=n;
                             t1[r].casex=u;
                               t1[r].casey=v;
                               r++;s++;

                            }



                    }}}




                            }


                            }

                             }


  }
                                    srand(time(NULL));
                                                   rs=rand()%r+0;
                                                cm_i.casex=t1[rs].casex;
                                                 cm_i.casey=t1[rs].casey;
                                                 cm_f.casex=t2[rs].casex;
                                                 cm_f.casey=t2[rs].casey;






                                                move(merelle,cm_i,cm_f,-1);
                                                affiche(merelle,ecran,positionFond);
                                                if(Test_moulin(merelle,-1,cm_f)==0){
                                                    cm_i.casex=9;
                                                    cm_i.casey=9;
                                                  }
                                                else{

                                                    int f=0;Case t3[9];
   for(u=0;u<7;u++){
         for(v=0;v<7;v++){
             if (merelle[u][v]==1){
                 t3[f].casex=u;
                 t3[f].casey=v;
                f++;
             }}}
             srand(time(NULL));
              r=rand()%(f+1)+0;
              while(Test_moulin(merelle,1,t3[r])!=0);
              r=rand()%(f+1)+0;
                                                    cm_i.casex= t3[r].casex;
                                                    cm_i.casey=t3[r].casey;
                                                    supprimer(merelle,cm_i,-1);
                                                    affiche(merelle,ecran,positionFond);
                                                    cm_i.casex=9;
                                                    cm_i.casey=9;
                                                    cm_f.casex=9;
                                                    cm_f.casey=9;

                                                    }
              }
              }
              }
               }
          else{
                    texte = SDL_LoadBMP("DEPLACER.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);
      Case e;
         for(u=0;u<7;u++){
         for(v=0;v<7;v++){
             if (merelle[u][v]==1){
                               ligne=code(u,v);
                               for(k=0;k<4;k++){

 if(voisinnage[ligne][k]==24)
         {e.casex=0;
          e.casey=2;}
          else {
                                for(m=0;m<7;m++){
        for(n=0;n<7;n++){
            if(code(m,n)==voisinnage[ligne][k]){
                    e.casex=m;
                    e.casey=n;

                    }}} }


                                    if(merelle[e.casex][e.casey]!=0){
                                       a++;
                            }
                            }
                            if (a==4) {
                                    somme++;
                                    a=0;

                            }
                            }

                             }

  }if(somme==score1(merelle)){   gagner = SDL_LoadBMP("perdre.bmp");

                                                            SDL_BlitSurface(gagner, NULL, ecran, &positionmenu);
                                                            texte = SDL_LoadBMP("JOUEUR1.bmp");
                                                            SDL_BlitSurface(texte, NULL, ecran, &positionFond);
                                                            SDL_Flip(ecran);break;

                                                        } else{ somme=0;}
int u2,v2,k2,a2=0,somme2=0,ligne2;
Case e2;
 for(u2=0;u2<7;u2++){
         for(v2=0;v2<7;v2++){
             if (merelle[u2][v2]==-1){
                               ligne2=code(u2,v2);

                               for(k2=0;k2<4;k2++){
            int m2,n2;
 if(voisinnage[ligne2][k2]==24){e2.casex=0;
          e.casey=2;}
          else {
                                for(m2=0;m2<7;m2++){
        for(n2=0;n2<7;n2++){
            if(code(m2,n2)==voisinnage[ligne2][k2]){
                    e2.casex=m2;
                    e2.casey=n2;

                    }}} }


                                    if(merelle[e2.casex][e2.casey]!=0){
                                       a++;
                            }

                            }
                            if (a2==4) {
                                    somme2++;
                                    a2=0;

                            }
                            }}

  }if(somme2==score2(merelle)){   gagner = SDL_LoadBMP("gagner.bmp");

                                                            SDL_BlitSurface(gagner, NULL, ecran, &positionmenu);
                                                            texte = SDL_LoadBMP("JOUEUR1.bmp");
                                                            SDL_BlitSurface(texte, NULL, ecran, &positionFond);
                                                            SDL_Flip(ecran);break;

                                                        } else {somme2=0;}




            		for(i=0;i<7;i++){

						for(j=0;j<7;j++){

                               // positionCase.x=i*450/7 +70;
                                //positionCase.y=j*450/7 +70;



            				if ( event.button.x >(i*(450/7))+70   && event.button.x <((i+1)*(450/7))+70
                    			 && event.button.y > (j*(450/7))+70 && event.button.y <((j+1)*(450/7))+70 ){


                                    if(joueur1==1){
                                        if(merelle[i][j]==1){
                                            c_i.casex=i;
                                            c_i.casey=j;
                                                               texte = SDL_LoadBMP("DESTINER.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);

                                            printf("joueur1, choisissez mtn une case destiné");
                                            break;

                                           // vide = SDL_LoadBMP("vide.bmp");
                                           // SDL_BlitSurface(vide, NULL, ecran, &positionCase);
                                           // SDL_Flip(ecran);

 //                                       merelle[i][j]=0;
	//							 			affiche(merelle,ecran,positionFond);
//								 			joueur1=1;
	//							 			joueur2=0.5;


                                            }
                                            else{


                                                if(merelle[i][j]==-1 && Test_moulin(merelle,1,c_f)==1  && c_f.casex!=9 && c_f.casey!=9){
                                                    d.casex=i;
                                                    d.casey=j;
                                                      if (Test_moulin(merelle,-1,d)==0){
                                                    c_i.casex=i;
                                                    c_i.casey=j;
                                                    supprimer(merelle,c_i,1);
                                                    affiche(merelle,ecran,positionFond);
                                                    c_i.casex=9;
                                                    c_i.casey=9;
                                                    c_f.casex=9;
                                                    c_f.casey=9;
                                                    if(score1(merelle)>2 && score2(merelle)>2){


          r=0;s=0;
         for(u=0;u<7;u++){
         for(v=0;v<7;v++){
             if (merelle[u][v]==-1){
                               ligne=code(u,v);

                               for(k=0;k<4;k++){



                                for(m=0;m<7;m++){
        for(n=0;n<7;n++){
            if(code(m,n)==voisinnage[ligne][k]){
                    if(merelle[m][n]==0){
                            t2[s].casex=m;
                            t2[s].casey=n;
                             t1[r].casex=u;
                               t1[r].casey=v;
                               r++;s++;

                            }



                    }}}




                            }


                            }

                             }


  }
                                    srand(time(NULL));
                                                   rs=rand()%r+0;
                                                cm_i.casex=t1[rs].casex;
                                                 cm_i.casey=t1[rs].casey;
                                                 cm_f.casex=t2[rs].casex;
                                                 cm_f.casey=t2[rs].casey;






                                                move(merelle,cm_i,cm_f,-1);
                                                affiche(merelle,ecran,positionFond);
                                                if(Test_moulin(merelle,-1,cm_f)==0){
                                                    cm_i.casex=9;
                                                    cm_i.casey=9;}
                                                else{

                                                    int f=0;Case t3[9];
   for(u=0;u<7;u++){
         for(v=0;v<7;v++){
             if (merelle[u][v]==1){
                 t3[f].casex=u;
                 t3[f].casey=v;
                f++;
             }}}
             srand(time(NULL));
              r=rand()%(f+1)+0;
              while(Test_moulin(merelle,1,t3[r])!=0);
              r=rand()%(f+1)+0;
                                                    cm_i.casex= t3[r].casex;
                                                    cm_i.casey=t3[r].casey;
                                                    supprimer(merelle,cm_i,-1);
                                                    affiche(merelle,ecran,positionFond);
                                                    cm_i.casex=9;
                                                    cm_i.casey=9;
                                                    cm_f.casex=9;
                                                    cm_f.casey=9;
                                                    if(score1(merelle)>2 && score2(merelle)>2){



                                                                      texte = SDL_LoadBMP("JOUEUR1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);

                                                    }
                                                    else{
                                                        if(score1(merelle)<2){
                                                            gagner = SDL_LoadBMP("perdre.bmp");

                                                            SDL_BlitSurface(gagner, NULL, ecran, &positionmenu);
                                                            texte = SDL_LoadBMP("JOUEUR1.bmp");
                                                            SDL_BlitSurface(texte, NULL, ecran, &positionFond);
                                                            SDL_Flip(ecran);

                                                        }
                                                        else{
                                                            gagner = SDL_LoadBMP("gagner.bmp");

                                                            SDL_BlitSurface(gagner, NULL, ecran, &positionmenu);
                                                            texte = SDL_LoadBMP("JOUEUR1.bmp");
                                                            SDL_BlitSurface(texte, NULL, ecran, &positionFond);
                                                            SDL_Flip(ecran);

                                                        }
                                             }





                                                    }


                                                                      texte = SDL_LoadBMP("JOUEUR2.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);

                                                    }
                                                    else{
                                                        if(score1(merelle)<2){
                                                            gagner = SDL_LoadBMP("perdre.bmp");

                                                            SDL_BlitSurface(gagner, NULL, ecran, &positionmenu);
                                                            texte = SDL_LoadBMP("JOUEUR1.bmp");
                                                            SDL_BlitSurface(texte, NULL, ecran, &positionFond);
                                                            SDL_Flip(ecran);

                                                        }
                                                        else{
                                                            gagner = SDL_LoadBMP("gagner.bmp");

                                                            SDL_BlitSurface(gagner, NULL, ecran, &positionmenu);
                                                            texte = SDL_LoadBMP("JOUEUR1.bmp");
                                                            SDL_BlitSurface(texte, NULL, ecran, &positionFond);
                                                            SDL_Flip(ecran);

                                                        }
                                             }

                                                }
                                            }
                                            else{
                                        if(merelle[i][j]==0){
                                            c_f.casex=i;
                                            c_f.casey=j;
                                            if(move_ci_cf(voisinnage,c_i,c_f)==1){
                                                move(merelle,c_i,c_f,1);
                                                affiche(merelle,ecran,positionFond);
                                                if(Test_moulin(merelle,1,c_f)!=0){
                                                    c_i.casex=9;
                                                    c_i.casey=9;

}
                                                else{

                                                    c_i.casex=9;
                                                    c_i.casey=9;
                                                    c_f.casex=9;
                                                    c_f.casey=9;
                                                    if(score1(merelle)>2 && score2(merelle)>2) {
               r=0;s=0;
         for(u=0;u<7;u++){
         for(v=0;v<7;v++){
             if (merelle[u][v]==-1){
                               ligne=code(u,v);

                               for(k=0;k<4;k++){



                                for(m=0;m<7;m++){
        for(n=0;n<7;n++){
            if(code(m,n)==voisinnage[ligne][k]){
                    if(merelle[m][n]==0){
                            t2[s].casex=m;
                            t2[s].casey=n;
                             t1[r].casex=u;
                               t1[r].casey=v;
                               r++;s++;

                            }



                    }}}




                            }


                            }

                             }


  }



                                                   srand(time(NULL));
                                                   rs=rand()%r+0;
                                                cm_i.casex=t1[rs].casex;
                                                 cm_i.casey=t1[rs].casey;
                                                 cm_f.casex=t2[rs].casex;
                                                 cm_f.casey=t2[rs].casey;

                                                move(merelle,cm_i,cm_f,-1);
                                                affiche(merelle,ecran,positionFond);
                                                if(Test_moulin(merelle,-1,cm_f)==0){
                                                    cm_f.casex=9;
                                                    cm_f.casey=9;
                                                    cm_i.casex=9;
                                                    cm_i.casey=9;

                                                }
                                                else{


                                                      rs=0;Case t3[9];
   for(u=0;u<7;u++){
         for(v=0;v<7;v++){
             if (merelle[u][v]==1){
                 t3[rs].casex=u;
                 t3[rs].casey=v;
                rs++;
             }}}
             srand(time(NULL));
             do {
              r=rand()%rs+0;}
              while(Test_moulin(merelle,1,t3[r])!=0);


                                                    supprimer(merelle,t3[r],-1);
                                                    affiche(merelle,ecran,positionFond);
                                                    cm_i.casex=9;
                                                    cm_i.casey=9;
                                                    cm_f.casex=9;
                                                    cm_f.casey=9;
                                                    if(score1(merelle)>2 && score2(merelle)>2){


                                                                      texte = SDL_LoadBMP("JOUEUR1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);

                                                    }
                                                    else{
                                                        if(score1(merelle)<2){
                                                            gagner = SDL_LoadBMP("perdre.bmp");

                                                            SDL_BlitSurface(gagner, NULL, ecran, &positionmenu);
                                                            texte = SDL_LoadBMP("JOUEUR1.bmp");
                                                            SDL_BlitSurface(texte, NULL, ecran, &positionFond);
                                                            SDL_Flip(ecran);

                                                        }
                                                        else{
                                                            gagner = SDL_LoadBMP("gagner.bmp");

                                                            SDL_BlitSurface(gagner, NULL, ecran, &positionmenu);
                                                            texte = SDL_LoadBMP("JOUEUR1.bmp");
                                                            SDL_BlitSurface(texte, NULL, ecran, &positionFond);
                                                            SDL_Flip(ecran);

                                                        }
                                             }





                                                    }



                                                    }
                                            else{
                                                        if(score1(merelle)<2){
                                                            gagner = SDL_LoadBMP("perdre.bmp");

                                                            SDL_BlitSurface(gagner, NULL, ecran, &positionmenu);
                                                            texte = SDL_LoadBMP("JOUEUR1.bmp");
                                                            SDL_BlitSurface(texte, NULL, ecran, &positionFond);
                                                            SDL_Flip(ecran);

                                                        }
                                                        else{
                                                            gagner = SDL_LoadBMP("gagner.bmp");

                                                            SDL_BlitSurface(gagner, NULL, ecran, &positionmenu);
                                                            texte = SDL_LoadBMP("JOUEUR1.bmp");
                                                            SDL_BlitSurface(texte, NULL, ecran, &positionFond);
                                                            SDL_Flip(ecran);

                                                        }
                                                    }

                                                }
                                            }
                                        }
                                    }
                                            }
                                    }

                    		 	}

                           }

					}








       	}

if (  (event.button.y >=550 &&  event.button.x>385))
goto loop;

            break;


    }
    //Affichage:


 }
 break;

    }
   else {
    if (  (event.button.y >=305 && event.button.y<357 && event.button.x < 398&& event.button.x>214))


                  {
                    initialiser(merelle);
                    case_voisin(voisinnage);



  //                  fondnoir = SDL_LoadBMP("fondnoir.bmp");
                    SDL_BlitSurface(fondnoir, NULL, ecran, &positionfondnoir);

   //                 imageDeFond = SDL_LoadBMP("moulin.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

     //               pionrouge1 = SDL_LoadBMP("pionrouge1.bmp");

   					 SDL_BlitSurface(pionrouge1, NULL, ecran, &positionpionrouge1);
  		//			  pionblanc1 = SDL_LoadBMP("pionblanc1.bmp");
  					  SDL_BlitSurface(pionblanc1, NULL, ecran, &positionpionblanc1);
  			//		  pionrouge2 = SDL_LoadBMP("pionrouge1.bmp");

    SDL_BlitSurface(pionrouge1, NULL, ecran, &positionpionrouge2);
 //   pionblanc2 = SDL_LoadBMP("pionblanc1.bmp");

    SDL_BlitSurface(pionblanc1, NULL, ecran, &positionpionblanc2);
 //   pionrouge3 = SDL_LoadBMP("pionrouge1.bmp");

    SDL_BlitSurface(pionrouge1, NULL, ecran, &positionpionrouge3);
 //   pionblanc3 = SDL_LoadBMP("pionblanc1.bmp");

    SDL_BlitSurface(pionblanc1, NULL, ecran, &positionpionblanc3);
   // pionrouge4 = SDL_LoadBMP("pionrouge1.bmp");

    SDL_BlitSurface(pionrouge1, NULL, ecran, &positionpionrouge4);
  //  pionblanc4 = SDL_LoadBMP("pionblanc1.bmp");
    SDL_BlitSurface(pionblanc1, NULL, ecran, &positionpionblanc4);
    //pionrouge5 = SDL_LoadBMP("pionrouge1.bmp");

    SDL_BlitSurface(pionrouge1, NULL, ecran, &positionpionrouge5);
  //  pionblanc5 = SDL_LoadBMP("pionblanc1.bmp");

    SDL_BlitSurface(pionblanc1, NULL, ecran, &positionpionblanc5);
  //  pionrouge6 = SDL_LoadBMP("pionrouge1.bmp");

    SDL_BlitSurface(pionrouge1, NULL, ecran, &positionpionrouge6);
    //pionblanc6 = SDL_LoadBMP("pionblanc1.bmp");

    SDL_BlitSurface(pionblanc1, NULL, ecran, &positionpionblanc6);
   // pionrouge7 = SDL_LoadBMP("pionrouge1.bmp");

    SDL_BlitSurface(pionrouge1, NULL, ecran, &positionpionrouge7);
    //pionblanc7 = SDL_LoadBMP("pionblanc1.bmp");

    SDL_BlitSurface(pionblanc1, NULL, ecran, &positionpionblanc7);
   // pionrouge8 = SDL_LoadBMP("pionrouge1.bmp");

    SDL_BlitSurface(pionrouge1, NULL, ecran, &positionpionrouge8);
    //pionblanc8 = SDL_LoadBMP("pionblanc1.bmp");

    SDL_BlitSurface(pionblanc1, NULL, ecran, &positionpionblanc8);
   // pionrouge9 = SDL_LoadBMP("pionrouge1.bmp");

    SDL_BlitSurface(pionrouge1, NULL, ecran, &positionpionrouge9);
   // pionblanc9 = SDL_LoadBMP("pionblanc1.bmp");

    SDL_BlitSurface(pionblanc1, NULL, ecran, &positionpionblanc9);
    initialiser(merelle);
    affiche(merelle,ecran,positionFond);

    //affiche(merelle);  // 2- on affiche d'abord le damier et les pions

   //SDL_Flip(ecran); /* Mise à jour de l'écran avec sa nouvelle couleur */
    SDL_FreeSurface(imageDeFond); // Libération de la surface

 texte = SDL_LoadBMP("deposer.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);
    srand(time(NULL));
    int premierjoueur=rand()%2+0;
    joueur1=premierjoueur;
    joueur2=1-premierjoueur;
    premierjoueur=1;

   if( premierjoueur==0){
                      do             		{

                      r=rand()%7+0;
                      s=rand()%7+0;            	}
                       while(merelle[r][s]!=0) ;
                      	merelle[r][s]=-1;
                      	      affiche(merelle,ecran,positionFond);
     texte = SDL_LoadBMP("JOUEUR1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    supprimerespace(ecran,1,-1);
                    SDL_Flip(ecran);
   }

  while (continuer)
 {
    SDL_WaitEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_MOUSEBUTTONUP:
        	if(comteur2!=1){

             if(premierjoueur==1){
                    if (comteur3==0){
            	if( comteur!=9 )
            	{

            		for(i=0;i<7;i++){

						for(j=0;j<7;j++){
                            positionCase.x=i*450/7 +70;
                            positionCase.y=j*450/7 +70;



            				if ( event.button.x >(i*(450/7))+70   && event.button.x <((i+1)*(450/7))+70
                    			 && event.button.y > (j*(450/7))+70 && event.button.y <((j+1)*(450/7))+70 ){

                    		 		test=Test_moulin(merelle,1,c);
							 		if(test==0){
							 			if(merelle[i][j]==0){

								 			c.casex=i;
								 			c.casey=j;
                    		 				merelle[i][j]=1;
                                           // pionjaune1 = SDL_LoadBMP("pionrouge1.bmp");
                                            //SDL_BlitSurface(pionrouge1, NULL, ecran, &positionCase);
                                           // SDL_Flip(ecran);
                                           affiche(merelle,ecran,positionFond);
                                           comteur++;



                                      supprimerespace(ecran,comteur,1);


                   		 				test=Test_moulin(merelle,1,c);
                    		 				if(test==0){

            									                    texte = SDL_LoadBMP("JOUEUR2.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);


                                                printf("joueur2, votre tour ");


 ct=0;test1=0; int test2=0;

            for(u=0;u<7;u++){
                for(v=0;v<7;v++){
                    if(merelle[u][v]==0){
                    e.casex=u;
                    e.casey=v;
                    merelle[u][v]=1;
                    if (Test_moulin(merelle,1,e)==1){
                            merelle[u][v]=0;
                            r=u;
                            s=v;
                            ct++;
                    }
                    else{merelle[u][v]=0;}
                    merelle[u][v]=0;
                }
                }
              }

         if(ct!=0){
        merelle[r][s]=-1;
        cm.casex=r;cm.casey=s;
        }

        else{ if(merelle[1][3]==0){merelle[1][3]=-1; cm.casex=1;cm.casey=3;test1++;
                                   }
              else{if (merelle[3][1]==0)
               { cm.casex=3;cm.casey=1;
               merelle[3][1]=-1;test1++;}
                    else{ if (merelle[3][5]==0)
                      {merelle[3][5]=-1;
                     cm.casex=3;cm.casey=5;
                     test1++;}

                    else{  if(merelle[5][3]==0)
                     {merelle[5][3]=-1; cm.casex=5;cm.casey=3;test1++;
                    }else goto lab1;

                    }
              }
              }

               }
lab1:
if( test1==0 && ct==0){

 for(u=0;u<7;u++){
                for(v=0;v<7;v++){ if(u!=i || v!=j){
                    if(merelle[u][v]==0){
                    e.casex=u;
                    e.casey=v;
                    merelle[u][v]=-1;
                    if (Test_moulin(merelle,-1,e)==1){
                            merelle[u][v]=0;
                            r=u;
                            s=v;
                            ct++;
                    }
                    else{merelle[u][v]=0;}
                    merelle[u][v]=0;
                }}
                }
              }
              if(ct!=0){
             cm.casex=r;cm.casey=s;
             merelle[r][s]=-1;}


                else{
                        s=0;
         for(u=0;u<7;u++){
         for(v=0;v<7;v++){
             if (merelle[u][v]==-1){
                               ligne=code(u,v);

                               for(k=0;k<4;k++){



                                for(m=0;m<7;m++){
        for(n=0;n<7;n++){
            if(code(m,n)==voisinnage[ligne][k]){
                    if(merelle[m][n]==0){
                            t2[s].casex=m;
                            t2[s].casey=n;

                               s++;

                            }



                    }}}




                            }


                            }

                             }


  } if(s!=0){
                                    srand(time(NULL));
                                                   rs=rand()%s+0;
                                                 cm.casex=t2[rs].casex;
                                                 cm.casey=t2[rs].casey;
                                                 merelle[cm.casex][cm.casey]=-1;}
                                                 else{
                                                    do             		{

                      rs=rand()%7+0;
                      ss=rand()%7+0;
                         cm.casex=rs;
                                           cm.casey=ss;         	}
                       while(merelle[rs][ss]!=0 ) ;
                       merelle[rs][ss]=-1;
                                                 }
             }


}




                                             //   pionblanc1 = SDL_LoadBMP("pionblanc1.bmp");
                                               // SDL_BlitSurface(pionblanc1, NULL, ecran, &positionCase);
                                                //SDL_Flip(ecran);
                                                affiche(merelle,ecran,positionFond);
                    		 					test=Test_moulin(merelle,-1,cm);
                    		 					if(test==0){

c.casex=9;
								 			c.casey=9;
                                                texte = SDL_LoadBMP("JOUEUR1.bmp");
                                                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                                                 SDL_Flip(ecran);


            										if(comteur==9){
                                                    comteur2=1;

                                                    texte = SDL_LoadBMP("JOUEUR1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);



                                                    c_i.casex=9;
                                                    c_i.casey=9;
                                                    c_f.casex=9;
                                                    c_f.casey=9;
                                                    }
           							}
           						else{
            		    do             		{

                      rs=rand()%7+0;
                      ss=rand()%7+0;
                         dm.casex=rs;
                                           dm.casey=ss;         	}
                       while(merelle[rs][ss]!=1  || Test_moulin(merelle,1,dm)==1) ;



           								    printf("joueur2, vous avez droit de supprimmer un pion blanc ");
                                          //  vide = SDL_LoadBMP("vide.bmp");
                                            //SDL_BlitSurface(vide, NULL, ecran, &positionCase);
                                            //SDL_Flip(ecran);

           									merelle[rs][ss]=0;
                                            affiche(merelle,ecran,positionFond);


                                            texte = SDL_LoadBMP("JOUEUR1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);

            								if(comteur==9){
           									comteur2=1;
                                                     joueur1=1;
                                                    joueur2=0;

                                            c_i.casex=9;
                                            c_i.casey=9;
                                            c_f.casex=9;
                                            c_f.casey=9;

										   }

								   }




            	supprimerespace(ecran,comteur,-1);


           									}
                                  else {texte = SDL_LoadBMP("SUPRIMER1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);
                                            if (comteur==9){
                                                comteur3=1;

                                            }     }
           								}
           							}
           						else{

           							if(merelle[i][j]==-1){
                                    d.casex=i;
                                    d.casey=j;
                                      test=Test_moulin(merelle,-1,d);
                                      if(test==0){
                                        printf("joueur1, vous avez droit de supprimmer un pion blanc ");
if (code(i,j)!=4 && code(i,j)!=10 && code(i,j)!=13 && code(i,j)!=19 ){
merelle[i][j]=0;


                                       //vide = SDL_LoadBMP("vide.bmp");
                                       // SDL_BlitSurface(vide, NULL, ecran, &positionCase);
                                       // SDL_Flip(ecran);

 ct=0;test1=0; int test2=0;


merelle[i][j]=0;
            for(u=0;u<7;u++){
                for(v=0;v<7;v++){
                        if (u!=i || v!=j){
                    if(merelle[u][v]==0){
                    e.casex=u;
                    e.casey=v;
                    merelle[u][v]=1;
                    if (Test_moulin(merelle,1,e)==1){
                            merelle[u][v]=0;
                            r=u;
                            s=v;
                            ct++;
                    }
                    else{merelle[u][v]=0;}
                    merelle[u][v]=0;
                }
                } else{
                 e.casex=u;
                    e.casey=v;
                    merelle[u][v]=1;
                    if (Test_moulin(merelle,1,e)==1){
                            merelle[u][v]=0;
                            r=u;
                            s=v;
                            ct++;
                    }}  }
              }

         if(ct!=0){
        merelle[r][s]=-1;
        cm.casex=r;cm.casey=s;
        }

      else{  goto lab;}


lab:

if( test1==0 && ct==0){

 for(u=0;u<7;u++){
                for(v=0;v<7;v++){
                           if (u!=i || v!=j){
                    if(merelle[u][v]==0){
                    e.casex=u;
                    e.casey=v;
                    merelle[u][v]=-1;
                    if (Test_moulin(merelle,-1,e)==1){
                            merelle[u][v]=0;
                            r=u;
                            s=v;
                            ct++;
                    }
                    else{merelle[u][v]=0;}
                    merelle[u][v]=0;
                }}
                }
              }
              if(ct!=0){
             cm.casex=r;cm.casey=s;
             merelle[r][s]=-1;
              }
             else{
                s=0;
          for(u=0;u<7;u++){
         for(v=0;v<7;v++){
                   if (u!=i || v!=j){
             if (merelle[u][v]==-1){
                               ligne=code(u,v);

                               for(k=0;k<4;k++){



                                for(m=0;m<7;m++){
        for(n=0;n<7;n++){
            if(code(m,n)==voisinnage[ligne][k]){
                    if(merelle[m][n]==0){
                            t2[s].casex=m;
                            t2[s].casey=n;

                               s++;

                            }



                    }}}




                            }


                            }}

                             }


  } if(s!=0){
                                    srand(time(NULL));
                                                   rs=rand()%s+0;
                                                 cm.casex=t2[rs].casex;
                                                 cm.casey=t2[rs].casey;
                                                 merelle[cm.casex][cm.casey]=-1;}
                                                 else{
                                                    do             		{

                      rs=rand()%7+0;
                      ss=rand()%7+0;
                         cm.casex=rs;
                                           cm.casey=ss;         	}
                       while(merelle[rs][ss]!=0 ) ;
                       merelle[rs][ss]=-1;
                                                 }
             }


}
                                             //   pionblanc1 = SDL_LoadBMP("pionblanc1.bmp");
                                               // SDL_BlitSurface(pionblanc1, NULL, ecran, &positionCase);
                                                //SDL_Flip(ecran);
                                                affiche(merelle,ecran,positionFond);

                    		 					test=Test_moulin(merelle,-1,cm);
                    		 					if(test==0){

c.casex=9;c.casey=9;
                                                texte = SDL_LoadBMP("JOUEUR1.bmp");
                                                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                                                 SDL_Flip(ecran);

            										if(comteur==9){
                                                    comteur2=1;
                                                    joueur1=1;
                                                    joueur2=0;
                                                    texte = SDL_LoadBMP("JOUEUR1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);



                                                    c_i.casex=9;
                                                    c_i.casey=9;
                                                    c_f.casex=9;
                                                    c_f.casey=9;
                                                    }
           									}


           						else{  do             		{

                      rs=rand()%7+0;
                      ss=rand()%7+0;
                         dm.casex=rs;
                                           dm.casey=ss;         	}
                       while(merelle[rs][ss]!=1  || Test_moulin(merelle,1,dm)==1) ;


                                           dm.casex=rs;
                                           dm.casey=ss;

           								    printf("joueur2, vous avez droit de supprimmer un pion blanc ");
                                          //  vide = SDL_LoadBMP("vide.bmp");
                                            //SDL_BlitSurface(vide, NULL, ecran, &positionCase);
                                            //SDL_Flip(ecran);

           									merelle[rs][ss]=0;
                                            affiche(merelle,ecran,positionFond);


                                            texte = SDL_LoadBMP("JOUEUR1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);

            								if(comteur==9){
           									comteur2=1;


                                            c_i.casex=9;
                                            c_i.casey=9;
                                            c_f.casex=9;
                                            c_f.casey=9;

										   }

								   }




            	 supprimerespace(ecran,comteur,-1);




            							                    texte = SDL_LoadBMP("JOUEUR1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);


                                    printf("joueur2, votre tour ");

if (comteur==9) comteur2=1;
                                 // merelle[i][j]=0;
                                 //    vide = SDL_LoadBMP("vide.bmp");
                                  //          SDL_BlitSurface(vide, NULL, ecran, &positionCase);
                                   //         SDL_Flip(ecran);
                                       } else {  supprimerespace(ecran,comteur,-1);
                                       c.casex=9;c.casey=9; }
								   }}
								}
            				}
            			}
            		}





            	}

 }
            else{for(i=0;i<7;i++){

						for(j=0;j<7;j++){
                            positionCase.x=i*450/7 +70;
                            positionCase.y=j*450/7 +70;



            				if ( event.button.x >(i*(450/7))+70   && event.button.x <((i+1)*(450/7))+70
                    			 && event.button.y > (j*(450/7))+70 && event.button.y <((j+1)*(450/7))+70 ){

                    if(merelle[i][j]==-1){
                                    d.casex=i;
                                    d.casey=j;
                                      test=Test_moulin(merelle,-1,d);
                                      if(test==0){
                                        printf("joueur1, vous avez droit de supprimmer un pion blanc ");

           								merelle[i][j]=0;
                                       // vide = SDL_LoadBMP("vide.bmp");
                                        //SDL_BlitSurface(vide, NULL, ecran, &positionCase);
                                        //SDL_Flip(ecran);
                                        affiche(merelle,ecran,positionFond);


c.casex=9;
c.casey=9;



            		     srand(time(NULL));

            		    do             		{

                      r=rand()%7+0;
                      s=rand()%7+0;            	}
                       while(merelle[r][s]!=0) ;
cm.casex=r;
									 			cm.casey=s;


                    		 					merelle[r][s]=-1;
                                             //   pionblanc1 = SDL_LoadBMP("pionblanc1.bmp");
                                               // SDL_BlitSurface(pionblanc1, NULL, ecran, &positionCase);
                                                //SDL_Flip(ecran);
                                                affiche(merelle,ecran,positionFond);

                    		 					test=Test_moulin(merelle,-1,cm);
                    		 					if(test==0){


                                                texte = SDL_LoadBMP("JOUEUR1.bmp");
                                                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                                                 SDL_Flip(ecran);

           									}


           						else{  do             		{

                      rs=rand()%7+0;
                      ss=rand()%7+0;
                         dm.casex=rs;
                                           dm.casey=ss;         	}
                       while(merelle[rs][ss]!=1  || Test_moulin(merelle,1,dm)==1) ;


                                           dm.casex=rs;
                                           dm.casey=ss;

           								    printf("joueur2, vous avez droit de supprimmer un pion blanc ");
                                          //  vide = SDL_LoadBMP("vide.bmp");
                                            //SDL_BlitSurface(vide, NULL, ecran, &positionCase);
                                            //SDL_Flip(ecran);

           									merelle[rs][ss]=0;
                                            affiche(merelle,ecran,positionFond);


                                            texte = SDL_LoadBMP("JOUEUR1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);


								   }
                            supprimerespace(ecran,comteur,-1);
 		comteur2=1;
								               joueur1=1;
                                                    joueur2=0;
                                                    texte = SDL_LoadBMP("JOUEUR1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);






                                      }
						  }





              } }}}}
              else {    if(premierjoueur==0){
                    if (comteur3==0){
            	if( comteur!=9 )
            	{

            		for(i=0;i<7;i++){

						for(j=0;j<7;j++){
                            positionCase.x=i*450/7 +70;
                            positionCase.y=j*450/7 +70;



            				if ( event.button.x >(i*(450/7))+70   && event.button.x <((i+1)*(450/7))+70
                    			 && event.button.y > (j*(450/7))+70 && event.button.y <((j+1)*(450/7))+70 ){





                    		 		test=Test_moulin(merelle,1,c);
							 		if(test==0){
							 			if(merelle[i][j]==0){

								 			c.casex=i;
								 			c.casey=j;
                    		 				merelle[i][j]=1;
                                           // pionrouge1 = SDL_LoadBMP("pionrouge1.bmp");
                                            //SDL_BlitSurface(pionrouge1, NULL, ecran, &positionCase);
                                           // SDL_Flip(ecran);
                                           affiche(merelle,ecran,positionFond);
                                           comteur++;



                                      supprimerespace(ecran,comteur,1);


                   		 				test=Test_moulin(merelle,1,c);
                    		 				if(test==0){

            									                    texte = SDL_LoadBMP("JOUEUR2.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);


                                                ct=0;test1=0;

            for(u=0;u<7;u++){
                for(v=0;v<7;v++){
                    if(merelle[u][v]==0){
                    e.casex=u;
                    e.casey=v;
                    merelle[u][v]=1;
                    if (Test_moulin(merelle,1,e)==1){
                            merelle[u][v]=0;
                            r=u;
                            s=v;
                            ct++;
                    }
                    else{merelle[u][v]=0;}
                    merelle[u][v]=0;
                }
                }
              }

         if(ct!=0){
        merelle[r][s]=-1;
        cm.casex=r;cm.casey=s;
        }
        else{ if(merelle[1][3]==0){merelle[1][3]=-1; cm.casex=1;cm.casey=3;test1++;
                                   }
              else{if (merelle[3][1]==0)
               { cm.casex=3;cm.casey=1;
               merelle[3][1]=-1;test1++;}
                    else{ if (merelle[3][5]==0)
                      {merelle[3][5]=-1;
                     cm.casex=3;cm.casey=5;
                     test1++;}

                    else{  if(merelle[5][3]==0)
                     {merelle[5][3]=-1; cm.casex=5;cm.casey=3;test1++;
                    }

                    }
              }
              }

               }

if( test1==0 && ct==0){

ct=0;
 for(u=0;u<7;u++){
                for(v=0;v<7;v++){
                    if(merelle[u][v]==0){
                    e.casex=u;
                    e.casey=v;
                    merelle[u][v]=-1;
                    if (Test_moulin(merelle,-1,e)==1){
                            merelle[u][v]=0;
                            r=u;
                            s=v;
                            ct++;
                    }
                    else{merelle[u][v]=0;}
                    merelle[u][v]=0;
                }
                }
              }
            if(ct!=0){ cm.casex=r;cm.casey=s;
             merelle[r][s]=-1;}
             else{
                r=0;s=0;
         for(u=0;u<7;u++){
         for(v=0;v<7;v++){
             if (merelle[u][v]==-1){
                               ligne=code(u,v);

                               for(k=0;k<4;k++){



                                for(m=0;m<7;m++){
        for(n=0;n<7;n++){
            if(code(m,n)==voisinnage[ligne][k]){
                    if(merelle[m][n]==0){
                            t2[s].casex=m;
                            t2[s].casey=n;
                             t1[r].casex=u;
                               t1[r].casey=v;
                               r++;s++;

                            }



                    }}}




                            }


                            }

                             }


  }
                                    srand(time(NULL));
                                                   rs=rand()%r+0;
                                                 cm.casex=t2[rs].casex;
                                                 cm.casey=t2[rs].casey;
                                                 merelle[cm.casex][cm.casey]=-1;
             }


}



                                             //   pionblanc1 = SDL_LoadBMP("pionblanc1.bmp");
                                               // SDL_BlitSurface(pionblanc1, NULL, ecran, &positionCase);
                                                //SDL_Flip(ecran);
                                                affiche(merelle,ecran,positionFond);
                    		 					test=Test_moulin(merelle,-1,cm);
                    		 					if(test==0){


                                                texte = SDL_LoadBMP("JOUEUR1.bmp");
                                                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                                                 SDL_Flip(ecran);


            										if(comteur==9){
                                                      	merelle[r][s]=0;
                                                     affiche(merelle,ecran,positionFond);
                                                    comteur2=1;

                                                    texte = SDL_LoadBMP("JOUEUR1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);

 texte = SDL_LoadBMP("DEPLACER.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);



                                                    c_i.casex=9;
                                                    c_i.casey=9;
                                                    c_f.casex=9;
                                                    c_f.casey=9;
                                                    }


           							}
           						else{
            		    do             		{

                      rs=rand()%7+0;
                      ss=rand()%7+0;
                         dm.casex=rs;
                                           dm.casey=ss;         	}
                       while(merelle[rs][ss]!=1  || Test_moulin(merelle,1,dm)==1) ;



           								    printf("joueur2, vous avez droit de supprimmer un pion blanc ");
                                          //  vide = SDL_LoadBMP("vide.bmp");
                                            //SDL_BlitSurface(vide, NULL, ecran, &positionCase);
                                            //SDL_Flip(ecran);

           									merelle[rs][ss]=0;
                                            affiche(merelle,ecran,positionFond);


                                            texte = SDL_LoadBMP("JOUEUR1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);

            								if(comteur==9){
           									comteur2=1;


                                            c_i.casex=9;
                                            c_i.casey=9;
                                            c_f.casex=9;
                                            c_f.casey=9;

										   }

								   }




            	supprimerespace(ecran,comteur+1,-1);


           									}
                                  else {
                                        texte = SDL_LoadBMP("SUPRIMER1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);
                                            if (comteur==9){
                                                comteur3=1;

                                            }
                                            else{ c.casex=i;
                                            c.casey=j;}
                                  }
           								}
           							}
           						else{

           							if(merelle[i][j]==-1){
                                    d.casex=i;
                                    d.casey=j;
                                      test=Test_moulin(merelle,-1,d);
                                      if(test==0){
                                        printf("joueur1, vous avez droit de supprimmer un pion blanc ");

           								merelle[i][j]=0;
                                       // vide = SDL_LoadBMP("vide.bmp");
                                        //SDL_BlitSurface(vide, NULL, ecran, &positionCase);
                                        //SDL_Flip(ecran);
                                        affiche(merelle,ecran,positionFond);


c.casex=9;
c.casey=9;

            	ct=0;test1=0;

            for(u=0;u<7;u++){
                for(v=0;v<7;v++){
                    if(merelle[u][v]==0){
                    e.casex=u;
                    e.casey=v;
                    merelle[u][v]=1;
                    if (Test_moulin(merelle,1,e)==1){
                            merelle[u][v]=0;
                            r=u;
                            s=v;
                            ct++;
                    }
                    else{merelle[u][v]=0;}
                    merelle[u][v]=0;
                }
                }
              }

         if(ct!=0){
        merelle[r][s]=-1;
        cm.casex=r;cm.casey=s;
        }
        else{ if(merelle[1][3]==0){merelle[1][3]=-1; cm.casex=1;cm.casey=3;test1++;
                                   }
              else{if (merelle[3][1]==0)
               { cm.casex=3;cm.casey=1;
               merelle[3][1]=-1;test1++;}
                    else{ if (merelle[3][5]==0)
                      {merelle[3][5]=-1;
                     cm.casex=3;cm.casey=5;
                     test1++;}

                    else{  if(merelle[5][3]==0)
                     {merelle[5][3]=-1; cm.casex=5;cm.casey=3;test1++;
                    }

                    }
              }
              }

               }

if( test1==0 && ct==0){

ct=0;
 for(u=0;u<7;u++){
                for(v=0;v<7;v++){
                    if(merelle[u][v]==0){
                    e.casex=u;
                    e.casey=v;
                    merelle[u][v]=-1;
                    if (Test_moulin(merelle,-1,e)==1){
                            merelle[u][v]=0;
                            r=u;
                            s=v;
                            ct++;
                    }
                    else{merelle[u][v]=0;}
                    merelle[u][v]=0;
                }
                }
              }
           if(ct!=0) { cm.casex=r;cm.casey=s;
             merelle[r][s]=-1;}
             else{
                r=0;s=0;
         for(u=0;u<7;u++){
         for(v=0;v<7;v++){
             if (merelle[u][v]==-1){
                               ligne=code(u,v);

                               for(k=0;k<4;k++){



                                for(m=0;m<7;m++){
        for(n=0;n<7;n++){
            if(code(m,n)==voisinnage[ligne][k]){
                    if(merelle[m][n]==0){
                            t2[s].casex=m;
                            t2[s].casey=n;
                             t1[r].casex=u;
                               t1[r].casey=v;
                               r++;s++;

                            }



                    }}}




                            }


                            }

                             }


  }
                                    srand(time(NULL));
                                                   rs=rand()%r+0;
                                                 cm.casex=t2[rs].casex;
                                                 cm.casey=t2[rs].casey;
                                                 merelle[cm.casex][cm.casey]=-1;
             }


}
                                             //   pionblanc1 = SDL_LoadBMP("pionblanc1.bmp");
                                               // SDL_BlitSurface(pionblanc1, NULL, ecran, &positionCase);
                                                //SDL_Flip(ecran);
                                                affiche(merelle,ecran,positionFond);

                    		 					test=Test_moulin(merelle,-1,cm);
                    		 					if(test==0){


                                                texte = SDL_LoadBMP("JOUEUR1.bmp");
                                                SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                                                 SDL_Flip(ecran);

            										if(comteur==9){
                                                    comteur2=1;

                                                    texte = SDL_LoadBMP("JOUEUR1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);



                                                    c_i.casex=9;
                                                    c_i.casey=9;
                                                    c_f.casex=9;
                                                    c_f.casey=9;
                                                    }
           									}


           						else{  do             		{
                                  		     srand(time(NULL));
                      rs=rand()%7+0;
                      ss=rand()%7+0;
                         dm.casex=rs;
                                           dm.casey=ss;         	}
                       while(merelle[rs][ss]!=1  || Test_moulin(merelle,1,dm)==1) ;


                                           dm.casex=rs;
                                           dm.casey=ss;

           								    printf("joueur2, vous avez droit de supprimmer un pion blanc ");
                                          //  vide = SDL_LoadBMP("vide.bmp");
                                            //SDL_BlitSurface(vide, NULL, ecran, &positionCase);
                                            //SDL_Flip(ecran);

           									merelle[rs][ss]=0;
                                            affiche(merelle,ecran,positionFond);


                                            texte = SDL_LoadBMP("JOUEUR1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);

            								if(comteur==9){
           									comteur2=1;


                                            c_i.casex=9;
                                            c_i.casey=9;
                                            c_f.casex=9;
                                            c_f.casey=9;

										   }

								   }




            	 supprimerespace(ecran,comteur+1,-1);




            							                    texte = SDL_LoadBMP("JOUEUR1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);


                                    printf("joueur2, votre tour ");
               merelle[i][j]=0;

                                 SDL_BlitSurface(vide, NULL, ecran, &positionCase);
                                 SDL_Flip(ecran);
                                     }
								   }
								}
            				}
            			}
            		}





            	}

 }
            else{for(i=0;i<7;i++){

						for(j=0;j<7;j++){
                            positionCase.x=i*450/7 +70;
                            positionCase.y=j*450/7 +70;



            				if ( event.button.x >(i*(450/7))+70   && event.button.x <((i+1)*(450/7))+70
                    			 && event.button.y > (j*(450/7))+70 && event.button.y <((j+1)*(450/7))+70 ){

                    if(merelle[i][j]==-1){
                                    d.casex=i;
                                    d.casey=j;
                                      test=Test_moulin(merelle,-1,d);
                                      if(test==0){
                                        printf("joueur1, vous avez droit de supprimmer un pion blanc ");

           								merelle[i][j]=0;
                                       // vide = SDL_LoadBMP("vide.bmp");
                                        //SDL_BlitSurface(vide, NULL, ecran, &positionCase);
                                        //SDL_Flip(ecran);
                                        affiche(merelle,ecran,positionFond);


c.casex=9;
c.casey=9;




 		comteur2=1;

                                                  texte = SDL_LoadBMP("DEPLACER.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);







                                      }
						  }





              } }}}
              if(comteur2==1){
                r=0;s=0;
         for(u=0;u<7;u++){
         for(v=0;v<7;v++){
             if (merelle[u][v]==-1){
                               ligne=code(u,v);

                               for(k=0;k<4;k++){



                                for(m=0;m<7;m++){
        for(n=0;n<7;n++){
            if(code(m,n)==voisinnage[ligne][k]){
                    if(merelle[m][n]==0){
                            t2[s].casex=m;
                            t2[s].casey=n;
                             t1[r].casex=u;
                               t1[r].casey=v;
                               r++;s++;

                            }



                    }}}




                            }


                            }

                             }


  }
                                    srand(time(NULL));
                                                   rs=rand()%r+0;
                                                cm_i.casex=t1[rs].casex;
                                                 cm_i.casey=t1[rs].casey;
                                                 cm_f.casex=t2[rs].casex;
                                                 cm_f.casey=t2[rs].casey;






                                                move(merelle,cm_i,cm_f,-1);
                                                affiche(merelle,ecran,positionFond);
                                                if(Test_moulin(merelle,-1,cm_f)==0){
                                                    cm_i.casex=9;
                                                    cm_i.casey=9;
                                                  }
                                                else{

                                                    int f=0;Case t3[9];
   for(u=0;u<7;u++){
         for(v=0;v<7;v++){
             if (merelle[u][v]==1){
                 t3[f].casex=u;
                 t3[f].casey=v;
                f++;
             }}}
             srand(time(NULL));
              r=rand()%(f+1)+0;
              while(Test_moulin(merelle,1,t3[r])!=0);
              r=rand()%(f+1)+0;
                                                    cm_i.casex= t3[r].casex;
                                                    cm_i.casey=t3[r].casey;
                                                    supprimer(merelle,cm_i,-1);
                                                    affiche(merelle,ecran,positionFond);
                                                    cm_i.casex=9;
                                                    cm_i.casey=9;
                                                    cm_f.casex=9;
                                                    cm_f.casey=9;

                                                    }
              }
              }
              }
               }
          else{
         texte = SDL_LoadBMP("DEPLACER.bmp");
         SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
         SDL_Flip(ecran);
      Case e;Case t4[9];
         for(u=0;u<7;u++){
         for(v=0;v<7;v++){
             if (merelle[u][v]==1){
                               ligne=code(u,v);
                               for(k=0;k<4;k++){

 if(voisinnage[ligne][k]==24)
         {e.casex=0;
          e.casey=2;}
          else {
                                for(m=0;m<7;m++){
        for(n=0;n<7;n++){
            if(code(m,n)==voisinnage[ligne][k]){
                    e.casex=m;
                    e.casey=n;

                    }}} }


                                    if(merelle[e.casex][e.casey]!=0){
                                       a++;
                            }
                            }
                            if (a==4) {
                                    somme++;
                                    a=0;

                            }
                            }

                             }

  }if(somme==score1(merelle)){   gagner = SDL_LoadBMP("perdre.bmp");

                                                            SDL_BlitSurface(gagner, NULL, ecran, &positionmenu);
                                                            texte = SDL_LoadBMP("JOUEUR1.bmp");
                                                            SDL_BlitSurface(texte, NULL, ecran, &positionFond);
                                                            SDL_Flip(ecran);break;

                                                        } else{ somme=0;}
int u2,v2,k2,a2=0,somme2=0,ligne2;
Case e2;
 for(u2=0;u2<7;u2++){
         for(v2=0;v2<7;v2++){
             if (merelle[u2][v2]==-1){
                               ligne2=code(u2,v2);

                               for(k2=0;k2<4;k2++){
            int m2,n2;
 if(voisinnage[ligne2][k2]==24){e2.casex=0;
          e.casey=2;}
          else {
                                for(m2=0;m2<7;m2++){
        for(n2=0;n2<7;n2++){
            if(code(m2,n2)==voisinnage[ligne2][k2]){
                    e2.casex=m2;
                    e2.casey=n2;

                    }}} }


                                    if(merelle[e2.casex][e2.casey]!=0){
                                       a++;
                            }

                            }
                            if (a2==4) {
                                    somme2++;
                                     a2=0;
                                     t4[somme2].casex=u2;
                                     t4[somme2].casey=v2;
                            }
                            }}

  }if(somme2==score2(merelle)){   gagner = SDL_LoadBMP("gagner.bmp");

                                                            SDL_BlitSurface(gagner, NULL, ecran, &positionmenu);
                                                            texte = SDL_LoadBMP("JOUEUR1.bmp");
                                                            SDL_BlitSurface(texte, NULL, ecran, &positionFond);
                                                            SDL_Flip(ecran);break;

                                                        } else {somme2=0;}




            		for(i=0;i<7;i++){

						for(j=0;j<7;j++){
            				if ( event.button.x >(i*(450/7))+70   && event.button.x <((i+1)*(450/7))+70
                    			 && event.button.y > (j*(450/7))+70 && event.button.y <((j+1)*(450/7))+70 ){



                                        if(merelle[i][j]==1){
                                            c_i.casex=i;
                                            c_i.casey=j;
                                                               texte = SDL_LoadBMP("DESTINER.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);

                                            printf("joueur1, choisissez mtn une case destiné");
                                            break;

                                           // vide = SDL_LoadBMP("vide.bmp");
                                           // SDL_BlitSurface(vide, NULL, ecran, &positionCase);
                                           // SDL_Flip(ecran);

 //                                       merelle[i][j]=0;
	//							 			affiche(merelle,ecran,positionFond);
//								 			joueur1=1;
	//							 			joueur2=0.5;


                                            }
                                            else{


                                                if(merelle[i][j]==-1 && Test_moulin(merelle,1,c_f)==1  && c_f.casex!=9 && c_f.casey!=9){
                                                    d.casex=i;
                                                    d.casey=j;
                                                      if (Test_moulin(merelle,-1,d)==0){
                                                    c_i.casex=i;
                                                    c_i.casey=j;
                                                    supprimer(merelle,c_i,1);
                                                    affiche(merelle,ecran,positionFond);
                                                    c_i.casex=9;
                                                    c_i.casey=9;
                                                    c_f.casex=9;
                                                    c_f.casey=9;
                                                    if(score1(merelle)>2 && score2(merelle)>2){

     ct=0;
                                             r=0;s=0;
for(u=0;u<7;u++){
         for(v=0;v<7;v++){

                    if(merelle[u][v]==0){
                    e.casex=u;
                    e.casey=v;
                    merelle[u][v]=-1;
                    if (Test_moulin(merelle,-1,e)==1){
                            ligne=code(u,v);
                            for(k=0;k<4;k++){
                                for(m=0;m<7;m++){
                                     for(n=0;n<7;n++){
                                         if(code(m,n)==voisinnage[ligne][k]){
                                             e.casex=m;e.casey=n;
                                            if(merelle[m][n]==-1 && Test_moulin(merelle,-1,e)==0){


                            t2[s].casex=u;
                            t2[s].casey=v;
                             t1[r].casex=m;
                               t1[r].casey=n;
                               r++;s++;
                                            }

                                         }
                                     }
                                }
                            }
                    }
     merelle[u][v]=0;           }


                             }


  }
if(r!=0){
                                    srand(time(NULL));
                                                   rs=rand()%r+0;
                                                cm_i.casex=t1[rs].casex;
                                                 cm_i.casey=t1[rs].casey;
                                                 cm_f.casex=t2[rs].casex;
                                                 cm_f.casey=t2[rs].casey;}
                                                 else{

                           r=0; s=0;ct=0;int l=0;
for(u=0;u<7;u++){
         for(v=0;v<7;v++){

                    if(merelle[u][v]==0){
                    e.casex=u;
                    e.casey=v;
                    merelle[u][v]=1;
                    if (Test_moulin(merelle,1,e)==1){
                            ligne=code(u,v);
                            for(k=0;k<4;k++){
                                for(m=0;m<7;m++){
                                     for(n=0;n<7;n++){
                                         if(code(m,n)==voisinnage[ligne][k]){

                                            if(merelle[m][n]==1){
                                                    ct++;}
                                            if(merelle[m][n]==-1){
                                                l++;}







                                         }
                                     }
                                }
                            }

               if(ct!=0 && l!=0){
                            t2[s].casex=u;
                            t2[s].casey=v;
                             t1[r].casex=m;
                               t1[r].casey=n;
                               r++;s++;}


                             }

              merelle[u][v]=0 ;     }
                    }}
if(r!=0){

                                    srand(time(NULL));
                                                   rs=rand()%r+0;
                                                cm_i.casex=t1[rs].casex;
                                                 cm_i.casey=t1[rs].casey;
                                                 cm_f.casex=t2[rs].casex;
                                                 cm_f.casey=t2[rs].casey;}
                                                 else{


                    r=0;s=0;
for(u=0;u<7;u++){
         for(v=0;v<7;v++){

                    if(merelle[u][v]==-1){
                    e.casex=u;
                    e.casey=v;
                    if (Test_moulin(merelle,-1,e)==1){
                            ligne=code(u,v);
                            for(k=0;k<4;k++){
                                for(m=0;m<7;m++){
                                     for(n=0;n<7;n++){
                                         if(code(m,n)==voisinnage[ligne][k]){

                                            if(merelle[m][n]==0){


                            t2[s].casex=m;
                            t2[s].casey=n;
                             t1[r].casex=u;
                               t1[r].casey=v;
                               r++;s++;
                                            }

                                         }
                                     }
                                }
                            }
                    }
              }


                             }




   }      if(r!=0){    srand(time(NULL));
                                                   rs=rand()%r+0;
                                                cm_i.casex=t1[rs].casex;
                                                 cm_i.casey=t1[rs].casey;
                                                 cm_f.casex=t2[rs].casex;
                                                 cm_f.casey=t2[rs].casey;
   }
    else {                       r=0;s=0;
for(u=0;u<7;u++){
         for(v=0;v<7;v++){

                    if(merelle[u][v]==-1){
                    e.casex=u;
                    e.casey=v;

                            ligne=code(u,v);
                            for(k=0;k<4;k++){
                                for(m=0;m<7;m++){
                                     for(n=0;n<7;n++){
                                         if(code(m,n)==voisinnage[ligne][k]){

                                            if(merelle[m][n]==0 ){


                            t2[s].casex=m;
                            t2[s].casey=n;
                             t1[r].casex=u;
                               t1[r].casey=v;
                               r++;s++;
                                            }

                                         }
                                     }
                                }
                            }

              }


                             }


  }
   srand(time(NULL));
                                                   rs=rand()%r+0;
                                                    cm_i.casex=t1[rs].casex;
                                                 cm_i.casey=t1[rs].casey;
                                                 cm_f.casex=t2[rs].casex;
                                                 cm_f.casey=t2[rs].casey;}

                                                 }

                                                 }


                                                move(merelle,cm_i,cm_f,-1);
                                                affiche(merelle,ecran,positionFond);
                                                if(Test_moulin(merelle,-1,cm_f)==0){
                                                    cm_f.casex=9;
                                                    cm_f.casey=9;
                                                    cm_i.casex=9;
                                                    cm_i.casey=9;

                                                }
                                                else{


                                                      rs=0;Case t3[9];
   for(u=0;u<7;u++){
         for(v=0;v<7;v++){
             if (merelle[u][v]==1){
                 t3[rs].casex=u;
                 t3[rs].casey=v;
                rs++;
             }}}
             srand(time(NULL));
             do {
              r=rand()%rs+0;}
              while(Test_moulin(merelle,1,t3[r])!=0);


                                                    supprimer(merelle,t3[r],-1);
                                                    affiche(merelle,ecran,positionFond);
                                                    cm_i.casex=9;
                                                    cm_i.casey=9;
                                                    cm_f.casex=9;
                                                    cm_f.casey=9;
                                                    if(score1(merelle)>2 && score2(merelle)>2){


                                                                      texte = SDL_LoadBMP("JOUEUR1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);

                                                    }
                                                    else{
                                                        if(score1(merelle)<2){
                                                            gagner = SDL_LoadBMP("perdre.bmp");

                                                            SDL_BlitSurface(gagner, NULL, ecran, &positionmenu);
                                                            texte = SDL_LoadBMP("JOUEUR1.bmp");
                                                            SDL_BlitSurface(texte, NULL, ecran, &positionFond);
                                                            SDL_Flip(ecran);

                                                        }
                                                        else{
                                                            gagner = SDL_LoadBMP("gagner.bmp");

                                                            SDL_BlitSurface(gagner, NULL, ecran, &positionmenu);
                                                            texte = SDL_LoadBMP("JOUEUR1.bmp");
                                                            SDL_BlitSurface(texte, NULL, ecran, &positionFond);
                                                            SDL_Flip(ecran);

                                                        }
                                             }





                                                    }



                                                   }
                                                    else{
                                                        if(score1(merelle)<2){
                                                            perdre = SDL_LoadBMP("perdre.bmp");

                                                            SDL_BlitSurface(perdre, NULL, ecran, &positionmenu);
                                                            texte = SDL_LoadBMP("JOUEUR1.bmp");
                                                            SDL_BlitSurface(texte, NULL, ecran, &positionFond);
                                                            SDL_Flip(ecran);

                                                        }
                                                        else{
                                                            gagner = SDL_LoadBMP("gagner.bmp");

                                                            SDL_BlitSurface(gagner, NULL, ecran, &positionmenu);
                                                            texte = SDL_LoadBMP("JOUEUR1.bmp");
                                                            SDL_BlitSurface(texte, NULL, ecran, &positionFond);
                                                            SDL_Flip(ecran);

                                                        }
                                             }

                                                }
                                            }
                                            else{
                                        if(merelle[i][j]==0){
                                            c_f.casex=i;
                                            c_f.casey=j;
                                            if(move_ci_cf(voisinnage,c_i,c_f)==1){
                                                move(merelle,c_i,c_f,1);
                                                affiche(merelle,ecran,positionFond);
                                                if(Test_moulin(merelle,1,c_f)!=0){
                                                    c_i.casex=9;
                                                    c_i.casey=9;

}
                                                else{

                                                    c_i.casex=9;
                                                    c_i.casey=9;
                                                    c_f.casex=9;
                                                    c_f.casey=9;

                                                    if(score1(merelle)>2 && score2(merelle)>2) {

                                         ct=0;




                                             r=0;s=0;
for(u=0;u<7;u++){
         for(v=0;v<7;v++){

                    if(merelle[u][v]==0){
                    e.casex=u;
                    e.casey=v;
                    merelle[u][v]=-1;
                    if (Test_moulin(merelle,-1,e)==1){
                            ligne=code(u,v);
                            for(k=0;k<4;k++){
                                for(m=0;m<7;m++){
                                     for(n=0;n<7;n++){
                                         if(code(m,n)==voisinnage[ligne][k]){
                                             e.casex=m;e.casey=n;
                                            if(merelle[m][n]==-1 && Test_moulin(merelle,-1,e)==0){


                            t2[s].casex=u;
                            t2[s].casey=v;
                             t1[r].casex=m;
                               t1[r].casey=n;
                               r++;s++;
                                            }

                                         }
                                     }
                                }
                            }
                    }
     merelle[u][v]=0;           }


                             }


  }
if(r!=0){
                                    srand(time(NULL));
                                                   rs=rand()%r+0;
                                                cm_i.casex=t1[rs].casex;
                                                 cm_i.casey=t1[rs].casey;
                                                 cm_f.casex=t2[rs].casex;
                                                 cm_f.casey=t2[rs].casey;}
                                                 else{

                           r=0; s=0;ct=0;int l=0;
for(u=0;u<7;u++){
         for(v=0;v<7;v++){

                    if(merelle[u][v]==0){
                    e.casex=u;
                    e.casey=v;
                    merelle[u][v]=1;
                    if (Test_moulin(merelle,1,e)==1){
                            ligne=code(u,v);
                            for(k=0;k<4;k++){
                                for(m=0;m<7;m++){
                                     for(n=0;n<7;n++){
                                         if(code(m,n)==voisinnage[ligne][k]){

                                            if(merelle[m][n]==1){
                                                    ct++;}
                                            if(merelle[m][n]==-1){
                                                l++;}







                                         }
                                     }
                                }
                            }

               if(ct!=0 && l!=0){
                            t2[s].casex=u;
                            t2[s].casey=v;
                             t1[r].casex=m;
                               t1[r].casey=n;
                               r++;s++;}


                             }

              merelle[u][v]=0 ;     }
                    }}
if(r!=0){

                                    srand(time(NULL));
                                                   rs=rand()%r+0;
                                                cm_i.casex=t1[rs].casex;
                                                 cm_i.casey=t1[rs].casey;
                                                 cm_f.casex=t2[rs].casex;
                                                 cm_f.casey=t2[rs].casey;}
                                                 else{


                    r=0;s=0;
for(u=0;u<7;u++){
         for(v=0;v<7;v++){

                    if(merelle[u][v]==-1){
                    e.casex=u;
                    e.casey=v;
                    if (Test_moulin(merelle,-1,e)==1){
                            ligne=code(u,v);
                            for(k=0;k<4;k++){
                                for(m=0;m<7;m++){
                                     for(n=0;n<7;n++){
                                         if(code(m,n)==voisinnage[ligne][k]){

                                            if(merelle[m][n]==0){


                            t2[s].casex=m;
                            t2[s].casey=n;
                             t1[r].casex=u;
                               t1[r].casey=v;
                               r++;s++;
                                            }

                                         }
                                     }
                                }
                            }
                    }
              }


                             }




   }      if(r!=0){    srand(time(NULL));
                                                   rs=rand()%r+0;
                                                cm_i.casex=t1[rs].casex;
                                                 cm_i.casey=t1[rs].casey;
                                                 cm_f.casex=t2[rs].casex;
                                                 cm_f.casey=t2[rs].casey;
   }
    else {                       r=0;s=0;
for(u=0;u<7;u++){
         for(v=0;v<7;v++){

                    if(merelle[u][v]==-1){
                    e.casex=u;
                    e.casey=v;

                            ligne=code(u,v);
                            for(k=0;k<4;k++){
                                for(m=0;m<7;m++){
                                     for(n=0;n<7;n++){
                                         if(code(m,n)==voisinnage[ligne][k]){

                                            if(merelle[m][n]==0 ){


                            t2[s].casex=m;
                            t2[s].casey=n;
                             t1[r].casex=u;
                               t1[r].casey=v;
                               r++;s++;
                                            }

                                         }
                                     }
                                }
                            }

              }


                             }


  }
   srand(time(NULL));
                                                   rs=rand()%r+0;
                                                    cm_i.casex=t1[rs].casex;
                                                 cm_i.casey=t1[rs].casey;
                                                 cm_f.casex=t2[rs].casex;
                                                 cm_f.casey=t2[rs].casey;}

                                                 }

                                                 }


                                                move(merelle,cm_i,cm_f,-1);
                                                affiche(merelle,ecran,positionFond);
                                                if(Test_moulin(merelle,-1,cm_f)==0){
                                                    cm_f.casex=9;
                                                    cm_f.casey=9;
                                                    cm_i.casex=9;
                                                    cm_i.casey=9;

                                                }
                                                else{


                                                      rs=0;Case t3[9];
   for(u=0;u<7;u++){
         for(v=0;v<7;v++){
             if (merelle[u][v]==1){
                 t3[rs].casex=u;
                 t3[rs].casey=v;
                rs++;
             }}}
             srand(time(NULL));
             do {
              r=rand()%rs+0;}
              while(Test_moulin(merelle,1,t3[r])!=0);


                                                    supprimer(merelle,t3[r],-1);
                                                    affiche(merelle,ecran,positionFond);
                                                    cm_i.casex=9;
                                                    cm_i.casey=9;
                                                    cm_f.casex=9;
                                                    cm_f.casey=9;
                                                    if(score1(merelle)>2 && score2(merelle)>2){


                                                                      texte = SDL_LoadBMP("JOUEUR1.bmp");
                    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
                    SDL_Flip(ecran);

                                                    }
                                                    else{
                                                        if(score1(merelle)<2){
                                                            gagner = SDL_LoadBMP("perdre.bmp");

                                                            SDL_BlitSurface(gagner, NULL, ecran, &positionmenu);
                                                            texte = SDL_LoadBMP("JOUEUR1.bmp");
                                                            SDL_BlitSurface(texte, NULL, ecran, &positionFond);
                                                            SDL_Flip(ecran);

                                                        }
                                                        else{
                                                            gagner = SDL_LoadBMP("gagner.bmp");

                                                            SDL_BlitSurface(gagner, NULL, ecran, &positionmenu);
                                                            texte = SDL_LoadBMP("JOUEUR1.bmp");
                                                            SDL_BlitSurface(texte, NULL, ecran, &positionFond);
                                                            SDL_Flip(ecran);

                                                        }
                                             }





                                                    }



                                                    }
                                            else{
                                                        if(score1(merelle)<2){
                                                            gagner = SDL_LoadBMP("perdre.bmp");

                                                            SDL_BlitSurface(gagner, NULL, ecran, &positionmenu);
                                                            texte = SDL_LoadBMP("JOUEUR1.bmp");
                                                            SDL_BlitSurface(texte, NULL, ecran, &positionFond);
                                                            SDL_Flip(ecran);

                                                        }
                                                        else{
                                                            gagner = SDL_LoadBMP("gagner.bmp");

                                                            SDL_BlitSurface(gagner, NULL, ecran, &positionmenu);
                                                            texte = SDL_LoadBMP("JOUEUR1.bmp");
                                                            SDL_BlitSurface(texte, NULL, ecran, &positionFond);
                                                            SDL_Flip(ecran);

                                                        }
                                                    }

                                                }
                                            }
                                        }
                                    }
                                            }


                    		 	}

                           }

					}








       	}

        if (  (event.button.y >= 552 && event.button.x >=384))
            goto loop;


            break;


    }
    //Affichage:


 }
 break;

    }









   }

         break;                       }



                           }
    }
    }
 break;
  }

    }
    break;
     }
    else
    { if (  (event.button.y >= 282 && event.button.y<332 && event.button.x <204))

           { fondnoir = SDL_LoadBMP("fondnoir.bmp");
            SDL_BlitSurface(fondnoir, NULL, ecran, &positionfondnoir);

           instructions = SDL_LoadBMP("instructions.bmp");
           SDL_BlitSurface(instructions, NULL, ecran, &positioninstructions);
           SDL_Flip(ecran); /* Mise à jour de l'écran avec sa nouvelle couleur */

            while (continuer)
 {
    SDL_WaitEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_MOUSEBUTTONUP:
             if (  (event.button.y >=492 && event.button.y<541 && event.button.x >=396))
             {menu = SDL_LoadBMP("MENU1.bmp");
              SDL_BlitSurface(menu, NULL, ecran, &positionmenu);
              SDL_Flip(ecran);

             goto loop;
             }break;

           }}}
           else {
            if (  (event.button.y >= 332 && event.button.y<382 && event.button.x <204))
            {
                SDL_Quit();
                return EXIT_SUCCESS;
            }
           }




      }
      break;
    }

    SDL_Flip(ecran);
 }




    SDL_Quit();


    return EXIT_SUCCESS; // Fermeture du programme

}



///fonction  test de validité de mouvement de la case initiale vers celle  finale qui verifie si la cases finale est voisine a celle initiale
int move_ci_cf(int voisinnage[24][4], Case c_i,Case c_f)
{
	int test=0,ligne_i,ligne_f,k;
	ligne_i=code(c_i.casex,c_i.casey);
	ligne_f=code(c_f.casex,c_f.casey);
	for(k=0;k<4;k++){
		if(voisinnage[ligne_i][k]==ligne_f){
			test=1;                     //elle est voisine
			return test;
		}
	}
	return test;
}

// FONCTION QUI CALCULE LE NOMBRE DE PIONS DU JOUEUR1 ET QUI REPRESENTE AUSSI SON SCORE

int score1(int merelle[7][7])
{

	int score1=0;
	int i,j;
	for(i=0;i<7;i++){
		for(j=0;j<7;j++){
			if(merelle[i][j]==1)
				score1++;
		}
	}
	return score1;
}


// FONCTION QUI CALCULE LE NOMBRE DE PIONS DU JOUEUR2 ET QUI REPRESENTE AUSSI SON SCORE


int score2(int merelle[7][7])
{
	int score2=0;
	int i,j;
	for(i=0;i<7;i++){
		for(j=0;j<7;j++){
			if(merelle[i][j]==-1)
				score2++;
		}
	}
	return score2;
}

///// initialiser la matrice



void initialiser(int (*merelle)[7])
{
	int i ,k;
	for (i=0; i<7; i++){ 								// case nom utilisable contient 8
		for (k=0; k<7; k++){
			merelle[i][k] =  8;
		}
	}



	merelle[0][0]=0;
	merelle[3][0]=0;				// les cases contenant 0 sont vides du moulin  et peuvent etre remplises
	merelle[6][0]=0;
	merelle[0][6]=0;
	merelle[3][6]=0;
	merelle[6][6]=0;
	merelle[0][3]=0;
	merelle[6][3]=0;
	//

	merelle[1][1]=0;
	merelle[3][1]=0;
	merelle[5][1]=0;
	merelle[1][5]=0;
	merelle[3][5]=0;
	merelle[5][5]=0;
	merelle[1][3]=0;
	merelle[5][3]=0;
	//
	merelle[2][2]=0;
	merelle[3][2]=0;
	merelle[4][2]=0;
	merelle[2][4]=0;
	merelle[3][4]=0;
	merelle[4][4]=0;
	merelle[2][3]=0;
	merelle[4][3]=0;


}




//initialisation de la matrice voisinage



// fonction qui remplie la matrice voisinnage qui definie les positions (par ordre horizontale) des  cases voisines de chaque case  pouvant contenir un pion ..
// marquée au debut de l'initialisation par * pourrant etre remplie

void case_voisin(int (*voisin)[4])
{
	voisin[0][0]=1;
	voisin[0][1]=9;
	voisin[0][2]=24;
	voisin[0][3]=24;

	voisin[1][0]=0;
	voisin[1][1]=2;
	voisin[1][2]=4;
	voisin[1][3]=24;

	voisin[2][0]=1;
	voisin[2][1]=14;
	voisin[2][2]=24;
	voisin[2][3]=24;

	voisin[3][0]=4;
	voisin[3][1]=10;
	voisin[3][2]=24;
	voisin[3][3]=24;

	voisin[4][0]=1;
	voisin[4][1]=3;
	voisin[4][2]=5;
	voisin[4][3]=7;

	voisin[5][0]=4;
	voisin[5][1]=13;
	voisin[5][2]=24;
	voisin[5][3]=24;

	voisin[6][0]=7;
	voisin[6][1]=11;
	voisin[6][2]=24;
	voisin[6][3]=24;

	voisin[7][0]=4;
	voisin[7][1]=6;
	voisin[7][2]=8;
	voisin[7][3]=24;

	voisin[8][0]=7;
	voisin[8][1]=12;
	voisin[8][2]=24;
	voisin[8][3]=24;

	voisin[9][0]=0;
	voisin[9][1]=21;
	voisin[9][2]=10;
	voisin[9][3]=24;

	voisin[10][0]=3;
	voisin[10][1]=9;
	voisin[10][2]=18;
	voisin[10][3]=11;

	voisin[11][0]=6;
	voisin[11][1]=15;
	voisin[11][2]=10;
	voisin[11][3]=24;

	voisin[12][0]=8;
	voisin[12][1]=17;
	voisin[12][2]=13;
	voisin[12][3]=24;

	voisin[13][0]=12;
	voisin[13][1]=5;
	voisin[13][2]=20;
	voisin[13][3]=14;

	voisin[14][0]=2;
	voisin[14][1]=13;
	voisin[14][2]=23;
	voisin[14][3]=24;

	voisin[15][0]=11;
	voisin[15][1]=16;
	voisin[15][2]=24;
	voisin[15][3]=24;

	voisin[16][0]=15;
	voisin[16][1]=17;
	voisin[16][2]=19;
	voisin[16][3]=24;

	voisin[17][0]=12;
	voisin[17][1]=16;
	voisin[17][2]=24;
	voisin[17][3]=24;

	voisin[18][0]=10;
	voisin[18][1]=19;
	voisin[18][2]=24;
	voisin[18][3]=24;

	voisin[19][0]=16;
	voisin[19][1]=18;
	voisin[19][2]=20;
	voisin[19][3]=22;

	voisin[20][0]=13;
	voisin[20][1]=19;
	voisin[20][2]=24;
	voisin[20][3]=24;

	voisin[21][0]=9;
	voisin[21][1]=22;
	voisin[21][2]=24;
	voisin[21][3]=24;

	voisin[22][0]=19;
	voisin[22][1]=21;
	voisin[22][2]=23;
	voisin[22][3]=24;

	voisin[23][0]=22;
	voisin[23][1]=14;
	voisin[23][2]=24;
	voisin[23][3]=24;


}

//fonction codage de case en matrice merelle -> equivalent en matrice environ
int code(int i,int j)
{
	int merelle[7][7];
	int l ,k;
	for (l=0; l<7; l++){ 								// case nom utilisable contient 8
		for (k=0; k<7; k++){
			merelle[l][k] =  8;
		}
	}



	merelle[0][0]=0;
	merelle[3][0]=0;				// les cases contenant 0 sont vides du moulin  et peuvent etre remplises
	merelle[6][0]=0;
	merelle[0][6]=0;
	merelle[3][6]=0;
	merelle[6][6]=0;
	merelle[0][3]=0;
	merelle[6][3]=0;
	//
	merelle[1][1]=0;
	merelle[3][1]=0;
	merelle[5][1]=0;
	merelle[1][5]=0;
	merelle[3][5]=0;
	merelle[5][5]=0;
	merelle[1][3]=0;
	merelle[5][3]=0;
	//
	merelle[2][2]=0;
	merelle[3][2]=0;
	merelle[4][2]=0;
	merelle[2][4]=0;
	merelle[3][4]=0;
	merelle[4][4]=0;
	merelle[2][3]=0;
	merelle[4][3]=0;

	int conteur=-1;





	for (l=0; l<7; l++){
		for (k=0; k<7; k++){
			if((merelle[l][k]!=8)){
				conteur++;
				if((l==i)&&(k==j)){
					return conteur;
				}
			}

		}
	}
}


	//  FONCTION POUR tester si un moulin existe en faveur du joueur en cour j_c la fonction retourne 1 si il existe un moulin pour j_c et 0 sinn

int Test_moulin(int merelle[7][7],int j_c,Case c)
{

	int test=0;

	switch(c.casex){
		case 0 :
			if((merelle[0][0]==j_c)&&(merelle[0][3]==j_c)&&(merelle[0][6]==j_c)&&(((c.casex==0)&&(c.casey==0))||((c.casex==0)&&(c.casey==3))||((c.casex==0)&&(c.casey==6)))){
				test++;
			}
			break;
		case 1 :
			if((merelle[1][1]==j_c)&&(merelle[1][3]==j_c)&&(merelle[1][5]==j_c)&&(((c.casex==1)&&(c.casey==1))||((c.casex==1)&&(c.casey==3))||((c.casex==1)&&(c.casey==5)))){
				test++;
			}
			break;

		case 3 :
			if(((merelle[3][0]==j_c)&&(merelle[3][1]==j_c)&&(merelle[3][2]==j_c)&&(((c.casex==3)&&(c.casey==0))||((c.casex==3)&&(c.casey==1))||((c.casex==3)&&(c.casey==2))))||((merelle[3][4]==j_c)&&(merelle[3][5]==j_c)&&(merelle[3][6]==j_c)&&(((c.casex==3)&&(c.casey==4))||((c.casex==3)&&(c.casey==5))||((c.casex==3)&&(c.casey==6))))){
				test++;
			}
			break;
		case 2 :
			if((merelle[2][2]==j_c)&&(merelle[2][3]==j_c)&&(merelle[2][4]==j_c)&&(((c.casex==2)&&(c.casey==2))||((c.casex==2)&&(c.casey==3))||((c.casex==2)&&(c.casey==4)))){
				test++;

			}
			break;
		case 4 :
			if((merelle[4][2]==j_c)&&(merelle[4][3]==j_c)&&(merelle[4][4]==j_c)&&(((c.casex==4)&&(c.casey==2))||((c.casex==4)&&(c.casey==3))||((c.casex==4)&&(c.casey==4)))){
				test++;
			}
			break;
		case 5 :
			if((merelle[5][1]==j_c)&&(merelle[5][3]==j_c)&&(merelle[5][5]==j_c)&&(((c.casex==5)&&(c.casey==1))||((c.casex==5)&&(c.casey==3))||((c.casex==5)&&(c.casey==5)))){
				test++;
			}
			break;
		case 6 :
			if((merelle[6][0]==j_c)&&(merelle[6][3]==j_c)&&(merelle[6][6]==j_c)&&(((c.casex==6)&&(c.casey==0))||((c.casex==6)&&(c.casey==3))||((c.casex==6)||(c.casey==6)))){
				test++;
			}
			break;
		default:
			break;

	}

	switch(c.casey){
		case 0 :
			if((merelle[0][0]==j_c)&&(merelle[3][0]==j_c)&&(merelle[6][0]==j_c)&&(((c.casex==0)&&(c.casey==0))||((c.casex==3)&&(c.casey==0))||((c.casex==6)||(c.casey==0))))
				test++;
			break;
		case 1 :
			if((merelle[1][1]==j_c)&&(merelle[3][1]==j_c)&&(merelle[5][1]==j_c)&&(((c.casex==1)&&(c.casey==1))||((c.casex==3)&&(c.casey==1))||((c.casex==5)||(c.casey==1))))
				test++;
			break;
		case 3 :
			if(((merelle[0][3]==j_c)&&(merelle[1][3]==j_c)&&(merelle[2][3]==j_c)&&(((c.casex==0)&&(c.casey==3))||((c.casex==1)&&(c.casey==3))||((c.casex==2)||(c.casey==3))))||((merelle[4][3]==j_c)&&(merelle[5][3]==j_c)&&(merelle[6][3]==j_c)&&(((c.casex==4)&&(c.casey==3))||((c.casex==5)&&(c.casey==3))||((c.casex==6)||(c.casey==3)))))
				test++;
			break;
		case 2 :
			if((merelle[2][2]==j_c)&&(merelle[3][2]==j_c)&&(merelle[4][2]==j_c)&&(((c.casex==2)&&(c.casey==2))||((c.casex==3)&&(c.casey==2))||((c.casex==4)||(c.casey==2))))
				test++;
			break;

		case 4 :
			if((merelle[2][4]==j_c)&&(merelle[3][4]==j_c)&&(merelle[4][4]==j_c)&&(((c.casex=2)&&(c.casey==4))||((c.casex==3)&&(c.casey==4))||((c.casex==4)||(c.casey==4))))
				test++;
			break;
		case 5 :
			if((merelle[1][5]==j_c)&&(merelle[3][5]==j_c)&&(merelle[5][5]==j_c)&&(((c.casex==1)&&(c.casey==5))||((c.casex==3)&&(c.casey==5))||((c.casex==5)||(c.casey==5))))
				test++;
			break;
		case 6 :
			if((merelle[0][6]==j_c)&&(merelle[3][6]==j_c)&&(merelle[6][6]==j_c)&&(((c.casex==0)&&(c.casey==6))||((c.casex==3)&&(c.casey==6))||((c.casex==6)||(c.casey==6))))
				test++;
			break;
		default:
			break;

		}

	return test;

}


void affiche(int merelle[7][7],SDL_Surface* ecran,SDL_Rect positionFond)
{
    int i, j;
    SDL_Rect positionCase={0,0,0,0};

    imageDeFond = SDL_LoadBMP("moulin.bmp");
    pionrouge1 = SDL_LoadBMP("pionrouge1.bmp");
    pionblanc1 = SDL_LoadBMP("pionblanc1.bmp");
    vide = SDL_LoadBMP("vide.bmp");


    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 7; j++)
            {
                positionCase.x=i*450/7 +70;
                positionCase.y=j*450/7 +70;

            switch(merelle[i][j])
            {

                case 1:
                    SDL_BlitSurface(pionrouge1, NULL, ecran, &positionCase);
                    break;

                case -1:
                    SDL_BlitSurface(pionblanc1, NULL, ecran, &positionCase);

                    break;

                case 0:
                    SDL_BlitSurface(vide, NULL, ecran, &positionCase);
                    break;

                default:
                    break;
            }
        }
    }
    SDL_Flip(ecran);
}






// FONCTION QUI EFFECTUE LE MOUVEMENT DU PION DU JOUEUR EN COURS

void move(int (*merelle)[7],Case c_i,Case c_f,int j_c )
{
	merelle[c_i.casex][c_i.casey]=0;
	merelle[c_f.casex][c_f.casey]=j_c;

}

// fonction qui suprimme un pion
void supprimer(int (*merelle)[7],Case c,int j_c)
{
	if((merelle[c.casex][c.casey]!=j_c)&&(merelle[c.casex][c.casey]!=0)){
		merelle[c.casex][c.casey]=0;
	}}

	//cette fonction supprime les pions posées à gauche et à droite du plateau du jeu à chaque fois lors de la pose
void supprimerespace(SDL_Surface *ecran,int comteur,int j_c)
{  SDL_Surface *espacejaune1=NULL;
    SDL_Surface *espaceblue1=NULL;


      SDL_Rect pstjn1,pstjn2,pstjn3,pstjn4,pstjn5,pstjn6,pstjn7,pstjn8,pstjn9;
    SDL_Rect pstbl1,pstbl2,pstbl3,pstbl4,pstbl5,pstbl6,pstbl7,pstbl8,pstbl9;
   pstjn1.x=0;
    pstjn1.y=0;
   pstbl1.x=550;
   pstbl1.y=0;
   pstjn2.x=0;
    pstjn2.y=50;
    pstbl2.x=550;
   pstbl2.y=50;
    pstjn3.x=0;
pstjn3.y=100;
    pstbl3.x=550;
pstbl3.y=100;
    pstjn4.x=0;
   pstjn4.y=150;
    pstbl4.x=550;
    pstbl4.y=150;
    pstjn5.x=0;
    pstjn5.y=200;
    pstbl5.x=550;
    pstbl5.y=200;
    pstjn6.x=0;
    pstjn6.y=250;
    pstbl6.x=550;
    pstbl6.y=250;
    pstjn7.x=0;
   pstjn7.y=300;
    pstbl7.x=550;
    pstbl7.y=300;
    pstjn8.x=0;
   pstjn8.y=350;
    pstbl8.x=550;
    pstbl8.y=350;
    pstjn9.x=0;
    pstjn9.y=400;
    pstbl9.x=550;
    pstbl9.y=400;

        espacejaune1=SDL_LoadBMP("jn1.bmp");
        espaceblue1=SDL_LoadBMP("bl1.bmp");



    if(j_c==1)  {
     switch(comteur)
            {
            case 1:
                SDL_BlitSurface(espacejaune1, NULL, ecran, &pstjn1);
                break;
                case 2:
                SDL_BlitSurface(espacejaune1, NULL, ecran, &pstjn2);
                 break;
                case 3:
                SDL_BlitSurface(espacejaune1, NULL, ecran, &pstjn3);
                break;
                case 4:
                SDL_BlitSurface(espacejaune1, NULL, ecran, &pstjn4);
                 break;
                case 5:
                SDL_BlitSurface(espacejaune1, NULL, ecran, &pstjn5);
                 break;
                case 6:
                SDL_BlitSurface(espacejaune1, NULL, ecran, &pstjn6);
                 break;
                case 7:
                SDL_BlitSurface(espacejaune1, NULL, ecran, &pstjn7);
                 break;
                case 8:
                SDL_BlitSurface(espacejaune1, NULL, ecran, &pstjn8);
                 break;
                case 9:
                SDL_BlitSurface(espacejaune1, NULL, ecran, &pstjn9);
                 break;
                default:
                break;
            }

 }
 else { switch(comteur)
            {
            case 1:
                SDL_BlitSurface(espaceblue1, NULL, ecran, &pstbl1);
                break;
                case 2:
                SDL_BlitSurface(espaceblue1, NULL, ecran, &pstbl2);
                 break;
                case 3:
                SDL_BlitSurface(espaceblue1, NULL, ecran, &pstbl3);
                break;
                case 4:
                SDL_BlitSurface(espaceblue1, NULL, ecran, &pstbl4);
                 break;
                case 5:
                SDL_BlitSurface(espaceblue1, NULL, ecran, &pstbl5);
                 break;
                case 6:
                SDL_BlitSurface(espaceblue1, NULL, ecran, &pstbl6);
                 break;
                case 7:
                SDL_BlitSurface(espaceblue1, NULL, ecran, &pstbl7);
                 break;
                case 8:
                SDL_BlitSurface(espaceblue1, NULL, ecran, &pstbl8);
                 break;
                case 9:
                SDL_BlitSurface(espaceblue1, NULL, ecran, &pstbl9);
                 break;
                default:
                break;

}
}
           SDL_Flip(ecran);}
