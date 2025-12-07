//end(List *pL)
Position end(List *l){
    return l->last+1;
}
//insert(x, p, pL)
void insert(ElementType x,Position p,List *l){
    if(p<1||p>l->last+1||l->last>=MAXLENGTH){
        return;
    }
    for(int i=l->last;i>=p;i--){
        l->elements[i]=l->elements[i-1];
    }
    l->elements[p-1]=x;
    l->last++;
}
//locate(x, pL)
Position locate(ElementType x,List *l){
    for(Position p=1;p<=l->last;p++){
        if(l->elements[p-1]==x){
            return p;
        }
    }
    return end(l);
}
//retrieve(p, pL)
ElementType retrieve(Position p,List *l){
    if(p<1||p>=l->last+1||l->last>=MAXLENGTH){
        return -99.99;
    }
    return l->elements[p-1];
}
//delete(p, L)
void delete(Position p,List *l){
    if(p<1||p>=l->last+1||l->last>=MAXLENGTH){
        return;
    }
    for(int i=p;i<l->last;i++){
        l->elements[i-1]=l->elements[i];
    }
    l->last--;
}
// next(p, L)
Position next(Position p,List *l){
    if(p<1||p>=l->last+1||l->last>=MAXLENGTH){
        return -1;
    }
    return p+1;
}
//previous(p, L)
Position previous(Position p,List *l){
    if(p<2||p>l->last+1||l->last>=MAXLENGTH){
        return -1;
    }
    return p-1;
}
//first(p, L)
Position first(List *l){
    return 1;
}
//makeNull(L)
Position makeNull(List *l){
    l->last=0;
    return end(l);
}
//printList(L)
void printList(List *l){
    for(int i=0;i<l->last;i++){
        printf("%.2lf",l->elements[i]);
        if(i<l->last-1){
            printf(", ");
        }
    }
}
//Define a Data Structure List to store integers (max: 100) and implement some basic operators:
#include<stdio.h>
#define MAXLENGTH 100
typedef int ElementType;
typedef int Position;
typedef struct{
    ElementType elements[MAXLENGTH];
    Position last;
}List;
void makeNull(List *l){
    l->last=0;
}
Position end(List *l){
    return l->last+1;
}
void insert(ElementType x,Position p,List *l){
    if(p<1||p>l->last+1||l->last>=MAXLENGTH){
        return;
    }
    for(int i=l->last;i>=p;i--){
        l->elements[i]=l->elements[i-1];
    }
    l->elements[p-1]=x;
    l->last++;
}
void delete(Position p,List *l){
    if(p<1||p>l->last+1||l->last>=MAXLENGTH){
        return;
    }
    for(int i=p;i<l->last;i++){
        l->elements[i-1]=l->elements[i];
    }
    l->last--;
}
Position locate(ElementType x,List *l){
    for(Position p=1;p<=l->last;p++){
        if(l->elements[p-1]==x){
            return p;
        }
    }
    return end(l);
}
ElementType retrieve(Position p,List *l){
    if(p<1||p>l->last+1||l->last>=MAXLENGTH){
        return -1;
    }
    return l->elements[p-1];
}
Position next(Position p,List *l){
    if(p<1||p>l->last+1||l->last>=MAXLENGTH){
        return -1;
    }
    return p+1;
}
Position first(List *l){
    return 1;
}
void printList(List *l){
    for(int i=0;i<l->last;i++){
        printf("%d",l->elements[i]);
        if(i<l->last-1){
            printf(", ");
        }
    }
    printf("\n");
}
int main(){
    List l;
    makeNull(&l);
    int n,t;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        insert(t,end(&l),&l);
    }
    printList(&l);
    insert(20,4,&l);
    printList(&l);
    delete(first(&l),&l);
    printList(&l);
    int x;
    scanf("%d",&x);
    Position p=locate(x,&l);
    printf("%d",p);
}
//Define a data structure List to store Students (max: 100)
#include<stdio.h>
#include<string.h>
#define MAXLENGTH 100
typedef struct{
    char name[60];
    int mark;
}ElementType;
typedef int Position;
typedef struct{
    ElementType elements[MAXLENGTH];
    Position last;
}List;
void makeNull(List *l){
    l->last=0;
}
Position end(List *l){
    return l->last+1;
}
void insert(ElementType x,Position p,List *l){
    if(p<1||p>l->last+1||l->last>=MAXLENGTH){
        return;
    }
    for(int i=l->last;i>=p;i--){
        l->elements[i]=l->elements[i-1];
    }
    l->elements[p-1]=x;
    l->last++;
}
void delete(Position p,List *l){
    if(p<1||p>l->last+1||l->last>=MAXLENGTH){
        return;
    }
    for(int i=p;i<l->last;i++){
        l->elements[i-1]=l->elements[i];
    }
    l->last--;
}
Position first(List *l){
    return 1;
}
Position next(Position p,List *l){
    if(p<1||p>l->last+1||l->last>=MAXLENGTH){
        return -1;
    }
    return p+1;
}
void printList(List *l){
    for(int i=0;i<l->last;i++){
        printf("%s: %d",l->elements[i].name,l->elements[i].mark);
        if(i<l->last+1){
            printf("\n");
        }
    }
    printf("---END---\n");
}
Position locate(char *name,List *l){
    for(Position p=1;p<l->last;p++){
        if(strcmp(name,l->elements[p-1].name)==0){
            return p;
        }
    }
    return end(l);
}
int main(){
    List l;
    makeNull(&l);
    ElementType s1={"Harry Potter",10};
    ElementType s2={"Hermione Granger",8};
    ElementType s3={"Draco Malfoy",7};
    ElementType s4={"Luna Lovegood", 8};
    ElementType s5={"Ron Weasley", 9};
    insert(s1,end(&l),&l);
    insert(s2,end(&l),&l);
    insert(s3,end(&l),&l);
    insert(s4,end(&l),&l);
    insert(s5,end(&l),&l);
    printList(&l);
    ElementType s6={"Ginny Weasley",6};
    insert(s6,2,&l);
    printList(&l);
    delete(3,&l);
    printList(&l);
    char s[51];
    fgets(s,51,stdin);
    s[strcspn(s,"\n")]='\0';
    Position found=locate(s,&l);
    if( found!=end(&l)){
        printf("%d",l.elements[found-1].mark);
    }
    else{
        return -1;
    }
}
//locate(x, pL)*
Position locate(ElementType x,List *l){
    Position p=*l;
    while(p->next!=NULL){
        if(p->next->element==x){
            break;
        }
        p=p->next;
    }
    return p;
}
//previous(p, L)*
Position previous(Position p,List *l){
    Position q=*l;
    while(q->next!=NULL&&q->next!=p){
        q=q->next;
    }
    return q;
}
//first(p, L)*
Position first(List *l){
    return *l;
}
//next(p, L)*
Position next(Position p,List *l){
    return p->next;
}
//printList(L)*
void printList(List *l){
    Position p=*l;
    if(p->next==NULL){
        printf("empty");
    }
    while(p->next!=NULL){
        printf("%.2lf",p->next->element);
        p=p->next;
        if(p->next!=NULL){
            printf(", ");
        }
    }
}
//retrieve(p, pL)*
ElementType retrieve(Position p,List *l){
    return p->next->element;
}
// end(List *pL)*
Position end(List *l){
    Position p=*l;
    while(p->next!=NULL){
        p=p->next;
    }
    return p;
}
// makeNull(L)*
Position makeNull(List *l){
    (*l)=(Position)malloc(sizeof(Cell));
    (*l)->element=16678;
    (*l)->next=NULL;
    return *l;
}
//insert(x, p, pL)*
void insert(ElementType x,Position p,List *l){
    Position temp=p->next;
    p->next=(Position)malloc(sizeof(Cell));
    
    p->next->element=x;
    p->next->next=temp;
}
//delete(p, L)*
void delete(Position p,List *l){
    Position temp=p->next;
    p->next=temp->next;
    free(temp);
}
//Define a Data Structure List (using pointers) to store integers (max: 100) and implement some basic operators: end(), insert(), locate, retrieve(), delete(), first(), next(), makeNull(), printList()
#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;
struct Cell{
    ElementType element;
    struct Cell *next;
};
typedef struct Cell *Position;
typedef Position List;
Position end(List *l){
    Position p=*l;
    while(p->next!=NULL){
        p=p->next;
    }
    return p;
}
void  insert(ElementType x,Position p,List *l){
    Position temp=p->next;
    p->next=(Position)malloc(sizeof(struct Cell));
    p->next->element=x;
    p->next->next=temp;
}
Position locate(ElementType x,List *l){
    Position p=*l;
    while(p->next!=NULL){
        if(p->next->element==x){
            break;
        }
        p=p->next;
    }
    return p;
}
ElementType retrieve(Position p,List *l){
    return p->next->element;
}
void delete(Position p,List *l){
    Position temp=p->next;
    p->next=temp->next;
    free(temp);
}
Position first(List *l){
    return *l;
}
Position next(Position p,List *l){
    return p->next;
}
Position makeNull(List *l){
    (*l)=(Position)malloc(sizeof(struct Cell));
    (*l)->next=NULL;
    return *l;
}
void printList(List *l){
    Position p=*l;
    if(p->next==NULL){
        printf("empty");
    }
    while(p->next!=NULL){
        printf("%d",p->next->element);
        p=p->next;
        if(p->next!=NULL){
            printf(", ");
        }
    }
    printf("\n");
}
int main(){
    List l;
    makeNull(&l);
    int n,temp;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        insert(temp,end(&l),&l);
    }
    printList(&l);
    Position p=l;
    for(int i=0;i<3;i++){
        p=p->next;
    }
    insert(20,p,&l);
    printList(&l);
    delete(first(&l),&l);
    printList(&l);
    int x;
    scanf("%d",&x);
    if(locate(x,&l)->next!=NULL){
        printf("%d is in L.\n", x);
    }
    else {
        printf("%d is not in L.\n", x);
    }
}
//Define a data structure List to store Students (using pointers) 
Implement some basic operators: end(), insert(), delete(), makeNull(), first(), next(), printList()
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    char name[51];
    int mark;
} ElementType;
struct Cell{
    ElementType element;
    struct Cell *next;
};

