 process.stdin.setEncoding('utf8');
//process.exit();
//process.();

process.stdin.on('readable', () => {
  const chunk = process.stdin.read();
  if (chunk !== null) {
    process.stdout.write(`data: ${chunk}`);
    process.exit();  
  }
});

process.stdin.on('end', () => {
  process.stdout.write('end');
});


/**{ a:0, b:0}--->()=>{...}
console.log ('Ente the .. number')
*/