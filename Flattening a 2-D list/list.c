#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#ifndef ASSIGNMENT3_H
#define ASSIGNMENT3_H
/* Node in a singly linked list */
struct SLnode {
    /* gives the node a value */
    int key ;
    /* pointer to the next item in a list */
    struct SLnode *next ;
};
typedef struct SLnode *SLnodePtr ;
/* Node in the "horizontal" list */
struct HBnode {
    /* gives the node a value */
    int key ;
    /* pointer to the next item in the horizontal list */
    struct HBnode *next ;
    /* pointer to the bottom list */
    SLnodePtr bottom ;
};
typedef struct HBnode *HBnodePtr ;
// DONE!!!
HBnodePtr createHBlist (int n , int m){
    /* Randomizes */
    srand(time(NULL));
    /* sets all pointers to NULL */
    /* head of the HB list */
    HBnodePtr HBhead = NULL;
    /* keeps track of previous element in the HB list */
    HBnodePtr HBprevious = NULL;
    /* keeps track of current element in the HB list */
    HBnodePtr HBcurrent = NULL;
    /* used to iterate through the HB list */
    HBnodePtr HBp = NULL;
    /* creates 'n' number of HB nodes */
    for (int i = 0; i < n; i++){
        /* allocate HB node */
        HBcurrent = malloc(sizeof(struct HBnode));
        /* generates a random number */
        int randM = rand() % m;
        /* initialize the first of the list */
        SLnodePtr head = NULL;
        /* initialize the pointer that will iterate through the list */
        SLnodePtr prevSLnode = NULL;
        /* initializes the current element of the list */
        SLnodePtr current = NULL;
        /* used to iterate through the SL list */
        SLnodePtr p = NULL;
        /* creates 'm' number of SL nodes */
        for(int j = 0; j < randM; j++){
            /* allocates SL node */
            current = malloc(sizeof(struct SLnode));
            /* if list is empty set head to the first element */
            if (head == NULL){
                /* sets the value of nextSLnode */
                current->key = rand() % 50;
                /* sets the current pointer to point to nothing */
                current->next = NULL;
                /* sets the value of the head pointer */
                head = current;
                /* sets the previous node to the current node */
                prevSLnode = current;
            }
            else{
                /* sets the value of nextSLnode */
                current->key = rand() % 50 + prevSLnode->key;
                /* sets the current pointer to point to nothing */
                current->next = NULL;
                /* sets p node to the beginning of the SL list */
                p = head;
                /* iterates through the SL list */
                while(p->next != NULL)
                    p = p->next;
                /* makes previous node point to current node */
                prevSLnode->next = current;
                /* sets the previous node to the current node */
                prevSLnode = current;
            }       
        }
        if(HBhead == NULL){
            /* sets the nodes value */
            HBcurrent->key = rand() % 50;
            /* sets the current pointer to point to nothing */
            HBcurrent->next = NULL;
            /* checks to see if you are at the start of the HB list */
            HBcurrent->bottom = head;
            /* sets the value of the head pointer */
            HBhead = HBcurrent;
            /* sets the previous node to the current node */
            HBprevious = HBcurrent;
        }
        else{
            /* sets the nodes value */
            HBcurrent->key = rand() % 50 + HBprevious->key;
            /* sets the current pointer to point to nothing */
            HBcurrent->next = NULL;
            /* checks to see if you are at the start of the HB list */
            HBcurrent->bottom = head;
            /* sets HBp node to the beginning of the HB list */
            HBp = HBhead;
            /* iterates through the HB list */
            while(HBp->next != NULL)
                HBp = HBp->next;
            /* makes previous node point to current node */
            HBprevious->next = HBcurrent;
            /* sets the previous node to the current node */
            HBprevious = HBcurrent;
        }
    }
    /*returns a pointer to the first element of the HB list */
    return HBhead;
};
// DONE!!
static SLnodePtr merge (SLnodePtr a, SLnodePtr b) { 
    SLnodePtr copy;
    if(a == NULL & b == NULL)
        return NULL;
    /* If first list is empty, the second list is result */
    if (a == NULL){
        copy = malloc(sizeof(struct SLnode));
        copy->key = b->key;
        copy->next = merge(a, b->next);
        return copy;
    } 
    /* If second list is empty, the second list is result */
    if (b == NULL) 
        return a; 
    /* Compare the data members of head nodes of both lists */
    /* and put the smaller one in result */
    if (a->key < b->key) { 
        a->next = merge(a->next, b); 
        return a; 
    }
    else{ 
        copy = malloc(sizeof(struct SLnode)); 
        copy->key = b->key;
        copy->next = merge(a, b->next);
        return copy;
    }  
};
// DONE!!!
SLnodePtr flattenList (const HBnodePtr L){
    /* Base cases */
    SLnodePtr flatten;

    if (L != NULL){ 
        flatten = malloc(sizeof(struct SLnode));
        flatten->key = L->key;
        flatten->next = NULL; 
        return merge(merge(flatten , L->bottom) , flattenList(L->next));
    }else{
        /* Merge this list with the list on right side */
        return NULL;
    }
};
// DONE!!!
void freeHBlist (HBnodePtr L){
    /* setting "HBerase to the start of the HB list */
    HBnodePtr HBerase = L;
    /* setting "HBhold" to nothing */
    HBnodePtr HBhold = NULL;
    /* makes sure I am not at the end of the HB list */
    while(HBerase != NULL){
        /* sets "HBhold" to the next element */
        HBhold = HBerase->next;
        /* setting "SLerase" to the start of the SL list */
        SLnodePtr SLerase = HBerase->bottom;
        /* setting "SLhold" to nothing */
        SLnodePtr SLhold = NULL;
        /* makes sure I am not at the end of the SL list */
        while(SLerase != NULL){
            /* sets "SLhold" to the next element */
            SLhold = SLerase->next;
            /* frees the first element */
            free(SLerase);
            /* sets "SLerase" back to the first element */
            SLerase = SLhold;
        }
        /* frees the first element of the HB list */
        free(HBerase);
        /* sets "HBerase" back to the first element */
        HBerase = HBhold;
    }
};
// DONE!!!
void freeSLlist (SLnodePtr L){
    /* setting "erase" to the start of the list */
    SLnodePtr erase = L;
    /* setting "hold" to nothing */
    SLnodePtr hold = NULL;
    /* makes sure I am not at the end of the list */
    while(erase != NULL){
        /* sets "hold" to the next element */
        hold = erase->next;
        /* frees the first element */
        free(erase);
        /* sets "erase" back to the first element */
        erase = hold;
    }

};
// DONE!!!
void printHBlist (const HBnodePtr L){
    /* sets HBcurrent (HBc) to the first element */
    HBnodePtr HBc = L;
    /* makes sure I am not at the end of the HB list */
    while(HBc != NULL){
        /* sets SLcurrent (SLc) to the first element */
        SLnodePtr SLc = HBc->bottom;
        /* prints the first HB element */
        printf("%d-> ", HBc->key);
        /* makes sure I am not at the end of the SL list */
        while(SLc != NULL){
            /* prints the first SL element */
            printf("%d  ", SLc->key);
            /* iterates through the SL list */
            SLc = SLc->next;
        }
        /* line break */
        printf("\n");
        /* iterates through the HB list */
        HBc = HBc->next;
    }
};
// DONE!!!
void printSLlist (const SLnodePtr L){
    /* sets SLcurrent to the first element */
    SLnodePtr SLcurrent = L;
    /* makes sure I am not at the end of the SL list */
    while(SLcurrent != NULL){
        /* prints the first SL element */
        printf("%d  ", SLcurrent->key);
        /* iterates through the SL list */
        SLcurrent = SLcurrent->next;
    }
};
#endif /* ASSIGNMENT3_H */