typedef struct Cell *Position;
typedef Position List;
Position end(List *l){
    Position p=*l;
    while(p->next!=NULL){
        p=p->next;
    }
    return p;
}
void insert(ElementType x,Position p,List *l){
    Position temp=p->next;
    p->next=(Position)malloc(sizeof(struct Cell));
    p->next->element=x;
    p->next->next=temp;
}
Position locate(char *name,List *l){
    Position p=*l;
    while(p->next!=NULL){
        if(strcmp(p->next->element.name,name)==0){
            break;
        }
        p=p->next;
    }
    return p;
}
ElementType retrieve(Position p,List *l){
    return p->next->element;
}
void delete(Position p,List *l){
    Position temp=p->next;
    p->next=temp->next;
    free(temp);
}
Position first(List *l){
    return *l;
}
Position next(Position p,List *l){
    return p->next;
}
Position makeNull(List *l){
    *l=(Position)malloc(sizeof(struct Cell));
    
    (*l)->next=NULL;
    return *l;
}
void printList(List *l){
    Position p=*l;
    if(p->next==NULL){
        printf("empty");
    }
    while(p->next!=NULL){
        printf("%s: %d\n",p->next->element.name,p->next->element.mark);
        p=p->next;
    }
    printf("---END---\n");
}
int main(){
    List l;
    makeNull(&l);
    ElementType s1={"Harry Potter",10};
    ElementType s2={"Hermione Granger",8};
    ElementType s3={"Draco Malfoy",7};
    ElementType s4={"Luna Lovegood",8};
    ElementType s5={"Ron Weasley",9};
    insert(s1,end(&l),&l);
    insert(s2,end(&l),&l);
    insert(s3,end(&l),&l);
    insert(s4,end(&l),&l);
    insert(s5,end(&l),&l);
    printList(&l);
    ElementType s6={"Ginny Weasley",6};
    Position p = l;
    for(int i=0;i<1;i++){
        p=p->next;
        
    }
    insert(s6,p,&l);
    printList(&l);
    for(int i=0;i<1;i++){
        p=p->next;
    }
    delete(p,&l);
    printList(&l);
    char s[51];
    fgets(s,51,stdin);
    s[strcspn(s,"\n")]='\0';
    Position found=locate(s,&l);
    if (found->next != NULL) {
        printf("%d\n", found->next->element.mark);
    } else {
        printf("-1\n");
    }
}
//makeNull(S)
void makeNull(Stack *s){
    s->top=MAXLENGTH;
}
//empty(S) 
int empty(Stack *s){
    return s->top==MAXLENGTH;
}
//pop(S)
void pop(Stack *s){
    if(s->top==MAXLENGTH){
        printf("Error: stack is empty.\n");
        return;
    }
    s->top++;
}
//top(S) 
ElementType top(Stack *s){
    if(s->top==MAXLENGTH){
        return -90.67;
    }
    return s->elements[s->top];
}
// push(x, S)
void push(ElementType x,Stack *s){
    if(s->top==0){
        printf("Error: stack is full\n");
        return;
    }
    s->top--;
    s->elements[s->top]=x;
}
// push(x, S)*
void push(ElementType x,Stack *s){
    Cell *temp=*s;
    *s=malloc(sizeof(Cell));
    (*s)->element=x;
    (*s)->next=temp;
}
//top(S)*
ElementType top(Stack *s){
    if(*s==NULL){
        return -96.53;
    }
    return (*s)->element;
}
//makeNull(S)*
void makeNull(Stack *s){
    (*s)=NULL;
}
//pop(S)*
void pop(Stack *s){
    if(*s==NULL){
        printf("Error: stack is empty.\n");
        return;
    }
    Cell *temp=*s;
    *s=temp->next;
    free(temp);
}
//empty(S)*
int empty(Stack *s){
    return *s==NULL;
}
//Write a program to convert an integer n in binary form. n is read from stdin.
#include<stdio.h>
#define MAXLENGTH 100
typedef int ElementType;
typedef struct{
    ElementType elements[MAXLENGTH];
    int top;
}Stack;
void pop(Stack *s){
    if(s->top==MAXLENGTH){
        printf("Error: stack is empty.");
    }
    s->top++;
}
void makeNull(Stack *s){
    s->top=MAXLENGTH;
}
int empty(Stack *s){
    return s->top==MAXLENGTH;
}
void push(ElementType x,Stack *s){
    if(s->top==0){
        printf("Error: stack is full\n");
        return;
    }
    s->top--;
    s->elements[s->top]=x;
}
ElementType top(Stack *s){
    if(s->top==MAXLENGTH){
        return -97.94;
    }
    return s->elements[s->top];
}
int main(){
    Stack s;
    makeNull(&s);
    int n;
    scanf("%d",&n);
    while(n!=0){
        push(n%2,&s);
        n/=2;
    }
    while(!empty(&s)){
        printf("%d",top(&s));
        pop(&s);
    }
}
//Write a program to evaluate a postfix expression read from stdin.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXLENGTH 100
typedef double ElementType;
typedef struct{
    ElementType elements[MAXLENGTH];
    int top;
}Stack;
void pop(Stack *s){
    if(s->top==MAXLENGTH){
        printf("Error: stack is empty.");
    }
    s->top++;
}
void makeNull(Stack *s){
    s->top=MAXLENGTH;
}
int empty(Stack *s){
    return s->top==MAXLENGTH;
}
void push(ElementType x,Stack *s){
    if(s->top==0){
        printf("Error: stack is full\n");
        return;
    }
    s->top--;
    s->elements[s->top]=x;
}
ElementType top(Stack *s){
    if(s->top==MAXLENGTH){
        return -97.94;
    }
    return s->elements[s->top];
}
int main(){
    Stack s;
    makeNull(&s);
    char n[MAXLENGTH];
    scanf("%s",n);
    for(int i=0;n[i]!='\0';i++){
        if(isdigit(n[i])){
            push(n[i]-'0',&s);
        }
        else if(n[i]=='+'||n[i]=='-'||n[i]=='*'||n[i]=='/'){
            if(s.top==0){
                printf("day\n");
                
            }
            ElementType b=top(&s);
            pop(&s);
            ElementType a=top(&s);
            pop(&s);
            ElementType c;
            switch(n[i]){
                case '+':c=a+b;break;
                case '-':c=a-b;break;
                case '*':c=a*b;break;
                case '/':c=a/b;break;
            }
            push(c,&s);
        }
    }
    printf("%.2lf",top(&s));
}
//Write a program to evaluate a postfix expression read from stdin.*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef double ElementType;

typedef struct Node {
    ElementType element;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

void makeNull(Stack* s) {
    while (s->top != NULL) {
        Node* temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
}

int empty(Stack* s) {
    return s->top == NULL;
}

void push(ElementType x, Stack* s) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: memory allocation failed\n");
        return;
    }
    newNode->element = x;
    newNode->next = s->top;
    s->top = newNode;
}

void pop(Stack* s) {
    if (empty(s)) {
        printf("Error: stack is empty\n");
        return;
    }
    Node* temp = s->top;
    s->top = s->top->next;
    free(temp);
}

ElementType top(Stack* s) {
    if (empty(s)) {
        printf("Error: stack is empty\n");
        return -97.94;
    }
    return s->top->element;
}

int main() {
    Stack s;
    makeNull(&s);
    char n[100];
    scanf("%s", n);
    
    for (int i = 0; n[i] != '\0'; i++) {
        if (isdigit(n[i])) {
            push(n[i] - '0', &s);
        } else if (n[i] == '+' || n[i] == '-' || n[i] == '*' || n[i] == '/') {
            if (empty(&s)) {
                printf("Error: insufficient operands\n");
                return 1;
            }
            ElementType b = top(&s);
            pop(&s);
            if (empty(&s)) {
                printf("Error: insufficient operands\n");
                return 1;
            }
            ElementType a = top(&s);
            pop(&s);
            ElementType c;
            switch (n[i]) {
                case '+': c = a + b; break;
                case '-': c = a - b; break;
                case '*': c = a * b; break;
                case '/': 
                    if (b == 0) {
                        printf("Error: division by zero\n");
                        return 1;
                    }
                    c = a / b; 
                    break;
            }
            push(c, &s);
        }
    }
    
    if (!empty(&s)) {
        printf("%.2lf\n", top(&s));
    } else {
        printf("Error: empty stack\n");
    }
    
    makeNull(&s); // Clean up
    return 0;
}
//Write a program to convert an integer n in binary form. n is read from stdin.*
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct Node {
    ElementType element;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

void makeNull(Stack* s) {
    while (s->top != NULL) {
        Node* temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
}

int empty(Stack* s) {
    return s->top == NULL;
}

void push(ElementType x, Stack* s) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: memory allocation failed\n");
        return;
    }
    newNode->element = x;
    newNode->next = s->top;
    s->top = newNode;
}

void pop(Stack* s) {
    if (empty(s)) {
        printf("Error: stack is empty\n");
        return;
    }
    Node* temp = s->top;
    s->top = s->top->next;
    free(temp);
}

ElementType top(Stack* s) {
    if (empty(s)) {
        printf("Error: stack is empty\n");
        return -97; // Changed to integer since ElementType is int
    }
    return s->top->element;
}

