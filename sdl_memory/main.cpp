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
    fenetre = SDL_CreateWindow("Le jeu de memoire", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, LARGEUR_FENETRE, HAUTEUR_FENETRE, 0);
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
    int aleatoire2 = 0;
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
        }
        else if (aleatoire2 == 2)
        {
            ConfigBouton(5, ((HAUTEUR_FENETRE/2)+5), ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);//case 1 redeviens grise
            SDL_RenderPresent(rendu);
            SDL_Delay(1000);
            if(SDL_SetRenderDrawColor(rendu, 236, 236, 236, SDL_ALPHA_OPAQUE)!=0)//COUELUR GRIS DES TOUCHES
            {
                SDL_ExitWithError("Impossible de changer la couleur du rendu.");
            }
            ConfigBouton(5, ((HAUTEUR_FENETRE/2)+5), ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);//case 1 redeviens grise
            SDL_RenderPresent(rendu);
        }
    }
    //affiche de nouveau les cases grises.
    SDL_RenderPresent(rendu);



    SDL_bool programme_launched = SDL_TRUE;//un booléen en sdl pour avoir une

    //coordonées clic souris .
    int CooX = 0;
    int CooY = 0;
    int case1 = false;
    int case2 = false;
    int case3 = false;
    int case4 = false;

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
                    if(CooX > 5 && CooX < ((LARGEUR_FENETRE-15)/2) && CooY > 5 && CooY < ((HAUTEUR_FENETRE-15)/2))//case 1
                    {
                        //si click sur la cae 1, elle devient verte
                        if(SDL_SetRenderDrawColor(rendu, 70, 250, 10, SDL_ALPHA_OPAQUE)!=0)//COUELUR VERTE
                        {
                            SDL_ExitWithError("Impossible de changer la couleur du rendu.");
                        }
                        ConfigBouton(5, 5, ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);
                        SDL_RenderPresent(rendu);
                        case1 = true;

                    }
                    else if(CooX > ((LARGEUR_FENETRE/2)+5) && CooX < (LARGEUR_FENETRE-5) && CooY > 5 && CooY < ((HAUTEUR_FENETRE-15)/2))
                    {
                        if(SDL_SetRenderDrawColor(rendu, 70, 250, 10, SDL_ALPHA_OPAQUE)!=0)//COUELUR VERTE
                        {
                            SDL_ExitWithError("Impossible de changer la couleur du rendu.");
                        }
                        ConfigBouton(((LARGEUR_FENETRE/2)+5), 5, ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);
                        SDL_RenderPresent(rendu);
                        case2 = true;
                    }
                    else if(CooX > 5 && CooX < ((LARGEUR_FENETRE-15)/2) && CooY > ((HAUTEUR_FENETRE/2)+5) && CooY < (HAUTEUR_FENETRE-5))
                    {
                        if(SDL_SetRenderDrawColor(rendu, 70, 250, 10, SDL_ALPHA_OPAQUE)!=0)//COUELUR VERTE
                        {
                            SDL_ExitWithError("Impossible de changer la couleur du rendu.");
                        }
                        ConfigBouton(5, ((HAUTEUR_FENETRE/2)+5), ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);
                        SDL_RenderPresent(rendu);
                        case3 = true;
                    }
                    else if(CooX > ((LARGEUR_FENETRE/2)+5) && CooX < (LARGEUR_FENETRE-5) && CooY > ((HAUTEUR_FENETRE/2)+5) && CooY < (HAUTEUR_FENETRE-5))
                    {
                        if(SDL_SetRenderDrawColor(rendu, 70, 250, 10, SDL_ALPHA_OPAQUE)!=0)//COUELUR VERTE
                        {
                            SDL_ExitWithError("Impossible de changer la couleur du rendu.");
                        }
                        ConfigBouton(((LARGEUR_FENETRE/2)+5), ((HAUTEUR_FENETRE/2)+5), ((LARGEUR_FENETRE-15)/2), ((HAUTEUR_FENETRE-15)/2), rendu);
                        SDL_RenderPresent(rendu);
                        case4 = true;
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
