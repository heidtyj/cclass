/*
#include<stdio.h>
#include<string.h>
#define MAX 101

int main(){
    int a, b, i, c;
    scanf("%d %d", &a, &b);
    for (i = 2; i <= a > b ? b : a; i++){
        if (a % i == 0 && b % i == 0){
            c = i;
        }
    }
    printf("%d", i);
    return 0;
}

int gcd(int a, int b);
int gcd2(int a, int b);
 
int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d", gcd2(a, b));
    return 0;
}

int gcd(int a, int b){
    while(a != b){
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

int gcd2(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd2(b, a%b);
}



//과제
char arr[MAX];

int main() {
    fgets(arr, MAX, stdin);

    for (int i = 0; arr[i] != '\0'; i++) {
        if (arr[i] != ' ' && arr[i] != '\n' && arr[i] != '\t') {
            printf("%c", arr[i]);
        }
    }
    return 0;
}


 
char arr2[MAX];

int main(){
    int sum = 0;
    fgets(arr2, MAX, stdin);
    for (int i = 0; arr2[i] != '\0'; i++) {
        if (arr2[i] >= '0' && arr2[i] <= '9') { // 숫자면
            sum += arr2[i] - '0';
        }
    }
    printf("%d", sum);
}

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n][n]; 
    int num = 1;
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) arr[top][i] = num++;
        top++;
        for (int i = top; i <= bottom; i++) arr[i][right] = num++;
        right--;
        if (top <= bottom) {
            for (int i = right; i >= left; i--) arr[bottom][i] = num++;
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) arr[i][left] = num++;
            left++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}


int main() {
    int a, b;
    int n;
    scanf("%d", &n);
    int arr[n][n];
    int value = 1;
    int k = 0;
    scanf("%d %d", &a, &b);
    while (1){
        for (int i = 0; i < b; i++){
            for (int j = 0; j < a; j++){
                if (i + j == k)
                    arr[j][i] = value++;
            }
        }
        k++;
        if (value - 1 == a * b){
            break;
        }
    }
    for (int i = 0; i < a; i++){
        for (int j = 0; j < b; j++) {
            printf("%3d", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

*/






#include <stdio.h>
int main(){
    printf("Hello World.");
}