int main() {
    Stack s;
    makeNull(&s);
    int n;
    scanf("%d", &n);
    
    if (n == 0) {
        printf("0");
    } else {
        while (n != 0) {
            push(n % 2, &s);
            n /= 2;
        }
        while (!empty(&s)) {
            printf("%d", top(&s));
            pop(&s);
        }
    }
    
    makeNull(&s); // Clean up
    return 0;
}
//enqueue(x, Q)
void enqueue(ElementType x,Queue *q){
    if((q->front==0&&q->rear==MAXLENGTH-1)||(q->rear+1)%MAXLENGTH==q->front){
        printf("Error: Queue is full, cannot enqueue.\n");
        return;
    }
    if(q->front==-1){
        q->front=0;
        q->rear=-1;
    }
    q->rear=(q->rear+1)%MAXLENGTH;
    q->elements[q->rear]=x;
}
//makeNull(Q)
void makeNull(Queue *q){
    q->front=-1;
    q->rear=-1;
}
//dequeue(Q)
void dequeue(Queue *q){
    if(q->front==-1){
        printf("Error: Queue is empty, cannot dequeue.\n");
        return;
    }
    if(q->front==q->rear){
        q->rear=-1;
        q->front=-1;
        return;
    }
    q->front=(q->front+1)%MAXLENGTH;
}
//empty(Q)
int empty(Queue *q){
    return q->front==-1;
}
// front(Q)
ElementType front(Queue *q){
    if(q->front==-1){
        return 93.94;
    }
    return q->elements[q->front];
}
//makeNull(Q)*
void makeNull(Queue *q){
    Position temp=malloc(sizeof(Cell));
    temp->next=NULL;
    q->front=temp;
    q->rear=temp;
}
//empty(Q)*
int empty(Queue *q){
    return q->front->next==NULL;
}
//front(Q)*
ElementType front(Queue *q){
    if(q->front->next==NULL){
        return 95.66;
    }
    return q->front->next->element;
}
//dequeue(Q)*
void dequeue(Queue *q){
    if(q->front->next==NULL){
        printf("Error: Queue is empty, cannot dequeue.\n");
        return;
    }
    Position temp=q->front;
    q->front=temp->next;
    free(temp);
}
//enqueue(x,Q)*
void enqueue(ElementType x,Queue *q){
    q->rear->next=malloc(sizeof(Cell));
    q->rear->next->element=x;
    q->rear->next->next=NULL;
    q->rear=q->rear->next;
}
//Define a Data Structure Queue (using circular array) to store integers (max: 100) and implement some basic operators:
#include<stdio.h>
#define MAXLENGTH 20
typedef int ElementType;
typedef struct{
    ElementType elements[MAXLENGTH];
    int front,rear;
}Queue;
void makeNull(Queue *q){
    q->front=-1;
    q->rear=-1;
}
int empty(Queue *q){
    return q->front==-1;
}
ElementType front(Queue *q){
    if(empty(q)){
        return -1;
    }
    return q->elements[q->front];
}
ElementType dequeue(Queue *q){
    if(q->front==-1){
        return 0;
    }
    ElementType temp=q->elements[q->front];
    if(q->front==q->rear){
        q->rear=-1;
        q->front=-1;
    }
    else{
        q->front=(q->front+1)%MAXLENGTH;
    }
    return temp;
}
void enqueue(ElementType x,Queue *q){
    if((q->front==0&&q->rear==MAXLENGTH-1)||(q->rear+1)%MAXLENGTH==q->front){
        return;
    }
    if(empty(q)){
        q->front=0;
        q->rear=-1;
        
    }
    q->rear=(q->rear+1)%MAXLENGTH;
    q->elements[q->rear]=x;
}
int main(){
    Queue q;
    makeNull(&q);
    int n;
    scanf("%d",&n);
    enqueue(n,&q);
    while(!empty(&q)){
        n=dequeue(&q);
        printf("%d\n",n);
        for(int i=2;i<=n/2;i++){
        if(n%i==0){
            enqueue(i,&q);
           }
        }
    }
}
//Define a Data Structure Queue (using pointers) to store integers and implement some basic operators:
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType; 

typedef struct CellTag {
    ElementType element;
    struct CellTag *next;
} Cell;

typedef Cell *Position;

typedef struct {
    Position front, rear;
} Queue;


void makeNull(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}


int empty(Queue *q) {
    return q->front == NULL;
}


ElementType front(Queue *q) {
    if (q->front == NULL) {
        printf("Error: Queue is empty, cannot get front.\n");
        exit(1);
    }
    return q->front->element;
}


ElementType dequeue(Queue *q) {
    if (q->front == NULL) {
        printf("Error: Queue is empty, cannot dequeue.\n");
        exit(1);
    }
    Position temp = q->front;
    ElementType result = temp->element;
    q->front = temp->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return result; 
}


