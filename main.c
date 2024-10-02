/*
claude delcroix 03.10.2024 02:48
 * liste chainee exo 9 lien du site : https://theccoder.com/exercices-c#google_vignette
 * creer trois fonctions
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node node;
struct node {
    int value;
    node* next;
};

typedef struct Liste Liste;
struct Liste {
    node* first;
};

Liste* initialisation() {
    Liste* liste = malloc(sizeof(liste));
    if(liste == NULL) {
        exit(EXIT_FAILURE);
    }
    liste->first = NULL;
    return liste;
}

void insertValue(Liste* liste,const int nombre) {
    node* noeud = (node*)malloc(sizeof(node));
    if(liste == NULL || noeud == NULL) {
        exit(EXIT_FAILURE);
    }
    noeud->value = nombre;

    if(liste->first == NULL) {
        noeud->next = liste->first;
        liste->first = noeud;
        return;
    }

    node* current = liste->first;
    while(current->next != NULL) {
        current = current->next;
    }
    noeud->next = NULL;
    current->next = noeud;
}

void printList(const Liste* liste) {
    const node* current = liste->first;
    while(current != NULL) {
        printf("%d->",current->value);
        current = current->next;
    }
    printf("NULL\n");
}

void boucleListe(const Liste* liste) {
    node *firstNode = liste->first, *current = liste->first;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = firstNode;
}

bool isBoucle(const Liste* liste) {
    node* current = liste->first->next;
    node* firstNode = liste->first;

    while(current != NULL) {
        if(current == firstNode) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void fundMaxNodeAndReturnIt(Liste* liste) {
    node *current = liste->first->next,*firstNode = liste->first,*maxNode = firstNode;
    while(current != firstNode) {
        if(current->value >= maxNode->value) {
            maxNode = current;
        }
        current = current->next;
    }

    liste->first = maxNode;
    while(current->next != maxNode) {
        current = current->next;
    }
    current->next = NULL;
}

void deleteNode(Liste* liste) {
    node *current = liste->first,*suivant = NULL;

    while(current != NULL) {
        suivant = current->next;
        free(current);
        current = suivant;
    }
    free(liste);
    free(current);
    free(suivant);
}

int main(void) {
    printf("entrez le nombre d'element de la liste :   ");
    int nbre_element = 0;
    Liste* liste_chaine = initialisation();
    scanf("%d",&nbre_element);

    for(int i = 0;i < nbre_element;i++) {
        printf("\n entrez l'element numero %d :  ",i+1);
        int nbre = 0;
        scanf("%d",&nbre);
        insertValue(liste_chaine,nbre);
    }
    printf("\n affichage du tableau...\n");
    printList(liste_chaine);
    printf("Passage a la fonction pour le bouclage de liste...\n");

    boucleListe(liste_chaine);
    printf("verification si la liste est bouclee...\n");
    if(isBoucle(liste_chaine)) {
        printf("la liste a ete bouclee avec succes...\n");
    }
    else {
        printf("liste non boucle!!!");
    }

    printf("cherchons et trouvons le max node ensuite le placer en tete de la liste et deboucler la liste\n");
    fundMaxNodeAndReturnIt(liste_chaine);
    printf("verification si la liste est reellement deboucler avant tout\n");
    if(isBoucle(liste_chaine)) {
        printf("la liste a ete bouclee avec succes...\n");
    }
    else {
        printf("liste non boucle!!!\n");
    }

    printf("affichage de la liste apres le debouclage et le placement du max en tete de la liste\n");
    printList(liste_chaine);
    printf("suppression de l'espace occupe\n");
    deleteNode(liste_chaine);

    return 0;
}
