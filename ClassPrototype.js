'use strict';
/*
//PROTOTYPE SYNTAX
function Rect(x, y, z){
  this.x = x;
  this.y = y;
  this.z = z;
}

Rect.prototype.toString = function() {
  return `[${this.x}, ${this.y}, ${this.z}]`;
};

const p1 = new Rect(10, 20, 50);


console.log(p1);
console.log(p1.toString());
console.log(p1 + '');


//MIXIN
const mixin = {
  volume: function(x, y, z) {
    return x*y*z;
  }
};

const extend = (obj, mixin) => {
  Object.keys(mixin).forEach(key => obj[key] = mixin[key]);
  return obj;
};

extend(Rect, mixin);
console.log(Rect.volume(3, 5, 10));


//MIXIN WITHOUT EXTEND
const mixin1 = function(){
  this.sb = function(){
    return (this.x + this.y)*this.z;
  };
  return this;
}
mixin1.call(Rect.prototype);
const p2 = new Rect(2, 3, 5);
console.log(p2.sb());


function Polyhedron(x, y, z){
  this.x = x;
  this.y = y;
  this.z = z;
}

Polyhedron.prototype = Object.create(Rect.prototype);
Polyhedron.prototype.volume = function(x, y, z){
  return x*y*z;
}
const p2 = new Polyhedron(1, 5, 10); 
console.log(p2);   //Rect { x: 1, y: 5, z: 10 } 
console.log(p2.volume(2, 4, 8)); //64
console.log(p2 + ''); //[1, 5, 10]

//CLASSES 
class Paralelogram {
  constructor(d1, d2, sinAlpha){
    this.d1 = d1;
    this.d2 = d2;
    this.sinAlpha = sinAlpha;
  }

  area(d1, d2, sinAlpha){
    return d1*d2*sinAlpha/2;
  }
  toString() {
    return `[${this.d1}, ${this.d2}, ${this.sinAlpha}]`;
  }
}

const paral = new Paralelogram(10, 12, 0.3);
console.log(paral.area(10, 12, 0.3)); //18

class Rhombus extends Paralelogram {
  constructor(d1, d2){
    super(d1, d2);
    this.sinAlpha = 1;
  }
  area(d1, d2){
    return d1*d2/2;
  }
}

const rhomb = new Rhombus(13, 28);
console.log(rhomb.area(13, 28)); //182
console.log(rhomb.toString()); //[13, 28, 1]


class Rectangle extends Paralelogram {
  constructor(d1, sinAlpha){
    super(d1, sinAlpha);
    this.d2 = d1;
  }
  area(d1, sinAlpha){
    return d1*d1*sinAlpha/2;
  }
}

const rectangle = new Rectangle(12, 0.2);
console.log(rectangle.area(12, 0.2)); //14.4

//OBJECT
const triangle = {
  a: 10,
  b: 20,
  sinBeta: 0.5,
  area(a, b, sinBeta){
    return a*b*sinBeta/2;
  },
  toString(){
    return  `[${this.a}, ${this.b}, ${this.sinBeta}]`;
  }
};

console.log(triangle.toString()); //[10, 20, 0.5]
console.log(triangle.area(11, 11, 0.2)); //12.1
*/

//FACTORY
function Funct(ad, bc)  {
  return function Function(ac){
    return ad*ac*bc;
  };
}

const Mul = Funct(2, 9);
const mul = new Mul(6);
console.log(mul); //108