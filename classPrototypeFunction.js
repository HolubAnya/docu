'use strict';

//PROTOTYPE

const ObjProto = {
  constructor: function(name, age){
    this.name = name;
    this.age = age;
    return this;
  },
  greet: function(){
    console.log('Hi, my name is ' + this.name)
  }
};


const obj = Object.create(ObjProto).constructor('Violetta', 17);

// console.log(obj.name); //Violetta
// obj.greet();

const Obj1 = Object.create(ObjProto);
Obj1.constructor = function(name, age, skills){
	ObjProto.constructor.apply(this, arguments);
	this.skills = skills || [];
	return this;
};

const anotherObj1 = Object.create(Obj1).constructor('Amili', 18, ['JS']);
//console.log(anotherObj1.skills);


//ANOTHER!!!

const AnotherProto = function(name){
	this.name = name;
};

AnotherProto.prototype.tellName = function(){
	console.log('My name is ' + this.name);
};

const Developer = function(neme, skill){
	AnotherProto.apply(this, arguments);
	this.skill = skill || [];
};

Developer.prototype = Object.create(AnotherProto.prototype);
Developer.prototype.constructor = Developer;
const developer = new Developer('Bob', ['php', 'js']);
//console.log(developer.skill);

const person = new AnotherProto('Sandra');
//person.tellName();

// console.log(person instanceof AnotherProto); //true
// console.log(AnotherProto.prototype.isPrototypeOf(person));  //true


//CLASS

function Animal (name) {
  this.name = name;  
}
Animal.prototype.speak = function () {
  console.log(this.name + ' makes a noise.');
}

class Dog extends Animal {
  speak() {
    super.speak();
    console.log(this.name + ' barks.');
  }
}

const d = new Dog('Mitzie');
//d.speak();



class Polygon {
  constructor(height, width) {
    this.name = 'Polygon';
    this.height = height;
    this.width = width;
  }
  sayName() {
    console.log('Hi, I am a ', this.name + '.');
  }
}

class Square extends Polygon {
  constructor(length) {
     super(length, length);
  }

  get area() {
    return this.height * this.width;
  }

  set area(value) {
    this.height = this.width = Math.sqrt(value);
  } 
}
const square = new Square(5);
//console.log(square.area); //25


const Rect = class {
  constructor(x, y, width, height) {
    this.x = x;
    this.y = y;
    this.width = width;
    this.height = height;
  }

  toString() {
    return `[${this.x}, ${this.y}, ${this.width}, ${this.height}]`;
  }
};

const equilateral = Category => class extends Category {
  constructor(x, y, side) {
    super(x, y, side, side);
  }
};

const Square = equilateral(Rect);

const p1 = new Square(10, 20, 50);
//console.log(p1.toString());



class Worker {
	constructor(name, surname, rate, days){
		this.name = name;
		this.surname = surname;
		this.rate = rate;
		this.days = days;
	}
	set anotherSurname(m){
		this.surname = m;
	}
	get salery(){
		return this.rate*this.days;
	}
	get workersSurname(){
		return this.surname;
	}
	set anotherName(n){
		this.name = n;
	}
}
const david = new Worker('David', 'Jeferson', 1023, 24);
console.log(david.workersSurname); //Jeferson
david.anotherSurname = 'Baker';
console.log(david.workersSurname); //Baker
console.log(david.salery); //24552



//MIXIN
function basic(anotherFn){
	anotherFn.greet = function(name){
		return 'Hello there, ' + name;
	};

}

const t1 = setTimeout(() => {
  console.log('Hello from timer');
}, 1000);

basic(t1);
//console.log(t1.greet('James'));



//FUNCTION EXTEND!!!
const extend = (obj, mixin) => {
  Object.keys(mixin).forEach(key => obj[key] = mixin[key]);
  return obj;
};

const obj1 = {
  name: 'Marcus Aurelius',
  city: 'Rome',
  born: '121-04-26'
};

const mix1 = {
  toString() {
    return `${this.name} was born in ${this.city} in ${this.born}`;
  },
  age() {
    const year = new Date().getFullYear();
    const born = new Date(this.born).getFullYear();
    return year - born;
  }
};

extend(obj1, mix1);
// console.log(obj1);
// console.log(obj1.toString());
// console.log(`His age is ${obj1.age()} as of today`);

//THE $AME USING OBJECT.A$$IGN
Object.assign(obj1, mix1);

console.log(obj1.toString());
console.log(`His age is ${obj1.age()} as of today`);