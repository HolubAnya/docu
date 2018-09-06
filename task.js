'use strict';

//summing figures of number in string
let string = '1999';
function fun(str){
	let el = str.split('').map(el => parseFloat(el));
	let res = el.reduce((a, b) => a+b);
	if (res.toString().length > 1){
		res = fun(res.toString());
	  
	}
	console.log(res);
}
//fun(string);

//number of seconds before the day end
const date = new Date();
let end = new Date(date.getFullYear(), date.getMonth(), date.getDate(), 23, 59, 59);
let result = Math.floor((end.getTime() - date.getTime())/1000); //42074
//console.log(result);

//finds positive and brings to degree
const array = [2, -3, 8];
const fn = arr => arr.filter(el => el > 0);
const fn1 = arr1 => arr1.map(a => a*a);
const compose = (f1, f2) => x => f2(f1(x));
const composed = compose(fn, fn1);
//console.log(composed(array)); //[4, 64]

//finds average arithmatic
const fn2 = arr2 => arr2.reduce((a,b) => a + b)/arr2.length;
//console.log(fn2(array));

const obj = {a: 'aaa', b: 'bbb'};
console.log( JSON.stringify(obj)); 