/*
In excel and other spreadsheet software, columns are encoded by letters.
I.e., column A refers to column 1, column Z refers to column 26. 

Column encodings can be multiple characters
I.e., column AA refers to column 27, column AB to column 28 etc.

Write a function that takes an alphabet string and returns its corresponding column number as an integer
*/

var encodeExcel = function(string){
  
  function convertToInt(letter){
    return letter.charCodeAt(0) - 64;
  }

  var arrayRep = string.split('').map(convertToInt);

  var result = arrayRep.pop();
  var index = 1;

  while(arrayRep.length){
    result += Math.pow(26, index) * arrayRep.pop();
    index++;
  }
  
  return result;
};


//export for testing
module.exports = encodeExcel;
