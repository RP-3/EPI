/*
Write a function, merge, that takes two linked lists (L and F), where L and F
are two individual linked lists that are sorted in ascending order, 
and returns a single, sorted, linked List. 

Make this function exist on the prototype of the linkedList class
you've been given

Your solution should use O(1) additional storage: i.e., you should reuse 
the nodes provided in the input instead of creating new ones. The only field
you can change in a node is "next".

E.g., 
List1 = 2 -> 3 -> 9 -> 11
List2 = 5 -> 7 -> 10  -> 12

List1.zip(list2) === 2 -> 3 -> 5 -> 7 -> 9 -> 10 -> 11 -> 12 //true

*/

var Node = function(data, next){
  this.data = data;
  this.next = next || null;
};

Node.prototype.addToTail = function(data) {
  if(this.next !== null){
    this.next.addToTail(data);
  }else{
    this.next = new Node(data, null);
  }
};

Node.prototype.getLength = function(nodeNumber) {
  nodeNumber = nodeNumber+1 || 0;
  if(this.next !== null){
    return this.next.getLength(nodeNumber);
  }else{
    return nodeNumber;
  }
};


Node.prototype.merge = function(list) {
  
  if(!list) return this;

  var myPtr = this;
  var prev = null;
  var yourPtr = list;
  var temp;

  while(myPtr !== null && yourPtr !== null){

    //inspect current node in both lists to see wich is greater
    if(yourPtr.data <= myPtr.data){

      //break node from other list and splice into this list
      temp = yourPtr.next;
      yourPtr.next = myPtr;
      
      if(prev){
        prev.next = yourPtr;
      }else{
        prev = myPtr;
      }

      myPtr = yourPtr;

      yourPtr = temp;

    }else{

      prev = myPtr;
      myPtr = myPtr.next;

    }

  }

  if(yourPtr !== null){
    prev.next = yourPtr;
  }

  return this;

};

module.exports = Node;
