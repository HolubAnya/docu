const express  = require('express');

let app = express();

app.get('/', function(req, res){
	res.send('Hello API!')
})

app.listen(8000, function(){
	console.log('API app has been started!');
})