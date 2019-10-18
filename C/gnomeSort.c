// gnome sort
int main(){
  // test numbers to sort
  int toSort[] = {4, 7, 9, 2, 6};
  int index = 0;

  // perform gnome sort
  while (index < 5){
    if (index == 0){
      index++;
    }
    if (toSort[index] >= toSort[index-1]){
      index++;
    }
    else {
      // swap
      int temp = toSort[index];
      toSort[index] = toSort[index-1];
      toSort[index-1] = temp;
      index--;
    }
  }

  // print final order
  for (int i = 0; i < 5; i++){
    printf("%d\n", toSort[i]);
  }

}
