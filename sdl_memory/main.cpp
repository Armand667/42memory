#include <exception>
#include <string>
#include <iostream>
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LARGEUR_FENETRE (800)
#define HAUTEUR_FENETRE (600)


void SDL_ExitWithError(const char *message);
void ConfigBouton(int x, int y, int w, int h, SDL_Renderer *rendu);
int verification(int case1, int case2, int case3, int case4, int verite);

int main( int argc, char ** argv)//inclure argc et argv quand on fait du sdl.
{
    //dans le terminale
    SDL_version nb;
    SDL_VERSION(&nb);
    printf("bienvenue sur la SDL %d.%d.%d !\n", nb.major, nb.minor, nb.patch);

    //lancement SDL
    SDL_Window *fenetre = NULL;//créer une fenetre
    SDL_Renderer *rendu = NULL;//pour créer un rendu

    if(SDL_Init(SDL_INIT_VIDEO)!= 0)//prend un Flag, type SDL_INIT_OPTION. si SDL renvoie pasla bonne valeur.
    {
        SDL_ExitWithError("initialisation SDL");//SDL_log prend un texte en parametre.
        //ce texte ici prend une chaine de caractere aussi %s qui prend comme valeur : SDL_GetError() renvoie l'erreur qui est effective.
    }

    //Création fênetre
    fenetre = SDL_CreateWindow("Le jeu de memoire", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, LARGEUR_FENETRE, 656, 0);
    //le pointeur window prend en valeur SDL_Create Window
    //SDL_CreateWindow prend en valeur ("Le nom", position x pouvant etre un Flag puis y haut à gauche, largeur, hauteur, mode affichage)
    if(fenetre == NULL)
    {
        SDL_ExitWithError("Création fenetre echouee");
    }

    //création de rendu
    rendu = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_SOFTWARE);// prend le pointeur de la fentre en parametre, -1 et pour le rendu
    if (rendu == NULL)
    {
        SDL_ExitWithError("Creation rendu echouee");
    }
    if (SDL_RenderClear(rendu) != 0)//efface les rendu des fenetres.

    {
        SDL_ExitWithError("Effacement rendu echoue");
    }

    //programme
    //set couleur à gris
    if(SDL_SetRenderDrawColor(rendu, 236, 236, 236, SDL_ALPHA_OPAQUE)!=0)//COUELUR GRIS DES TOUCHES
    {
        SDL_ExitWithError("Impossible de changer la couleur du rendu.");
    }

    //crée les 4 boutons
    ConfigBouton(5, 5, ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);//fonction qui crée un rectangle avec comme option coordonnées de création x/y largeur/hauteur et rendu.

    ConfigBouton(((LARGEUR_FENETRE/2)+5), ((HAUTEUR_FENETRE/2)+5), ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);

    ConfigBouton(5, ((HAUTEUR_FENETRE/2)+5), ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);

    ConfigBouton(((LARGEUR_FENETRE/2)+5), 5, ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);//case 2

    SDL_RenderPresent(rendu);//affiche les 4 boutons
    SDL_Delay(5000);//affiche les 4 boutons gris durant 5secondes
    //apres 5 secondes

    //couleur bleue d'une case
    int boutonbleue = 15;//indique quel bouton est bleue
    srand( time( NULL ) );//importe le module aléatoire
    int aleatoire = rand()%4;
    int aleatoire2 = 0;//crée un deuxieme nombre aléatoire entre 0 et 2 pour définir la deuxieme case blue a allumer

    //en fonction du résultat du nombre aléatoire, une case différente va devenir bleue
    if (aleatoire == 0)//si le modulo du nombre aléatoire généré est 0 alors
    {
        if(SDL_SetRenderDrawColor(rendu, 96, 191, 236, SDL_ALPHA_OPAQUE)!=0)//COUELUR BLEUE DES TOUCHES
        {
            SDL_ExitWithError("Impossible de changer la couleur du rendu.");
        }
        ConfigBouton(5, 5, ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);
        printf("C'est 0");
        boutonbleue = 0;

    }
    else if (aleatoire == 1)//si le modulo du nombre aléatoire généré est 1 alors
    {
        if(SDL_SetRenderDrawColor(rendu, 96, 191, 236, SDL_ALPHA_OPAQUE)!=0)//COUELUR BLEUE DES TOUCHES
        {
            SDL_ExitWithError("Impossible de changer la couleur du rendu.");
        }
        ConfigBouton(((LARGEUR_FENETRE/2)+5), 5, ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);
        printf("C'est 1");
        boutonbleue = 1;

    }
    else if (aleatoire == 2)//si le modulo du nombre aléatoire généré est 2 alors
    {
        if(SDL_SetRenderDrawColor(rendu, 96, 191, 236, SDL_ALPHA_OPAQUE)!=0)//COUELUR BLEUE DES TOUCHES
        {
            SDL_ExitWithError("Impossible de changer la couleur du rendu.");
        }
        ConfigBouton(5, ((HAUTEUR_FENETRE/2)+5), ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);
        printf("C'est 2");
        boutonbleue = 2;

    }
    else if (aleatoire == 3)//si le modulo du nombre aléatoire généré est 3 alors
    {
        if(SDL_SetRenderDrawColor(rendu, 96, 191, 236, SDL_ALPHA_OPAQUE)!=0)//COUELUR BLEUE DES TOUCHES
        {
            SDL_ExitWithError("Impossible de changer la couleur du rendu.");
        }
        ConfigBouton(((LARGEUR_FENETRE/2)+5), ((HAUTEUR_FENETRE/2)+5), ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);
        printf("C'est 3");
        boutonbleue = 3;

    }

    SDL_RenderPresent(rendu);//pour afficher la case bleue
    SDL_Delay(1000);//pendnat une seconde

    int verite = 0;

    //re initialise la couleur à gris
    if(SDL_SetRenderDrawColor(rendu, 236, 236, 236, SDL_ALPHA_OPAQUE)!=0)//COUELUR GRIS DES TOUCHES
    {
        SDL_ExitWithError("Impossible de changer la couleur du rendu.");
    }
    //et remet la case bleue en gris.
    if (boutonbleue == 0)// si la case 0 est bleu alors
    {
        ConfigBouton(5, 5, ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);//case 0 redeviens grise
        if(SDL_SetRenderDrawColor(rendu, 96, 191, 236, SDL_ALPHA_OPAQUE)!=0)//COUELUR BLEUE DES TOUCHES
        {
            SDL_ExitWithError("Impossible de changer la couleur du rendu.");
        }
        srand(time( NULL ));// rappel la fonction time pour définir la deuxieme case à allumer
        aleatoire2 = rand()%3;// créeun nouveau nombre aléatoire
        if (aleatoire2 == 0)//si le nouveau nombre aléatoire est 0
        {
            ConfigBouton(((LARGEUR_FENETRE/2)+5), 5, ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);// alors case 2 devient bleue
            SDL_RenderPresent(rendu);//on affiche case 2 bleue est case 1 gris
            SDL_Delay(1000);//pendant 1 secondes
            if(SDL_SetRenderDrawColor(rendu, 236, 236, 236, SDL_ALPHA_OPAQUE)!=0)//COUELUR GRIS DES TOUCHES
            {
                SDL_ExitWithError("Impossible de changer la couleur du rendu.");
            }
            ConfigBouton(((LARGEUR_FENETRE/2)+5), 5, ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);//case 2 redeviens gris
            SDL_RenderPresent(rendu);// on affiche
            verite = 12;
        }
        else if(aleatoire2 == 1)
        {
            ConfigBouton(5, ((HAUTEUR_FENETRE/2)+5), ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);
            SDL_RenderPresent(rendu);
            SDL_Delay(1000);
            if(SDL_SetRenderDrawColor(rendu, 236, 236, 236, SDL_ALPHA_OPAQUE)!=0)//COUELUR GRIS DES TOUCHES
            {
                SDL_ExitWithError("Impossible de changer la couleur du rendu.");
            }
            ConfigBouton(5, ((HAUTEUR_FENETRE/2)+5), ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);
            SDL_RenderPresent(rendu);
            verite = 13;
        }
        else if (aleatoire2 == 2)
        {
            ConfigBouton(((LARGEUR_FENETRE/2)+5), ((HAUTEUR_FENETRE/2)+5), ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);
            SDL_RenderPresent(rendu);
            SDL_Delay(1000);
            if(SDL_SetRenderDrawColor(rendu, 236, 236, 236, SDL_ALPHA_OPAQUE)!=0)//COUELUR GRIS DES TOUCHES
            {
                SDL_ExitWithError("Impossible de changer la couleur du rendu.");
            }
            ConfigBouton(((LARGEUR_FENETRE/2)+5), ((HAUTEUR_FENETRE/2)+5), ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);
            SDL_RenderPresent(rendu);
            verite = 14;
        }
        /*SDL_RenderPresent(rendu);
        SDL_Delay(1000);*/
    }
    else if (boutonbleue == 1)
    {
        ConfigBouton(((LARGEUR_FENETRE/2)+5), 5, ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);//case 1 redeviens grise
        if(SDL_SetRenderDrawColor(rendu, 96, 191, 236, SDL_ALPHA_OPAQUE)!=0)//COUELUR BLEUE DES TOUCHES
        {
            SDL_ExitWithError("Impossible de changer la couleur du rendu.");
        }
        srand(time( NULL ));// rappel la fonction time pour définir la deuxieme case à allumer
        aleatoire2 = rand()%3;// créeun nouveau nombre aléatoire
        if (aleatoire2 == 0)//si le nouveau nombre aléatoire est 0
        {
            ConfigBouton(5, 5, ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);// alors case 0 devient bleue
            SDL_RenderPresent(rendu);//on affiche case 2 bleue est case 1 gris
            SDL_Delay(1000);//pendant 1 secondes
            if(SDL_SetRenderDrawColor(rendu, 236, 236, 236, SDL_ALPHA_OPAQUE)!=0)//COUELUR GRIS DES TOUCHES
            {
                SDL_ExitWithError("Impossible de changer la couleur du rendu.");
            }
            ConfigBouton(5, 5, ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);//case 0 redeviens gris
            SDL_RenderPresent(rendu);// on affiche
            verite = 21;
        }
        else if(aleatoire2 == 1)
        {
            ConfigBouton(5, ((HAUTEUR_FENETRE/2)+5), ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);
            SDL_RenderPresent(rendu);
            SDL_Delay(1000);
            if(SDL_SetRenderDrawColor(rendu, 236, 236, 236, SDL_ALPHA_OPAQUE)!=0)//COUELUR GRIS DES TOUCHES
            {
                SDL_ExitWithError("Impossible de changer la couleur du rendu.");
            }
            ConfigBouton(5, ((HAUTEUR_FENETRE/2)+5), ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);
            SDL_RenderPresent(rendu);
            verite = 23;
        }
        else if (aleatoire2 == 2)
        {
            ConfigBouton(((LARGEUR_FENETRE/2)+5), ((HAUTEUR_FENETRE/2)+5), ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);
            SDL_RenderPresent(rendu);
            SDL_Delay(1000);
            if(SDL_SetRenderDrawColor(rendu, 236, 236, 236, SDL_ALPHA_OPAQUE)!=0)//COUELUR GRIS DES TOUCHES
            {
                SDL_ExitWithError("Impossible de changer la couleur du rendu.");
            }
            ConfigBouton(((LARGEUR_FENETRE/2)+5), ((HAUTEUR_FENETRE/2)+5), ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);
            SDL_RenderPresent(rendu);
            verite = 24;
        }
        /*SDL_RenderPresent(rendu);
        SDL_Delay(1000);*/

    }
    else if (boutonbleue == 2)
    {
        ConfigBouton(5, ((HAUTEUR_FENETRE/2)+5), ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);//case 1 redeviens grise
        if(SDL_SetRenderDrawColor(rendu, 96, 191, 236, SDL_ALPHA_OPAQUE)!=0)//COUELUR BLEUE DES TOUCHES
        {
            SDL_ExitWithError("Impossible de changer la couleur du rendu.");
        }
        srand(time( NULL ));// rappel la fonction time pour définir la deuxieme case à allumer
        aleatoire2 = rand()%3;// créeun nouveau nombre aléatoire
        if (aleatoire2 == 0)//si le nouveau nombre aléatoire est 0
        {
            ConfigBouton(5, 5, ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);// alors case 0 devient bleue
            SDL_RenderPresent(rendu);//on affiche case 2 bleue est case 1 gris
            SDL_Delay(1000);//pendant 1 secondes
            if(SDL_SetRenderDrawColor(rendu, 236, 236, 236, SDL_ALPHA_OPAQUE)!=0)//COUELUR GRIS DES TOUCHES
            {
                SDL_ExitWithError("Impossible de changer la couleur du rendu.");
            }
            ConfigBouton(5, 5, ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);//case 0 redeviens gris
            SDL_RenderPresent(rendu);// on affiche
            verite = 31;
        }
        else if(aleatoire2 == 1)
        {
            ConfigBouton(((LARGEUR_FENETRE/2)+5), 5, ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);
            SDL_RenderPresent(rendu);
            SDL_Delay(1000);
            if(SDL_SetRenderDrawColor(rendu, 236, 236, 236, SDL_ALPHA_OPAQUE)!=0)//COUELUR GRIS DES TOUCHES
            {
                SDL_ExitWithError("Impossible de changer la couleur du rendu.");
            }
            ConfigBouton(((LARGEUR_FENETRE/2)+5), 5, ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);
            SDL_RenderPresent(rendu);
            verite = 32;
        }
        else if (aleatoire2 == 2)
        {
            ConfigBouton(((LARGEUR_FENETRE/2)+5), ((HAUTEUR_FENETRE/2)+5), ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);
            SDL_RenderPresent(rendu);
            SDL_Delay(1000);
            if(SDL_SetRenderDrawColor(rendu, 236, 236, 236, SDL_ALPHA_OPAQUE)!=0)//COUELUR GRIS DES TOUCHES
            {
                SDL_ExitWithError("Impossible de changer la couleur du rendu.");
            }
            ConfigBouton(((LARGEUR_FENETRE/2)+5), ((HAUTEUR_FENETRE/2)+5), ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);
            SDL_RenderPresent(rendu);
            verite = 34;
        }

    }
    else if (boutonbleue == 3)
    {
        ConfigBouton(((LARGEUR_FENETRE/2)+5), ((HAUTEUR_FENETRE/2)+5), ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);
        if(SDL_SetRenderDrawColor(rendu, 96, 191, 236, SDL_ALPHA_OPAQUE)!=0)//COUELUR BLEUE DES TOUCHES
        {
            SDL_ExitWithError("Impossible de changer la couleur du rendu.");
        }
        srand(time( NULL ));// rappel la fonction time pour définir la deuxieme case à allumer
        aleatoire2 = rand()%3;// créeun nouveau nombre aléatoire
        if (aleatoire2 == 0)//si le nouveau nombre aléatoire est 0
        {
            ConfigBouton(5, 5, ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);// alors case 0 devient bleue
            SDL_RenderPresent(rendu);//on affiche case 2 bleue est case 1 gris
            SDL_Delay(1000);//pendant 1 secondes
            if(SDL_SetRenderDrawColor(rendu, 236, 236, 236, SDL_ALPHA_OPAQUE)!=0)//COUELUR GRIS DES TOUCHES
            {
                SDL_ExitWithError("Impossible de changer la couleur du rendu.");
            }
            ConfigBouton(5, 5, ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);//case 0 redeviens gris
            SDL_RenderPresent(rendu);// on affiche
            verite = 41;
        }
        else if(aleatoire2 == 1)
        {
            ConfigBouton(((LARGEUR_FENETRE/2)+5), 5, ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);
            SDL_RenderPresent(rendu);
            SDL_Delay(1000);
            if(SDL_SetRenderDrawColor(rendu, 236, 236, 236, SDL_ALPHA_OPAQUE)!=0)//COUELUR GRIS DES TOUCHES
            {
                SDL_ExitWithError("Impossible de changer la couleur du rendu.");
            }
            ConfigBouton(((LARGEUR_FENETRE/2)+5), 5, ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);
            SDL_RenderPresent(rendu);
            verite = 42;
        }
        else if (aleatoire2 == 2)
        {
            ConfigBouton(5, ((HAUTEUR_FENETRE/2)+5), ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);//case 1 devient bleu
            SDL_RenderPresent(rendu);
            SDL_Delay(1000);
            if(SDL_SetRenderDrawColor(rendu, 236, 236, 236, SDL_ALPHA_OPAQUE)!=0)//COUELUR GRIS DES TOUCHES
            {
                SDL_ExitWithError("Impossible de changer la couleur du rendu.");
            }
            ConfigBouton(5, ((HAUTEUR_FENETRE/2)+5), ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);//case 1 redeviens grise
            SDL_RenderPresent(rendu);
            verite = 43;
        }
    }
    //affiche de nouveau les cases grises.
    SDL_RenderPresent(rendu);

    printf("la combinaison est %d \n", verite);

    //AJOUT DE L'IMAGE POUR VALIDER

    SDL_Surface *validationImg = NULL;//pour importer l'image
    SDL_Texture *validationTex = NULL;//pour crée une txture avec limage
    validationImg = SDL_LoadBMP("./picture/validation.bmp");//on va chercher limage
    if (validationImg == NULL)//si limage est bien here alors on quitte pas
    {
        SDL_ExitWithError("Echec lors du chargement de l'image");
        SDL_DestroyRenderer(rendu);
        SDL_DestroyWindow(fenetre);
    }

    validationTex = SDL_CreateTextureFromSurface(rendu, validationImg);//la texture se crée avec l'image et le rendu en parametre
    SDL_FreeSurface(validationImg);// on libere image
    if(validationTex == NULL)//verifie si la texture est bienchargée
    {
        SDL_ExitWithError("Echec lors du chargement de l'image");
        SDL_DestroyRenderer(rendu);
        SDL_DestroyWindow(fenetre);
    }

    SDL_Rect image; //déclare un carré pour l'iamge

    if(SDL_QueryTexture(validationTex, NULL, NULL, &image.w, &image.h)!= 0)//charge l'image en mémoire
    {
        SDL_ExitWithError("Echec lors du chargement de la texture en mémoire");
        SDL_DestroyRenderer(rendu);
        SDL_DestroyWindow(fenetre);
    }
    image.x = 322;//indique l'emplacement a prendre en largeur
    image.y = 605;//indique l'emplacement a prendre en hauteur

    if(SDL_RenderCopy(rendu, validationTex, NULL, &image)!=0)//crée un copie de la texture
    {
        SDL_ExitWithError("Echec lors de l'affichage du rendu.");
        SDL_DestroyRenderer(rendu);
        SDL_DestroyWindow(fenetre);
    }

    SDL_RenderPresent(rendu);//affiche la texture :)

    SDL_bool programme_launched = SDL_TRUE;//un booléen en sdl pour avoir une

    //coordonées clic souris .
    int CooX = 0;
    int CooY = 0;
    int case1 = 0;
    int case2 = 0;
    int case3 = 0;
    int case4 = 0;

    while(programme_launched)//boucle infini pour la fenetre ouverte
    {
        SDL_Event event;//a faire une fois dans le prog pour el quitter

        while(SDL_PollEvent(&event))//cette fonction lit tout les events de la touche clavier au deplacement souris.
        {
            switch(event.type)//traite les infos pour exit
            {
                case SDL_MOUSEBUTTONDOWN:
                    CooX = event.button.x;
                    CooY = event.button.y;
                    //CASE VERTE LORS D'UN CLIC
                    if(CooX > 5 && CooX < ((LARGEUR_FENETRE-15)/2) && CooY > 5 && CooY < ((HAUTEUR_FENETRE-15)/2) && case1 == 0)//case 1
                    {
                        //si click sur la cae 1, elle devient verte
                        if(SDL_SetRenderDrawColor(rendu, 70, 250, 10, SDL_ALPHA_OPAQUE)!=0)//COUELUR VERTE
                        {
                            SDL_ExitWithError("Impossible de changer la couleur du rendu.");
                        }
                        ConfigBouton(5, 5, ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);
                        SDL_RenderPresent(rendu);
                        case1 = 1;

                    }
                    else if(CooX > ((LARGEUR_FENETRE/2)+5) && CooX < (LARGEUR_FENETRE-5) && CooY > 5 && CooY < ((HAUTEUR_FENETRE-15)/2) && case2 == 0)//case 2
                    {
                        if(SDL_SetRenderDrawColor(rendu, 70, 250, 10, SDL_ALPHA_OPAQUE)!=0)//COUELUR VERTE
                        {
                            SDL_ExitWithError("Impossible de changer la couleur du rendu.");
                        }
                        ConfigBouton(((LARGEUR_FENETRE/2)+5), 5, ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);
                        SDL_RenderPresent(rendu);
                        case2 = 1;
                    }
                    else if(CooX > 5 && CooX < ((LARGEUR_FENETRE-15)/2) && CooY > ((HAUTEUR_FENETRE/2)+5) && CooY < (HAUTEUR_FENETRE-5) && case3 == 0)//case 3
                    {
                        if(SDL_SetRenderDrawColor(rendu, 70, 250, 10, SDL_ALPHA_OPAQUE)!=0)//COUELUR VERTE
                        {
                            SDL_ExitWithError("Impossible de changer la couleur du rendu.");
                        }
                        ConfigBouton(5, ((HAUTEUR_FENETRE/2)+5), ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);
                        SDL_RenderPresent(rendu);
                        case3 = 1;
                    }
                    else if(CooX > ((LARGEUR_FENETRE/2)+5) && CooX < (LARGEUR_FENETRE-5) && CooY > ((HAUTEUR_FENETRE/2)+5) && CooY < (HAUTEUR_FENETRE-5) && case4 == 0)//case 4
                    {
                        if(SDL_SetRenderDrawColor(rendu, 70, 250, 10, SDL_ALPHA_OPAQUE)!=0)//COUELUR VERTE
                        {
                            SDL_ExitWithError("Impossible de changer la couleur du rendu.");
                        }
                        ConfigBouton(((LARGEUR_FENETRE/2)+5), ((HAUTEUR_FENETRE/2)+5), ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);
                        SDL_RenderPresent(rendu);
                        case4 = 1;
                    }
                    //REMETTRE LES CASES VERTES EN GRIS SI RE CLIC
                    else if(CooX > 5 && CooX < ((LARGEUR_FENETRE-15)/2) && CooY > 5 && CooY < ((HAUTEUR_FENETRE-15)/2) && case1 == 1)//case 1
                    {
                        //si click sur la cae 1, elle devient verte
                        if(SDL_SetRenderDrawColor(rendu, 236, 236, 236, SDL_ALPHA_OPAQUE)!=0)//COUELUR GRIS DES TOUCHES
                        {
                            SDL_ExitWithError("Impossible de changer la couleur du rendu.");
                        }
                        ConfigBouton(5, 5, ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);
                        SDL_RenderPresent(rendu);
                        case1 = 0;

                    }
                    else if(CooX > ((LARGEUR_FENETRE/2)+5) && CooX < (LARGEUR_FENETRE-5) && CooY > 5 && CooY < ((HAUTEUR_FENETRE-15)/2) && case2 == 1)
                    {
                        if(SDL_SetRenderDrawColor(rendu, 236, 236, 236, SDL_ALPHA_OPAQUE)!=0)//COUELUR GRIS DES TOUCHES
                        {
                            SDL_ExitWithError("Impossible de changer la couleur du rendu.");
                        }
                        ConfigBouton(((LARGEUR_FENETRE/2)+5), 5, ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);
                        SDL_RenderPresent(rendu);
                        case2 = 0;
                    }
                    else if(CooX > 5 && CooX < ((LARGEUR_FENETRE-15)/2) && CooY > ((HAUTEUR_FENETRE/2)+5) && CooY < (HAUTEUR_FENETRE-5) && case3 == 1)
                    {
                        if(SDL_SetRenderDrawColor(rendu, 236, 236, 236, SDL_ALPHA_OPAQUE)!=0)//COUELUR GRIS DES TOUCHES
                        {
                            SDL_ExitWithError("Impossible de changer la couleur du rendu.");
                        }
                        ConfigBouton(5, ((HAUTEUR_FENETRE/2)+5), ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);
                        SDL_RenderPresent(rendu);
                        case3 = 0;
                    }
                    else if(CooX > ((LARGEUR_FENETRE/2)+5) && CooX < (LARGEUR_FENETRE-5) && CooY > ((HAUTEUR_FENETRE/2)+5) && CooY < (HAUTEUR_FENETRE-5) && case4 == 1)
                    {
                        if(SDL_SetRenderDrawColor(rendu, 236, 236, 236, SDL_ALPHA_OPAQUE)!=0)//COUELUR GRIS DES TOUCHES
                        {
                            SDL_ExitWithError("Impossible de changer la couleur du rendu.");
                        }
                        ConfigBouton(((LARGEUR_FENETRE/2)+5), ((HAUTEUR_FENETRE/2)+5), ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);
                        SDL_RenderPresent(rendu);
                        case4 = 0;
                    }
                    else if(CooX > 322 && CooX < 478 && CooY > 605 && CooY < 656)//si on clic sur validation
                    {
                        if(verification(case1, case2, case3, case4, verite) == 1)
                        {
                            printf("GG! vous avez reussi, pas comme si c'etait dure :)\n");
                        }
                        else
                        {
                            printf("Dommage...\n");
                        }

                    }
                    break;
                case SDL_KEYDOWN:
                case SDL_KEYUP:
                    if( event.key.keysym.sym == SDLK_ESCAPE )
                    {
                        programme_launched = SDL_FALSE;
                    }
                    break;

                case SDL_QUIT://pour quitter le programme
                    programme_launched = SDL_FALSE;//boucle infini prend false donc s'arrete.
                    break;//quitter le switch

                default://par defaut ne fait rien
                    break;
            }
        }
    }


    //fin SDL
    SDL_DestroyRenderer(rendu); //prend le pointeur sur rendu en parametre
    SDL_DestroyWindow(fenetre);//pour détruire la fenetre , supp de mémoire.
    SDL_Quit();//quitte la SDL

    return 0;// retour à zéro.
}