void enqueue(ElementType x, Queue *q) {
    Position newNode = malloc(sizeof(Cell));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    newNode->element = x;
    newNode->next = NULL;
    if (q->front == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int main() {
    Queue q;
    int n;
    makeNull(&q);
    scanf("%d", &n);
    if (n <= 0) {
        printf("n phai la so nguyen duong!\n");
        return 1;
    }
    enqueue(n, &q);
    while (!empty(&q)) {
        n = dequeue(&q);
        printf("%d\n", n);
        for (int i = 2; i <= n / 2; i++) {
            if (n % i == 0) {
                enqueue(i, &q);
            }
        }
    }
    return 0;
}
//Define a Data Structure Queue (using circular array) to store strings (max: 50 characters) and implement some basic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLENGTH 100
typedef struct {
    char data[50];
} ElementType;

typedef struct {
	ElementType elements[MAXLENGTH];
    int front, rear;
} Queue;


void enqueue(ElementType x, Queue *pQ) {
    if ((pQ->rear + 1) % MAXLENGTH == pQ->front) {
        printf("Error: full queue.\n");
        return;
    }
    
    pQ->rear = (pQ->rear + 1) % MAXLENGTH;
    pQ->elements[pQ->rear] = x;
    
    if (pQ->front == -1)
        pQ->front = 0;
}

ElementType front(Queue *pQ) {
	return pQ->elements[pQ->front];
}


void dequeue(Queue *pQ) {
    if (pQ->front == pQ->rear)
        pQ->front = pQ->rear = -1;
    else
        pQ->front = (pQ->front + 1) % MAXLENGTH;
}

int empty(Queue *pQ) {
    return pQ->front == -1;
}

void makeNull(Queue *pQ) {
    pQ->front = pQ->rear = -1;
}

int main() {
	Queue Q;
	makeNull(&Q);

	ElementType d;
	char c[50];
	
	while (1) {
	    scanf("%s", c);
        if (strcmp(c, "DONE") == 0)
        break;
        
        if (strcmp(c, "ADD") == 0) {
            scanf("%s", d.data);
            enqueue(d, &Q);
        } else if (strcmp(c, "PRINT") == 0) {
            if (empty(&Q)) {
                printf("Queue is empty, cannot print.\n");
                continue;
            }
            printf("Print %s\n", front(&Q).data);
            dequeue(&Q);
        } else if (strcmp(c, "CANCEL") == 0) {
            if (empty(&Q)) {
                printf("Queue is empty, cannot cancel.\n");
                continue;
            }
            printf("Delete %s\n", front(&Q).data);
            dequeue(&Q);
        }
    }

	return 0;
}
//Define a Data Structure Queue (using circular array) to store strings (max: 50 characters) and implement some basic*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char data[50];
} ElementType;


typedef struct Node {
    ElementType element;
    struct Node* next;
} Node;

typedef Node* Position;

typedef struct {
    Position front, rear;
} Queue;


void makeNull(Queue *Q) {
    Q->front = NULL;
    Q->rear = NULL;
}


int empty(Queue *Q) {
    return Q->front == NULL;
}


void enqueue(ElementType x, Queue *Q) {
    Position newNode = (Position)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    newNode->element = x;
    newNode->next = NULL;
    if (empty(Q)) {
        Q->front = newNode;
        Q->rear = newNode;
    } else {
        Q->rear->next = newNode;
        Q->rear = newNode;
    }
}


ElementType dequeue(Queue *Q) {
    ElementType emptyStr = {""};
    if (empty(Q)) {
        return emptyStr; 
    }
    Position temp = Q->front;
    ElementType result = temp->element;
    Q->front = temp->next;
    if (Q->front == NULL) {
        Q->rear = NULL;
    }
    free(temp);
    return result;
}


ElementType front(Queue *Q) {
    ElementType emptyStr = {""};
    if (empty(Q)) {
        return emptyStr; 
    }
    return Q->front->element;
}

int main() {
    Queue Q;
    char command[50];
    ElementType x;
    makeNull(&Q);
    while (1) {
        scanf("%s", command);
        if (strcmp(command, "DONE") == 0) {
            break;
        }
        
        if (strcmp(command, "ADD") == 0) {
            scanf("%s", x.data); 
            enqueue(x, &Q);
        } else if (strcmp(command, "PRINT") == 0) {
            if (empty(&Q)) {
                printf("Queue is empty, cannot print.\n");
            } else {
                ElementType result = dequeue(&Q);
                printf("Print %s\n", result.data);
            }
        } else if (strcmp(command, "CANCEL") == 0) {
            if (empty(&Q)) {
                printf("Queue is empty, cannot cancel.\n");
            } else {
                ElementType result = dequeue(&Q);
                printf("Delete %s\n", result.data);
            }
        } else {
            printf("Unknown command: %s\n", command);
        }
    }
    
    return 0;
}
//makeNull(T)
void makeNull(Tree *t){
    t->maxNode=-1;
}
//empty(T)
int empty(Tree *t){
    return t->maxNode==-1;
}
//parent(n, T)
Node parent(Node n,Tree *t){
    if(n<0||n>t->maxNode){
        return -1;
    }
    return t->P[n];
}
//label(n, T)
LabelType label(Node n,Tree *t){
    if(n<0||n>t->maxNode){
        return '4';
    }
    return t->L[n];
}
//root(T)
Node root(Tree *t){
    if(t->maxNode==-1){
        return -1;
    }
    return 0;
}
//leftmostChild(n, T)
Node leftmostChild(Node n,Tree *t){
    if(n<0||t->maxNode==-1){
        return -1;
    }
    for(int i=n+1;i<=t->maxNode;i++){
        if(t->P[i]==n){
            return i;
        }
    }
    return -1;
}
//rightSibling(n, T)
Node rightSibling(Node n,Tree *t){
    if(n<0||n>t->maxNode){
        return -1;
    }
    for(int i=n+1;i<=t->maxNode;i++){
        if(t->P[i]==t->P[n]){
            return i;
        }
    }
    return -1;
}
//preorder(n, T)
void preorder(Node n,Tree *t){
    if(n<0||n>t->maxNode){
        return;
    }
    printf("%c",label(n,t));
    Node child=leftmostChild(n,t);
    while(child!=-1){
        printf(" ");
        preorder(child,t);
        child=rightSibling(child,t);
    }
}
//inorder(n, T)
void inorder(Node n,Tree *t){
    if(n<0||n>t->maxNode){
        return;
    }
    Node child=leftmostChild(n,t);
    if (child != NULL_NODE) {
        inorder(child, t);
        printf(" ");
    }
    printf("%c",label(n,t));
    child=rightSibling(child,t);
    while(child!=-1){
        printf(" ");
        inorder(child,t);
        child=rightSibling(child,t);
    }
}
//postorder(n, T)
void postorder(Node n,Tree *t){
    if(n<0||n>t->maxNode){
        return;
    }
    Node child=leftmostChild(n,t);
    while(child!=-1){
        postorder(child,t);
        child=rightSibling(child,t);
        if (child != -1 || n != -1) {
            printf(" ");
        }
    }
    printf("%c",label(n,t));
}
//height(n, T)
int height(Node n,Tree *t){
    if(n<0||n>t->maxNode){
        return -1;
    }
    int Height=0;
    Node child=leftmostChild(n,t);
    while(child!=-1){
        int childheight=height(child,t);
        if(Height<childheight+1){
           Height=childheight+1;
        }
        child=rightSibling(child,t);
    }
    return Height;
}
//depth(n, T)
int depth(Node n, Tree *pT) {
    if (n < 0 || n > pT->maxNode) {
        return -1;
    }
    int Depth = 0;
    Node temp = n;
    while (pT->P[temp] != NULL_NODE) {
        temp=pT->P[temp];
        Depth++;
    }
    return Depth;
}
//Use the snippet below to read a tree from stdin
#include <stdio.h>

#define MAXLENGTH 100
#define NULL_NODE -1

typedef int Node;
typedef char LabelType;

typedef struct {
    Node      P[MAXLENGTH];
    LabelType L[MAXLENGTH];
    int maxNode;
} Tree;
void makeNull(Tree *t){
    t->maxNode=-1;
}
int empty(Tree *t){
    return t->maxNode==-1;
}
Node parent(Node n,Tree *t){
    if(n<0||n>t->maxNode){
        return -1;
    }
    return t->P[n];
}
LabelType label(Node n,Tree *t){
    if(n<0||n>t->maxNode){
        return '4';
    }
    return t->L[n];
}
Node root(Tree *t){
    if(t->maxNode==-1){
        return -1;
    }
    return 0;
}
Node leftmostChild(Node n,Tree *t){
    if(n<0||t->maxNode==-1){
        return -1;
    }
    for(int i=n+1;i<=t->maxNode;i++){
        if(t->P[i]==n){
            return i;
        }
    }
    return -1;
}
Node rightSibling(Node n,Tree *t){
    if(n<0||n>t->maxNode){
        return -1;
    }
    for(int i=n+1;i<=t->maxNode;i++){
        if(t->P[i]==t->P[n]){
            return i;
        }
    }
    return -1;
}
void preorder(Node n,Tree *t){
    if(n<0||n>t->maxNode){
        return;
    }
    printf("%c",label(n,t));
    Node child=leftmostChild(n,t);
    while(child!=-1){
        printf(" ");
        preorder(child,t);
        child=rightSibling(child,t);
    }
}
void inorder(Node n,Tree *t){
    if(n<0||n>t->maxNode){
        return;
    }
    Node child=leftmostChild(n,t);
    if (child != NULL_NODE) {
        inorder(child, t);
        printf(" ");
    }
    printf("%c",label(n,t));
    child=rightSibling(child,t);
    while(child!=-1){
        printf(" ");
        inorder(child,t);
        child=rightSibling(child,t);
    }
}
void postorder(Node n,Tree *t){
    if(n<0||n>t->maxNode){
        return;
    }
    Node child=leftmostChild(n,t);
    while(child!=-1){
        postorder(child,t);
        child=rightSibling(child,t);
        if (child != -1 || n != -1) {
            printf(" ");
        }
    }
    printf("%c",label(n,t));
}
int height(Node n,Tree *t){
    if(n<0||n>t->maxNode){
        return -1;
    }
    int Height=0;
    Node child=leftmostChild(n,t);
    while(child!=-1){
        int childheight=height(child,t);
        if(Height<childheight+1){
           Height=childheight+1;
        }
        child=rightSibling(child,t);
    }
    return Height;
}
int depth(Node n, Tree *pT) {
    if (n < 0 || n > pT->maxNode) {
        return -1;
    }
    int Depth = 0;
    Node temp = n;
    while (pT->P[temp] != NULL_NODE) {
        temp=pT->P[temp];
        Depth++;
    }
    return Depth;
}
int main(){
    Tree t;
    int n;
    scanf("%d", &n);    
    t.maxNode = n - 1;  

    for (int i = 0; i < n; i++) 
        scanf(" %c", &t.L[i]);
    t.P[0] = NULL_NODE;         
    for (int i = 1; i < n; i++) 
        scanf("%d", &t.P[i]);
    preorder(0, &t);
    printf("\n");
    inorder(0, &t);
    printf("\n");
    postorder(0, &t);
    printf("\n");
    int u;
    scanf("%d", &u);
    printf("%d\n", height(u, &t));
    printf("%d\n", depth(u, &t));
}
//buildTree(T)
void buildTree(Tree *pT) {
    // Set maxNode for 11 nodes (indices 0 to 10)
    pT->maxNode = 10;

    // Assign labels to nodes
    pT->L[0] = 'I';  // Node 0
    pT->L[1] = 'A';  // Node 1
    pT->L[2] = 'C';  // Node 2
    pT->L[3] = 'B';  // Node 3
    pT->L[4] = 'G';  // Node 4
    pT->L[5] = 'F';  // Node 5
    pT->L[6] = 'H';  // Node 6
    pT->L[7] = 'J';  // Node 7
    pT->L[8] = 'E';  // Node 8
    pT->L[9] = 'K';  // Node 9
    pT->L[10] = 'D'; // Node 10

    // Assign parents as specified
    pT->P[0] = NULL_NODE; // Node 0 (I, root)
    pT->P[1] = 0;        // Node 1 (A, parent I)
    pT->P[2] = 0;        // Node 2 (C, parent I)
    pT->P[3] = 0;        // Node 3 (B, parent I)
    pT->P[4] = 1;        // Node 4 (G, parent A)
    pT->P[5] = 1;        // Node 5 (F, parent A)
    pT->P[6] = 1;        // Node 6 (H, parent A)
    pT->P[7] = 3;        // Node 7 (J, parent B)
    pT->P[8] = 5;        // Node 8 (E, parent F)
    pT->P[9] = 5;        // Node 9 (K, parent F)
    pT->P[10] = 8;       // Node 10 (D, parent E)
}
//makeNull(T)*
void makeNull(Tree *t){
    *t=NULL;
}
// empty(T)*
int empty(Tree *t){
    return *t==NULL;
}
//parent(n)*
Node* parent(Node *n){
    if(n==NULL){
        return NULL;
    }
    return n->parent;
}
//leftmostChild(n)*
Node* leftmostChild(Node *n){
    if(n==NULL){
        return NULL;
    }
    return n->leftmost_child;
}
//rightSibling(n)*
Node* rightSibling(Node *n){
    if(n==NULL){
        return NULL;
    }
    return n->right_sibling;
}
//label(n)*
LabelType label(Node *n){
    if(n==NULL){
        return '!';
    }
    return n->label;
}
//preorder(n)*
void preorder(Node *n){
    if(n==NULL){
        return;
    }
    printf("%c ",n->label);
    preorder(n->leftmost_child);
    preorder(n->right_sibling);
}
//postorder(n)*
void postorder(Node *n){
    if(n==NULL){
        return;
    }
    Node *child=leftmostChild(n);
    while(child!=NULL){
        postorder(child);
        child=rightSibling(child);
    }
    printf("%c ",n->label);
}
// inorder(n)*
void inorder(Node *n){
    if(n==NULL){
        return;
    }
    Node *child=leftmostChild(n);
    if(child!=NULL){
        inorder(child);
    }
    printf("%c ",n->label);
    child=rightSibling(child);
    while(child!=NULL){
        inorder(child);
        child=rightSibling(child);
    }
}
// height(n)*
int height(Node *n){
    if(n==NULL){
        return -1;
    }
    int Height=0;
    Node *child=leftmostChild(n);
    while(child!=NULL){
        int childheight=height(child);
        if(Height<childheight+1){
            Height=childheight+1;
        }
        child=rightSibling(child);
    }
    return Height;
}
//depth(n)*
int depth(Node *n){
    if(n==NULL){
        return -1;
    }
    if(parent(n)==NULL){
        return 0;
    }
    return depth(parent(n))+1;
}
//create0(v)
Tree create0(LabelType v){
    Node *root=(Node *)malloc(sizeof(Node));
    root->parent=NULL;
    root->label=v;
    root->leftmost_child=NULL;
    root->right_sibling=NULL;
    return root;
}
//create1(v, T1)
Tree create1(LabelType v, Tree T1){
    Node *root=(Node *)malloc(sizeof(Node));
    root->label=v;
    root->parent=NULL;
    root->right_sibling=NULL;
    root->leftmost_child=T1;
    if(T1!=NULL){
        return T1->parent=root;
    }
    if(T1==NULL){
        printf("Error: T1 is null, cannot create1.\n");
        return NULL;
    }
    return root;
}
//create2(v, T1, T2)
Tree create2(LabelType v,Tree T1, Tree T2){
    Node *root=(Node *)malloc(sizeof(Node));
    root->label=v;
    root->parent=NULL;
    root->leftmost_child=T1;
    root->right_sibling=NULL;
    while(T1!=NULL||T2!=NULL){
        T1->parent=root;
        T2->parent=root;
        break;
    }
    if(T1==NULL||T2==NULL){
        printf("Error: T1 or T2 is null, cannot create2.\n");
        return NULL;
    }
    T1->right_sibling=T2;
    T2->right_sibling=NULL;
    return root;
}
//insertNode(v, parent, leftSibling)
Node *insertNode(LabelType v,Node *parent, Node *left){
    Node *root=(Node *)malloc(sizeof(Node));
    root->parent=parent;
    root->label=v;
    if(left){
        root->right_sibling=left->right_sibling;
        left->right_sibling=root;
    }
    else{
        root->right_sibling=parent->leftmost_child;
        parent->leftmost_child=root;
    }
    return root;
}
// appendNode(v, parent)
Node *appendNode(LabelType v,Node *parent){
    Node *root=(Node *)malloc(sizeof(Node));
    root->parent=parent;
    root->label=v;
    root->leftmost_child=NULL;
    root->right_sibling=NULL;
    Node *left=parent->leftmost_child;
    if(!left){
        parent->leftmost_child=root;return root;
    }
    while(left->right_sibling!=NULL){
        left=left->right_sibling;
    }
    left->right_sibling=root;
    return root;
}
//locate(v, n)
Node* locate(LabelType v, Tree n) {
    if (n == NULL_NODE) {
        return NULL_NODE;
    }
    if (n->label == v) {
        return n;
    }
    for (Node* child = n->leftmost_child; child != NULL_NODE; child = child->right_sibling) {
        Node* result = locate(v, child);
        if (result != NULL_NODE) {
            return result;
        }
    }
    return NULL_NODE;
}
//buildTree()*
       G
      / \
     Q   N
    /     \
   H       K
  /
 U
Node* create_node(LabelType label) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->parent = NULL_NODE;
    node->leftmost_child = NULL_NODE;
    node->right_sibling = NULL_NODE;
    node->label = label;
    return node;
}

