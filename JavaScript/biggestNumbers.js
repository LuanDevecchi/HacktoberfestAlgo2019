////return an array containing all the biggest numbers of each array

function largestOfFour(arr) {
  let maxArr=[];
  for (let i=0; i< arr.length; i++){
     let  max = arr[i][0];
    for (let j=0; j< arr[i].length; j++){
      console.log(max)
       if (arr[i][j] > max ){
          max = arr[i][j];
       }
    }
     maxArr.push(max);
  }
  return maxArr;
}

largestOfFour([[13, 27, 18, 26], [32, 35, 37, 39], [-1000, -1001, -857, -1],[4, 5, 1, 6]])
////answer : [27,39, -1, 6]
