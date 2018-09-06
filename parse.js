'use strict'

let a = parseInt('1000', 2);
console.log(a); //8

/*
console.log(parseFloat('12.3sfd')); //12.3
console.log(parseFloat('123sfd'));  //123
console.log(parseFloat('12,3sfd')); //12
console.log(parseFloat(12)) // 12

const sum = new Function('a, b', 'return a + b');

console.dir({
  name: sum.name,
  length: sum.length,
  toString: sum.toString()
});

//COMPOSE

const compose = (f1, f2) => x => f2(f1(x));

const s = 'MARCUS AURELIUS';
console.log(s);
console.log('lower(' + s + ') = ' + lower(s));
console.log('upperCapital(' + s + ') = ' + upperCapital(s));

const capitalize = compose(lower, upperCapital);
console.log('capitalize(' + s + ') = ' + capitalize(s));

function upperCapital(s) {
  return s.replace(/\w+/g, (word) =>
     word.charAt(0).toUpperCase() + word.substr(1)
  );
}

function lower(s) {
  return typeof(s) === 'string' ? s.toLowerCase() : '';
}

//PARTIAL APPLICATION
const log = (base, n) => Math.log(n) / Math.log(base);
const lg = (n) => log(10, n);
console.log(lg(10));
const ln = log.bind(null, Math.E);

const sum3 = function(a, b, c) {
  return a + b + c;
};

// const sum3 = (a, b, c) => (a + b + c);

function partial(fn, x) {
  return function(...args) {
    return fn(x, ...args);
  };
}

// const partial = (fn, x) => (...args) => fn(x, ...args);

const f1 = partial(sum3, 10); //10
const f2 = partial(f1, 5); //10+5
const y = f2(1); //15+1
console.log(y); //16
*/

//FACTORY
function fn45(a) {
  const b = 'Closure variable';
  return function(c) {
    console.dir({ a, b, c });
  };
}

const f1 = fn45('Parameter 1');
f1('Parameter 2');

/*
//CHAIN
function fn(a) {
  return function(b) {
    return function(c) {
      return a + b + c;
    };
  };
}

const n1 = fn(1);
const n2 = n1(2);
const res = n2(3);
console.log('a + b + c = ' + res);

const fn = a => b => c => a + b + c;

const res = fn(1)(2)(3);
console.log('a + b + c = ' + res);

//CALLBACK
const fn = () => {
  console.log('Callback from from timer');
};

setTimeout(fn, 5000);


//LISTENER
const iterate = (array, listener) => {
  for (const item of array) {
    listener(item);
  }
};

const cities = ['Kiev', 'London', 'Beijing'];

const each = city => {
  console.log('City: ' + city);
};

iterate(cities, each);

//EVENTS
const adder = (value) => {
  const add = (a) => {
    value += a;
    if (value >= add.maxValue) add.maxEvent(value);
    return add;
  };
  add.max = (max, event) => {
    add.maxValue = max;
    add.maxEvent = event;
    return add;
  };
  return add;
};

// Usage

const maxReached = (value) => {
console.log('max value reached, value: ' + value);
};

const a1 = adder(10).max(100, maxReached)(-5);

a1(25);
a1(50);
a1(75);
a1(100);
a1(-200)(50)(30);


//EVENT_EMITTER
const events = require('events');

const emitter = new events.EventEmitter();

emitter.on('new city', (city) => {
  console.log('Emitted city: ' + city);
});

emitter.on('data', (array) => {
  console.log(array.reduce((a, b) => a + b));
});

emitter.emit('new city', 'Delhi');
emitter.emit('new city', 'Berlin');
emitter.emit('new city', 'Tokyo');
emitter.emit('data', [5, 10, 7, -3]);

//Wrapper
const wrap = (fn) => {
  console.log('Wrap function: ' + fn.name);
  return (...args) => {
    console.log('Called wrapper for: ' + fn.name);
    console.dir({ args });
    const result = fn(...args);
    console.log('Ended wrapper for: ' + fn.name);
    console.dir({ result });
    return result;
  };
};

// Usage:

const func = (par1, par2) => {
  console.dir({ method: { par1, par2 } });
  return [par1, par2];
};

const cloned = wrap(func);
cloned('Uno', 'Due');


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

// Usage:

const fn = (par) => {
  console.log('Function called, par: ' + par);
};

const f = once(fn);

f('first');
f('second');

//COUNT
const limit = (count, fn) => {
  let counter = 0;
  return (...args) => {
    if (counter === count) return;
    const res = fn(...args);
    counter++;
    return res;
  };
};

// Usage:

const fn3 = (par) => {
  console.log('Function called, par: ' + par);
};

const fn2 = limit(2, fn3);

fn2('first');
fn2('second');
fn2('third');

*/
//CANCELABLE
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

// Usage:

const fn = (par) => {
  console.log('Function called, par: ' + par);
};

const f = cancelable(fn);
f('first');

f.cancel();
f('second');


//CLASS
class Point {
  constructor(x, y) {
    this.x = x;
    this.y = y;
  }

  move(x, y) {
    this.x += x;
    this.y += y;
  }

  toString() {
    return `[${this.x}, ${this.y}]`;
  }
}



const p1 = new Point(10, 20);
p1.move(-5, 10);

console.log(p1);
console.log(p1.toString());
console.log(p1 + '');