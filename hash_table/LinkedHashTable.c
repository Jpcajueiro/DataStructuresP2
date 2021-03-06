#include "../Main.h"
#include "LinkedHashTable.h"

ElementNode* createElementNode(int key,int value){
    ElementNode *element = (ElementNode*) malloc(sizeof(ElementNode));
    element->key = key;
    element->value = value;
    element->next = NULL;
    return element;
}
LinkedHashTable* createLinkedHashTable(){
    LinkedHashTable *hash = (LinkedHashTable*) malloc(sizeof(LinkedHashTable));
    int i;
    for(i=0;i<SIZE;i++){
        hash->table[i] = NULL;
    }
    return hash;
}
int hash(int key){
    return key%SIZE;
}
ElementNode* get(LinkedHashTable *ht,int key){
    int h = hash(key);
    ElementNode *current = ht->table[h];
    while(current!=NULL){
        if(current->key==key) return current;
        current = current->next;
    }
    return NULL;
}
void put(LinkedHashTable *ht,int key,int value){
    ElementNode *new_element = createElementNode(key,value);
    int h = hash(key);
    new_element->next = ht->table[h];
    ht->table[h] = new_element;
}
void removeElement(ElementNode **head,int key){
    if(head==NULL){
        printf("This element isn't present in this Hash Table\n");
    }else{
        ElementNode *aux,*prev = NULL,*nodeToRemove = NULL;
        while(aux!=NULL){
            if(aux->key == key){
                nodeToRemove = aux;
            }
            prev = aux;
            aux = aux->next;
        }
        if(nodeToRemove==NULL){
            printf("This element isn't present in this Hash Table\n");
            return;
        }else{
            if(prev==NULL){
                if((*head)->next==NULL){
                    *head = NULL;
                    return;
                }
                if(nodeToRemove->next!=NULL){
                    *head = nodeToRemove->next;
                }
            }else {
                prev->next = nodeToRemove->next;
            }
            free(nodeToRemove);
        }
    }
}
void remove(LinkedHashTable *ht,int key){
    int h = hash(key);
    removeElement(&(ht->table[h]),key);
}