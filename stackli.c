#include "stackli.h"
#include "fatal.h"
#include <stdlib.h>

struct Node {
    ElementType Element;
    PtrToNode Next;
};

int
IsEmpty(Stack S) {
    return S->Next == NULL;
}

Stack
CreateStack(void) {
    Stack S;

    S = malloc(sizeof(struct Node));
    if (S == NULL) {
        FatalError("Out of space!!!");
    }
    S->Next = NULL;
    MakeEmpty(S);

    return S;
}

void
MakeEmpty(Stack S) {
    if (S == NULL) {
        Error("Must use CreateStack first");
    } else {
        while (!IsEmpty(S)) {
            Pop(S);
        }
    }
}

void
DisposeStack(Stack S) {
    MakeEmpty(S);
    free(S);
}

void
Push(ElementType X, Stack S) {
    PtrToNode TmpCell;

    TmpCell = malloc(sizeof(struct Node));
    if (TmpCell == NULL) {
        FatalError("Out of space!!!");
    } else {
        TmpCell->Element = X;
        TmpCell->Next = S->Next;
        S->Next = TmpCell;
    }
}

ElementType
Top(Stack S) {
    if (!IsEmpty(S)) {
        return S->Next->Element;
    }
    Error("Empty stack");
    return 0;  /* Return value used to avoid warning */
}

void
Pop(Stack S) {
    PtrToNode FirstCell;

    if (IsEmpty(S)) {
        Error("Empty stack");
    } else {
        FirstCell = S->Next;
        S->Next = S->Next->Next;
        free(FirstCell);
    }
}

ElementType
TopAndPop(Stack S) {
    ElementType TopElement = Top(S);
    Pop(S);
    return TopElement;
}
