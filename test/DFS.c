#include<stdio.h>
#include<stdlib.h>

#define NODES 6

typedef struct adjMat
{
    int matrix [NODES] [NODES];
    int vNodes [NODES];
} adjMat;

typedef struct Data{
    int value;
} Data;

typedef struct Stack{
   int * top;
   int num;
} Stack;

struct Stack * initStack() {
    struct Stack * stack = (struct Stack *) malloc(sizeof(struct Stack));
    stack->top = NULL;
    stack->num = 0;
    return stack;
}
void push(struct Stack * s, struct Data d) {
    s->num ++;
    s->top = realloc(s->top, sizeof(struct Data) * s->num);
    // move all values over by one index in top
    for (int i = s->num - 1; i > 0; i--) {
        s->top[i] = s->top[i - 1];
    }
    s->top[0] = d.value;
}

Data pop(struct Stack * s){
    Data d;
    d.value = s->top[0];
    s->num --;
    // move al values down one index in top
    for (int i = 0; i < s->num; i++) {
        s->top[i] = s->top[i + 1];
    }
    s->top = realloc(s->top, sizeof(struct Data) * s->num);
    return d;
}

int isEmpty(struct Stack * s) {
    return s->num == 0;
}
void deleteStack(struct Stack * s){
    free(s->top);
    free(s);
}

void dfTraversal(struct adjMat * aM, int n) {
    Stack * s = initStack();
    int visited [NODES];
    for (int i = 0; i < NODES; i++) {
        visited[i] = 0;
    }
    
}