// Function to build the tree with labels G, Q, N, H, K, U
Tree buildTree() {
    // Create nodes for each label
    Node* G = create_node('G');
    Node* Q = create_node('Q');
    Node* N = create_node('N');
    Node* H = create_node('H');
    Node* K = create_node('K');
    Node* U = create_node('U');

    // Set up the tree structure based on provided relationships
    // G: parent = NULL, leftmost_child = Q, right_sibling = NULL
    G->leftmost_child = Q;

    // Q: parent = G, leftmost_child = H, right_sibling = N
    Q->parent = G;
    Q->leftmost_child = H;
    Q->right_sibling = N;

    // N: parent = G, leftmost_child = K, right_sibling = NULL
    N->parent = G;
    N->leftmost_child = K;

    // H: parent = Q, leftmost_child = U, right_sibling = NULL
    H->parent = Q;
    H->leftmost_child = U;

    // K: parent = N, leftmost_child = NULL, right_sibling = NULL
    K->parent = N;

    // U: parent = H, leftmost_child = NULL, right_sibling = NULL
    U->parent = H;

    return G;
}
// create2(v, T1, T2)bt
Tree create2(LabelType v, Tree T1, Tree T2) {
    Node *root = (Node *)malloc(sizeof(Node));
    root->label = v;
    root->parent = NULL_NODE;
    root->left = T1;
    root->right = T2;
    if (T1 != NULL_NODE) {
        T1->parent = root; 
    }
    if (T2 != NULL_NODE) {
        T2->parent = root; 
    }
    return root;
}
//buildTree()bt vs create0
       B
      /
     C
    / \
   A   F
  /     \
 D       E
 Tree buildTree(){
    Node* B=create0('B');
    Node* C=create0('C');
    Node* A=create0('A');
    Node* D=create0('D');
    Node* F=create0('F');
    Node* E=create0('E');
    
    B->left=C;
    
    C->parent=B;
    C->left=A;
    C->right=F;
    
    A->parent=C;
    A->left=D;
    
    D->parent=A;
    
    F->parent=C;
    F->right=E;
    
    E->parent=F;
    return B;
}
//buildTree()bt vs create2
       B
      / \
     C   F
    / \   \
   D   E   A
   Tree buildTree(){
    Node* B=create2('B',NULL,NULL);
    Node* C=create2('C',NULL,NULL);
    Node* D=create2('D',NULL,NULL);
    Node* F=create2('F',NULL,NULL);
    Node* A=create2('A',NULL,NULL);
    Node* E=create2('E',NULL,NULL);
    
    B->left=C;
    B->right=F;
    
    C->parent=B;
    C->left=D;
    C->right=E;
    D->parent=C;
    E->parent=C;
    
    F->parent=B;
    F->right=A;
    A->parent=F;
    return B;
}
//preorder(n)bt
void preorder(Node *n){
    if(n==NULL){
        return;
    }
    printf("%c ",n->label);
    preorder(n->left);
    preorder(n->right);
}
//inorder(n)bt
void inorder(Node *n){
    if(n==NULL){
        return;
    }
    if(n!=NULL){
        inorder(n->left);
    }
    printf("%c ",n->label);
    while(n!=NULL){
        inorder(n->right);
        break;
    }
}
//postorder(n)bt
void postorder(Node *n){
    if(n==NULL){
        return;
    }
    while(n!=NULL){
        postorder(n->left);
        break;
    }
    postorder(n->right);
    printf("%c ",n->label);
}
//preorder(n)bst
void preorder(Node *n){
    if(n==NULL){
        return;
    }
    printf("%d ",n->label);
    preorder(n->left);
    preorder(n->right);
}
// inorder(n)bst
void inorder(Node *n){
    if(n==NULL){
        return;
    }
    if(n!=NULL){
        inorder(n->left);
    }
    printf("%d ",n->label);
    while(n!=NULL){
        inorder(n->right);
        break;
    }
}
//postorder(n)bst
void postorder(Node *n){
    if(n==NULL){
        return;
    }
    while(n!=NULL){
        postorder(n->left);
        break;
    }
    postorder(n->right);
    printf("%d ",n->label);
}
//insert(x, T)bst recursive
1/
void insert(LabelType x, Tree *pT) {
    // Tru?ng h?p co b?n: cây r?ng, t?o node m?i
    if (*pT == NULL) {
        *pT = (Node*)malloc(sizeof(Node));
        if (*pT == NULL) return; // Ki?m tra l?i c?p phát b? nh?
        (*pT)->label = x;
        (*pT)->left = NULL;
        (*pT)->right = NULL;
        return;
    }
    // N?u x dã t?n t?i, không làm gì
    if ((*pT)->label == x) {
        return;
    }
    
    // Ð? quy chèn vào cây con thích h?p
    if (x < (*pT)->label) {
        insert(x, &((*pT)->left));
    } else {
        insert(x, &((*pT)->right));
    }
}
2/
void insert(LabelType x, Tree *pT) {
    // Tru?ng h?p co b?n: cây r?ng, t?o node m?i
    if (*pT == NULL) {
        *pT = (Node*)malloc(sizeof(Node));
        if (*pT == NULL) return; // Ki?m tra l?i c?p phát b? nh?
        (*pT)->label = x;
        (*pT)->left = NULL;
        (*pT)->right = NULL;
        return;
    }
    // N?u x dã t?n t?i, không làm gì
    if ((*pT)->label == x) {
        printf("Error: %d has existed in the tree. Cannot insert.\n",x);
        return;
    }
    
    // Ð? quy chèn vào cây con thích h?p
    if (x < (*pT)->label) {
        insert(x, &((*pT)->left));
    } else {
        insert(x, &((*pT)->right));
    }
}
//insert(x, T)bst non-recursive
1/
void insert(LabelType x, Tree *pT) {
    // Luu tr? node hi?n t?i và node cha
    Node *temp = *pT;
    Node *parent = NULL;

    // Tìm v? trí d? chèn
    while (temp != NULL) {
        // N?u x dã t?n t?i, không làm gì
        if (temp->label == x) {
            return;
        }
        parent = temp;
        if (x < temp->label) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }

    // T?o node m?i
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return; // Ki?m tra l?i c?p phát b? nh?
    newNode->label = x;
    newNode->left = NULL;
    newNode->right = NULL;

    // Chèn node m?i vào v? trí thích h?p
    if (parent == NULL) {
        // Cây r?ng, node m?i là g?c
        *pT = newNode;
    } else if (x < parent->label) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}
2/
void insert(LabelType x, Tree *pT) {
    // Luu tr? node hi?n t?i và node cha
    Node *temp = *pT;
    Node *parent = NULL;

    // Tìm v? trí d? chèn
    while (temp != NULL) {
        // N?u x dã t?n t?i, không làm gì
        if (temp->label == x) {
            printf("Error: %d has existed in the tree. Cannot insert.\n",x);
            return;
        }
        parent = temp;
        if (x < temp->label) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }

    // T?o node m?i
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return; // Ki?m tra l?i c?p phát b? nh?
    newNode->label = x;
    newNode->left = NULL;
    newNode->right = NULL;

    // Chèn node m?i vào v? trí thích h?p
    if (parent == NULL) {
        // Cây r?ng, node m?i là g?c
        *pT = newNode;
    } else if (x < parent->label) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}
