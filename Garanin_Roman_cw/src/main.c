#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>
#include <time.h>

char* input_mass(int *countPR){
    int M = 10;
    int N = 10;
    char c;
    int i = 0;
    int new = 0;

    char *arr = malloc(N * sizeof(char));
    
    while(1){
        c = getchar();
        if(c == '\n'){
           arr[i] = '\0';
           break;
        }
        if(new == 1){
            new = 0;
            while((c = getchar()) == ' ');
        }
        if(i+1 == N){
            N = N + 10;
            arr = realloc(arr, N * sizeof(char));
        }
        arr[i] = c;
        i++;
        if(c =='.'){
            (*countPR)++;
            new = 1;
        }
    }

    return arr;
}

void processing_of_text(char ***mass, char **str, int countPR){
    int M = 10;
    int F = 0;
    int G = 0;
    int count1 = 0;

    for(int i = 0; i < countPR; i++){
        (*mass)[i] = malloc(M * sizeof(char));
    }
    
    for(int i = 0; (*str)[i]; i++){
        if(G+1 == M){
            M = M + 10;
            (*mass)[F] = realloc((*mass)[F], M * sizeof(char));
        }
        (*mass)[F][G] = (*str)[i];
        G++;
        if((int)(*str)[i] == 46){
            (*mass)[F][G] = '\0';
            F++;
            G = 0;
            M = 10;
        }
    }
}

int compare(char *str1, char *str2){
    int first = strlen(str1);
    int second = strlen(str2);

    if(first != second){
        return 0;
    }

    int identical = 1;
    for(int i = 0; i < first; i++){
        if(str1[i] != str2[i]){
            identical = 0;
        }
    }

    return identical;
}

void correct_the_text(char ***mass, int *countPR){
    for(int i = 1; i < *countPR; i++){
        for(int j = 0; j < i; j++){
            if(strlen((*mass)[i]) == strlen((*mass)[j])){
                if(compare((*mass)[i], (*mass)[j])){
                    (*mass)[i][0] = '\0';
                    break;
                }
            }
        }
    }  

    int j = 0;
    for(int i = 0; i < *countPR; i++){
        if((*mass)[i][0] == '\0'){
            free((*mass)[i]);
            j++;
            continue;
        }
        (*mass)[i - j] = (*mass)[i];
    }
    *countPR -= j;
}

void dates_in_text(char ***mass, int countPR){
    for(int i = 0; i < countPR; i++){
        int n = 0;
        int v = 0;
        int otvet;
        char *t1;
        char *t2;
        char *t3;
        int dr = 0;
        int NM;
        char mes[12][4] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        
        char *copy1 = malloc(strlen((*mass)[i]) * sizeof(char));
        strncpy(copy1, (*mass)[i], strlen((*mass)[i]) * sizeof(char));
        
        char *temp = strtok(copy1, " ,.");
        while(temp){
            if(n == 2){
                t3 = temp;
                for(int i = 0; temp[i]; i++){
                    if(isdigit(temp[i])){
                        n = 3;
                        continue;
                    }else{
                        n = 0;
                        break;
                    }
                }
            }
            
            if(n == 1){
                for(int w = 0; w < 12; w++){
                    if(strlen(temp) == 3 && memcmp(temp, mes[w], 3) == 0){
                        NM = w+1;
                        n = 2;
                        t2 = temp;
                        break;
                    }else{
                        n = 0;
                    }
                }
            }
            
            if(n == 0){
                t1 = temp;
                for(int q = 0; temp[q]; q++){
                    if(isdigit(temp[q])){
                        n = 1;
                        continue;
                    }else{
                        n = 0;
                        break;
                    }
                }
                
                dr = t1 - copy1;
            }
            if(n == 3){
                int WS = atoi(t3);
                
                time_t time_of_day;
                struct tm tmbuf, *tptr;
                time_of_day = NULL;
                memset(&tmbuf, 0, sizeof(tmbuf));
                tmbuf.tm_mday = WS;
                tmbuf.tm_mon = NM;
                tmbuf.tm_mon--;
                tmbuf.tm_year = 2010 - 1900;
                time_of_day = mktime(&tmbuf);
                otvet  = (365 - tmbuf.tm_yday) * 24;
                break;
            }
            temp = strtok(NULL, " ,.");
            
        }
        
        if(n == 3){
            int len = strlen(t1) + 7;
            int ln = 0;
            char *che = malloc(5 * sizeof(char));
            che[0] = '0';
            char c;
            int gh = 0;
            while(otvet > 0){
                che[ln++] = otvet%10 + '0';
                otvet/=10;
            }
            for(gh = 0; gh < (ln/2); gh++){
                c = che[gh];
                che[gh] = che[ln - 1 - gh];
                che[ln - 1 - gh] = c;
            }
            for(int y = dr; y < (dr + ln); y++){
                (*mass)[i][y] = che[y - dr];
            }
            
            memmove((*mass)[i] + dr + ln, (*mass)[i] + dr + len, (strlen((*mass)[i]) - dr - len + 1) * sizeof(char));
        }
    }
    for(int err = 0; err < countPR; err++){
        puts((*mass)[err]);
    }
}

