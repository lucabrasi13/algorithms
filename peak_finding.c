#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gen_random_numbers(int *buf, int n, int seed){
  /*Pick a random seed*/
  //srand(time(0));
  srand(seed);
  /*Generate a set of random numbers*/
  for(int i=0;i<n;i++){buf[i]=rand()%10+1;}
}

int peak_search_1D(int arr[], int n){
  int peak_pos = 0;
  /* 1-D traversal Peak search Algorithm*/
  for(int i=1;i<n-1;i++){
    if((arr[i]>=arr[i-1])&&(arr[i]>=arr[i+1])){
      peak_pos = i;
    }
  }
  return peak_pos;
}

int peak_search_1D_recursion(int buf[], int upper, int lower, int n){
    int middle = (upper+lower)/2;
    if(middle==0 || middle==n){return middle;}
    if(buf[middle] < buf[middle-1]){
      upper = middle;
      peak_search_1D_recursion(buf, upper, lower, n);
    }
    else if(buf[middle] < buf[middle+1]){
      lower = middle;
      peak_search_1D_recursion(buf, upper, lower, n);
    }
    else{
      return middle;
    }
}

void print_array(int arr[], int n)
{
  for(int i=0;i<n;i++){printf("%d\n",arr[i]);}
}

int main()
{
  int n = 1000000;
  int arr[1000000] = {0}; 
  int seed = time(NULL);
  gen_random_numbers(arr,n, seed);
  double total_time;
  clock_t start, end;
  printf("Start the time without using recursion.... \n");
  printf("------------------------------------------ \n");
  start = clock();
  int peak_pos_1 = peak_search_1D(arr,n);
  end = clock();
  printf("The peak position is: %d \n", peak_pos_1);
  printf("End of clock without recursion.... \n");
  total_time = ((double)(end-start))/ CLOCKS_PER_SEC;
  printf("Total time elapsed: %f", total_time);
  printf("------------------------------------------ \n");

  printf("Start the time with recursion.... \n");
  printf("------------------------------------------ \n");
  start = clock();
  int peak_pos = peak_search_1D_recursion(arr,10,0,n);
  end = clock();
  printf("The peak position using recursion is: %d \n", peak_pos);
  printf("End of clock without recursion.... \n");
  total_time = ((double)(end-start))/ CLOCKS_PER_SEC;
  printf("Total time elapsed: %f", total_time);
  printf("------------------------------------------ \n");

  return 0;
}
