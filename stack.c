/*
#include <stdio.h>
#include <stdlib.h>

#define MAX 100 

typedef struct {
    int data[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("full\n");
        return;
    }
    s->data[++(s->top)] = value;
    printf("push %d\n", value);
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("empty\n");
        return -1;
    }
    return s->data[(s->top)--];
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("empty\n");
        return -1;
    }
    return s->data[s->top];
}

void printStack(Stack *s) {
    printf("현재 스택: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

int main() {
    Stack s;
    init(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    printStack(&s);
    printf("peek: %d\n", peek(&s));
    printf("pop: %d\n", pop(&s));
    printStack(&s);
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void init_stack(StackType* s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

int is_full(StackType* s) {
	return (s->top == MAX_STACK_SIZE - 1);
}

void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else {
		s->data[++(s->top)] = item;
	}
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else {
		return s->data[(s->top)--];
	}
}

element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else {
		return s->data[s->top];
	}
}

int main(void)
{
	StackType s;
	init_stack(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	return 0;
}


    #include <stdio.h>
    #include <stdlib.h>
    #define MAX_STACK_SIZE 100
    
    typedef int element;
    typedef struct {
        element* data;
        int capacity;
        int top;
    }StackType;
    
    //스택 초기화 함수
    void init_stack(StackType* s) {
        s->top = -1;
        s->capacity = 1;
        s->data = (element *)malloc(s->capacity * sizeof(element));
    }
    
    //공백 상태 검출 함수
    int is_empty(StackType* s) {
        return (s->top == -1);
    }
    
    //포화 상태 검출 함수
    int is_full(StackType* s) {
        return (s->top == (s->capacity - 1));
    }
    
    //삽입 함수
    void push(StackType* s, element item) {
        if (is_full(s)) {
            (s->capacity) *= 2;
            s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
        }
    
        s->data[++(s->top)] = item;
    }
    
    //삭제 함수
    element pop(StackType* s) {
        if (is_empty(s)) {
            fprintf(stderr, "스택 공백 에러\n");
            exit(1);
        }
        else {
            return s->data[(s->top)--];
        }
    }
    
    //피크 함수
    element peek(StackType* s) {
        if (is_empty(s)) {
            fprintf(stderr, "스택 공백 에러\n");
            exit(1);
        }
        else {
            return s->data[s->top];
        }
    }
    
    int main(void)
    {
        StackType s;
        init_stack(&s);
        push(&s, 1);
        push(&s, 2);
        push(&s, 3);
        printf("%d\n", pop(&s));
        printf("%d\n", pop(&s));
        printf("%d\n", pop(&s));
        free(s.data);
        return 0;
    }


    #include <stdio.h>
    #include <stdlib.h>
    #define MAX_STACK_SIZE 100
    
    typedef int element;
    typedef struct {
        element* data;
        int capacity;
        int top;
    }StackType;
    
    //스택 초기화 함수
    void init_stack(StackType* s) {
        s->top = -1;
        s->capacity = 1;
        s->data = (element *)malloc(s->capacity * sizeof(element));
    }
    
    //공백 상태 검출 함수
    int is_empty(StackType* s) {
        return (s->top == -1);
    }
    
    //포화 상태 검출 함수
    int is_full(StackType* s) {
        return (s->top == (s->capacity - 1));
    }
    
    //삽입 함수
    void push(StackType* s, element item) {
        if (is_full(s)) {
            (s->capacity) *= 2;
            s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
        }
    
        s->data[++(s->top)] = item;
    }
    
    //삭제 함수
    element pop(StackType* s) {
        if (is_empty(s)) {
            fprintf(stderr, "스택 공백 에러\n");
            exit(1);
        }
        else {
            return s->data[(s->top)--];
        }
    }
    
    //피크 함수
    element peek(StackType* s) {
        if (is_empty(s)) {
            fprintf(stderr, "스택 공백 에러\n");
            exit(1);
        }
        else {
            return s->data[s->top];
        }
    }
    
    int main(void)
    {
        StackType s;
        init_stack(&s);
        push(&s, 1);
        push(&s, 2);
        push(&s, 3);
        printf("%d\n", pop(&s));
        printf("%d\n", pop(&s));
        printf("%d\n", pop(&s));
        free(s.data);
        return 0;
    }

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #define MAX_STACK_SIZE 100
    
    typedef char element;
    typedef struct {
        element data[MAX_STACK_SIZE];
        int top;
    }StackType;
    
    //스택 초기화 함수
    void init_stack(StackType* s) {
        s->top = -1;
    }
    
    //공백 상태 검출 함수
    int is_empty(StackType* s) {
        return (s->top == -1);
    }
    
    //포화 상태 검출 함수
    int is_full(StackType* s) {
        return (s->top == MAX_STACK_SIZE - 1);
    }
    
    //삽입 함수
    void push(StackType* s, element item) {
        if (is_full(s)) {
            fprintf(stderr, "스택 포화 에러\n");
            return;
        }
        else {
            s->data[++(s->top)] = item;
        }
    }
    
    //삭제 함수
    element pop(StackType* s) {
        if (is_empty(s)) {
            fprintf(stderr, "스택 공백 에러\n");
            exit(1);
        }
        else {
            return s->data[(s->top)--];
        }
    }
    
    //피크 함수
    element peek(StackType* s) {
        if (is_empty(s)) {
            fprintf(stderr, "스택 공백 에러\n");
            exit(1);
        }
        else {
            return s->data[s->top];
        }
    }
    
    int check_matching(const char *in) {
        StackType s;
        char ch, open_ch;
        int i, n = strlen(in);
        init_stack(&s);
    
        for (i=0;i<n;i++){
            ch = in[i];
            switch (ch)
            {
                case '(': case '[': case '{':
                    push(&s, ch);
                    break;
                case ')': case ']': case '}':
                    if (is_empty(&s)) return 0;
                    else {
                        open_ch = pop(&s);
                        if ((open_ch == '(' && ch != ')') || (open_ch == '[' && ch != ']') || (open_ch == '{' && ch != '}')) {
                            return 0;
                        }
                        break;
                    }
            }
        }
        if (!is_empty(&s)) return 0;
        return 1;
    }
    
    int main(void)
    {
        char *p = "{ A[(i+1)]=0; }";
        if (check_matching(p) == 1)
            printf("%s 괄호검사성공\n", p);
        else
            printf("%s 괄호검사실패\n", p);
        return 0;
    }

   #include <stdio.h>
   #include <stdlib.h>
   #include <string.h>
   #define MAX_STACK_SIZE 100
   
   typedef char element;
   typedef struct {
       element data[MAX_STACK_SIZE];
       int top;
   }StackType;
   
   //스택 초기화 함수
   void init_stack(StackType* s) {
       s->top = -1;
   }
   
   //공백 상태 검출 함수
   int is_empty(StackType* s) {
       return (s->top == -1);
   }
   
   //포화 상태 검출 함수
   int is_full(StackType* s) {
       return (s->top == MAX_STACK_SIZE - 1);
   }
   
   //삽입 함수
   void push(StackType* s, element item) {
       if (is_full(s)) {
           fprintf(stderr, "스택 포화 에러\n");
           return;
       }
       else {
           s->data[++(s->top)] = item;
       }
   }
   
   //삭제 함수
   element pop(StackType* s) {
       if (is_empty(s)) {
           fprintf(stderr, "스택 공백 에러\n");
           exit(1);
       }
       else {
           return s->data[(s->top)--];
       }
   }
   
   //피크 함수
   element peek(StackType* s) {
       if (is_empty(s)) {
           fprintf(stderr, "스택 공백 에러\n");
           exit(1);
       }
       else {
           return s->data[s->top];
       }
   }
   
   //연산자의 우선순위를 반환한다.
   int prec(char op){
       switch (op)
       {
           case '(': case ')': return 0;
           case '+': case '-': return 1;
           case '*': case '/': return 2;
       }
       return -1;
   }
   
   //중위 표기 수식 -> 후위 표기 수식 
   void infix_to_postfix(char exp[])
   {
       int i = 0;
       char ch, top_op;
       int len = strlen(exp);
       StackType s;
   
       init_stack(&s);
       for (i = 0; i<len; i++) {
           ch = exp[i];
           switch (ch) {
           case '+': case '-': case '*': case '/':
               while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
                   printf("%c", pop(&s));
               push(&s, ch);
               break;
           case '(':
               push(&s, ch);
               break;
           case ')':
               top_op = pop(&s);
               while (top_op != '(') {
                   printf("%c", top_op);
                   top_op = pop(&s);
               }
               break;
           default:
               printf("%c", ch);
               break;
           }
       }
       while (!is_empty(&s))
           printf("%c", pop(&s));
   }
   
   int main (void) {
       char *s = "(2+3)*4+9";
       printf("중위표시수식 %s \n", s);
       printf("후위표시수식 ");
       infix_to_postfix(s);
       printf("\n");
       return 0;
   }
    */

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    #define MAX_STACK_SIZE 100
    
    typedef char element;
    
    typedef struct
    {
        element data[MAX_STACK_SIZE];
        int top;
    } StackType;
    
    void init_stack(StackType *s)
    {
        s->top = -1;
    }
    
    int is_empty(StackType *s)
    {
        return (s->top == -1);
    }
    
    int is_full(StackType *s)
    {
        return (s->top == MAX_STACK_SIZE - 1);
    }
    
    void push(StackType *s, element item)
    {
        if (is_full(s))
        {
            fprintf(stderr, "스택 포화 에러\n");
            return;
        }
        s->data[++(s->top)] = item;
    }
    
    element pop(StackType *s)
    {
        if (is_empty(s))
        {
            fprintf(stderr, "스택 공백 에러\n");
            exit(1);
        }
        return s->data[(s->top)--];
    }
    
    element peek(StackType *s)
    {
        if (is_empty(s))
        {
            fprintf(stderr, "스택 공백 에러\n");
            exit(1);
        }
        return s->data[s->top];
    }
    
    int prec(char op)
    {
        switch (op)
        {
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        }
        return -1;
    }
    
    void infix_to_postfix(char exp[])
    {
        StackType s;
        init_stack(&s);
    
        int len = strlen(exp);
    
        for (int i = 0; i < len; i++)
        {
            char ch = exp[i];
    
            // 피연산자 (숫자 또는 알파벳)
            if ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
            {
                printf("%c", ch);
            }
            // 연산자
            else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
            {
                while (!is_empty(&s) && prec(ch) <= prec(peek(&s)))
                    printf("%c", pop(&s));
                push(&s, ch);
            }
            else if (ch == '(')
            {
                push(&s, ch);
            }
            else if (ch == ')')
            {
                char top_op = pop(&s);
                while (top_op != '(')
                {
                    printf("%c", top_op);
                    top_op = pop(&s);
                }
            }
        }
    
        while (!is_empty(&s))
            printf("%c", pop(&s));
    }
    
    int main(void)
    {
        char s[] = "(2+3)*4+9";
    
        printf("중위 표기식: %s\n", s);
        printf("후위 표기식: ");
        infix_to_postfix(s);
        printf("\n");
    
        return 0;
    }