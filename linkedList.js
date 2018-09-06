'use strict';


//DoublyList
function Node(value){
	this.data = value;
	this.previous = null;
	this.next = null;
}

function DoublyList(){
	this.length = 0;
	this.head;
	this.tail;
	this[Symbol.iterator] = function() {
    let element = this.head;
    return {
      next() {
        this.current = element;
        if (!element) return { value: null, done: true };
        element = element.next;
        return { value: this.current.data, done: false };
      }
    };
};
}

//Adding an element
DoublyList.prototype.add = function(value){
	const node = new Node(value);

	if(this.length){
		this.tail.next = node;
		node.previous = this.tail;
		this.tail = node;
		this.length++;
		
	} else {
		this.head = node;
		this.tail = node;
		this.length = 1;
	}
	
	return node;
};


//removing an element
DoublyList.prototype.remove = function(position){
  let currentNode = this.head,
	length = this.length,
	count = 1,
	message = {failure: 'Failure: non-existent node in this list.'},
	nodeBefore = null,
	nodeToDelete = null,
	deletedNode = null,
	nodeAfter = null;

  
  //failure
  if (length === 0|| position < 1 || position > length){
  	throw new Error(message.failure);
  }

  //deleted the first node
  if (position === 1){
  	this.head = currentNode.next;
   }

  //deleted the last node
  if (position === this.length){
  	this.tail = this.tail.previous;
  	this.tail.next = null;
  }

  //deleted node was in the middle
  else {
  	
  	while (count < position){
  		
		currentNode = currentNode.next;
  		count++;
  		
  	}
  
  nodeBefore = currentNode.previous;
  nodeAfter = currentNode.next;
  nodeToDelete = currentNode;
        
  nodeAfter.previous = nodeBefore;
  deletedNode = nodeToDelete;
  nodeToDelete = null;
  }

  this.length--;
  return 

  };


  //Method append  
DoublyList.prototype.append = function(info){
   let element = this.head;
   let i = 1;
   while (i <= this.length){
      let value = element.data;
      element.data = [value, info];
      element = element.next;
      i++;
   } 
   return doublylist;
}


//Making access to the node by index
DoublyList.prototype.makeIndex = function(){
  let element = this.head;
  for (let i = 1; i <= doublylist.length; i++){
    element.index = i;
    doublylist[i] = element;
    element = element.next;
  }
  return;
}


// Rewriting insert
DoublyList.prototype.insert = function(index, value){
  let node = new Node(value);
  node.index = index;
  

  if (index <= this.length && index != 1){ 
    node.previous = doublylist[index].previous;
    node.next = doublylist[index].next;
    doublylist[index] = node;
    doublylist[index].previous.next = node;
    doublylist[index].next.previous = node;
  }
  if (index === 1){
    doublylist[index] = node;
    node.next = this.head.next;
    node.previous = null;
    this.head = node;
    this.head.next.previous = node;
  } 
  if (index > this.length){
    doublylist[index] = node;
    this.tail.next = node;
    node.previous = this.tail;
    node.next = null;
    this.tail = node;
    this.length++;
  }
  
  return doublylist;
}
 

//Making a copy
DoublyList.prototype.clone = function(){
  const anotherlist = new DoublyList();
  let element = this.head;
  anotherlist.length = this.length;
  anotherlist.head = this.head;
  anotherlist.tail = this.tail;
  for (let i = 1; i <= doublylist.length; i++){
    element.index = i;
    element = element.next;
  }
  return anotherlist;
}   

//Map
DoublyList.prototype.map = function(fn){
  let element = this.head;
  for (let i = 1; i <= doublylist.length; i++){
    element.index = i;
    const result = fn(element.data);
    element = element.next;
    return result;
  }
  
}
const fun = (str1, str2) => str1 === str2 ? true : false;

//Comparing data in the lists 
DoublyList.prototype.compare = function(list){
  if (this.length != list.length){return false};
  let element1 = list.head;
  let element2 = this.head;
  let res;
  for (let i = 1; i <= doublylist.length; i++){
    res = fun(element1.data, element2.data);
    element1 = element1.next;
    element2 = element2.next;
  }
return res;
}


//Usage
const doublylist = new DoublyList();
doublylist.add('first'); 
doublylist.add('second');
doublylist.add('third');
//doublylist.remove(1);
doublylist.append('number');
doublylist.makeIndex();
doublylist.insert(22, 'fourth');
//console.log(doublylist[2]);;
doublylist.clone();
//console.log(doublylist);
