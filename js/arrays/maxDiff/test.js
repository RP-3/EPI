var should = require('should');
var maxDiff = require('./maxDiff.js');

describe('maxDiff', function(){

  it('should be a function', function(){
    maxDiff.should.be.type('function');
  });

  it('should return 0 when given a downward trend', function(){
    maxDiff([5, 4, 3, 2, 1]).should.equal(0);
  });

  it('should should return max - min when given an upward trend', function(){
    maxDiff([0, 1, 2, 3, 4, 5]).should.equal(5);
  });

  it('should return difference when given a wiggly data set', function(){
    maxDiff([0, 1, -1, 2, -2, 3, -3, 4, -4, 5]).should.equal(9);
    maxDiff([20, 0, 5, 2, 10, 3, 2, -5, 15, 21, -5, 10]).should.equal(26);
  });

});
