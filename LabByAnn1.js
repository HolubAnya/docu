'use strict';
const obj = [70, 30]; //amount of brick
const a1 = [2, 5]; //costs
const a2 = [3, 6];

let x1, x2;

const cheapest = (a, b) => a < b ? obj : [b, a]; //choosing cheaper transportation cost

const fullFill = function(need, fn){ //defining the cheapest solution
	let left = obj[0] - need;
	if (left >= 0){
		x1 = need;
		x2 = 0;
		obj[0] = left;	
	}
	if (left < 0){
		need = need - obj[0];
		x1 = obj[0];
		x2 = need;
		}
	let result = [x1, x2];
	return result;
}
const multiply = (a, min) => a.map(function(value, index){ return value * min[index] }); //finding multiplication and sum
const sum = (multiplied1, multiplied2) => multiplied1.map(function(value, index){ return value + multiplied2[index] });
const sumAnswer = arr => arr.reduce((a, b) => a + b);

//usage
const min1 = fullFill(40, cheapest(a1)); 
const min2 = fullFill(50, cheapest(a2));//result is: 40, 0, 30, 20

const multiply1 = multiply(a1, min1);
const multiply2 = multiply(a2, min2);

const summedArr = sum(multiply1, multiply2);

console.log('Final answer is ' + sumAnswer(summedArr));
