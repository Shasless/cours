#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct t_maillon {
    int info;
    struct t_maillon* suiv;
} t_maillon;


t_maillon* creer_t_maillon(int n)
{
    t_maillon* t_maillon=malloc(sizeof(t_maillon));
    t_maillon->info=n;
    t_maillon->suiv=NULL;
    return t_maillon;
}

void aff_liste(t_maillon* liste){
    if (liste == NULL){
        printf("X\n");
    }
    else{
        //aff_liste(liste->suiv);
        printf("%d=>", liste->info);
        aff_liste(liste->suiv);
    }
}

void free_list(t_maillon* liste){
    if (liste != NULL){
        free_list(liste->suiv);
        free(liste);
    }
}

void ajouter_end(t_maillon** l, t_maillon* e){
    if(*l == NULL){
        *l = e;
    }
    else{
        t_maillon* temp = *l;
        while (temp->suiv != NULL){
            temp = temp->suiv;
        }
        temp->suiv = e;
    }

}

int  compter(t_maillon** l){
    int i=1;
    if(*l == NULL){
            return 0;
    }
    else{
        t_maillon* temp = *l;
        while (temp->suiv != NULL){
            temp = temp->suiv;
            i++;
        }

    }
    return i;
}
int  trouver(t_maillon** l,int a){
    int i=1;
    if(*l == NULL){
        return 0;
    }
    else{
        t_maillon* temp = *l;
        while (temp->suiv != NULL && temp->info!=a){
            temp = temp->suiv;
            i++;
        }
        if(temp->suiv == NULL && temp->info!=a){
            return 0;
        }

    }
    return i;
}
int  iteration(t_maillon** l,int a){
    int i=0;
    if(*l == NULL){
        return 0;
    }
    else{
        t_maillon* temp = *l;
        while (temp->suiv != NULL ){
            temp = temp->suiv;
            if(temp->info==a){
                i++;
            }

        }

    }
    return i;
}

void aff_liste1sur2(t_maillon* liste,int a){
    if (liste != NULL)
       {
        if(a%2==0){
            printf("%d ", liste->info);
        }
        a++;
        aff_liste1sur2(liste->suiv,a);
    }
}
char*  croissant(t_maillon** l){

    if(*l == NULL){
        return "NULL";
    }
    else{
        t_maillon* temp = *l;
        while (temp->suiv != NULL ){
            if(temp->info>temp->suiv->info){
                return "FAUX";
            }
            temp = temp->suiv;


        }

    }
    return "VRAIX";
}

/*  EN COURS DE CODAGE
void decaledroite(t_maillon** l){
    if(*l == NULL){
        *l = e;
    }
    else{
        t_maillon* temp = *l;
        while (temp->suiv != NULL){
            temp = temp->suiv;
        }
        temp->suiv = e;
    }

}
void ajouter(t_maillon** l, t_maillon* e, int a){
    int i=0;
    if(*l == NULL || a==0){

        *l = e;
    }
    else{
        t_maillon* temp = *l;
        while (temp->suiv != NULL){
            temp = temp->suiv;
        }
        temp->suiv = e;
    }

}*/
int main()
{
    t_maillon* ma_liste = creer_t_maillon(5);
    ajouter_end(&ma_liste, creer_t_maillon(6));
    ajouter_end(&ma_liste, creer_t_maillon(7));
    ajouter_end(&ma_liste, creer_t_maillon(8));
    aff_liste(ma_liste);
    printf(" compter :%d\n",compter(&ma_liste));
    printf(" trouver 6 : %d\n",trouver(&ma_liste,6));
    printf(" iteration 8 : %d\n",iteration(&ma_liste,7));
    aff_liste1sur2(ma_liste,0);
    printf("\n croissant : %s\n",croissant(&ma_liste));


    free_list(ma_liste);
    ma_liste = NULL;


    return 0;
}


