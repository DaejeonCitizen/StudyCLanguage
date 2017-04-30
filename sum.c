#include <stdio.h>

int Sum(int, int);
int InputValue(void);
void ShowMeTheResult(int);

int main(void)
{
  int num1, num2;
  Printf("Input Two Values : ");
  num1=InputValue();
  num2=InputValue();
  ShowMeTheResult(Sum(num1,num2));
  
  return 0;
 }
 
 int Sum(int num1, int num2)
 {
  return num1 + num2;
 }
 
 int IntputValue(void)
 {
  int n;
  scanf("%d", &n);
  return n;
 }
 
 void ShowMeTheResult(int result)
 {
  printf("result : %d\n", result);
 }
