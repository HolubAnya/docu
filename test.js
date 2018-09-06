'use strict';
let array = [1, 2, 3];
const makearr = function(array, n){
 
  for (let i = 0; i < n; i++){
    let a = Math.round(Math.random()*100);
    array[i] = a;
  }
  return array;
}

makearr(array, 5000);
//console.log(array);

function swap(a, b, arr){
    let t = arr[b]; 
    arr[b] = arr[a]; 
    arr[a] = t;
}

function selectionSort(arr){  
    let n = arr.length;
    for (let i = 0; i < n-1; i++){
       let min = i;
       for ( let j = i+1; j < n; j++)
          if (arr[j] < arr[min])min = j; 
          swap(i, min, arr);
    }                    
    return arr;    
}

let arr = [1, 8, 9, 4, 7, 11]; 
console.log(selectionSort(arr)); //[ 1, 4, 7, 8, 9, 11 ]