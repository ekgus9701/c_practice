#include <stdio.h>
 
#define MAX  9 //억단위까지만 받읍시다.
 
//배열과 길이를 인자로 받아서, 수형 문자만 배열에 저장하는 기능을 합니다.
//자리수초과 : -1,  수가 아닌 문자가 있다. 입력실패 : -2, 정상 : 문자열의 길이 리턴
int get_only_number(char str[], int length){
    int i=0;
    char c;
 
    while(1){
        scanf("%c", &c);   //엔터가 눌렸을때까지 반복해서 입력!
        //크기체크 & //엔터체크
        if (c== '\n') break;
        if (i >= length) { 
            printf("자리수 초과! ");
            return -1;
        }
        if(c >='0' && c <='9') str[i++]=c;
        else {
            //printf(" %c : 수가 아닌 문자입니다. \n",c);
            return -2;
        }
    }
 
    str[i]='\0';  //문자열의 끝에는 종료코드로서, 널문자를 넣습니다.
 
    return i;
 
}
 
 
int power(int base, int exp){
 
    int i;
    int value=1;
 
    for(i=0; i<exp; i++)
        value *= base;
 
    return value;
}
 
//입력버퍼 비우기 : '엔터'가 있을 때까지 모든 입력을 변수가 읽어가므로 
//입력대기열에는 아무것도 남지않게 됩니다.
void flush(){
    char c;
 
    while(1){    
        scanf("%c",&c);
        if(c=='\n') break;
    }
}
int main(){
 
    char c;
    char str[MAX+1]="";
    int num=0;
    int i=0;
    int sig=0;
    
    
    //숫자가 입력될 때 까지 반복하기
    while(1){
        printf("숫자를 입력하세요 : ");
        //1.문자열로 받아서 변환합니다.
        //2.문자로 받아서 문자열에 저장한 후 변환합니다.
        sig=get_only_number(str, MAX);
        printf(" 리턴 시그널 : %d   ==> %s  \n", sig, (sig>=0)? "정상" : "비정상");
        if (sig >=0 ) break;        
        //입력대기열 비우기 : flush !!
        //flush();
        
    }
 
 
 
    printf("지금까지 입력된 문자열 : %s \n", str);
    printf("지금까지 입력된 문자의 길이 : %d \n", sig);
 
 
    //문자열 길이 :  strlen(str);
 
    for(i=0; i<sig; i++){
        //문자열 str에 있는 각 요소와 10의 누승 곱한 후 누적하기!!
        // (str[i] - '0') * 10의 (sig-1-i)승
        num += (str[i] - '0') * power(10, sig-1-i) ;
    
    }
 
    printf("변환된 숫자는 : %d \n", num);
    printf("num + 1  : %d \n", num+1);
    
 
 
}
