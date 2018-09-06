const rivers = ['Ganga','Yamuna','brahmaputra Assam','Mahanadi','godaяvari','Kris-hna','Na-rmada','Ta12pti','gomti','Ko3shi',
'Gaїnga','Gand45aki','Mahi','Ganga','123o','Betwa','Son','Sutlej','Ravi','Beas','Chenab','Jehlam','Ghaggar','Hugli','Damodar','Indus'];			


//SORT
const newarr = rivers => rivers.sort(function(a,b){
	return +(a.toString().toLowerCase()>=b.toString().toLowerCase()) ? 1 : -1;
});
//console.log(newarr(rivers));

const newarr1 = rivers => rivers.sort(function(a,b){return a.length - b.length;
});
 //console.log(newarr1(rivers));

const newarr2 = rivers => rivers.sort(function(a,b){
	return b.length - a.length;
});
 //console.log(newarr2(rivers));

const newarr3 = rivers => rivers.sort(function(a,b){
     return a.match(/[aeoui]/ig).length - b.match(/[aeoui]/ig).length;
});
//console.log(newarr3(rivers));





//FILTER
const arr0 = rivers => rivers.map(el => el.split(' ')).filter(el => el.length === 1).join('\n');
console.log(arr0(rivers));

const arr = rivers => rivers.filter(word => word.match(/^[A-Z].*/));
//console.log(arr(rivers));

const arr1 = rivers => rivers.filter(word => word.match(/[-]/));
//console.log(arr1(rivers));

const arr2 = rivers => rivers.map(word => word.split(' ')).filter(word => word.length === 1).join('\n');
//console.log(arr2(rivers));

const arr3 = rivers => rivers.filter(word => word.length <= 10);
//console.log(arr3(rivers));
const array = ['Ganga','Yamuna','brahmaputr-a Assam'];
 const arr4 = rivers => rivers.map(el => el.split('').filter(s => s.search(/[-]/gi)).join(''));
 console.log(arr4(array));

// const arr5 = rivers => rivers.map(el => el.split('').filter(s => s.search(/[0-9-]/gi)).join(''));
// console.log(arr5(rivers));



//ARRAY
const myarr = rivers => rivers.map(el => el.split(' '));
//console.log(myarr(rivers));

const myarr1 = rivers => rivers.map(el => el.split('').map(el => el.charCodeAt()));
//console.log(myarr1(rivers));

const myarr2 = rivers => rivers.map(el => el.split('').filter(s => s.search(/[\w-]/gi)));
//console.log(myarr2(rivers));



//ALL SIMBOLS IN REVERSE ORDER
const array = ['Ganga','Yamuna','brahmaputr-a Assam'];
const myArr = rivers => rivers.map(el => el.split('').reverse().join(''));
//console.log(myArr(array)); 

