'use strict';

// //CALLBACK
// let result;
// const fnc = function(a, b, callback){
// 	console.log(a,b);
// 	callback();
// }
// fnc('ham', 'cheese', function(){
// 	console.log('are components of sandwich'.toUpperCase());
// });

// //FACTORY
// function Funct(ad, bc)  {
//   return function Function(ac){
//     return ad*ac*bc;
//   };
// }

// const Mul = Funct(2, 9);
// const mul = Mul(6);
// console.log(mul); //108


// //MAP USING 2 ARRAYS
// const arrKeys = ['a', 'b', 'c', 'd'];
// const arrValues = [1, 2, 3, 4];
// const alpha = new Map();


// const setter = function(arr1, arr2){
// 	for (let i = 0; i < arr1.length; i++){
// 		alpha.set(`${arr1[i]}`, `${arr2[i]}`);
// 	}
// 	return alpha;
// };
// const fnc22 = setter(arrKeys, arrValues);
// console.log(alpha.entries()); //MapIterator { [ 'a', '1' ], [ 'b', '2' ], [ 'c', '3' ], [ 'd', '4' ] }


//ITERABLE
class Dictionary{
	constractor(){
		this.map = Object.create(null);
	}
	set(key, value) {
    return this.map[key] = value;
  }
	iterable(){
		return{
			next: function(){
				if (this.done === false)
					console.log(this)
					this.done = true;
			}
		}
	}
	done(){
		return true
	}
}

const numbers = new Dictionary;
numbers.set('one', 1);
numbers.iterable();