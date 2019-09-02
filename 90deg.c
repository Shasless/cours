#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void affichetab(int **tab,int tailletab, int rot);

void affichetab(int **tab,int tailletab, int rot){

    for(int i=0;i<tailletab;i++){
        for(int j=0;j<tailletab;j++){
            if(rot==1){
            printf(" %d ",tab[j][i]);}
            else{
            printf(" %d ",tab[i][j]);}

        }
        printf("\n");
    }
}


int main() {

    int tailletab;
    int **tab;


    printf(" Taille du tableau :\n ");
    scanf("%d",&tailletab);
    tab = malloc(tailletab* sizeof(int*));
    for(int i=0;i<tailletab;i++){
        tab[i]=malloc(tailletab* sizeof(int));
    }

    for(int i=0;i<tailletab;i++){
        for(int j=0;j<tailletab;j++){
            printf("Le nombre case [%d][%d]:\n",i,j);
            scanf("%d",&tab[i][j]);
        }
    }

    affichetab(tab,tailletab,0);
    printf("\n");
    affichetab(tab,tailletab,1);



    for(int i=0;i<tailletab;i++){
        free(tab[i]);
    }
    free(tab);
    return 0;
}