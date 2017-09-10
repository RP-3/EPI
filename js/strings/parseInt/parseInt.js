/*

Reimplement the parseInt function in javascript

You may use any mathematical operators.

Your solution should ignore decimals, commas, spaces
and any other characters.

*/

var nums = {
  "0": 0,
  "1": 1,
  "2": 2,
  "3": 3,
  "4": 4,
  "5": 5,
  "6": 6,
  "7": 7,
  "8": 8,
  "9": 9
}

var parseInt = function(numString){
  var result = 0;
  for(var i=0; i<numString.length; i++){

    //handle decimals
    if(numString[i] === '.') return result;

    //handle unknown characters
    if(!nums.hasOwnProperty(numString[i])) continue;

    result = (result * 10) + nums[numString[i]];
  }
  return result;
};

module.exports = parseInt;