void SDL_ExitWithError (const char *message)
{
    SDL_Log("ERREUR : %s > %s", message, SDL_GetError);
    SDL_Quit();
    exit(EXIT_FAILURE);
}
void ConfigBouton(int x, int y, int w, int h, SDL_Renderer *rendu)
{
    SDL_Rect bouton1;
    bouton1.x = x;
    bouton1.y = y;
    bouton1.w = w;//largeur
    bouton1.h = h;//hauteur
    if(SDL_RenderFillRect(rendu, &bouton1)!=0)// prend pointeur sur rendu et
    {
        SDL_ExitWithError("Impossible dessiner un rectangle plein .");
    }
}
int verification(int case1, int case2, int case3, int case4, int verite)
{
    int vof = 0;//bool de vrai ou faux
    int numerateur = 0;// prend les deux case allumé en valeur
    if(case1 = 1 && case2 == 1)
    {
        numerateur = 12;
        if(numerateur == verite)
        {
            //gg
            vof = 1;
            return vof;
        }
    }
    else if(case1 = 1 && case3 == 1)
    {
        numerateur = 13;
        if(numerateur == verite)
        {
            //gg
            vof = 1;
            return vof;
        }
    }
    else if(case1 = 1 && case4 == 1)
    {
        numerateur = 14;
        if(numerateur == verite)
        {
            //gg
            vof = 1;
            return vof;
        }
    }
    else if(case2 = 1 && case1 == 1)
    {
        numerateur = 21;
        if(numerateur == verite)
        {
            //gg
            vof = 1;
            return vof;
        }
    }
    else if(case2 = 1 && case3 == 1)
    {
        numerateur = 23;
        if(numerateur == verite)
        {
            //gg
            vof = 1;
            return vof;
        }
    }
    else if(case2 = 1 && case4 == 1)
    {
        numerateur = 24;
        if(numerateur == verite)
        {
            //gg
            vof = 1;
            return vof;
        }
    }
    else if(case3 = 1 && case1 == 1)
    {
        numerateur = 31;
        if(numerateur == verite)
        {
            //gg
            vof = 1;
            return vof;
        }
    }
    else if(case3 = 1 && case2 == 1)
    {
        numerateur = 32;
        if(numerateur == verite)
        {
            //gg
            vof = 1;
            return vof;
        }
    }
    else if(case3 = 1 && case4 == 1)
    {
        numerateur = 34;
        if(numerateur == verite)
        {
            //gg
            vof = 1;
            return vof;
        }
    }

    else if(case4 = 1 && case1 == 1)
    {
        numerateur = 41;
        if(numerateur == verite)
        {
            //gg
            vof = 1;
            return vof;
        }
    }
    else if(case4 = 1 && case2 == 1)
    {
        numerateur = 42;
        if(numerateur == verite)
        {
            //gg
            vof = 1;
            return vof;
        }
    }
    else if(case4 = 1 && case3 == 1)
    {
        numerateur = 43;
        if(numerateur == verite)
        {
            //gg
            vof = 1;
            return vof;
        }
    }
    return (vof);
}
