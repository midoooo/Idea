// Heap Garbage Collection in C
// collect.c by Steve Rhoads (rhoadss@yahoo.com) 7/23/09
// Software placed into the public domain by the author.
// All Root nodes must be identified by calling CollectRoot().
// In structures, all pointers to garbage collected items must be at the top.
// All garbage collected items must be created with CollectMalloc() and
// told how many garbage collecting pointers exist at the top of the structure.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAGIC 0x47

typedef struct OBJECT {
   unsigned char magic;       //Contains 0x47
   unsigned char referenced;  //Is this object referenced?
   unsigned char ptrCount;    //Number of GC pointers in object
   unsigned char index;       //Number of GC pointers that have been followed
   struct OBJECT *next;       //Next object in linked list of objects
   struct OBJECT *prev;       //Previous object in linked list of objects
} OBJECT;

static OBJECT *ObjectHead;    //Linked list of malloc'ed objects
static void **RootRef[32];    //Fixed root pointers into data structures
static int RootCount;         //Number of root pointers
static void *heapStart, *heapEnd;


// Garbage Collector version of malloc()
// ptrCount is the number of GC pointers at the start of the object
void *CollectMalloc(int size, int ptrCount)
{
   OBJECT *object;

   object = (OBJECT*)malloc(sizeof(OBJECT) + size);
   if(object == NULL)
      return NULL;
   if(object < heapStart)
      heapStart = object;
   if(object > heapEnd)
      heapEnd = object;
   memset(object, 0, sizeof(OBJECT) + size);
   object->magic = MAGIC;
   object->referenced = 0;
   if(ptrCount < 0 || ptrCount > size / sizeof(void*))
   {
      ptrCount = size / sizeof(void*);
      if(ptrCount > 255)
         ptrCount = 255;
   }
   object->ptrCount = (unsigned char)ptrCount;
   assert(object->ptrCount == ptrCount);
   object->index = 0;

   // Insert object into linked list
   object->next = ObjectHead;
   object->prev = NULL;
   if(ObjectHead)
      ObjectHead->prev = object;
   ObjectHead = object;
   return object + 1;       //Skip OBJECT header
}


// Garbage Collector version of free()
void CollectFree(void *ptr)
{
   OBJECT *object=(OBJECT*)ptr - 1;  //Backup to OBJECT header

   // Remove object from linked list
   if(object->prev == NULL)
      ObjectHead = object->next;
   else
      object->prev->next = object->next;
   if(object->next)
      object->next->prev = object->prev;
   object->magic = 0;

   free(object);
}


// Define another fixed root pointer
void CollectRoot(void *pRoot)
{
   assert(RootCount < sizeof(RootRef) / sizeof(void*));
   RootRef[RootCount++] = (void**)pRoot;
}


// Mark objects that are referenced (changes prev pointers)
static void CollectWalk(OBJECT *object)
{
   int i;
   OBJECT **refs;
   OBJECT *obj;

   if(object->referenced)
      return;
   object->referenced = 1;
   object->prev = NULL;                //used for backward walk
   while(object)
   {
      assert(object->magic == MAGIC);
      refs = (OBJECT**)(object + 1);   //pointers at top of object
      for(i = object->index; i < object->ptrCount; ++i)
      {
         ++object->index;
         if(refs[i] != NULL)
         {
            obj = refs[i] - 1;
            if(heapStart <= obj && obj <= heapEnd &&   //verify GC pointer
               ((unsigned int)obj & 3) == 0 && obj->magic == MAGIC && 
               obj->referenced == 0 
               //&& (obj->next == NULL || 
               //   (heapStart <= obj->next && obj->next <= heapEnd && 
               //   ((unsigned int)obj->next & 3) == 0 && 
               //   obj->next->magic == MAGIC))
            )
            {
               obj->prev = object;     //remember for backwards walk
               object = obj;
               object->referenced = 1;
               break;
            }
         }
      }
      if(object->index >= object->ptrCount)
         object = object->prev;        //backwards walk
   }
}


// Free any unreferenced objects
int CollectGarbage(void)
{
   OBJECT *object, *next, *prev;
   int i;
   int objectCount=0;

   // Mark all referenced objects
   for(i = 0; i < sizeof(RootRef)/sizeof(void*); ++i)
   {
      if(RootRef[i] && *RootRef[i])
      {
         object = (OBJECT*)*RootRef[i] - 1;
         CollectWalk(object);
      }
   }

   // Sweep and free unreferenced objects
   prev = NULL;
   for(object = ObjectHead; object; object = next)
   {
      next = object->next;
      if(object->referenced == 0)
      {
         CollectFree(object + 1);
      }
      else
      {
         object->prev = prev;         //repair prev pointers
         object->referenced = 0;
         object->index = 0;
         prev = object;
         ++objectCount;
      }
   }
   return objectCount;
}

/////////////////////// Test code /////////////////////////

#if 1
#define _gc                      //Mark garbage collected pointers

#define TREE_NODE_PTR_COUNT 2
typedef struct TreeNode {
   struct TreeNode _gc *left;
   struct TreeNode _gc *right;
   int value;
} TreeNode;

TreeNode *top, *node0, *node1, *node2, *node3;

int main(int argc, char *argv[])
{
   int count;
   (void)argc; (void)argv;

   node0 = (TreeNode*)CollectMalloc(sizeof(TreeNode), TREE_NODE_PTR_COUNT);
   node1 = (TreeNode*)CollectMalloc(sizeof(TreeNode), TREE_NODE_PTR_COUNT);
   node2 = (TreeNode*)CollectMalloc(sizeof(TreeNode), TREE_NODE_PTR_COUNT);
   node3 = (TreeNode*)CollectMalloc(sizeof(TreeNode), TREE_NODE_PTR_COUNT);

   CollectRoot(&top);              //define a fixed root node
   top = node0;
   node0->left = node2;
   node2->left = node0;
   node2->right = node3;
   node3->value = 1234;

   /*-------------------
   | top -> node0
   |        /   \
   |     node2  NULL
   |     /   \
   |  node0  node3   
   *-------------------*/
   printf("value = %d\n", top->left->right->value);

   count = CollectGarbage();       //run the garbage collector; frees node1
   printf("count = %d\n", count);

   node2->right = NULL;
   count = CollectGarbage();       //frees unreferenced node3
   printf("count = %d\n", count);

   top = NULL;
   count = CollectGarbage();       //frees node0 and node2
   printf("count = %d\n", count);

   //getchar();
   return 0;
}
#endif
