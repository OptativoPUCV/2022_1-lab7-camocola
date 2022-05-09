#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
   if (pq == NULL) return NULL;
   if (pq->heapArray == NULL) return NULL;
   if (pq->size == 0) return NULL;
   return pq->heapArray[0].data;
}


void heap_push(Heap* pq, void* data, int priority){
   if (pq->size == pq->capac)
   {
      pq->heapArray = realloc(pq->heapArray, sizeof(heapElem) * (pq->capac*2+1));
      pq->capac = pq->capac*2+1;
   }
   int indiceHijo = pq->size;
   pq->heapArray[indiceHijo].data = data;
   pq->heapArray[indiceHijo].priority = priority;
   
   heapElem aux; 
   while (indiceHijo > 0)
   {
      int indicePadre = (indiceHijo - 1) / 2;
      if (pq->heapArray[indicePadre].priority < priority)
      {
         aux.priority = pq->heapArray[indicePadre].priority;
         aux.data = pq->heapArray[indicePadre].data;
         pq->heapArray[indicePadre].priority = priority;
         pq->heapArray[indicePadre].data = data;
         pq->heapArray[indiceHijo].priority = aux.priority;
         pq->heapArray[indiceHijo].data = aux.data;
         indiceHijo = indicePadre;
      }
      else break;
   }
   pq->size++;
}


void heap_pop(Heap* pq){
   //profe, no caché que era recuperativo, no necesito la nota, lo dejé hasta ahí nomás
   //vi lo del recuperativo en el ptt, si no es así me da más tiempo?
}

Heap* createHeap(){
   Heap* heap = (Heap*) malloc (sizeof(Heap*));
   if (heap == NULL) return NULL;
   heap->heapArray = (heapElem*) malloc (sizeof(heapElem) * 3);
   heap->size = 0;
   heap->capac = 3;
   return heap;
}
