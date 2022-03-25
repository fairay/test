#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <windows.h>

#define WHITE 15 
#define DARKGREY 8
#define SUCCESS 1
#define EMPTY_SIZE_ERROR -1 
#define EMPTY_SIZE_MSG printf("\n  Error: not enough size for it!\n")
#define REALLOC_ERROR -2
#define REALLOC_MSG printf("\n  Error: realloc was finished with NULL ptr!\n")


typedef int* arr_p;
typedef struct Array {
    arr_p ptr;
    int size;
} Stack;
typedef Stack* StackPtr;


// FoolProof get int func
int  ScanInt(int* valuePtr) {
    int scanCount = scanf("%d", valuePtr);
    if (scanCount) return 1; 
    return getc(stdin) != '\n';
}


// Dynamic's array funcs

Stack CreateStack() {
    Stack thisStack;
    thisStack.ptr = NULL;
    thisStack.size = 0;
    return thisStack;
}
void ReallocStack(StackPtr stack, int newSize) {
    int* tmp_ptr = (int*)realloc(stack->ptr, newSize * sizeof(int));
    if (tmp_ptr != NULL || newSize == 0) {
        stack->ptr = tmp_ptr;
        stack->size = newSize;
    } else {
        throw REALLOC_ERROR;
    }
}
void DeleteStack(StackPtr stack) {
    stack->size = 0;
    free(stack->ptr);
    stack = NULL;
}

// ��� ����
Stack GetPrimaryState(StackPtr stack) {
    Stack currStack = CreateStack();
    ReallocStack(&currStack, stack->size);
    for (int i = 0; i < stack->size; i++)
        currStack.ptr[i] = stack->ptr[i];
    return currStack;
}
int Pop(StackPtr stack) {
    if (stack->size == 0) return EMPTY_SIZE_ERROR;
    int topElem = stack->ptr[stack->size - 1];
    ReallocStack(stack, stack->size - 1);
    return topElem;
}
int Push(StackPtr stack, int newValue) { 
    ReallocStack(stack, stack->size + 1);
    stack->ptr[stack->size-1] = newValue;
    return stack->ptr[stack->size - 1];
}
int WasError(int errorCode, StackPtr stack, StackPtr primaryStack) {
    if (errorCode >= SUCCESS) return 0;
    if (errorCode == REALLOC_ERROR) REALLOC_MSG;
    if (errorCode == EMPTY_SIZE_ERROR) EMPTY_SIZE_MSG; 
    
    printf("%d, %d, %d", errorCode, stack->size, primaryStack->size);

    DeleteStack(stack);
    *stack = CreateStack();
    stack->size = primaryStack->size;
    for (int i = 0; i < stack->size; i++)
        stack->ptr[i] = primaryStack->ptr[i];
    

    *primaryStack = GetPrimaryState(stack);
    if (primaryStack == stack) return REALLOC_ERROR; 

    return 1;
}


 // not BASE
// int FreeStack(StackPtr stack, StackPtr primaryStack)
// int SwapTop(StackPtr stack, StackPtr primaryStack) 

int PopBack(StackPtr stack, StackPtr primaryStack) {
    Stack tempStack = CreateStack();

    try {
        DeleteStack(primaryStack);
        *primaryStack = GetPrimaryState(stack);

        int peakElem = Pop(stack);
        if (peakElem < 0) return peakElem;

        while (peakElem > 0) {
            Push(&tempStack, peakElem);
            peakElem = Pop(stack);
        }
        
        int deletedElem = Pop(&tempStack);
        peakElem = Pop(&tempStack);
        while (peakElem > 0) {
            Push(stack, peakElem);
            peakElem = Pop(&tempStack);
        }
        
        return deletedElem;
    } catch (int exp) {
        DeleteStack(&tempStack);
        return REALLOC_ERROR;
    }
}
int SwapEdges(StackPtr stack, StackPtr primaryStack) { 
    Stack tempStack = CreateStack();
    int code = SUCCESS;

    try {
        DeleteStack(primaryStack);
        *primaryStack = GetPrimaryState(stack);

        // {1,2,3,4} => {2,3,4}
        int topElem = Pop(stack);
        if (topElem < 0) { DeleteStack(&tempStack); return topElem; } 

        // {2,3,4} => {2,3} 
        int bottomElem = PopBack(stack, &tempStack);
        if (bottomElem < 0) { DeleteStack(&tempStack); return bottomElem; }

        // {} => {4}
        Push(&tempStack, bottomElem); 

        // {4} => {3,2,4}
        int peakElem = Pop(stack);
        while (peakElem > 0) {
            Push(&tempStack, peakElem);
            peakElem = Pop(stack);
        }

        // {3,2,4} => {1,3,2,4}
        Push(&tempStack, topElem); 

        // {1,3,2,4} => {4,2,3,1}
        peakElem = Pop(&tempStack);
        while (peakElem > 0) {
            Push(stack, peakElem);
            peakElem = Pop(&tempStack);
        }

        printf("\n  %d, %d", topElem, bottomElem);
    } catch (int exp) {
        code = REALLOC_ERROR;
    }

    DeleteStack(&tempStack);

    return SUCCESS; 
}

int main() {
    srand(time(0));
    system("chcp 1251");
    system("cls"); 


    Stack stack = CreateStack();
    Stack primaryStack = CreateStack();
    // Menu(&stack, &primaryStack);


    system("pause");
    DeleteStack(&stack);
    DeleteStack(&primaryStack);
    return 0;
}
