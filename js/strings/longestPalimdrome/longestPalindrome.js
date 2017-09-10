/*
Write a function that finds the longest
palindrome in a string that's passed to it

in the string "My dad is a racecar athlete", the longest
palindrome is "a racecar a".  Count whitespaces as valid characters. Other
palindromes in the above string include "dad", "ete", " dad " (including
whitespace on each side of dad).

*/

//naiive solution
var drome = function(string){
  var dromes = [];

  //isDrome
  function isDrome(string){
    return string.split('').reverse().join('') === string;
  }

  //extract longest drome
  function fetchLongestDromeStarting(index){
    if(!isDrome(string.slice(index-1, index+2))){
      return;
    }

    for(var i=2; i<string.length; i++){
      if(isDrome(string.slice(index-i, index+i+1))){
        continue;
      }else{
        dromes.push(string.slice(index-(i-1), index+i));
        break;
      }
    }
  }

  //attempt to extract dromes from all points in the string
  for(var j=1; j<string.length; j++){
    fetchLongestDromeStarting(j);
  }

  var result = '';
  for(var i=0; i<dromes.length; i++){
    result = dromes[i].length > result.length ? dromes[i] : result;
  }

  return result;
};



module.exports = drome;
