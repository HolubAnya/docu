'use strict'
const events = require('events');
const myEmitter = new events.EventEmitter();
myEmitter.on('month', (mon) => {
	let a = Math.round(Math.random());
	let b;
	a === 0 ? 10 : 12;
	console.log();
});
myEmitter.on('month', (prediction) => {
  console.log('Today you will find your love');
});




myEmitter.emit('month', 'prediction');