var should = require('should');
var quotient = require('./quotient.js');

describe('quotient', function(){

  it('should be a function', function(){
    quotient.should.be.type('function');
  });

  it('should return return the correct quotient', function(){
    quotient(1, 1).should.equal(1);
    quotient(1, 2).should.equal(0);
    quotient(10, 2).should.equal(5);
    quotient(10, 3).should.equal(3);
    quotient(21, 3).should.equal(7);
    quotient(100, 3).should.equal(33);
    quotient(100, 4).should.equal(25);
  });


});
