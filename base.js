'use strict';

//RECURSION
const arr = [11, 2, 3, 4];

function func(arr) {
	console.log(arr[0]);
	arr.splice(0, 1);
	if (arr.length > 0) {
		func(arr);
	}
}
//func(arr);

//COMPOSITION
const compose = (f1, f2) => x => f2(f1(x));

//FIBOACHI
const fib = n => (n<=1) ? n : fib(n-1)+fib(n-2);
//console.log(fib(4)); //3 

//LOG
const log = (base, n) => Math.log(n) / Math.log(base);

//CLOSURE
const createLog = (base) => (n) => log(base, n);

const lg = createLog(10);
const ln = createLog(Math.E);

//BIND
const lg1 = log.bind(null, 10);
const ln1 = log.bind(null, Math.E);

//console.log(lg(5));

//PARTIAL
const partial = (fn, x) => (...args) => fn(x, ...args);
const sum3 = (a, b, c) => (a + b + c);

const f1 = partial(sum3, 10);
const f2 = partial(f1, 5);
const y = f2(1);
//console.log(y); //16

//CURRY
const curry = (fn) => (...args) => {
  if (fn.length > args.length) {
    const f = fn.bind(null, ...args);
    return curry(f);
  } else {
    return fn(...args);
  }
};

// Usage

const sum = (a, b, c) => (a + b + c);

const f = curry(sum);
const y1 = sum(1, 2, 3);
const y2 = f(1, 2, 3);
const y3 = f(1, 2)(3);
const y4 = f(1)(2, 3);
const y5 = f(1)(2)(3);
//console.log(y1, y2, y3, y4, y5);

//CALL/APPLY
const user = {
	name: 'Bob', 
	id: 123243,
	age: 27
};
//function funct(first, second) {console.log(this[first]+ ' ' +this[second])};
funct.call(user, 'name', 'age');
funct.apply(user, ['name', 'id']);

//CALLBACK
function fnc(a, b, callback){
	let c = a*b;
	callback(c);
};
fnc(3,5, function(d){console.log(d)}); //15


//WRAPPERS:
//1//ONCE
const once = (fn) => {
	let finished = false;
	return (...args) => {
		if (finished) return;
		const res = fn(...args);
		finished = true;
		return res;
	};
};

// Usage

const fn = (par) => {
//	console.log('Function called, par: ' + par);
};

const fn1 = once(fn);

fn1('first');
fn1('second');

//2//LIMIT
const limit = (count, fn) => {
  let counter = 0;
  return (...args) => {
    if (counter === count) return;
    const res = fn(...args);
    counter++;
    return res;
  };
};

// Usage

const fn = (par) => {
  console.log('Function called, par: ' + par);
};

const fn2 = limit(2, fn);

fn2('first');
fn2('second');
fn2('third');

//3//CANCELABLE
const cancelable = (fn) => {
  const wrapper = (...args) => {
    if (fn) return fn(...args);
  };
  wrapper.cancel = () => {
    fn = null;
    return wrapper;
  };
  return wrapper;
};

// Usage

const fn = (par) => {
  console.log('Function called, par: ' + par);
};

const f = cancelable(fn);
f('first');

f.cancel();
f('second');

//FACTORY
const dog = () => {
  const sound = 'woof';
  return {
    talk: () => console.log(sound)
  }
}
const sniffles = dog();
sniffles.talk();
