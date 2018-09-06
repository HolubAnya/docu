
//LOG
const createLog = function(base,n){
	return Math.log(n)/Math.log(base);
};
console.log(createLog(2,8));

const add = x => y => Math.log(x)/Math.log(y);

const res = add(81)(9);

console.log(res);

const ln = add.bind(null, Math.E);
const resu = ln()(64);
console.log(resu);

const lg = b => add(b)(10);
console.log(lg(100));


//POW
const createSqrt = a => n => Math.pow(a,n);
console.log(createSqrt(2)(3));


//SUM
const sum = (...args) => args.reduce((c, d) => c + d);
console.log(sum(2,3,6));

//FIBONACHI with memoization
const fib = n => n <= 1 ? n : fib(n - 1) + fib(n - 2);
console.log(fib(3));//2

//memoization
function memoizer(fun){
	let cache = [];
	return function(n){
		let abc = n.toString();
		if (cache[abc] == undefined){
		cache[abc] = fun(n);
		}
	return cache[abc];
	};
}
fastFib = memoizer(fib);
console.log(fastFib(40));
console.log(fastFib(40));
console.log(fastFib(40));


let fibs = lazy([0, 1])(_ => fibs[_ - 1] + fibs[_ - 2])
fibs[10] // 55

//COMPOSITION
//UNLIMITED NUMBER OF FUNCTIONS
const sum1 = (a) => a + 3;
const product = (a) => a * 2;
//const compose = (f1, f2) => x => f1(f2(x)); //5*2+3
const compose = (...funcs) => (...args) => (funcs.reduce((args, fn) => [fn(...args)], args));//(5+3)*2
const composition = compose(sum1, product);
console.log(composition(5)); 

//UNLIMITED NUMBER OF ARGUMENTS
const sum2 = (a) => a + 3;
const product1 = (a) => a * 5;
const compose3 = (f1, f2) => (...args) => args.reduce(x => f1(f2(x)));
const composition4 = compose3(sum2, product1);
console.log(composition4(5, 4));

//ALL SIMBOLS IN REVERSE ORDER USING COMPOSITION
const array = ['Ganga','Yamuna','brahmaputra Assam'];
//const myArr = rivers => rivers.map(el => el.split('').reverse().join(''));
const myArr1 = rivers => rivers.map(el => el.split(''));
const myArr2 = rivers => rivers.map(el => el.reverse());
const myArr3 = rivers => rivers.map(el => el.join(''));
const compose2 = (...funcs) => (...args) => (funcs.reduce((args, fn) => [fn(...args)], args));
const composition10 = compose2(myArr1, myArr2, myArr3);
console.log(composition10(array));

//PARSE
const par = a => parseInt(a, 2);
console.log(par('1000'));

//BIND
const fnc = (arg1) => arg1*2;
const g = fnc.bind(null, 100);//context = null, if it is not used
console.log(g(0.01)); //100*0.01*2=200

const fnc1 = function(){
	return this;
};
const g1 = fnc1.bind('Context');
console.log(g1());
 

//CURRYING
const func = ac => bc => ac + bc;
const curried = func(8);
console.log(curried(9)); //17

const func1 = ad => dc => cd => ad*dc*cd*3;
const curried1 = func1(9);
console.log(curried1(1)(3)); //81

//PARTIAL
const funct = (alfa, beta) => alfa/beta;
const partial = (fn, x) => (...args) => fn(x, ...args);
const funct1 = partial(funct, 80);
console.log(funct1(8)); //10

//WRAPPER
const fnct = (an, de) => an + de;
const dec = function(fnc){
	return function(){
		let result = fnc.apply(this, arguments);
		console.log('Result = ' + result);
		return result;
	}
};
const wrapped = dec(fnct);
wrapped(29, 27); //Resullt = 56


//WRAPPER + SETTIMEOUT
const fakt = nu => (nu != 1) ? nu = fakt(nu - 1)*nu : nu; //recursive factorial
console.log(fakt(5)); //120 

const timeout = function(funct){
	return function(){
		let result1 = funct.apply(this, arguments);
		setTimeout(function(){console.log('Faktorial is: ', result1);}, 2000);
		return result1;
	}
};
const wrappped = timeout(fakt);
wrappped(8); //Faktorial is: 40320 (after 2 sec)


//ONCE
const once = (fn) => {
  let finished = false;
  return (...args) => {
    if (finished) return;
    const res = fn(...args);
    finished = true;
    return res;
  };
};
const fh = word =>{ 
	console.log(word); 
};
const wrapper = once(fh);
wrapper('Anya');
wrapper('Denys'); //Anya

//MAX
const max = (...args) => args.reduce((a,b) => (a > b) ? a : b);
console.log(max(2,4,8,7)); //8

//CALL
function sumArgs(){
	
	return [].reduce.call(arguments, (a, b) => a + b);
}
console.log(sumArgs(1, 2, 3)); //6