/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 2
 *   Hari dan Tanggal    : Selasa, 21 April 2026
 *   Nama (NIM)          : 13224024
 *   Nama File           : soal1.c
 *   Deskripsi           : 
 * 
 */

#include <stdio.h>
#include <string.h>

void delItem(int idx, char *str){
    for (int i = idx; i < strlen(str)-1; i++)
    {
        str[i] = str[i+1];
    }
    str[strlen(str)-1] = '\0'; 
}

int findIdxFirst (char *str, char find){
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == find)
        {
            return i;
        }
    }
    return -1;
}

int findIdxLast (char *str, char find){
    for (int i = strlen(str)-1; i <= 0; i--)
    {
        if (str[i] == find)
        {
            return i;
        }
    }
    return -1;
}


int main(){
    char str[50]; char result [50];
    scanf("%s", str);
    
    int size = strlen(str);
    char *ptr = str;
    int res_idx = 0;

    int buka = 0; int tutup = 0;
    for (int i = 0; i <  size; i++)
    {
        if (str[i] != '(' && str[i] != ')')
        {
            result[res_idx] = str[i];
            res_idx++;
            printf("op1\n");
        }
        else if (str[i] == ')' && buka != 0){
            result[res_idx] = str[i];
            tutup ++;
            res_idx++;
            printf("op2\n");
        }
        else if (str[i] == '('){
            result[res_idx] = str[i];
            buka++;
            res_idx++;
            printf("op3\n");
        } 
    }
    result[res_idx] = '\0';

    int potong;
    if (buka > tutup)
    {
        potong = buka-tutup;
        while (potong != 0)
        {
            delItem(findIdxFirst(result, '('), result);
            potong --;
        }
    }
    else if (tutup > buka)
    {
        potong = tutup-buka;
        while (potong != 0)
        {
            delItem(findIdxLast(result, ')'), result);
            potong --;
        }
    }
    printf("%s", result);
    return 0;
}
