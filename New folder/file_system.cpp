#include<bits/stdc++.h>
using namespace std;
int main(){

  FILE *fptr;
  fptr = fopen("file.txt", "w");

  if (fptr == NULL){
    cout << "Failed" << endl;
    return 1;
  }

  fprintf(fptr, "hello");
  fclose(fptr);

  fptr = fopen("file.txt" , "r");

  char ch;

  while((ch = fgetc(fptr)) != EOF){
    putchar(ch);
}

fclose(fptr);
fptr = NULL;






}