void marker_for_text(char **mass, int countPR){
    int num;
    for(int i = 0; i < countPR; i++){
        num = -1;
        for(int j = 0; mass[i][j]; j++){
            if(isalnum(mass[i][j]) && (num == -1 || num == 1)){
                num = 1;
                printf("\033[32m%c\033[0m", mass[i][j]);
            }
            else if(isalnum(mass[i][j]) && (num == -2 || num == 2)){
                num = 2;
                printf("\033[31m%c\033[0m", mass[i][j]);
            }
            else{
                if(num == 1){
                    num = -2;
                }
                if(num == 2){
                    num = -1;
                }
                printf("%c", mass[i][j]);
            }
        }
        printf("\n");
    }
}

void del_of_predl(char ***mass, int *countPR){
    for(int i = 0; i < *countPR; i++){
        
        char *copy1 = malloc(strlen((*mass)[i]) * sizeof(char));
        strncpy(copy1, (*mass)[i], strlen((*mass)[i]) * sizeof(char));
        char *first = strtok(copy1, " .,");

        char *second = malloc((strlen(first) + 1) * sizeof(char));
        strncpy(second, &(*mass)[i][strlen((*mass)[i]) - strlen(first) - 1], strlen(first) * sizeof(char));
        if(strlen((*mass)[i]) - strlen(first) - 1 != 0 && isalpha((*mass)[i][strlen((*mass)[i]) - strlen(first) - 2])){
            continue;
        }
        second[strlen(first)] = '\0';
        if(strcmp(first, second) == 0){
            (*mass)[i][0] = '\0';
        }
    }
    
    int j = 0;
    for(int i = 0; i < *countPR; i++){
        if((*mass)[i][0] == '\0'){
            free((*mass)[i]);
            j++;
            continue;
        }
        (*mass)[i - j] = (*mass)[i];
    }
    *countPR -= j;
    
    for(int i = 0; i < *countPR; i++){
        puts((*mass)[i]);
    }
}

int cmp(const void** s1, const void** s2){
    char *str1 = (char*)*s1;
    char *str2 = (char*)*s2;

    char *copy1 = malloc(strlen(str1) * sizeof(char));
    strncpy(copy1, str1, strlen(str1) * sizeof(char));
    char *temp1 = strtok(copy1, " .,");
    int sum1 = 0;
    for(int i = 0; temp1[i]; i++){
        sum1+=(int)temp1[i];
    }

    char *copy2 = malloc(strlen(str2) * sizeof(char));
    strncpy(copy2, str2, strlen(str2) * sizeof(char));
    char *temp2 = strtok(copy2, " .,");
    int sum2 = 0;
    for(int i = 0; temp2[i]; i++){
        sum2+=(int)temp2[i];
    }

    if(sum1 > sum2){
        return 1;
    }else if(sum1 == sum2){
        return 0;
    }else{
        return -1;
    }
}

void sorting_by_code(char ***mass, int countPR){
    qsort(*mass, countPR, sizeof(char*), cmp);
    for(int i = 0; i < countPR; i++){
        puts((*mass)[i]);
    }
}

void free_up_memory(char **mass, char *str, int countPR){
    free(str);
    for(int i = 0; i < countPR; i++){
        free(mass[i]);
    }
    free(mass);
}
int main(){
    int countPR = 0;

    setlocale(LC_ALL, "Rus");

    printf("Введите предложения. Для конца ввода нажмите ENTER.\n");    
    char *str = input_mass(&countPR);
    char **mass = malloc(countPR * sizeof(char*));
    processing_of_text(&mass, &str, countPR);
    correct_the_text(&mass, &countPR);

    printf("Вы можете выбрать одно из следующих действий:\n");
    printf("1) Найти в предложениях все даты записанные в виде “<год> <месяц> <day>” (“1886 Jun 03”) и заменить их на строку показывающую сколько осталось часов до конца года.\n");
    printf("2) Вывести все строки выделив слова на четных позициях красным цветом, а на нечетных зеленым.\n");
    printf("3) Удалить все предложения, которые начинаются и заканчиваются на одно и то же слово.\n");
    printf("4) Отсортировать предложения по увеличению сумме кодов символов первого слова в предложении.\n");
    printf("5) Выход их программы\n");

    int variant = 0;
    printf("Введите вариант действия: ");
    scanf("%d", &variant);

    switch(variant){

    case 1:{
        printf("Выбрано действие 1.\n");
        dates_in_text(&mass, countPR);
        break;
    }

    case 2:{
        printf("Выбрано действие 2.\n");
        marker_for_text(mass, countPR);
        break;
    }

    case 3:{
        printf("Выбрано действие 3.\n");
        del_of_predl(&mass, &countPR);
        break;
    }

    case 4:{
        printf("Выбрано действие 4.\n");
        sorting_by_code(&mass, countPR);
        break;
    }

    case 5:{
        printf("Выбрано действие 5.\n");
        printf("Всего хорошего:)");
        break;
    }  
    
    default:
        printf("Введенные данные не корректны! Попробуйте еще раз!\n");
        break;
    }
    
    free_up_memory(mass, str, countPR);

    return 0;
}
