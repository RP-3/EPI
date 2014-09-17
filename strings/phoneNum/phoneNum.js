/*
Write a function that takes a string of digits
and returns all possible combinations of letters
that could result from that string of digits.
*/

var digits = {
  "1": "",
  "2": "ABC",
  "3": "DEF",
  "4": "GHI",
  "5": "JKL",
  "6": "MNO",
  "7": "PQRS",
  "8": "TUV",
  "9": "WXYZ",
  "0": ""
};

var phoneNum = function(phoneNum){
  
  var results = [];

  var Tree = function(character){
    this.character = character;
    this.children = [];
  }

  Tree.prototype.build = function(string){

    if(string.length === 0) return;

    var options = digits[string[0]];

    for(var i=0; i<options.length; i++){
      this.children[i] = new Tree(options[i]);
      this.children[i].build(string.slice(1));
    }
  };

  Tree.prototype.retrieveWords = function(prefix){
    if(this.children.length){
      for(var i=0; i<this.children.length; i++){
        this.children[i].retrieveWords(prefix + this.children[i].character);
      }
    }else{
      results.push(prefix);
    }
  };

  var t = new Tree('');
  t.build(phoneNum);
  t.retrieveWords('');

  return results;

};

module.exports = phoneNum;
