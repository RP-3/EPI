/*
Given an array of arbitrary length containing only positive integers, 
write a function that returns the maximum difference between two
integers in the array
*/

var maxDiff = function(array){
  
  var min = array[0];

  var max = 0;

  for(var i=0; i<array.length; i++){
    
    if(array[i] < min){
      min = array[i];
    }

    max = array[i] - min > max ? array[i] - min : max;

  }

  return max;

};

module.exports = maxDiff;
