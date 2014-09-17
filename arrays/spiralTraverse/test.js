var should = require('should');
var traverse = require('./spiralTraverse');

var input = [
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12],
  [13,14,15,16]
];

var input2 = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]
];

var input3 = [
  [1, 2, 3, 4],
  [4, 5, 6, 7],
  [9, 10,11,12]
];

var input4 = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9],
  [10,11,12]
];

describe('spiralTraverse', function(){

  it('should be a function', function(){
    traverse.should.be.type('function');
  });

  it('should traverse an even-sized array correctly', function(){
    var result = [];
    traverse(input, function(element){
      result.push(element);
    });
    result.should.eql([1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10]);
  });

  it('should traverse an odd-sized array correctly', function(){
    var result = [];
    traverse(input2, function(element){
      result.push(element);
    });
    result.should.eql([1, 2, 3, 6, 9, 8, 7, 4, 5]);
  });

  it('should traverse a horizontal rectangular array correctly', function(){
    var result = [];
    traverse(input3, function(element){
      result.push(element);
    });
    result.should.eql([1, 2, 3, 4, 7, 12, 11, 10, 9, 4, 5, 6]);
  });

  it('should traverse a vertical rectangular array correctly', function(){
    var result = [];
    traverse(input4, function(element){
      result.push(element);
    });
    result.should.eql([1, 2, 3, 6, 9, 12, 11, 10, 7, 4, 5, 8]);
  });

});
