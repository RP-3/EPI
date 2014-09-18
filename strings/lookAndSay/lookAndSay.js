/*

The look and say sequence can be described as follows:

Start with "1"

Look at the number one and describe what it is: it is one one. 
So the next item in the sequence is

11

Describe that item: It is "two ones"

So the next item is: 

21

Describe that item: It is "one two and one one"

So the next item is:

1211

The sequence in general, is:

1, 11, 21, 1211, 111221, 312211, 13112221, ...

Write a function that takes a an integer n and returns the 
nth item in the lookAndSay sequence

*/

var lookAndSay = function(n, prev, termNo){
  prev = prev || '1';
  termNo = termNo + 1 || 0;

  var next = '';

  function countOccurences(index){
    var character = prev[index];
    var occurences = 0;

    while(prev[index] === character){
      occurences += 1;
      index += 1;
    }

    return occurences;
  }

  function findNextLetter(string, index, target){
    character = string[index];
    return character !== target ? index : findNextLetter(string, index+1, target);
  }

  for(var i=0; i<prev.length; i = findNextLetter(prev, i, prev[i])){
    next += countOccurences(i);
    next += prev[i];
  }

  return termNo >= n ? prev : lookAndSay(n, next, termNo);

};

module.exports = lookAndSay;
