/*
Integers are represented as an array of 0s and 1s
See https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/Bitwise_Operators

The parity of an integer is given by the number of 1s in an integer's bitwise representation.
I.e. the parity of 3 (011) is 0, and the parity of 4 (100) is 1.

write a function that computes the parity of a given integer.
*/


//solution:
var parity = function(intiger){
  var result = 0;

  //we'll keep shifting the right-most bit off until the int is 0
  while(intiger){

    //intiger&1 returns 1 if right-most bit is 1 and vice versa
    //result ^= intiger & 1 will flip to 1 when it first encounters a 1...
    //...and will flip back to 0 when it next encounters a 1
    result ^= intiger & 1;

    intiger >>= 1; //discard the right-most bit and repeat
  }

  return result; //which will alwas be zero or one
};

//export for testing
module.exports = parity;
