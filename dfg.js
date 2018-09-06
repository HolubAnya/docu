'use strict';

/*const data = [
  ['Marcus Aurelius', '212-04-26', 'Rome'],
  ['Commodus Antoninus', '312-04-26', 'Rome'],
  ['Victor Glushkov', '1923-08-24', 'Rostov on Don'],
  ['Ibn Arabi', '1165-11-16', 'Murcia'],
  ['Mao Zedong', '1893-12-26', 'Shaoshan'],
  ['Rene Descartes', '1596-03-31', 'La Haye en Touraine']
];

class Person {
  get name() {
    return this[0];
  }
  get birth() {
    return this[1];
  }
  get city() {
    return this[2];
  }
}
const query = person => person.name !== 'Marcus Aurelius';

data.forEach(person => {
  Object.setPrototypeOf(person, Person.prototype);
  // person.__proto__ = Person.prototype
});
 const res = data.filter(query);
 console.dir(res);
 
const cities1 = new Set(['Beijing', 'Kiev']);
const cities2 = new Set(['Kiev', 'London', 'Baghdad']);


const union = (s1, s2) => new Set ([...s1, ...s2]);
const intersection = (s1, s2) => new Set ([...s1].filter(v => s2.has(v)));
const difference = (s1, s2) =>  new Set ([...s1].filter(v => !s2.has(v)));
const complement = (s1, s2) => difference(s2, s1);

const operations = [union, intersection, difference, complement];

const results = operations.map(operation => ({ [operation.name]: operation(cities1, cities2) }));
console.dir(results);
*/

const arrKeys = ['a', 'b', 'c', 'd'];
const arrValues = [1, 2, 3, 4];
const alpha = new Map();
const fun = (arr1, arr2) => arr1.forEach(el => alpha.set(el, 4));
console.dir(alpha);