//delete(x, T)bst non-recursive
1/deleteMin
LabelType deleteMin(Tree *pT) {
    if (*pT == NULL) return 0; // Cây r?ng, tr? v? 0 (gi? d?nh không h?p l?)

    Node *temp = *pT;
    Node *parent = NULL;

    // Tìm node nh? nh?t (c?c trái)
    while (temp->left != NULL) {
        parent = temp;
        temp = temp->left;
    }

    LabelType minValue = temp->label; // Luu giá tr? nh? nh?t

    // Xóa node nh? nh?t
    if (parent == NULL) {
        // Node nh? nh?t là g?c
        *pT = temp->right;
    } else {
        // G?n cây con ph?i c?a node nh? nh?t vào parent
        parent->left = temp->right;
    }

    free(temp); // Gi?i phóng node
    return minValue;
}

// Hàm xóa node có giá tr? x kh?i cây
void delete(LabelType x, Tree *pT) {
    if (*pT == NULL) return; // Cây r?ng ho?c không tìm th?y x

    // Tìm node c?n xóa
    if (x < (*pT)->label) {
        delete(x, &((*pT)->left)); // Xóa ? cây con trái
    } else if (x > (*pT)->label) {
        delete(x, &((*pT)->right)); // Xóa ? cây con ph?i
    } else {
        // Tìm th?y node c?n xóa
        Node *temp = *pT;

        // Tru?ng h?p 1: Node không có con ho?c ch? có m?t con
        if (temp->left == NULL) {
            *pT = temp->right;
            free(temp);
        } else if (temp->right == NULL) {
            *pT = temp->left;
            free(temp);
        } else {
            // Tru?ng h?p 2: Node có c? hai con
            // Thay th? b?ng giá tr? nh? nh?t c?a cây con ph?i
            temp->label = deleteMin(&temp->right);
        }
    }
}
2/deleteMax
// Hàm h? tr? d? xóa node l?n nh?t và tr? v? giá tr? c?a nó
LabelType deleteMax(Tree *pT) {
    if (*pT == NULL) return 0; // Cây r?ng, tr? v? 0 (có th? c?n di?u ch?nh)

    Node *temp = *pT;
    Node *parent = NULL;

    // Tìm node l?n nh?t (c?c ph?i)
    while (temp->right != NULL) {
        parent = temp;
        temp = temp->right;
    }

    LabelType maxValue = temp->label; // Luu giá tr? l?n nh?t

    // Xóa node l?n nh?t
    if (parent == NULL) {
        // Node l?n nh?t là g?c
        *pT = temp->left;
    } else {
        // G?n cây con trái c?a node l?n nh?t vào parent
        parent->right = temp->left;
    }

    free(temp); // Gi?i phóng node
    return maxValue;
}

// Hàm không d? quy d? xóa node có giá tr? x
void delete(LabelType x, Tree *pT) {
    Node *temp = *pT;
    Node *parent = NULL;

    // Tìm node c?n xóa và node cha c?a nó
    while (temp != NULL && temp->label != x) {
        parent = temp;
        if (x < temp->label) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }

    // N?u không tìm th?y x, thoát
    if (temp == NULL) return;

    // Tru?ng h?p 1: Node không có con ho?c ch? có m?t con
    if (temp->left == NULL) {
        if (parent == NULL) {
            *pT = temp->right; // Xóa g?c
        } else if (temp == parent->left) {
            parent->left = temp->right;
        } else {
            parent->right = temp->right;
        }
        free(temp);
    } else if (temp->right == NULL) {
        if (parent == NULL) {
            *pT = temp->left; // Xóa g?c
        } else if (temp == parent->left) {
            parent->left = temp->left;
        } else {
            parent->right = temp->left;
        }
        free(temp);
    } else {
        // Tru?ng h?p 2: Node có c? hai con
        // Thay th? b?ng giá tr? l?n nh?t c?a cây con trái
        temp->label = deleteMax(&temp->left);
    }
}
//delete(x, T)bst recursive
// Hàm h? tr? d? quy d? xóa node nh? nh?t và tr? v? giá tr? c?a nó
1/co deleteMin
LabelType deleteMin(Tree *pT) {
    if (*pT == NULL) return 0; // Cây r?ng, tr? v? 0 (có th? c?n di?u ch?nh)

    // N?u không có con trái, dây là node nh? nh?t
    if ((*pT)->left == NULL) {
        LabelType minValue = (*pT)->label;
        Node *temp = *pT;
        *pT = (*pT)->right; // G?n cây con ph?i
        free(temp); // Gi?i phóng node
        return minValue;
    }

    // Ð? quy tìm node nh? nh?t ? cây con trái
    return deleteMin(&((*pT)->left));
}

// Hàm d? quy d? xóa node có giá tr? x
void delete(LabelType x, Tree *pT) {
    if (*pT == NULL) return; // Cây r?ng ho?c không tìm th?y x

    // Tìm node c?n xóa
    if (x < (*pT)->label) {
        delete(x, &((*pT)->left)); // Xóa ? cây con trái
    } else if (x > (*pT)->label) {
        delete(x, &((*pT)->right)); // Xóa ? cây con ph?i
    } else {
        // Tìm th?y node c?n xóa
        Node *temp = *pT;

        // Tru?ng h?p 1: Node không có con ho?c ch? có m?t con
        if (temp->left == NULL) {
            *pT = temp->right;
            free(temp);
        } else if (temp->right == NULL) {
            *pT = temp->left;
            free(temp);
        } else {
            // Tru?ng h?p 2: Node có c? hai con
            // Thay th? b?ng giá tr? nh? nh?t c?a cây con ph?i
            temp->label = deleteMin(&temp->right);
        }
    }
}
2/co deleteMax

// Hàm h? tr? d? quy d? xóa node l?n nh?t và tr? v? giá tr? c?a nó
LabelType deleteMax(Tree *pT) {
    if (*pT == NULL) return 0; // Cây r?ng, tr? v? 0 (có th? c?n di?u ch?nh)

    // N?u không có con ph?i, dây là node l?n nh?t
    if ((*pT)->right == NULL) {
        LabelType maxValue = (*pT)->label;
        Node *temp = *pT;
        *pT = (*pT)->left; // G?n cây con trái
        free(temp); // Gi?i phóng node
        return maxValue;
    }

    // Ð? quy tìm node l?n nh?t ? cây con ph?i
    return deleteMax(&((*pT)->right));
}

