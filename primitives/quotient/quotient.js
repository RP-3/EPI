/*
write a function that returns the non-decimal value of dividing one 
integer by another using only addition, subtraction and bit-wise operators.

The algorithm you learnt for this in primary school is fine for now, but 
for extra credit, find a way to speed it up but an order of magnitude or so

*/

//naiive solution:
var quotient = function(a, b){
  var result = 0;

  while(a >= b){
    a -= b;
    result ++;
  }

  return result;
};

//better solution
var quotient = function(a, b){
  var result = 0;

  while(a >= b){

    //inner procedure to save several iterations
    var place = 0;
    while(a >= (b << place) ){ //work out how many times b * 2^place fits in
      place++;
    }

    result += 1 << (place -1); //add 2^place to result
    a -= (b << place -1); //subtract b*2^place from result

  }

  return result;
}

module.exports = quotient;

