/*
Memory is scarce!

Write a linear-time, constant-space, non-recursive function 
that reverses a singly-linked list.

Recursion is cheating! We want a constant-space solution
but recursion would implicitly use linear space on the call
stack :)

*/

var List = function(data){
  this.data = null;
  this.start = new Node(data);
};

List.prototype.addToTail = function(data) {
  this.start.addToTail(data);
};

List.prototype.reverse = function(data) {
  this.start = this.start.reverse();
};

var Node = function(data){
  this.data = data;
  this.next = null;
};

Node.prototype.addToTail = function(data) {
  if(this.next === null){
    this.next = new Node(data);
  }else{
    this.next.addToTail(data);
  }
};

Node.prototype.reverse = function(context) {
  
  //set up two pointers, to the first two nodes
  var ptr = this.next;
  var prev = this;
  var temp;

  //reset the head to be the tail
  this.next = null;

  //iterate over the list, setting the ptr's next
  //to the prev. 
  while(ptr !== null){
    temp = ptr.next;
    ptr.next = prev;
    prev = ptr;
    ptr = temp;
  }

  //change the reference to the head
  return prev;
};

module.exports = List;