// Hàm d? quy d? xóa node có giá tr? x
void delete(LabelType x, Tree *pT) {
    if (*pT == NULL) return; // Cây r?ng ho?c không tìm th?y x

    // Tìm node c?n xóa
    if (x < (*pT)->label) {
        delete(x, &((*pT)->left)); // Xóa ? cây con trái
    } else if (x > (*pT)->label) {
        delete(x, &((*pT)->right)); // Xóa ? cây con ph?i
    } else {
        // Tìm th?y node c?n xóa
        Node *temp = *pT;

        // Tru?ng h?p 1: Node không có con ho?c ch? có m?t con
        if (temp->left == NULL) {
            *pT = temp->right;
            free(temp);
        } else if (temp->right == NULL) {
            *pT = temp->left;
            free(temp);
        } else {
            // Tru?ng h?p 2: Node có c? hai con
            // Thay th? b?ng giá tr? l?n nh?t c?a cây con trái
            temp->label = deleteMax(&temp->left);
        }
    }
}
//makeNull(S)
void makeNull(Set *S){
    for(int i=0;i<N;i++){
        S->data[i]=0;
    }
}
//insert(x, S)
void insert(int x,Set *S){
        S->data[x]=1;
}
//insert(x, S)
void insert(int x,Set *S){
    if(S->data[x]){
        printf("Error: element %d has existed.\n",x);
    }
    S->data[x]=1;
}
// delete(x, S)
void delete(int x,Set *S){
    S->data[x]=0;
}
//delete(x, S)
void delete(int x,Set *S){
    if(S->data[x]==0){
        printf("Error: element %d does not exist.\n",x);
    }
    S->data[x]=0;
}
//member(x, S)
int member(int x,Set *S){
    return S->data[x]==1;
}
// setUnion(A, B, C)
void setUnion(Set *A,Set *B,Set *C){
    for(int i=0;i<N;i++){
        C->data[i]=A->data[i]||B->data[i];
    }
}
//setIntersection(A, B, C)
void setIntersection(Set *A,Set *B,Set *C){
    for(int i=0;i<N;i++){
        C->data[i]=A->data[i]&&B->data[i];
    }
}
// setDifference(A, B, C)
void setDifference(Set *A,Set *B,Set *C){
    for(int i=0;i<N;i++){
        C->data[i]=A->data[i]&&!B->data[i];
    }
}
//assign(A, B)
void assign(Set *A,Set *B){
    for(int i=0;i<N;i++){
        A->data[i]=B->data[i];
    }
}
//equal(A, B)
int equal(Set *A,Set *B){
    for(int i=0;i<N;i++){
        if(A->data[i]!=B->data[i]){
            return 0;
        }
    }
     return 1;
}
//makeNull(S)*
void makeNull(Set *pS) {
    for (int i = 0; i < N; ++i)
        pS->data[i] = 0;
}
//insert(x, S)*
void insert(int x,Set *S){
        int i=x/8;
        int j=x%8;
        S->data[i]|=(1<<j);
}
// insert(x, S)*
void insert(int x,Set *S){
        int i=x/8;
        int j=x%8;
        if(S->data[i]&(1<<j)){
            printf("Error: element %d has existed.\n",x);
        }
        S->data[i]|=(1<<j);
}
//delete(x, S)*
void delete(int x,Set *S){
        int i=x/8;
        int j=x%8;
        S->data[i]&=~(1<<j);
}
//delete(x, S)*
void delete(int x,Set *S){
        int i=x/8;
        int j=x%8;
        if((S->data[i]&(1<<j))==0){
            printf("Error: element %d does not exist.\n",x);
        }
        S->data[i]&=~(1<<j);
}
//member(x, S)*
int member(int x,Set *S){
        int i=x/8;
        int j=x%8;
        return S->data[i]&(1<<j);
}
// setUnion(A, B, C)*
void setUnion(Set *A,Set *B,Set *C){
    for(int i=0;i<N;i++){
        C->data[i]=A->data[i]|B->data[i];
    }
}
//setDifference(A, B, C)*
void setDifference(Set *A,Set *B,Set *C){
    for(int i=0;i<N;i++){
        C->data[i]=A->data[i]&~B->data[i];
    }
}
//setIntersection(A, B, C)*
void setIntersection(Set *A,Set *B,Set *C){
    for(int i=0;i<N;i++){
        C->data[i]=A->data[i]&B->data[i];
    }
}
//assign(A, B)*
void assign(Set *A,Set *B){
    for(int i=0;i<N;i++){
        A->data[i]=B->data[i];
    }
}
//equal(A, B)*
int equal(Set *A,Set *B){
    for(int i=0;i<N;i++){
        if(A->data[i]!=B->data[i]){
            return 0;
        }
    }
     return 1;
}
//makeNull(S)bnt
void makeNull(Set *pS) {
    *pS = NULL;
}
//member(x, S)bnt
int member(int x, Set *pS) {
    Set current = *pS;
    while (current != NULL) {
        if (x == current->label) {
            return 1;  
        } else if (x < current->label) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    
    return 0; 
}
// insert(x, S)bnt
void insert(int x, Set *pS) {
    if (*pS == NULL) {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->label = x;
        newNode->left = NULL;
        newNode->right = NULL;
        *pS = newNode;
        return;
    }
    
    if (x == (*pS)->label) {
        return; 
    }
    
    if (x < (*pS)->label) {
        insert(x, &(*pS)->left);
    } else {
        insert(x, &(*pS)->right);
    }
}
//insert(x, S)bnt
void insert(int x, Set *pS) {
    if (*pS == NULL) {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->label = x;
        newNode->left = NULL;
        newNode->right = NULL;
        *pS = newNode;
        return;
    }
    
    if (x == (*pS)->label) {
        printf("Error: element %d has existed.\n", x);
        return;
    }
    
    if (x < (*pS)->label) {
        insert(x, &(*pS)->left);
    } else {
        insert(x, &(*pS)->right);
    }
}
//delete(x, S)bnt
void delete(int x, Set *pS) {
    if (*pS == NULL) {
        return; // x not in the tree, do nothing
    }

    if (x < (*pS)->label) {
        // x is in the left subtree
        delete(x, &(*pS)->left);
    } else if (x > (*pS)->label) {
        // x is in the right subtree
        delete(x, &(*pS)->right);
    } else {
        // Found the node to delete
        Node *temp;

        if ((*pS)->left == NULL) {
            // Case 1: no left child
            temp = *pS;
            *pS = (*pS)->right;
            free(temp);
        } else if ((*pS)->right == NULL) {
            // Case 2: no right child
            temp = *pS;
            *pS = (*pS)->left;
            free(temp);
        } else {
            // Case 3: two children
            // Find the successor (smallest in right subtree)
            Node *succ = (*pS)->right;
            while (succ->left != NULL) {
                succ = succ->left;
            }
            // Copy successor's label to current node
            (*pS)->label = succ->label;
            // Delete the successor
            delete(succ->label, &(*pS)->right);
        }
    }
}
//delete(x, S)bnt
void delete(int x, Set *pS) {
    if (*pS == NULL) {
        printf("Error: element %d does not exist.\n", x);
        return;
    }

    if (x < (*pS)->label) {
        
        delete(x, &(*pS)->left);
    } else if (x > (*pS)->label) {
        
        delete(x, &(*pS)->right);
    } else {
        
        Node *temp;

        if ((*pS)->left == NULL) {
            
            temp = *pS;
            *pS = (*pS)->right;
            free(temp);
        } else if ((*pS)->right == NULL) {
            
            temp = *pS;
            *pS = (*pS)->left;
            free(temp);
        } else {
            
            Node *succ = (*pS)->right;
            while (succ->left != NULL) {
                succ = succ->left;
            }
            
            (*pS)->label = succ->label;
            
            delete(succ->label, &(*pS)->right);
        }
    }
}
// setUnion(A, B, C)bnt
void traverseAndInsert(Set *A,Set *B){
    if(*A==NULL){
        return;
    }
    insert((*A)->label,B);
    traverseAndInsert(&(*A)->left,B);
    traverseAndInsert(&(*A)->right,B);
}
void setUnion(Set *A,Set *B,Set *C){
    makeNull(C);
    traverseAndInsert(A,C);
    traverseAndInsert(B,C);
}
//setIntersection(A, B, C)bnt
int member(int x, Set *pS) {
    Set current = *pS;
    while (current != NULL) {
        if (x == current->label) {
            return 1;  
        } else if (x < current->label) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    
    return 0; 
}
void traverseTestAndInsert(Set *A,Set *B,Set *C){
    if((*A)==NULL){
        return;
    }
    if(member((*A)->label,B))
    insert((*A)->label,C);
    traverseTestAndInsert(&(*A)->left,B,C);
    traverseTestAndInsert(&(*A)->right,B,C);
}
void setIntersection(Set *A,Set *B,Set *C){
    makeNull(C);
    traverseTestAndInsert(A,B,C);
}
//setDifference(A, B, C)bnt
int member(int x, Set *pS) {
    Set current = *pS;
    while (current != NULL) {
        if (x == current->label) {
            return 1;  
        } else if (x < current->label) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    
    return 0; 
}
void traverseTestAndInsert(Set *A,Set *B,Set *C){
    if((*A)==NULL){
        return;
    }
    if(!member((*A)->label,B))
    insert((*A)->label,C);
    traverseTestAndInsert(&(*A)->left,B,C);
    traverseTestAndInsert(&(*A)->right,B,C);
}
void setDifference(Set *A,Set *B,Set *C){
    makeNull(C);
    traverseTestAndInsert(A,B,C);
}
//assign(A, B)bnt
void traverseAndInsert(Set *A,Set *B){
    if(*A==NULL){
        return;
    }
    insert((*A)->label,B);
    traverseAndInsert(&(*A)->left,B);
    traverseAndInsert(&(*A)->right,B);
}

void assign(Set *A,Set *B){
    makeNull(A);
    traverseAndInsert(B,A);
}
//equal(A, B)bnt
int isSubset(Set *A, Set *B) {
    if((*A)==NULL){
        return 1;
    }
    if(!member((*A)->label,B))
    return 0;
    if(!isSubset(&(*A)->left,B))
    return 0;
    return isSubset(&(*A)->right,B);
}

int equal(Set *pA, Set *pB) {
    return isSubset(pA, pB) && isSubset(pB, pA);
}
//makeNull(T)
void makeNull(HashTable *T){
    for(int i=0;i<B;i++){
        T->buckets[i]=NULL;
    }
}
//member(x, T)
int member(ElementType x,HashTable *T){
    int i=h(x);
    Position p=T->buckets[i];
    while(p!=NULL){
        if(x==p->element){
            return 1;
        }
        p=p->next;
    }
    return 0;
}
//insert(x, T)
int member(ElementType x,HashTable *T){
    int i=h(x);
    Position p=T->buckets[i];
    while(p!=NULL){
        if(x==p->element){
            return 1;
        }
        p=p->next;
    }
    return 0;
}
void insert(ElementType x,HashTable *T){
    if(member(x,T)) return;
    int i=h(x);
    Position temp=T->buckets[i];
    T->buckets[i]=(Cell*)malloc(sizeof(Cell));
    T->buckets[i]->element=x;
    T->buckets[i]->next=temp;
}
//insert(x, T)
int member(ElementType x,HashTable *T){
    int i=h(x);
    Position p=T->buckets[i];
    while(p!=NULL){
        if(x==p->element){
            printf("%d has already existed in the hash table, ignore.\n",x);
            return 1;
        }
        p=p->next;
    }
    return 0;
}
void insert(ElementType x,HashTable *T){
    if(member(x,T)) return;
    int i=h(x);
    Position temp=T->buckets[i];
    T->buckets[i]=(Cell*)malloc(sizeof(Cell));
    T->buckets[i]->element=x;
    T->buckets[i]->next=temp;
}
//delete(x, T)
void delete(ElementType x,HashTable *T){
    int i=h(x);
    if(T->buckets[i]==NULL){
        return;
    }
    if(x==T->buckets[i]->element){
        Position temp=T->buckets[i];
        T->buckets[i]=temp->next;
        free(temp);
        return;
    }
    Position p=T->buckets[i];
    while(p->next!=NULL){
        if(x==p->next->element){
            Position temp = p->next;
            p->next = temp->next;
            free(temp);
            return;
        }
        p=p->next;
    }
}
//delete(x, T)
void delete(ElementType x,HashTable *T){
    int i=h(x);
    if(T->buckets[i]==NULL){
        printf( "%d does not exist, ignore.\n",x);
        return;
    }
    if(x==T->buckets[i]->element){
        Position temp=T->buckets[i];
        T->buckets[i]=temp->next;
        free(temp);
        return;
    }
    
    Position p=T->buckets[i];
    while(p->next!=NULL){
        if(x==p->next->element){
            
            Position temp = p->next;
            p->next = temp->next;
            free(temp);
            return;
        }
        p=p->next;
    }
    printf( "%d does not exist, ignore.\n",x);
}
//makeNull(T)close
void makeNull(HashTable *T){
    for(int i=0;i<B;i++){
        T->buckets[i]=EMPTY;
    }
}
// member(x, T)close
int locate(ElementType x, HashTable *T){
    int i=h(x);
    int ino=0;
    while(i<B&&T->buckets[(i+ino)%B]!=x&&T->buckets[(i+ino)%B]!=EMPTY)
    i++;
    return (i+ino)%B;
}
int member(ElementType x,HashTable *T){
    int i=locate(x,T);
    return T->buckets[i]==x;
}
//insert(x, T)close
int locate(ElementType x, HashTable *T) {
    int i = h(x);
    int ino = 0;
    while (ino < B && T->buckets[(i + ino) % B] != x && T->buckets[(i + ino) % B] != EMPTY) {
        ino++;
    }
    return (i + ino) % B;
}

int locate1(ElementType x, HashTable *T) {
    int i = h(x);
    int ino = 0;
    while (ino < B && T->buckets[(i + ino) % B] != EMPTY && T->buckets[(i + ino) % B] != DELETED) {
        if (T->buckets[(i + ino) % B] == x) {
            return (i + ino) % B; // tìm th?y x ? tr? v? v? trí
        }
        ino++;
    }
    return (i + ino) % B; // tr? v? v? trí EMPTY ho?c DELETED d?u tiên
}

void insert(ElementType x, HashTable *T) {
    
    int i=locate(x,T);
    if(T->buckets[i]==x)
    return;
     i=locate1(x,T);
    if(T->buckets[i]==EMPTY||T->buckets[i]==DELETED){
        T->buckets[i]=x;
    }

}
// delete(x, T)close
int locate(ElementType x, HashTable *T){
    int i=h(x);
    int ino=0;
    while(i<B&&T->buckets[(i+ino)%B]!=x&&T->buckets[(i+ino)%B]!=EMPTY)
    i++;
    return (i+ino)%B;
}

void delete(ElementType x, HashTable *T) {
    int i=locate(x,T);
    if(T->buckets[i]==x){
        T->buckets[i]=DELETED;
        return;
    }
}
//makeNull(T)string
void makeNull(HashTable *T){
    for(int i=0;i<B;i++){
        T->buckets[i]=NULL;
    }
}
//member(x, T)string
int member(ElementType x, HashTable *pT) {
    int bucket = h(x);                    // compute hash
    Position p = pT->buckets[bucket];     // start of chain

    while (p != NULL) {
        if (strcmp(p->element, x) == 0) { // string comparison
            return 1;                     // found
        }
        p = p->next;
    }
    return 0;                             // not found
}
//insert(x, T)string
void insert(ElementType x, HashTable *pT) {
    int i = h(x);
    Position p = pT->buckets[i];
    while (p != NULL) {
        if (strcmp(p->element, x) == 0)
            return;
        p = p->next;
    }
    
    Position temp = pT->buckets[i];
    pT->buckets[i] = (Cell*)malloc(sizeof(Cell));
    strcpy(pT->buckets[i]->element, x);
    pT->buckets[i]->next = temp;
}
// delete(x, T)
void delete(ElementType x, HashTable *pT) {
    int i = h(x);
    Position p = pT->buckets[i];
    if (p == NULL) {
        //printf("%d does not exist, ignore.\n", x);
        return;
    }
    if (strcmp(p->element, x) == 0) { //delete first
        Position temp = p;
        pT->buckets[i] = temp->next;
        free(temp);
        return;
    }
    
    while (p->next != NULL) {
        if (strcmp(p->next->element, x) == 0) {
            Position temp = p->next;
            p->next = temp->next;
            free(temp);
            return;
        }
        p = p->next;
    }
    
    //printf("%d does not exist, ignore.\n", x);
}
// makeNull(T)stringclose
void makeNull(HashTable *pT) {
    for (int i = 0; i < B; i++) {
        strcpy(pT->buckets[i], EMPTY);
    }
}
// member(x, T)stringclose
int locate(ElementType x, HashTable *pT) {
    int init = h(x);
    int i = 0;
    while (i < B && strcmp(pT->buckets[(init + i)%B], x) != 0 &&
                    strcmp(pT->buckets[(init + i)%B], EMPTY) != 0)
        i++;
    
    return (init + i)%B;
}
int member(ElementType x, HashTable *pT) {
    int i = locate(x, pT);
    return strcmp(pT->buckets[i], x) == 0;
}
// insert(x, T)stringclose
int locate(ElementType x, HashTable *pT) {
    int init = h(x);
    int i = 0;
    while (i < B && strcmp(pT->buckets[(init + i)%B], x) != 0 &&
                    strcmp(pT->buckets[(init + i)%B], EMPTY) != 0)
        i++;
    
    return (init + i)%B;
}

int locate1(ElementType x, HashTable *pT) {
    int init = h(x);
    int i = 0;
    while (i < B && strcmp(pT->buckets[(init + i)%B], x) != 0 &&
                    strcmp(pT->buckets[(init + i)%B], EMPTY) != 0 &&
                    strcmp(pT->buckets[(init + i)%B], DELETED) != 0)
        i++;
    
    return (init + i)%B;
}

void insert(ElementType x, HashTable *pT) {
    int i = locate(x, pT);
    if (x == pT->buckets[i])
        return;
    
    i = locate1(x, pT);

    if (strcmp(EMPTY, pT->buckets[i]) == 0 || strcmp(DELETED, pT->buckets[i]) == 0)
        strcpy(pT->buckets[i], x);
}
// delete(x, T)stringclose
int locate(ElementType x, HashTable *pT) {
    int init = h(x);
    int i = 0;
    while (i < B && strcmp(pT->buckets[(init + i)%B], x) != 0 &&
                    strcmp(pT->buckets[(init + i)%B], EMPTY) != 0)
        i++; 
    return (init + i)%B;
}
void delete(ElementType x, HashTable *pT) {
    int i = locate(x, pT);
    if (strcmp(x, pT->buckets[i]) == 0)
        strcpy(pT->buckets[i], DELETED);
}
// insert(k, v, M)open
void insert(KeyType k, ValueType v, Map *pM) {
    int i = h(k);
    Position temp = pM->buckets[i];
    
    // Check if key already exists in this bucket
    while (temp!= NULL) {
        if (strcmp(temp->element.key, k) == 0) {
            return;  
        }
        temp = temp->next;
    }
    
    // Key not found, insert new element at the beginning of the chain
    Position newCell = (Position)malloc(sizeof(Cell));
    strcpy(newCell->element.key, k);
    newCell->element.value = v;
    newCell->next = pM->buckets[i];
    pM->buckets[i] = newCell;
}
// retrieve(k, M)open
ValueType retrieve(KeyType k, Map *pM) {
    int i = h(k);
    Position temp = pM->buckets[i];
    
    // Traverse the chain in this bucket
    while (temp != NULL) {
        if (strcmp(temp->element.key, k) == 0) {
            return temp->element.value;  // Key found, return its value
        }
        temp = temp->next;
    }
    
    // Key not found
    return -8241;
}
//delete(k, M)open
void delete(KeyType k, Map *pM) {
    int i = h(k);
    Position p = pM->buckets[i];
    if (p == NULL)
        return;
    
    if (strcmp(p->element.key, k) == 0) {
        Position temp = p;
        pM->buckets[i] = temp->next;
        free(temp);
        return;
    }
        
    
    while (p->next != NULL) {
        if (strcmp(p->next->element.key, k) == 0) {
            Position temp = p->next;
            p->next = temp->next;
            free(temp);
            return;
        }
        p = p->next;
    }
}
// update(k, new_v, M)open
void update(KeyType k, ValueType new_v, Map *pM) {
    int i = h(k);
    Position p = pM->buckets[i];
    while (p != NULL) {
        if (strcmp(p->element.key, k) == 0) {
            p->element.value = new_v;
            return;
        }
        p = p->next;
    }
}
// insert(k, v, M)close
void insert(KeyType k, ValueType v, Map *pM) {
    //1. locate the bucket i
    int i = locate(k, pM);

    //2a. if bucket.key contains k => return
    if (strcmp(pM->buckets[i].key, k) == 0) return;
    //2b. Call locate1 to find an empty or deleted
    i = locate1(k, pM);
    if (strcmp(pM->buckets[i].key, EMPTY) == 0 || 
        strcmp(pM->buckets[i].key, DELETED) == 0) {
        strcpy(pM->buckets[i].key, k);
        pM->buckets[i].value = v;
    }
}
// retrieve(k, M)close
ValueType retrieve(KeyType k, Map *pM) {
    int i = locate(k, pM);
    if (strcmp(pM->buckets[i].key, k) == 0)
        return pM->buckets[i].value;
    return -8048;
}
//delete(k, M)close
void delete(KeyType k, Map *pM) {
    //1. locate the bucket i
    int i = locate(k, pM);
    //2a. if bucket contains x
    if (strcmp(pM->buckets[i].key, k) == 0) {
        strcpy(pM->buckets[i].key, DELETED);
        return;
    }
    //2b. X does not appear in M
}
//update(k, v, M)close
void update(KeyType k, ValueType v, Map *pM) {
    //2b. Call locate1 to find an empty or deleted
    int i = locate1(k, pM);
    if (strcmp(pM->buckets[i].key, EMPTY) == 0 || 
        strcmp(pM->buckets[i].key, DELETED) == 0) {
        strcpy(pM->buckets[i].key, k);
        pM->buckets[i].value = v;
    } else if (strcmp(pM->buckets[i].key, k) == 0)
        pM->buckets[i].value = v;
}

