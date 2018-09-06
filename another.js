'use strict';

//MEMOIZATION
function memoizer(fun){
	let cache = [];
	return function(n) {
		let idx = n.toString();
		if (cache[idx] == undefined){
			cache[idx] = fun(n);
		}
		return cache[idx];
	};
}

function testFun(a){
	return a/22
};
const memoized = memoizer(testFun);
//console.log(memoized(11)); //0.5

//ANOTHER MOMOIZING FUNCTION
const generateKey = args => (
  args.map(x => x.toString() + ':' + typeof(x)).join('|')
);

const memoize = fn => {
  const cache = {};
  return (...args) => {
    const key = generateKey(args);
    const val = cache[key];
    if (val) return val;
    const res = fn(...args);
    cache[key] = res;
    return res;
  };
};

function testFun2(a, b){
	return a*b/22
};
const memFun = memoize(testFun2);
//console.log(memFun(2, 11)); //1


//SINGLETON
const counterModule =(function (){
	let counter = 0,
			instance;
	const getCounter = function (){
		return counter;
	}
	const increaseCounter = function (){
		counter++;
	}
	const createInstance = function (){
		return {
			getCounter: getCounter,
			increaseCounter: increaseCounter
		}
	}
	return {
		getInstance: function (){
			return instance || (instance = createInstance());
		}
	}
}());

// console.log(counterModule.getInstance());
// console.log(counterModule.getInstance().getCounter());
// console.log(counterModule.getInstance().increaseCounter());
// console.log(counterModule.getInstance().getCounter()); //1
// console.log(counterModule.getInstance());
// console.log(counterModule.getInstance().getCounter()); //1 as far it is singleton, nothing has changed


//LIST
const list = { value: 1 };
list.next = { value: 2 };
list.next.next = { value: 3 };
list.next.next.next = { value: 4 };

//LISTENER (callback many times)
const iterate = (array, listener) => {
  for (const item of array) {
    listener(item);
  }
};

const cities = ['Kiev', 'London', 'Beijing'];

const each = city => {
 // console.log('City: ' + city);
};

iterate(cities, each);

const a = Math.random();

try { 
	if (a <= 0.5){
  	console.log('работает');
	} else {
		throw new Error();
	}
} catch (e) {
  console.log();
}


//settimeout
const timeout = (msec, fn) => {
	setTimeout(() => {
		console.log('canceled');
		fn = null;
	}, msec);
	return (...args) => {
		if (fn) return fn(...args);
	};
};


// const fn = (par) => {
//   console.log('Function called, par: ' + par);
// };

// const f = timeout(1000, fn);
// f(5);
// setTimeout(() => {
// 	f('first');
// }, 2000);

// f('second');